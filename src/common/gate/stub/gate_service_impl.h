/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 22-01-2016 12:53:50
 * Name: gate_service_impl.h
 * Description:
 *   This file contains definitions of sample stub.
 ******************************************************************/
 
#ifndef _IR_NTNAEEM_GATE__GATE_SERVICE_IMPL_H_
#define _IR_NTNAEEM_GATE__GATE_SERVICE_IMPL_H_

#include <stdint.h>
#include <string>

#include "../service/abstract_gate_service.h"


namespace ir {
namespace ntnaeem {
namespace gate {
  class GateServiceImpl : public ::ir::ntnaeem::gate::service::AbstractGateService {
  public:
    GateServiceImpl() {}
    virtual ~GateServiceImpl() {}
  public:
    virtual void OnInit();
    virtual void OnShutdown();
    virtual void SendRequest(::ir::ntnaeem::gate::Request &request, ::naeem::hottentot::runtime::types::UInt32 &out);
    virtual void GetRequestStatus(::naeem::hottentot::runtime::types::UInt32 &id, ::naeem::hottentot::runtime::types::UInt32 &out);
    virtual void GetResponses(::naeem::hottentot::runtime::types::Utf8String &label, ::naeem::hottentot::runtime::types::List< ::ir::ntnaeem::gate::Response> &out);
  };
} // END OF NAMESPACE gate
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir

#endif