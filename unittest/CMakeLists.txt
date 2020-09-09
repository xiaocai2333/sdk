include_directories(${CMAKE_SOURCE_DIR}/grpc)
include_directories(.)
enable_testing()
set(unittest_srcs ${CMAKE_CURRENT_SOURCE_DIR}/unittest_entry.cpp)

set(unittest_libs
        milvus_sdk
        gtest
        pthread
        )


add_subdirectory(encode_test)