// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: hello.proto

#include "hello.pb.h"
#include "hello.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace milvus {
namespace grpc {

static const char* HelloService_method_names[] = {
  "/milvus.grpc.HelloService/SayHello",
};

std::unique_ptr< HelloService::Stub> HelloService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< HelloService::Stub> stub(new HelloService::Stub(channel));
  return stub;
}

HelloService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_SayHello_(HelloService_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status HelloService::Stub::SayHello(::grpc::ClientContext* context, const ::milvus::grpc::HelloRequest& request, ::milvus::grpc::HelloReply* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_SayHello_, context, request, response);
}

void HelloService::Stub::experimental_async::SayHello(::grpc::ClientContext* context, const ::milvus::grpc::HelloRequest* request, ::milvus::grpc::HelloReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_SayHello_, context, request, response, std::move(f));
}

void HelloService::Stub::experimental_async::SayHello(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::milvus::grpc::HelloReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_SayHello_, context, request, response, std::move(f));
}

void HelloService::Stub::experimental_async::SayHello(::grpc::ClientContext* context, const ::milvus::grpc::HelloRequest* request, ::milvus::grpc::HelloReply* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_SayHello_, context, request, response, reactor);
}

void HelloService::Stub::experimental_async::SayHello(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::milvus::grpc::HelloReply* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_SayHello_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::milvus::grpc::HelloReply>* HelloService::Stub::AsyncSayHelloRaw(::grpc::ClientContext* context, const ::milvus::grpc::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::milvus::grpc::HelloReply>::Create(channel_.get(), cq, rpcmethod_SayHello_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::milvus::grpc::HelloReply>* HelloService::Stub::PrepareAsyncSayHelloRaw(::grpc::ClientContext* context, const ::milvus::grpc::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::milvus::grpc::HelloReply>::Create(channel_.get(), cq, rpcmethod_SayHello_, context, request, false);
}

HelloService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      HelloService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< HelloService::Service, ::milvus::grpc::HelloRequest, ::milvus::grpc::HelloReply>(
          std::mem_fn(&HelloService::Service::SayHello), this)));
}

HelloService::Service::~Service() {
}

::grpc::Status HelloService::Service::SayHello(::grpc::ServerContext* context, const ::milvus::grpc::HelloRequest* request, ::milvus::grpc::HelloReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace milvus
}  // namespace grpc

