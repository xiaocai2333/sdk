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

#include <getopt.h>
#include <libgen.h>
#include <cstring>
#include <string>

#include "src/ClientTest.h"
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

void
print_help(const std::string &app_name);

int
main(int argc, char *argv[]) {
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
//    printf("Client start...\n");
//
//    std::string app_name = basename(argv[0]);
//    static struct option long_options[] = {{"server", optional_argument, nullptr, 's'},
//                                           {"port", optional_argument, nullptr, 'p'},
//                                           {"help", no_argument, nullptr, 'h'},
//                                           {nullptr, 0, nullptr, 0}};
//
//    int option_index = 0;
//    std::string address = "127.0.0.1", port = "19530";
//    app_name = argv[0];
//
//    int value;
//    while ((value = getopt_long(argc, argv, "s:p:h", long_options, &option_index)) != -1) {
//        switch (value) {
//            case 's': {
//                char* address_ptr = strdup(optarg);
//                address = address_ptr;
//                free(address_ptr);
//                break;
//            }
//            case 'p': {
//                char* port_ptr = strdup(optarg);
//                port = port_ptr;
//                free(port_ptr);
//                break;
//            }
//            case 'h':
//            default:
//                print_help(app_name);
//                return EXIT_SUCCESS;
//        }
//    }
//
//    ClientTest test(address, port);
//    test.Test();
//
//    printf("Client stop...\n");
//    return 0;
}

void
print_help(const std::string &app_name) {
    printf("\n Usage: %s [OPTIONS]\n\n", app_name.c_str());
    printf("  Options:\n");
    printf("   -s --server   Server address, default 127.0.0.1\n");
    printf("   -p --port     Server port, default 19530\n");
    printf("   -h --help     Print help information\n");
    printf("\n");
}
