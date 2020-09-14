//
// Created by zc on 2020/9/14.
//
#include "gtest/gtest.h"
#include "interface/ConnectionImpl.h"
#include "include/MilvusApi.h"
#include <gtest/gtest.h>
#include "grpc/ClientProxy.h"
#include "interface/ConnectionImpl.h"

const int n = 100000;
const int dim = 16;

const milvus::FieldValue GetData() {
    milvus::FieldValue value_map;
    std::vector<int32_t> int32_data;
    for (int i = 0; i < n; i++) {
        int32_data.push_back(i);
    }
    std::vector<milvus::VectorData> vector_data;
    for (int i = 0; i < n; i++) {
        std::vector<float> float_data(dim, 10.25);
        milvus::VectorData vectorData;
        vectorData.float_data = float_data;
        vector_data.push_back(vectorData);
    }

    value_map.int32_value["INT32"] = int32_data;
    value_map.vector_value["VECTOR"] = vector_data;
    value_map.row_num = n;
    return value_map;
}

int main() {
    auto client = milvus::ConnectionImpl();
    milvus::ConnectParam connect_param;
    connect_param.ip_address = "127.0.0.1";
    connect_param.port = "19530";
    client.Connect(connect_param);
    std::vector <int64_t> ids_array;
    auto data = GetData();
    for (int64_t i = 0; i < n; i++) {
        ids_array.push_back(i);
    }
    auto status = client.Insert("collection1", "tag01", data, ids_array);
//    if (status != )
}