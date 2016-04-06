#include <signal.h>
#include <unistd.h>

#include <thread>
#include <chrono>
#include <iostream>

#include <naeem++/os/proc.h>
#include <naeem++/conf/config_manager.h>

#include <naeem/gate/client/runtime.h>
#include <naeem/gate/client/simple_gate_client.h>


bool cont = true;
::naeem::gate::client::GateClient *gateClient = NULL;

void 
SigTermHanlder(int flag) {
  if (gateClient) {
    gateClient->Shutdown();
    // delete gateClient;
  }
  ::naeem::conf::ConfigManager::Clear();
}

int main(int argc, char **argv) {

  struct sigaction sigIntHandler;
  sigIntHandler.sa_handler = SigTermHanlder;
  sigemptyset(&sigIntHandler.sa_mask);
  sigIntHandler.sa_flags = 0;
  sigaction(SIGINT, &sigIntHandler, NULL);
  signal(SIGPIPE, SIG_IGN);

  std::string execDir = ::naeem::os::GetExecDir();
  ::naeem::conf::ConfigManager::LoadFromFile(execDir + "/test2.conf");
  gateClient = new ::naeem::gate::client::SimpleGateClient("hop", "hop-reply");
  gateClient->Init();
  std::vector<::naeem::gate::client::Message*> messages;
  messages = gateClient->GetMessages();
  while (cont) {
    for (uint32_t i = 0; i < messages.size(); i++) {
      std::cout << "Id: '" << messages[i]->GetId() << "'" << std::endl;
      std::cout << "RelId: '" << messages[i]->GetRelId() << "'" << std::endl;
      std::cout << "Label: '" << messages[i]->GetLabel() << "'" << std::endl;
      std::cout << messages[i]->GetContent() << std::endl;
      std::cout << "---------------------" << std::endl;
      delete messages[i];
    }
    messages = gateClient->GetMessages();
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  return 0;
}