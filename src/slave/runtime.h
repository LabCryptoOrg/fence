#ifndef _IR_NTNAEEM_GATE__RUNTIME_H_
#define _IR_NTNAEEM_GATE__RUNTIME_H_

#include <mutex>

#include "../common/gate/message.h"
#include "../common/transport/transport_message.h"

#include "label_queue_map.h"
#include "bag.h"


namespace ir {
namespace ntnaeem {
namespace gate {
namespace slave {
  class Runtime {
  public:
    static void Init();
    static void PrintStatus();
  public:
    static uint64_t messageCounter_;
    static std::mutex counterLock_;
    static std::mutex mainLock_;
    static std::mutex inboxQueueLock_;
    static std::mutex outboxQueueLock_;
    static LabelQueueMap< ::ir::ntnaeem::gate::Message> *inboxQueue_;
    static Bag< ::ir::ntnaeem::gate::Message> *outboxQueue_;
    static Bag< ::ir::ntnaeem::gate::transport::TransportMessage> *sentQueue_;
    static Bag< ::ir::ntnaeem::gate::transport::TransportMessage> *failedQueue_;
  };
}
}
}
}

#endif