set(encode_tests_src
        ${unittest_srcs}
        encode_test.cpp)

add_executable(encode_tests ${encode_tests_src})

target_link_libraries(encode_tests
        milvus_sdk
        gtest
        pthread
        )

install(TARGETS encode_tests DESTINATION unittest)