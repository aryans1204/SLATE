#ifndef SCHEDULER_HEADER
#define SCHEDULER_HEADER

#include "gateway.h"
#include "../configuration/client.h"
#include <vector>
#include "../configuration/functions.h"
#include "../configuration/instance.h"

class Scheduler {
    public:

        Scheduler(std::vector<Instance*>& candidates, Client* client);
        Client* client;
        void checkHealth(); //periodically checks idle time of idle instances. If idle time of any instance is greater than 10s, instance is removed from the group.
        Instance* schedule(Request* client_request);
    
    private:
        std::vector<Instance*> busy_candidates;
        std::vector<Instance*> idle_candidates;
        
};
#endif