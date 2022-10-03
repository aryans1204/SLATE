#include "configuration/functions.h"
#include "configuration/client.h"
#include "configuration/instance.h"
#include <vector>
#include "scheduler.h"

//defining client request

class Gateway {
    public:
        Scheduler* scheduler;
        Client* client;

        Gateway(Scheduler* scheduler, Client* client);  //gateway is initialized with the scheduler having the configured environment and minimum instance group .

        void acceptRequest(FunctionDef* request);  //accepts request from the client

}