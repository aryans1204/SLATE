#include "scheduler.h"
#include "gateway.h"
#include <vector>
#include "configuration/functions.h"

Scheduler::Scheduler(std::vector<Instance*>& candidates) {
    for (auto it = candidates.begin(); it != v.end(); ++it) {
        if ((*it)->state == busy) this.busy_candidates.push_back(*it);
        else this.idle_candidates.push_back(*it);
    }
}
void Scheduler::schedule(FunctionDef* client_request) {
    //main scheduler algorithm implementation....schedules client requests in real time based on configured environment and candidate instance types.

}