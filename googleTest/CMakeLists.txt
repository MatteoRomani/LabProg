project(googleTest)

add_subdirectory(./lib/googletest-master)
set(gtest_SOURCE_DIR, ./lib/googletest-master)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTest.cpp CellTest.cpp CellTest.h FormulaTest.cpp FormulaTest.h)
add_executable(runTest ${TEST_SOURCE_FILES} runAllTest.cpp)


target_link_libraries(runTest gtest gtest_main core)