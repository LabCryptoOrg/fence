/***********************************************************************
 * Generated by Hottentot CC Generator
 * Date: 26-01-2016 12:58:21
 * Name: transport_service_request_handler.h
 * Description:
 *   This file contains definition of service's request handler class.
 ***********************************************************************/

#ifndef _IR_NTNAEEM_GATE_TRANSPORT__SERVICE__TRANSPORT_SERVICE_REQUEST_HANDLER_H_
#define _IR_NTNAEEM_GATE_TRANSPORT__SERVICE__TRANSPORT_SERVICE_REQUEST_HANDLER_H_

#include <stdint.h>
#include <string>

#include <naeem/hottentot/runtime/service/request_handler.h>


namespace ir {
namespace ntnaeem {
namespace gate {
namespace transport {
namespace service {
  class TransportServiceRequestHandler : public ::naeem::hottentot::runtime::service::RequestHandler {
  public:
    TransportServiceRequestHandler(::naeem::hottentot::runtime::service::Service *service)
      : ::naeem::hottentot::runtime::service::RequestHandler(service) {
    }
    virtual ~TransportServiceRequestHandler() {}
  public:
    virtual void HandleRequest(::naeem::hottentot::runtime::Request &   /* Request object */, ::naeem::hottentot::runtime::Response &  /* Response object */);
  };
} // END OF NAMESPACE service
} // END OF NAMESPACE transport
} // END OF NAMESPACE gate
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir

#endif