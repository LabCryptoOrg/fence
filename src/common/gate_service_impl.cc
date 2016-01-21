#include <naeem/hottentot/runtime/configuration.h>
#include <naeem/hottentot/runtime/logger.h>
#include <naeem/hottentot/runtime/utils.h>

#include "gate_service_impl.h"
#include "runtime.h"

#include "gate/message.h"


namespace ir {
namespace ntnaeem {
namespace gate {
  void
  GateServiceImpl::OnInit() {
    Runtime::messageCounter_ = 0;
    Runtime::queue_ = new Queue< ::ir::ntnaeem::gate::Message>;
    ::naeem::hottentot::runtime::Logger::GetOut() << "Gate Service is initialized." << std::endl;
  }
  void
  GateServiceImpl::OnShutdown() {
    // TODO: Called when service is shutting down.
  }
  void
  GateServiceImpl::EnqueueMessage(::ir::ntnaeem::gate::Message &message, ::naeem::hottentot::runtime::types::UInt32 &out) {
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "GateServiceImpl::EnqueueMessage() is called." << std::endl;
    }
    std::lock_guard<std::mutex> guard(Runtime::gateServiceLock_);
    message.SetId(Runtime::messageCounter_++);
    out.SetValue(Runtime::messageCounter_ - 1);
    Runtime::queue_->Put((const char*)message.GetLabel().Serialize(NULL), &message);
  }
  void
  GateServiceImpl::GetMessageStatus(::naeem::hottentot::runtime::types::UInt32 &id, ::naeem::hottentot::runtime::types::UInt32 &out) {
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "GateServiceImpl::GetMessageStatus() is called." << std::endl;
    }
    std::lock_guard<std::mutex> guard(Runtime::gateServiceLock_);
    // TODO
  }
  void
  GateServiceImpl::GetMessages(::naeem::hottentot::runtime::types::Utf8String &label, ::naeem::hottentot::runtime::types::List< ::ir::ntnaeem::gate::Message> &out) {
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "GateServiceImpl::GetMessages() is called." << std::endl;
    }
    std::lock_guard<std::mutex> guard(Runtime::gateServiceLock_);
    // TODO
  }
} // END OF NAMESPACE gate
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir