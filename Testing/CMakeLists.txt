set(TMP_DIR ${CMAKE_BINARY_DIR}/Testing/Temporary)

set(TEST_CASES
inputParserTest
  # lrgCommandLineArgsTest
#   lrgFileReaderTest
)

foreach(_test_case ${TEST_CASES})
  add_executable(${_test_case} ${_test_case}.cpp)
  target_link_libraries(${_test_case} stringcal ${ALL_THIRD_PARTY_LIBRARIES})
endforeach()


add_test(inputParser ${EXECUTABLE_OUTPUT_PATH}/inputParserTest)