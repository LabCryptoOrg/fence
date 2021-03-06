#ifndef _ORG_LABCRYPTO__FENCE__MASTER__RUNTIME_H_
#define _ORG_LABCRYPTO__FENCE__MASTER__RUNTIME_H_

#include <deque>
#include <map>
#include <mutex>

#include <fence/message.h>

#include <transport/transport_message.h>


namespace org {
namespace labcrypto {
namespace fence {
namespace master {
  class Runtime {
  public:
    static void Init();
    static void Shutdown();
    static std::string GetCurrentStat();
  public:
    
    static bool termSignal_;
    static bool masterThreadTerminated_;

    static uint64_t messageIdCounter_;
    static uint64_t arrivedTotalCounter_;
    static uint64_t readyForPopTotalCounter_;
    static uint64_t poppedAndAckedTotalCounter_;
    static uint64_t enqueuedTotalCounter_;
    static uint64_t enqueueFailedTotalCounter_;
    static uint64_t readyForRetrievalTotalCounter_;
    static uint64_t retrievedAndAckedTotalCounter_;

    static std::mutex termSignalLock_;
    static std::mutex messageIdCounterLock_;
    static std::mutex mainLock_;
    static std::mutex readyForPopLock_;
    static std::mutex arrivedLock_;
    static std::mutex enqueueLock_;
    static std::mutex readyForRetrievalLock_;

    static std::map<uint64_t, uint16_t> states_;
    static std::vector<uint64_t> arrived_;
    static std::vector<uint64_t> enqueued_;
    static std::map<std::string, std::map<uint64_t, uint64_t>*> poppedButNotAcked_;
    static std::map<std::string, std::deque<uint64_t>*> readyForPop_;
    static std::map<uint32_t, std::vector<uint64_t>*> readyForRetrieval_;
    static std::map<uint32_t, std::map<uint64_t, uint64_t>*> retrievedButNotAcked_;
  };
} // END NAMESPACE master
} // END NAMESPACE fence
} // END NAMESPACE labcrypto
} // END NAMESPACE org

#endif
