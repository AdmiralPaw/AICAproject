# 'Google_test' is the subproject name
project(GoogleTests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run
        test_main.cpp
        TableTests.cpp
        ../Data/Implementations/TableImpl_0.cpp
        ../Utils/Utils.cpp
        ../Base/Settings.cpp
        ../Base/Implementations/AlgorithmImpl_0.cpp
        AlgorithmTests.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)