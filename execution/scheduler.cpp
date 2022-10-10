#include "scheduler.h"
#include "gateway.h"
#include <vector>
#include "../configuration/functions.h"
#include <vector>
#include <algorithm>
#include "../configuration/instance.h"

Scheduler::Scheduler(std::vector<Instance*>& candidates) {
    for (auto it = candidates.begin(); it != v.end(); ++it) {
        if ((*it)->state == busy) this->busy_candidates.push_back(*it);
        else this->idle_candidates.push_back(*it);
    }
}
Instance* Scheduler::schedule(Request* client_request) {
    //main scheduler algorithm implementation....schedules client requests in real time based on configured environment and candidate instance types.
    if (!this->idle_candidates.size()) { //if idle candidates is empty, then spawn a new instance with required config.
        FunctionDef* f = new FunctionDef(client_request->func_type, 0, 0, 0);
        Instance* i = new Instance(1, GPU, f);  //spawning new instance
        i->state = busy;
        return i;
    }
    auto it = this->idle_candidates.begin();
    while (it != this->idle_candidates.end()) {
        if (client_request->size1 <= (*it)->f->max_domain - (*it)->f->min_domain && client_request->size2 <= (*it)->f->max_domain - (*it)->f->min_domain) {
            (*it)->state = busy;
            (*it)->resetTime();
            Instance* ret = (*it);
            this->busy_candidates.push_back((*it));
            it = this->idle_candidates.erase(it);
            return ret;
        }
        else {
            ++it;
        } 
    }
}
void Scheduler::checkHealth() {
    auto it = this->idle_candidates.begin();
    while (it != this->idle_candidtaes.end()) {
        if ((*it)->checkTime() >= 10000) {
            (*it)->stopInstance();
            it = this->idle_candidates.erase(it);
        }
        else ++it;
    }
}