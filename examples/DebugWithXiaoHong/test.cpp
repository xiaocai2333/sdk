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

int main() {
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
    std::vector<int64_t> delete_ids;
    delete_ids.push_back(2);
    delete_ids.push_back(3);
    client.DeleteEntityByID("collection0", delete_ids);
    return 0;
}