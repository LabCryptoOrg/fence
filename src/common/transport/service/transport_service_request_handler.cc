/****************************************************************************
 * Generated by Hottentot CC Generator
 * Date: 23-01-2016 11:53:09
 * Name: transport_service_request_handler.cc
 * Description:
 *   This file contains implementation of service's request handler class.
 ****************************************************************************/
 
#include <string.h>

#include <naeem/hottentot/runtime/request.h>
#include <naeem/hottentot/runtime/response.h>

#include "transport_service_request_handler.h"
#include "abstract_transport_service.h"
#include "../transport_service.h"
#include "../transport_status.h"
#include "../transport_message.h"


namespace ir {
namespace ntnaeem {
namespace gate {
namespace transport {
namespace service {
  void 
  TransportServiceRequestHandler::HandleRequest(::naeem::hottentot::runtime::Request &request, ::naeem::hottentot::runtime::Response &response) {
    if (request.GetMethodId() == 2943362819) {
      ::ir::ntnaeem::gate::transport::service::AbstractTransportService *serviceObject = 
        dynamic_cast< ::ir::ntnaeem::gate::transport::service::AbstractTransportService*>(service_);
      /*
       * Deserialization and making input variables
       */
      ::ir::ntnaeem::gate::transport::TransportMessage message;
      message.Deserialize(request.GetArgumentData(0), request.GetArgumentLength(0));
      /*
       * Calling service method
       */
      ::naeem::hottentot::runtime::types::UInt32 result;
      serviceObject->Send(message, result);
      /*
       * Serializiation of returned object
       */
      uint32_t serializedDataLength = 0;
      unsigned char *serializedData = result.Serialize(&serializedDataLength);

      response.SetStatusCode(0);
      response.SetData(serializedData);
      response.SetDataLength(serializedDataLength);
      return;
    }
    if (request.GetMethodId() == 3457238775) {
      ::ir::ntnaeem::gate::transport::service::AbstractTransportService *serviceObject = 
        dynamic_cast< ::ir::ntnaeem::gate::transport::service::AbstractTransportService*>(service_);
      /*
       * Deserialization and making input variables
       */
      ::naeem::hottentot::runtime::types::UInt32 slaveId;
      slaveId.Deserialize(request.GetArgumentData(0), request.GetArgumentLength(0));
      /*
       * Calling service method
       */
      ::naeem::hottentot::runtime::types::Boolean result;
      serviceObject->AnyMessagesLeft(slaveId, result);
      /*
       * Serializiation of returned object
       */
      uint32_t serializedDataLength = 0;
      unsigned char *serializedData = result.Serialize(&serializedDataLength);

      response.SetStatusCode(0);
      response.SetData(serializedData);
      response.SetDataLength(serializedDataLength);
      return;
    }
    if (request.GetMethodId() == 3646239416) {
      ::ir::ntnaeem::gate::transport::service::AbstractTransportService *serviceObject = 
        dynamic_cast< ::ir::ntnaeem::gate::transport::service::AbstractTransportService*>(service_);
      /*
       * Deserialization and making input variables
       */
      ::naeem::hottentot::runtime::types::UInt32 slaveId;
      slaveId.Deserialize(request.GetArgumentData(0), request.GetArgumentLength(0));
      /*
       * Calling service method
       */
      ::ir::ntnaeem::gate::transport::TransportMessage result;
      serviceObject->Receive(slaveId, result);
      /*
       * Serializiation of returned object
       */
      uint32_t serializedDataLength = 0;
      unsigned char *serializedData = result.Serialize(&serializedDataLength);

      response.SetStatusCode(0);
      response.SetData(serializedData);
      response.SetDataLength(serializedDataLength);
      return;
    }
    if (request.GetMethodId() == 2030923975) {
      ::ir::ntnaeem::gate::transport::service::AbstractTransportService *serviceObject = 
        dynamic_cast< ::ir::ntnaeem::gate::transport::service::AbstractTransportService*>(service_);
      /*
       * Deserialization and making input variables
       */
      ::naeem::hottentot::runtime::types::UInt32 id;
      id.Deserialize(request.GetArgumentData(0), request.GetArgumentLength(0));
      /*
       * Calling service method
       */
      ::ir::ntnaeem::gate::transport::TransportStatus result;
      serviceObject->GetStatus(id, result);
      /*
       * Serializiation of returned object
       */
      uint32_t serializedDataLength = 0;
      unsigned char *serializedData = result.Serialize(&serializedDataLength);

      response.SetStatusCode(0);
      response.SetData(serializedData);
      response.SetDataLength(serializedDataLength);
      return;
    }
    char errorMessage[] = "Method not found.";
    response.SetStatusCode(1);
    response.SetData((unsigned char*)errorMessage);
    response.SetDataLength(strlen(errorMessage));
  }
} // END OF NAMESPACE service
} // END OF NAMESPACE transport
} // END OF NAMESPACE gate
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir