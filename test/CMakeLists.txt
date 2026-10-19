cmake_minimum_required(VERSION 3.13)
project(cjson_tests LANGUAGES C)

option(CJSON_TEST_SANITIZERS "Build the cjson tests with ASan and UBSan" ON)

find_path(CJSON_INCLUDE_DIR NAMES cjson/cJSON.h)
find_library(CJSON_LIBRARY NAMES cjson)
if(NOT CJSON_INCLUDE_DIR OR NOT CJSON_LIBRARY)
    message(FATAL_ERROR "cJSON headers or library not found")
endif()

set(REPO_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/..)
set(INBOUNDS_SRC ${REPO_ROOT}/src/cjson/inbounds.c)
set(LOG_SRC ${REPO_ROOT}/src/log.c)
set(JSON_VALIDATION_SRC ${REPO_ROOT}/src/cjson/jsonValidation.c)
set(TEST_INCLUDE_DIRS
    ${REPO_ROOT}/include
    ${REPO_ROOT}/include/cjson
    ${CJSON_INCLUDE_DIR}
)

set(SANITIZE_FLAGS "")
if(CJSON_TEST_SANITIZERS)
    set(SANITIZE_FLAGS -fsanitize=address,undefined -fno-omit-frame-pointer)
endif()

function(add_cjson_test target source)
    add_executable(${target} ${source} ${ARGN})
    target_include_directories(${target} PRIVATE ${TEST_INCLUDE_DIRS})
    target_compile_options(${target} PRIVATE -Wall -Wextra -g ${SANITIZE_FLAGS})
    target_link_libraries(${target} PRIVATE ${CJSON_LIBRARY} ${SANITIZE_FLAGS})
endfunction()

enable_testing()

# Real code under test
add_cjson_test(test_import_post test_import_post.c ${INBOUNDS_SRC} ${LOG_SRC} ${JSON_VALIDATION_SRC})
add_test(NAME import_post_xhttp COMMAND test_import_post false xhttp)
add_test(NAME import_post_xhttp_negative COMMAND test_import_post false xhttp negative)
add_test(NAME import_post_httpupgrade COMMAND test_import_post false httpupgrade)
add_test(NAME import_post_httpupgrade_negative COMMAND test_import_post false httpupgrade negative)

add_cjson_test(test_delete_multi test_delete_multi.c ${INBOUNDS_SRC} ${LOG_SRC} ${JSON_VALIDATION_SRC})
add_test(NAME delete_multi COMMAND test_delete_multi)

add_cjson_test(test_set_fallbacks_response test_set_fallbacks_response.c ${INBOUNDS_SRC} ${LOG_SRC} ${JSON_VALIDATION_SRC})
add_test(NAME set_fallbacks_response COMMAND test_set_fallbacks_response)

add_cjson_test(test_set_fallbacks_post test_set_fallbacks_post.c ${INBOUNDS_SRC} ${LOG_SRC} ${JSON_VALIDATION_SRC})
add_test(NAME set_fallbacks_post COMMAND test_set_fallbacks_post)
add_cjson_test(test_list_every_client test_list_every_client.c ${REPO_ROOT}/src/cjson/clients.c ${INBOUNDS_SRC} ${LOG_SRC} ${JSON_VALIDATION_SRC})
add_test(NAME list_every_client COMMAND test_list_every_client)

add_cjson_test(test_clients_samples test_clients_samples.c ${REPO_ROOT}/src/cjson/clients.c ${INBOUNDS_SRC} ${LOG_SRC} ${JSON_VALIDATION_SRC})
add_test(NAME clients_samples COMMAND test_clients_samples)

add_cjson_test(test_clients_bulk test_clients_bulk.c ${REPO_ROOT}/src/cjson/clients.c ${INBOUNDS_SRC} ${LOG_SRC} ${JSON_VALIDATION_SRC})
add_test(NAME clients_bulk COMMAND test_clients_bulk)

add_cjson_test(test_clients_endpoints test_clients_endpoints.c ${REPO_ROOT}/src/cjson/clients.c ${INBOUNDS_SRC} ${LOG_SRC} ${JSON_VALIDATION_SRC})
add_test(NAME clients_endpoints COMMAND test_clients_endpoints)

add_cjson_test(test_security_sample test_security_sample.c ${INBOUNDS_SRC} ${LOG_SRC} ${JSON_VALIDATION_SRC})
add_test(NAME security_sample COMMAND test_security_sample ${CMAKE_CURRENT_SOURCE_DIR}/sample_inbounds.json)

# Assertion mutants return early without freeing, so LeakSanitizer would exit
# before stdout is flushed and hide the FAILED line. Leak detection is turned off
# for them; the delete_leak mutant keeps it on, since LSan is what catches it.
# Mutation checks: each mutant is a copy of inbounds.c with one guard or
# cleanup broken. The matching test must FAIL against it, so the test is
# marked WILL_FAIL. A mutant whose target text is missing is a configure error.
file(READ ${INBOUNDS_SRC} INBOUNDS_TEXT)
set(MUTANT_DIR ${CMAKE_CURRENT_BINARY_DIR}/mutants)
file(MAKE_DIRECTORY ${MUTANT_DIR})

function(make_mutant mutant_name find_text replace_text out_var)
    string(FIND "${INBOUNDS_TEXT}" "${find_text}" found_at)
    if(found_at EQUAL -1)
        message(FATAL_ERROR "mutant ${mutant_name}: target text not found in inbounds.c")
    endif()
    string(REPLACE "${find_text}" "${replace_text}" mutated "${INBOUNDS_TEXT}")
    # inbounds.c uses includes relative to its own location, so point them at the repo
    string(REPLACE "../../include/" "${REPO_ROOT}/include/" mutated "${mutated}")
    set(path ${MUTANT_DIR}/${mutant_name}_inbounds.c)
    file(WRITE ${path} "${mutated}")
    set(${out_var} ${path} PARENT_SCOPE)
endfunction()

make_mutant(xhttp_gate
    "if (xhttpSockoptStruct->listInStreamSettingsXHTTPSockoptObjCustomScokArrStructEnabled) {"
    "if (1) {"
    XHTTP_GATE_SRC)
add_cjson_test(mutant_xhttp_gate test_import_post.c ${XHTTP_GATE_SRC} ${LOG_SRC} ${JSON_VALIDATION_SRC})
add_test(NAME mutant_xhttp_gate_is_caught COMMAND mutant_xhttp_gate false xhttp negative)
set_tests_properties(mutant_xhttp_gate_is_caught PROPERTIES WILL_FAIL TRUE
    ENVIRONMENT "ASAN_OPTIONS=detect_leaks=0")

make_mutant(httpupgrade_gate
    "if (httpUpgradeSockoptStruct->listInStreamSettingsHTTPUpgradeSockoptObjCustomScokArrStructEnabled) {"
    "if (1) {"
    HTTPUPGRADE_GATE_SRC)
add_cjson_test(mutant_httpupgrade_gate test_import_post.c ${HTTPUPGRADE_GATE_SRC} ${LOG_SRC} ${JSON_VALIDATION_SRC})
add_test(NAME mutant_httpupgrade_gate_is_caught COMMAND mutant_httpupgrade_gate false httpupgrade negative)
set_tests_properties(mutant_httpupgrade_gate_is_caught PROPERTIES WILL_FAIL TRUE
    ENVIRONMENT "ASAN_OPTIONS=detect_leaks=0")

make_mutant(delete_guard
    "if(!deleteMultipleInboundsPostStruct->idsCount) {"
    "if(deleteMultipleInboundsPostStruct->idsCount) {"
    DELETE_GUARD_SRC)
add_cjson_test(mutant_delete_guard test_delete_multi.c ${DELETE_GUARD_SRC} ${LOG_SRC} ${JSON_VALIDATION_SRC})
add_test(NAME mutant_delete_guard_is_caught COMMAND mutant_delete_guard)
set_tests_properties(mutant_delete_guard_is_caught PROPERTIES WILL_FAIL TRUE
    ENVIRONMENT "ASAN_OPTIONS=detect_leaks=0")

make_mutant(delete_rawjson_leak
    "    free(rawJson);\n    cJSON_Delete(json);\n\n    return rawJsonCopy;"
    "    cJSON_Delete(json);\n\n    return rawJsonCopy;"
    DELETE_LEAK_SRC)
add_cjson_test(mutant_delete_leak test_delete_multi.c ${DELETE_LEAK_SRC} ${LOG_SRC} ${JSON_VALIDATION_SRC})
add_test(NAME mutant_delete_leak_is_caught COMMAND mutant_delete_leak)
set_tests_properties(mutant_delete_leak_is_caught PROPERTIES WILL_FAIL TRUE)

make_mutant(reality_key
    "cJSON_AddNumberToObject(realitySettingsObj, \"maxTimediff\""
    "cJSON_AddNumberToObject(realitySettingsObj, \"maxTimeDiff\""
    REALITY_KEY_SRC)
add_cjson_test(mutant_reality_key test_security_sample.c ${REALITY_KEY_SRC} ${LOG_SRC} ${JSON_VALIDATION_SRC})
add_test(NAME mutant_reality_key_is_caught COMMAND mutant_reality_key ${CMAKE_CURRENT_SOURCE_DIR}/sample_inbounds.json)
set_tests_properties(mutant_reality_key_is_caught PROPERTIES WILL_FAIL TRUE)

make_mutant(set_fallbacks_success
    "        cJSON_IsTrue(cJSON_GetObjectItem(jsonParser, \"success\")) &&\n        cJSON_HasObjectItem(jsonParser, \"msg\") &&\n        cJSON_IsString("
    "        cJSON_HasObjectItem(jsonParser, \"msg\") &&\n        cJSON_IsString("
    SET_FALLBACKS_SUCCESS_SRC)
add_cjson_test(mutant_set_fallbacks_success test_set_fallbacks_response.c ${SET_FALLBACKS_SUCCESS_SRC} ${LOG_SRC} ${JSON_VALIDATION_SRC})
add_test(NAME mutant_set_fallbacks_success_is_caught COMMAND mutant_set_fallbacks_success)
set_tests_properties(mutant_set_fallbacks_success_is_caught PROPERTIES WILL_FAIL TRUE
    ENVIRONMENT "ASAN_OPTIONS=detect_leaks=0")

make_mutant(set_fallbacks_xver_gate
    "        if (fallbacksItem->xverEnabled) {"
    "        if (fallbacksItem->xver) {"
    SET_FALLBACKS_XVER_SRC)
add_cjson_test(mutant_set_fallbacks_xver test_set_fallbacks_post.c ${SET_FALLBACKS_XVER_SRC} ${LOG_SRC} ${JSON_VALIDATION_SRC})
add_test(NAME mutant_set_fallbacks_xver_is_caught COMMAND mutant_set_fallbacks_xver)
set_tests_properties(mutant_set_fallbacks_xver_is_caught PROPERTIES WILL_FAIL TRUE
    ENVIRONMENT "ASAN_OPTIONS=detect_leaks=0")
