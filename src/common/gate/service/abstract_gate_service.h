/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 27-01-2016 10:52:10
 * Name: gate_service.h
 * Description:
 *   This file contains definition of an abstract service class.
 ******************************************************************/

#ifndef _IR_NTNAEEM_GATE__SERVICE__ABSTRACT_GATE_SERVICE_H_
#define _IR_NTNAEEM_GATE__SERVICE__ABSTRACT_GATE_SERVICE_H_

#include <stdint.h>
#include <string>

#include <naeem/hottentot/runtime/service/service.h>

#include "../message_status.h"
#include "../message.h"
#include "../gate_service.h"
#include "gate_service_request_handler.h"


namespace ir {
namespace ntnaeem {
namespace gate {
namespace service {
  class AbstractGateService : public GateService, public ::naeem::hottentot::runtime::service::Service {
  public:
    inline virtual uint32_t GetServiceId() const {
      return 58024360;
    }
  protected:
    inline virtual ::naeem::hottentot::runtime::service::RequestHandler* MakeRequestHandler() {
      return new GateServiceRequestHandler(this);
    }
  };
} // END OF NAMESPACE service
} // END OF NAMESPACE gate
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir

#endif