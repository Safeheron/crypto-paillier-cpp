find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

find_package(PkgConfig REQUIRED)
pkg_search_module(PROTOBUF REQUIRED protobuf)  # this looks for opencv.pc file

include_directories("../src")

add_executable(paillier-test paillier-test.cpp)
target_link_libraries( paillier-test
        CryptoBN
        CryptoPaillier
        ${GTEST_BOTH_LIBRARIES}
        pthread )
add_test(NAME test-paillier COMMAND paillier-test)


