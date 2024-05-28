project(Google_tests)
add_subdirectory(Lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_tests_run CarRepositoryTest.cpp
        CustomerControllerTest.cpp
        CustomerRepositoryTest.cpp
)

target_link_libraries(Google_tests_run CarRepositoryLib CustomerControllerLib )

target_link_libraries(Google_tests_run gtest gtest_main)