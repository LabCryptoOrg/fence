/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 22-01-2016 03:59:56
 * Name: transport_service_impl.h
 * Description:
 *   This file contains definitions of sample stub.
 ******************************************************************/
 
#ifndef _IR_NTNAEEM_GATE_TRANSPORT__TRANSPORT_SERVICE_IMPL_H_
#define _IR_NTNAEEM_GATE_TRANSPORT__TRANSPORT_SERVICE_IMPL_H_

#include <stdint.h>
#include <string>

#include "../service/abstract_transport_service.h"


namespace ir {
namespace ntnaeem {
namespace gate {
namespace transport {
  class TransportServiceImpl : public ::ir::ntnaeem::gate::transport::service::AbstractTransportService {
  public:
    TransportServiceImpl() {}
    virtual ~TransportServiceImpl() {}
  public:
    virtual void OnInit();
    virtual void OnShutdown();
    virtual void Send(::ir::ntnaeem::gate::transport::TransportMessage &message, ::naeem::hottentot::runtime::types::UInt32 &out);
    virtual void Receive(::naeem::hottentot::runtime::types::UInt32 &slaveId, ::ir::ntnaeem::gate::transport::TransportMessage &out);
    virtual void GetStatus(::naeem::hottentot::runtime::types::UInt32 &id, ::ir::ntnaeem::gate::transport::TransportStatus &out);
  };
} // END OF NAMESPACE transport
} // END OF NAMESPACE gate
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir

#endif