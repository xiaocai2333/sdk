set(test_src
#        ${CMAKE_SOURCE_DIR}/interface/ConnectionImpl.cpp
#        ${CMAKE_SOURCE_DIR}/interface/Status.cpp
        main.cpp)


add_executable(test_query ${test_src})

#include_directories(${CMAKE_SOURCE_DIR}/interface)
#include_directories(${CMAKE_SOURCE_DIR}/grpc)

target_link_libraries(test_query
        milvus_sdk
        pthread)

install(TARGETS test_query DESTINATION test)

set(test_insert_src
        #        ${CMAKE_SOURCE_DIR}/interface/ConnectionImpl.cpp
        #        ${CMAKE_SOURCE_DIR}/interface/Status.cpp
        test.cpp)


add_executable(test_insert ${test_insert_src})

#include_directories(${CMAKE_SOURCE_DIR}/interface)
#include_directories(${CMAKE_SOURCE_DIR}/grpc)

target_link_libraries(test_insert
        milvus_sdk
        pthread)

install(TARGETS test_insert DESTINATION test)