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

#include "grpc/GrpcClient.h"

#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include <memory>
#include <string>
#include <vector>

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientReaderWriter;
using grpc::ClientWriter;
using grpc::Status;

namespace milvus {
GrpcClient::GrpcClient(std::shared_ptr<::grpc::Channel>& channel)
    : stub_(::milvus::grpc::MilvusService::NewStub(channel)) {
}

GrpcClient::~GrpcClient() = default;

Status
GrpcClient::CreateCollection(const milvus::grpc::Mapping& mapping) {
//    ClientContext context;
//    ::milvus::grpc::Status response;
//    ::grpc::Status grpc_status = stub_->CreateCollection(&context, mapping, &response);
//
//    if (!grpc_status.ok()) {
//        std::cerr << "CreateHybridCollection gRPC failed!" << std::endl;
//        return Status(StatusCode::RPCFailed, grpc_status.error_message());
//    }
//
//    if (response.error_code() != grpc::SUCCESS) {
//        std::cerr << response.reason() << std::endl;
//        return Status(StatusCode::ServerFailed, response.reason());
//    }
    return Status::OK();
}

bool
GrpcClient::HasCollection(const ::milvus::grpc::CollectionName& collection_name, Status& status) {
    ClientContext context;
    ::milvus::grpc::BoolReply response;
//    ::grpc::Status grpc_status = stub_->HasCollection(&context, collection_name, &response);
//
//    if (!grpc_status.ok()) {
//        std::cerr << "HasCollection gRPC failed!" << std::endl;
//        status = Status(StatusCode::RPCFailed, grpc_status.error_message());
//    }
//    if (response.status().error_code() != grpc::SUCCESS) {
//        std::cerr << response.status().reason() << std::endl;
//        status = Status(StatusCode::ServerFailed, response.status().reason());
//    }
//    status = Status::OK();
    return response.bool_reply();
}

Status
GrpcClient::DropCollection(const ::milvus::grpc::CollectionName& collection_name) {
//    ClientContext context;
//    grpc::Status response;
//    ::grpc::Status grpc_status = stub_->DropCollection(&context, collection_name, &response);
//
//    if (!grpc_status.ok()) {
//        std::cerr << "DropCollection gRPC failed!" << std::endl;
//        return Status(StatusCode::RPCFailed, grpc_status.error_message());
//    }
//    if (response.error_code() != grpc::SUCCESS) {
//        std::cerr << response.reason() << std::endl;
//        return Status(StatusCode::ServerFailed, response.reason());
//    }

    return Status::OK();
}

Status
GrpcClient::CreateIndex(const ::milvus::grpc::IndexParam& index_param) {
//    ClientContext context;
//    grpc::Status response;
//    ::grpc::Status grpc_status = stub_->CreateIndex(&context, index_param, &response);
//
//    if (!grpc_status.ok()) {
//        std::cerr << "CreateIndex rpc failed!" << std::endl;
//        return Status(StatusCode::RPCFailed, grpc_status.error_message());
//    }
//    if (response.error_code() != grpc::SUCCESS) {
//        std::cerr << response.reason() << std::endl;
//        return Status(StatusCode::ServerFailed, response.reason());
//    }

    return Status::OK();
}

Status
GrpcClient::Insert(const ::milvus::grpc::InsertParam& insert_param, ::milvus::grpc::EntityIds& entitiy_ids) {
    ClientContext context;
    ::grpc::Status grpc_status = stub_->Insert(&context, insert_param, &entitiy_ids);

    if (!grpc_status.ok()) {
        std::cerr << "Insert rpc failed!" << std::endl;
        return Status(StatusCode::RPCFailed, grpc_status.error_message());
    }
    if (entitiy_ids.status().error_code() != grpc::SUCCESS) {
//        std::cerr << entitiy_ids.status().reason() << std::endl;
        return Status(StatusCode::ServerFailed, entitiy_ids.status().reason());
    }

    return Status::OK();
}

Status
GrpcClient::GetEntityByID(const grpc::EntityIdentity& entity_identity, ::milvus::grpc::Entities& entities) {
    ClientContext context;
    ::grpc::Status grpc_status = stub_->GetEntityByID(&context, entity_identity, &entities);

    if (!grpc_status.ok()) {
        std::cerr << "GetEntityByID rpc failed!" << std::endl;
        return Status(StatusCode::RPCFailed, grpc_status.error_message());
    }
    if (entities.status().error_code() != grpc::SUCCESS) {
        std::cerr << entities.status().reason() << std::endl;
        return Status(StatusCode::ServerFailed, entities.status().reason());
    }

    return Status::OK();
}

Status
GrpcClient::ListIDInSegment(const grpc::GetEntityIDsParam& param, grpc::EntityIds& entity_ids) {
//    ClientContext context;
//    ::grpc::Status grpc_status = stub_->GetEntityIDs(&context, param, &entity_ids);
//
//    if (!grpc_status.ok()) {
//        std::cerr << "GetIDsInSegment rpc failed!" << std::endl;
//        return Status(StatusCode::RPCFailed, grpc_status.error_message());
//    }
//    if (entity_ids.status().error_code() != grpc::SUCCESS) {
//        std::cerr << entity_ids.status().reason() << std::endl;
//        return Status(StatusCode::ServerFailed, entity_ids.status().reason());
//    }

    return Status::OK();
}

Status
GrpcClient::Search(const ::milvus::grpc::SearchParam& search_param,
                   ::milvus::grpc::QueryResult& topk_query_result) {
    ClientContext context;
    ::grpc::Status grpc_status = stub_->Search(&context, search_param, &topk_query_result);

    if (!grpc_status.ok()) {
        std::cerr << "Search rpc failed!" << std::endl;
        std::cerr << grpc_status.error_message() << std::endl;
        return Status(StatusCode::RPCFailed, grpc_status.error_message());
    }
    if (topk_query_result.status().error_code() != grpc::SUCCESS) {
        std::cerr << topk_query_result.status().reason() << std::endl;
        return Status(StatusCode::ServerFailed, topk_query_result.status().reason());
    }

    return Status::OK();
}

Status
GrpcClient::GetCollectionInfo(const std::string& collection_name, ::milvus::grpc::Mapping& grpc_schema) {
    ClientContext context;
    ::milvus::grpc::CollectionName grpc_collectionname;
    grpc_collectionname.set_collection_name(collection_name);
    ::grpc::Status grpc_status = stub_->DescribeCollection(&context, grpc_collectionname, &grpc_schema);

    if (!grpc_status.ok()) {
        std::cerr << "DescribeCollection rpc failed!" << std::endl;
        std::cerr << grpc_status.error_message() << std::endl;
        return Status(StatusCode::RPCFailed, grpc_status.error_message());
    }

    if (grpc_schema.status().error_code() != grpc::SUCCESS) {
        std::cerr << grpc_schema.status().reason() << std::endl;
        return Status(StatusCode::ServerFailed, grpc_schema.status().reason());
    }

    return Status::OK();
}

int64_t
GrpcClient::CountEntities(grpc::CollectionName& collection_name, Status& status) {
//    ClientContext context;
    ::milvus::grpc::CollectionRowCount response;
//    ::grpc::Status grpc_status = stub_->CountCollection(&context, collection_name, &response);
//
//    if (!grpc_status.ok()) {
//        std::cerr << "CountCollection rpc failed!" << std::endl;
//        status = Status(StatusCode::RPCFailed, grpc_status.error_message());
//        return -1;
//    }
//
//    if (response.status().error_code() != grpc::SUCCESS) {
//        std::cerr << response.status().reason() << std::endl;
//        status = Status(StatusCode::ServerFailed, response.status().reason());
//        return -1;
//    }
//
    status = Status::OK();
//    return response.collection_row_count();
    return 100;
}

Status
GrpcClient::ListCollections(milvus::grpc::CollectionNameList& collection_name_list) {
//    ClientContext context;
//    ::milvus::grpc::Command command;
//    ::grpc::Status grpc_status = stub_->ShowCollections(&context, command, &collection_name_list);
//
//    if (!grpc_status.ok()) {
//        std::cerr << "ShowCollections gRPC failed!" << std::endl;
//        std::cerr << grpc_status.error_message() << std::endl;
//        return Status(StatusCode::RPCFailed, grpc_status.error_message());
//    }
//
//    if (collection_name_list.status().error_code() != grpc::SUCCESS) {
//        std::cerr << collection_name_list.status().reason() << std::endl;
//        return Status(StatusCode::ServerFailed, collection_name_list.status().reason());
//    }

    return Status::OK();
}

Status
GrpcClient::GetCollectionStats(grpc::CollectionName& collection_name, grpc::CollectionInfo& collection_stats) {
//    ClientContext context;
//    ::milvus::grpc::Command command;
//    ::grpc::Status grpc_status = stub_->ShowCollectionInfo(&context, collection_name, &collection_stats);
//
//    if (!grpc_status.ok()) {
//        std::cerr << "ShowCollectionInfo gRPC failed!" << std::endl;
//        std::cerr << grpc_status.error_message() << std::endl;
//        return Status(StatusCode::RPCFailed, grpc_status.error_message());
//    }
//
//    if (collection_stats.status().error_code() != grpc::SUCCESS) {
//        std::cerr << collection_stats.status().reason() << std::endl;
//        return Status(StatusCode::ServerFailed, collection_stats.status().reason());
//    }

    return Status::OK();
}

Status
GrpcClient::Cmd(const std::string& cmd, std::string& result) {
//    ClientContext context;
//    ::milvus::grpc::StringReply response;
//    ::milvus::grpc::Command command;
//    command.set_cmd(cmd);
//    ::grpc::Status grpc_status = stub_->Cmd(&context, command, &response);
//
//    result = response.string_reply();
//    if (!grpc_status.ok()) {
//        std::cerr << "Cmd gRPC failed!" << std::endl;
//        return Status(StatusCode::RPCFailed, grpc_status.error_message());
//    }
//
//    if (response.status().error_code() != grpc::SUCCESS) {
//        std::cerr << response.status().reason() << std::endl;
//        return Status(StatusCode::ServerFailed, response.status().reason());
//    }

    return Status::OK();
}

Status
GrpcClient::LoadCollection(milvus::grpc::CollectionName& collection_name) {
//    ClientContext context;
//    ::milvus::grpc::Status response;
//    ::grpc::Status grpc_status = stub_->PreloadCollection(&context, collection_name, &response);
//
//    if (!grpc_status.ok()) {
//        std::cerr << "PreloadCollection gRPC failed!" << std::endl;
//        return Status(StatusCode::RPCFailed, grpc_status.error_message());
//    }
//
//    if (response.error_code() != grpc::SUCCESS) {
//        std::cerr << response.reason() << std::endl;
//        return Status(StatusCode::ServerFailed, response.reason());
//    }
    return Status::OK();
}

Status
GrpcClient::DeleteEntityByID(grpc::DeleteByIDParam& delete_by_id_param) {
    ClientContext context;
    ::milvus::grpc::Status response;
    ::grpc::Status grpc_status = stub_->DeleteByID(&context, delete_by_id_param, &response);

    if (!grpc_status.ok()) {
        std::cerr << "DeleteByID gRPC failed!" << std::endl;
        return Status(StatusCode::RPCFailed, grpc_status.error_message());
    }

    if (response.error_code() != grpc::SUCCESS) {
        std::cerr << response.reason() << std::endl;
        return Status(StatusCode::ServerFailed, response.reason());
    }
    return Status::OK();
}

Status
GrpcClient::GetIndexInfo(grpc::CollectionName& collection_name, grpc::IndexParam& index_param) {
//    ClientContext context;
//    ::grpc::Status grpc_status = stub_->DescribeIndex(&context, collection_name, &index_param);
//
//    if (!grpc_status.ok()) {
//        std::cerr << "DescribeIndex rpc failed!" << std::endl;
//        return Status(StatusCode::RPCFailed, grpc_status.error_message());
//    }
//    if (index_param.status().error_code() != grpc::SUCCESS) {
//        std::cerr << index_param.status().reason() << std::endl;
//        return Status(StatusCode::ServerFailed, index_param.status().reason());
//    }

    return Status::OK();
}

Status
GrpcClient::DropIndex(grpc::IndexParam& index_param) {
//    ClientContext context;
//    ::milvus::grpc::Status response;
//    ::grpc::Status grpc_status = stub_->DropIndex(&context, index_param, &response);
//
//    if (!grpc_status.ok()) {
//        std::cerr << "DropIndex gRPC failed!" << std::endl;
//        return Status(StatusCode::RPCFailed, grpc_status.error_message());
//    }
//
//    if (response.error_code() != grpc::SUCCESS) {
//        std::cerr << response.reason() << std::endl;
//        return Status(StatusCode::ServerFailed, response.reason());
//    }
    return Status::OK();
}

Status
GrpcClient::CreatePartition(const grpc::PartitionParam& partition_param) {
//    ClientContext context;
//    ::milvus::grpc::Status response;
//    ::grpc::Status grpc_status = stub_->CreatePartition(&context, partition_param, &response);
//
//    if (!grpc_status.ok()) {
//        std::cerr << "CreatePartition gRPC failed!" << std::endl;
//        return Status(StatusCode::RPCFailed, grpc_status.error_message());
//    }
//
//    if (response.error_code() != grpc::SUCCESS) {
//        std::cerr << response.reason() << std::endl;
//        return Status(StatusCode::ServerFailed, response.reason());
//    }
    return Status::OK();
}

bool
GrpcClient::HasPartition(const grpc::PartitionParam& partition_param, Status& status) const {
    ClientContext context;
    ::milvus::grpc::BoolReply response;
//    ::grpc::Status grpc_status = stub_->HasPartition(&context, partition_param, &response);
//
//    if (!grpc_status.ok()) {
//        std::cerr << "HasPartition gRPC failed!" << std::endl;
//        status = Status(StatusCode::RPCFailed, grpc_status.error_message());
//    }
//    if (response.status().error_code() != grpc::SUCCESS) {
//        std::cerr << response.status().reason() << std::endl;
//        status = Status(StatusCode::ServerFailed, response.status().reason());
//    }
//    status = Status::OK();
    return response.bool_reply();
}

Status
GrpcClient::ListPartitions(const grpc::CollectionName& collection_name, grpc::PartitionList& partition_array) const {
//    ClientContext context;
//    ::grpc::Status grpc_status = stub_->ShowPartitions(&context, collection_name, &partition_array);
//
//    if (!grpc_status.ok()) {
//        std::cerr << "ShowPartitions gRPC failed!" << std::endl;
//        return Status(StatusCode::RPCFailed, grpc_status.error_message());
//    }
//
//    if (partition_array.status().error_code() != grpc::SUCCESS) {
//        std::cerr << partition_array.status().reason() << std::endl;
//        return Status(StatusCode::ServerFailed, partition_array.status().reason());
//    }
    return Status::OK();
}

Status
GrpcClient::DropPartition(const ::milvus::grpc::PartitionParam& partition_param) {
//    ClientContext context;
//    ::milvus::grpc::Status response;
//    ::grpc::Status grpc_status = stub_->DropPartition(&context, partition_param, &response);
//
//    if (!grpc_status.ok()) {
//        std::cerr << "DropPartition gRPC failed!" << std::endl;
//        return Status(StatusCode::RPCFailed, grpc_status.error_message());
//    }
//
//    if (response.error_code() != grpc::SUCCESS) {
//        std::cerr << response.reason() << std::endl;
//        return Status(StatusCode::ServerFailed, response.reason());
//    }
    return Status::OK();
}

Status
GrpcClient::Flush(const std::string& collection_name) {
//    ClientContext context;
//
//    ::milvus::grpc::FlushParam param;
//    if (!collection_name.empty()) {
//        param.add_collection_name_array(collection_name);
//    }
//
//    ::milvus::grpc::Status response;
//    ::grpc::Status grpc_status = stub_->Flush(&context, param, &response);
//
//    if (!grpc_status.ok()) {
//        std::cerr << "Flush gRPC failed!" << std::endl;
//        return Status(StatusCode::RPCFailed, grpc_status.error_message());
//    }
//
//    if (response.error_code() != grpc::SUCCESS) {
//        std::cerr << response.reason() << std::endl;
//        return Status(StatusCode::ServerFailed, response.reason());
//    }
    return Status::OK();
}

Status
GrpcClient::Compact(milvus::grpc::CollectionName& collection_name) {
//    ClientContext context;
//    ::milvus::grpc::Status response;
//    ::grpc::Status grpc_status = stub_->Compact(&context, collection_name, &response);
//
//    if (!grpc_status.ok()) {
//        std::cerr << "Compact gRPC failed!" << std::endl;
//        return Status(StatusCode::RPCFailed, grpc_status.error_message());
//    }
//
//    if (response.error_code() != grpc::SUCCESS) {
//        std::cerr << response.reason() << std::endl;
//        return Status(StatusCode::ServerFailed, response.reason());
//    }
    return Status::OK();
}

Status
GrpcClient::Disconnect() {
    stub_.release();
    return Status::OK();
}

Status
GrpcClient::SearchPB(milvus::grpc::SearchParamPB& search_param, milvus::grpc::QueryResult& result) {
//    ClientContext context;
//    ::grpc::Status grpc_status = stub_->SearchPB(&context, search_param, &result);
//
//    if (!grpc_status.ok()) {
//        std::cerr << "HybridSearchPB gRPC failed!" << std::endl;
//        return Status(StatusCode::RPCFailed, grpc_status.error_message());
//    }
//
//    if (result.status().error_code() != grpc::SUCCESS) {
//        std::cerr << result.status().reason() << std::endl;
//        return Status(StatusCode::ServerFailed, result.status().reason());
//    }
    return Status::OK();
}

}  // namespace milvus
