/***************************************************************
 * Generated by Hottentot CC Generator
 * Date: 26-01-2016 12:58:21
 * Name: transport_service_proxy.h
 * Description:
 *   This file contains definition of the proxy class.
 ***************************************************************/

#ifndef _IR_NTNAEEM_GATE_TRANSPORT__PROXY__TRANSPORT_SERVICE_PROXY_H_
#define _IR_NTNAEEM_GATE_TRANSPORT__PROXY__TRANSPORT_SERVICE_PROXY_H_

#include <stdint.h>
#include <string>

#include <naeem/hottentot/runtime/types/primitives.h>
#include <naeem/hottentot/runtime/proxy/proxy.h>

#include "../transport_service.h"


namespace ir {
namespace ntnaeem {
namespace gate {
namespace transport {
class AcceptReport;
class TransportMessageStatus;
class TransportMessage;
namespace proxy {
  class TransportServiceProxy : public ::ir::ntnaeem::gate::transport::TransportService, 
    public ::naeem::hottentot::runtime::proxy::Proxy {
  public:
    TransportServiceProxy(std::string host, uint32_t port) 
      : ::naeem::hottentot::runtime::proxy::Proxy(host, port) {}
    virtual ~TransportServiceProxy() {}
  public:
    virtual void AcceptSlaveMassages(::naeem::hottentot::runtime::types::List< ::ir::ntnaeem::gate::transport::TransportMessage> &messages, ::naeem::hottentot::runtime::types::List< ::ir::ntnaeem::gate::transport::AcceptReport> &);
    virtual void RetrieveSlaveMessages(::naeem::hottentot::runtime::types::UInt32 &slaveId, ::naeem::hottentot::runtime::types::List< ::ir::ntnaeem::gate::transport::TransportMessage> &);
    virtual void Ack(::naeem::hottentot::runtime::types::List< ::naeem::hottentot::runtime::types::UInt64> &masterMIds);
    virtual void GetStatus(::naeem::hottentot::runtime::types::UInt64 &masterMId, ::ir::ntnaeem::gate::transport::TransportMessageStatus &);
  };
} // END OF NAMESPACE proxy
} // END OF NAMESPACE transport
} // END OF NAMESPACE gate
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir

#endif