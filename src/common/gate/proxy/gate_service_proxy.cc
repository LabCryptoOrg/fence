/***************************************************************
 * Generated by Hottentot CC Generator
 * Date: 22-01-2016 12:53:50
 * Name: gate_service_proxy.cc
 * Description:
 *   This file contains implementation of the proxy class.
 ***************************************************************/

#include <naeem/hottentot/runtime/configuration.h>
#include <naeem/hottentot/runtime/logger.h>
#include <naeem/hottentot/runtime/utils.h>
#include <naeem/hottentot/runtime/request.h>
#include <naeem/hottentot/runtime/response.h>
#include <naeem/hottentot/runtime/protocol_v1.h>
#include <naeem/hottentot/runtime/proxy/tcp_client.h>
#include <naeem/hottentot/runtime/proxy/proxy_runtime.h>
#include <naeem/hottentot/runtime/proxy/tcp_client_factory.h>

#include "gate_service_proxy.h"

#include "../request.h"
#include "../response.h"


namespace ir {
namespace ntnaeem {
namespace gate {
namespace proxy {
  void
  GateServiceProxy::SendRequest(::ir::ntnaeem::gate::Request &request, ::naeem::hottentot::runtime::types::UInt32 &out) {
    /*
     * Make request object
     */
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Making request object ..." << std::endl;
    }
    ::naeem::hottentot::runtime::Request request;
    request.SetServiceId(58024360);
    request.SetMethodId(1018765256);
    request.SetType(::naeem::hottentot::runtime::Request::InvokeStateless);
    /*
     * Serialize arguments
     */
    uint32_t serializedDataLength = 0;
    unsigned char *serializedData = 0;
    /*
     * Serialization of argument 'request'
     */
    serializedDataLength = 0;
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Serializing argument request ..." << std::endl;
    }
    serializedData = request.Serialize(&serializedDataLength);
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "request is serialized." << std::endl;
    }
    request.AddArgument(serializedData, serializedDataLength);

    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Request object is fill with serialized arguments." << std::endl;
    }
    /*
     * Connect to server
     */
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Connecting to server " << host_ << ":" << port_ << " ..." << std::endl;
    }
    ::naeem::hottentot::runtime::proxy::TcpClient *tcpClient = 
        ::naeem::hottentot::runtime::proxy::ProxyRuntime::GetTcpClientFactory()->CreateTcpClient(host_, port_);
    tcpClient->Connect();
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Connected." << std::endl;
    }
    /*
     * Serialize request according to HOTP
     */
    ::naeem::hottentot::runtime::Protocol *protocol = new ::naeem::hottentot::runtime::ProtocolV1(tcpClient->GetRemoteSocketFD()); // TODO(kamran): Use factory.
    uint32_t requestSerializedDataLength = 0;
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Serializing request object ..." << std::endl;
    }
    unsigned char *requestSerializedData = protocol->SerializeRequest(request, &requestSerializedDataLength);
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Request object is serialized." << std::endl;
    }
    /*
     * Send request byte array
     */
    uint32_t sendLength = (requestSerializedDataLength > 127 ? 3 : 1) + requestSerializedDataLength;
    unsigned char *sendData = new unsigned char[sendLength];
    uint32_t c = 0;
    if (requestSerializedDataLength > 127) {
      sendData[c++] = 0x82;
      sendData[c++] = requestSerializedDataLength / 256;
      sendData[c++] = requestSerializedDataLength % 256;
    } else {
      sendData[c++] = requestSerializedDataLength;
    }
    for (uint32_t i = 0; i < requestSerializedDataLength; i++) {
      sendData[c++] = requestSerializedData[i];
    }
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Writing " << sendLength << "    Bytes to socket ..." << std::endl;
      ::naeem::hottentot::runtime::Utils::PrintArray("To Write", sendData, sendLength);
    }
    tcpClient->Write(sendData, sendLength);
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Written." << std::endl;
    }
    delete sendData;
    delete requestSerializedData;
    /*
     * Read response from server
     */
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Waiting for response ..." << std::endl;
    }
    unsigned char buffer[256];
    while (!protocol->IsResponseComplete()) {
      int numOfReadBytes = tcpClient->Read(buffer, 256);
      protocol->ProcessDataForResponse(buffer, numOfReadBytes);
    }
    /*
     * Response deserialization
     */
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Utils::PrintArray("Response", protocol->GetResponse()->GetData(), protocol->GetResponse()->GetDataLength());
    }
    out.Deserialize(protocol->GetResponse()->GetData(), protocol->GetResponse()->GetDataLength());
    /*
     * Finalization
     */
    tcpClient->Close();
    delete serializedData;
    delete protocol;
    delete tcpClient;
  }
  void
  GateServiceProxy::GetRequestStatus(::naeem::hottentot::runtime::types::UInt32 &id, ::naeem::hottentot::runtime::types::UInt32 &out) {
    /*
     * Make request object
     */
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Making request object ..." << std::endl;
    }
    ::naeem::hottentot::runtime::Request request;
    request.SetServiceId(58024360);
    request.SetMethodId(609212704);
    request.SetType(::naeem::hottentot::runtime::Request::InvokeStateless);
    /*
     * Serialize arguments
     */
    uint32_t serializedDataLength = 0;
    unsigned char *serializedData = 0;
    /*
     * Serialization of argument 'id'
     */
    serializedDataLength = 0;
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Serializing argument id ..." << std::endl;
    }
    serializedData = id.Serialize(&serializedDataLength);
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "id is serialized." << std::endl;
    }
    request.AddArgument(serializedData, serializedDataLength);

    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Request object is fill with serialized arguments." << std::endl;
    }
    /*
     * Connect to server
     */
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Connecting to server " << host_ << ":" << port_ << " ..." << std::endl;
    }
    ::naeem::hottentot::runtime::proxy::TcpClient *tcpClient = 
        ::naeem::hottentot::runtime::proxy::ProxyRuntime::GetTcpClientFactory()->CreateTcpClient(host_, port_);
    tcpClient->Connect();
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Connected." << std::endl;
    }
    /*
     * Serialize request according to HOTP
     */
    ::naeem::hottentot::runtime::Protocol *protocol = new ::naeem::hottentot::runtime::ProtocolV1(tcpClient->GetRemoteSocketFD()); // TODO(kamran): Use factory.
    uint32_t requestSerializedDataLength = 0;
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Serializing request object ..." << std::endl;
    }
    unsigned char *requestSerializedData = protocol->SerializeRequest(request, &requestSerializedDataLength);
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Request object is serialized." << std::endl;
    }
    /*
     * Send request byte array
     */
    uint32_t sendLength = (requestSerializedDataLength > 127 ? 3 : 1) + requestSerializedDataLength;
    unsigned char *sendData = new unsigned char[sendLength];
    uint32_t c = 0;
    if (requestSerializedDataLength > 127) {
      sendData[c++] = 0x82;
      sendData[c++] = requestSerializedDataLength / 256;
      sendData[c++] = requestSerializedDataLength % 256;
    } else {
      sendData[c++] = requestSerializedDataLength;
    }
    for (uint32_t i = 0; i < requestSerializedDataLength; i++) {
      sendData[c++] = requestSerializedData[i];
    }
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Writing " << sendLength << "    Bytes to socket ..." << std::endl;
      ::naeem::hottentot::runtime::Utils::PrintArray("To Write", sendData, sendLength);
    }
    tcpClient->Write(sendData, sendLength);
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Written." << std::endl;
    }
    delete sendData;
    delete requestSerializedData;
    /*
     * Read response from server
     */
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Waiting for response ..." << std::endl;
    }
    unsigned char buffer[256];
    while (!protocol->IsResponseComplete()) {
      int numOfReadBytes = tcpClient->Read(buffer, 256);
      protocol->ProcessDataForResponse(buffer, numOfReadBytes);
    }
    /*
     * Response deserialization
     */
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Utils::PrintArray("Response", protocol->GetResponse()->GetData(), protocol->GetResponse()->GetDataLength());
    }
    out.Deserialize(protocol->GetResponse()->GetData(), protocol->GetResponse()->GetDataLength());
    /*
     * Finalization
     */
    tcpClient->Close();
    delete serializedData;
    delete protocol;
    delete tcpClient;
  }
  void
  GateServiceProxy::GetResponses(::naeem::hottentot::runtime::types::Utf8String &label, ::naeem::hottentot::runtime::types::List< ::ir::ntnaeem::gate::Response> &out) {
    /*
     * Make request object
     */
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Making request object ..." << std::endl;
    }
    ::naeem::hottentot::runtime::Request request;
    request.SetServiceId(58024360);
    request.SetMethodId(504981346);
    request.SetType(::naeem::hottentot::runtime::Request::InvokeStateless);
    /*
     * Serialize arguments
     */
    uint32_t serializedDataLength = 0;
    unsigned char *serializedData = 0;
    /*
     * Serialization of argument 'label'
     */
    serializedDataLength = 0;
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Serializing argument label ..." << std::endl;
    }
    serializedData = label.Serialize(&serializedDataLength);
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "label is serialized." << std::endl;
    }
    request.AddArgument(serializedData, serializedDataLength);

    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Request object is fill with serialized arguments." << std::endl;
    }
    /*
     * Connect to server
     */
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Connecting to server " << host_ << ":" << port_ << " ..." << std::endl;
    }
    ::naeem::hottentot::runtime::proxy::TcpClient *tcpClient = 
        ::naeem::hottentot::runtime::proxy::ProxyRuntime::GetTcpClientFactory()->CreateTcpClient(host_, port_);
    tcpClient->Connect();
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Connected." << std::endl;
    }
    /*
     * Serialize request according to HOTP
     */
    ::naeem::hottentot::runtime::Protocol *protocol = new ::naeem::hottentot::runtime::ProtocolV1(tcpClient->GetRemoteSocketFD()); // TODO(kamran): Use factory.
    uint32_t requestSerializedDataLength = 0;
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Serializing request object ..." << std::endl;
    }
    unsigned char *requestSerializedData = protocol->SerializeRequest(request, &requestSerializedDataLength);
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Request object is serialized." << std::endl;
    }
    /*
     * Send request byte array
     */
    uint32_t sendLength = (requestSerializedDataLength > 127 ? 3 : 1) + requestSerializedDataLength;
    unsigned char *sendData = new unsigned char[sendLength];
    uint32_t c = 0;
    if (requestSerializedDataLength > 127) {
      sendData[c++] = 0x82;
      sendData[c++] = requestSerializedDataLength / 256;
      sendData[c++] = requestSerializedDataLength % 256;
    } else {
      sendData[c++] = requestSerializedDataLength;
    }
    for (uint32_t i = 0; i < requestSerializedDataLength; i++) {
      sendData[c++] = requestSerializedData[i];
    }
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Writing " << sendLength << "    Bytes to socket ..." << std::endl;
      ::naeem::hottentot::runtime::Utils::PrintArray("To Write", sendData, sendLength);
    }
    tcpClient->Write(sendData, sendLength);
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Written." << std::endl;
    }
    delete sendData;
    delete requestSerializedData;
    /*
     * Read response from server
     */
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Waiting for response ..." << std::endl;
    }
    unsigned char buffer[256];
    while (!protocol->IsResponseComplete()) {
      int numOfReadBytes = tcpClient->Read(buffer, 256);
      protocol->ProcessDataForResponse(buffer, numOfReadBytes);
    }
    /*
     * Response deserialization
     */
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Utils::PrintArray("Response", protocol->GetResponse()->GetData(), protocol->GetResponse()->GetDataLength());
    }
    out.Deserialize(protocol->GetResponse()->GetData(), protocol->GetResponse()->GetDataLength());
    /*
     * Finalization
     */
    tcpClient->Close();
    delete serializedData;
    delete protocol;
    delete tcpClient;
  }
} // END OF NAMESPACE proxy
}  // END OF NAMESPACE gate
}  // END OF NAMESPACE ntnaeem
}  // END OF NAMESPACE ir