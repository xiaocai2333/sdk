// Copyright (C) 2019-2020 Zilliz. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance
// with the License. You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software distributed under the License
// is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
// or implied. See the License for the specific language governing permissions and limitations under the License.
#include <gtest/gtest.h>
#include "grpc/ClientProxy.h"
#include "interface/ConnectionImpl.h"

const milvus::FieldValue GetData() {
    milvus::FieldValue value_map;
    std::vector<int8_t> char_data;
    std::vector<int32_t> int32_data;
    for (int i = 0; i < 20; i++) {
        char_data.push_back(i);
        int32_data.push_back(i);
    }
    std::vector<milvus::VectorData> vector_data;
    for (int i = 0; i < 20; i++) {
        std::vector<float> float_data(10, 10.25);
        milvus::VectorData vectorData;
        vectorData.float_data = float_data;
        vector_data.push_back(vectorData);
    }
    value_map.int8_value["INT8"] = char_data;
    value_map.int32_value["INT32"] = int32_data;
    value_map.vector_value["VECTOR"] = vector_data;
    value_map.row_num = 20;
    return value_map;
}

milvus::Mapping
GetMapByInsertParam(milvus::grpc::InsertParam &insert_param) {
    milvus::Mapping map;
    for (int64_t i = 0; i < insert_param.schema().field_metas().size(); i++) {
        auto grpc_field = insert_param.schema().field_metas()[i];
        milvus::FieldPtr field_ptr = std::make_shared<milvus::Field>();
        field_ptr->field_name = grpc_field.field_name();
        field_ptr->field_type = (milvus::DataType) grpc_field.type();
        field_ptr->dim = grpc_field.dim();
        map.fields.emplace_back(field_ptr);
    }
    return map;
}

TEST(encode_test, encode_decode_test) {
    auto client = milvus::ConnectionImpl();
    milvus::ConnectParam connect_param;
    connect_param.ip_address = "127.0.0.1";
    connect_param.port = "8080";
    client.Connect(connect_param);
    std::vector<int64_t> ids_array;
    auto data = GetData();
    for (int64_t i = 0; i < 20; i++) {
        ids_array.push_back(i);
    }
    client.Insert("collection0", "tag01", data, ids_array);
}