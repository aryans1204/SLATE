#include "configration/client.h"
#include "configuration/client.cpp"
#include <vector>
#include "gateway.h"
#include "configuration/functions.h"

class Scheduler {
    public:

        Scheduler(std::vector<Instance*>& candidates);

        void schedule(FunctionDef* client_request);
    
    private:
        std::vector<Instance*> busy_candidates;
        std::vector<Instance*> idle_candidates;
        
}