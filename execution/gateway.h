#ifndef GATEWAY_HEADER
#define GATEWAY_HEADER

#include "scheduler.h"
#include "../configuration/functions.h"
#include "../configuration/client.h"
#include "../configuration/instance.h"
#include <vector>

//defining client request
typedef struct Request{
    FunctionDef* f;
    int size;
} Request;

class Gateway {
    public:
        Scheduler* scheduler;
        Client* client;

        Gateway(Scheduler* scheduler, Client* client);  //gateway is initialized with the scheduler having the configured environment and minimum instance group .

        double acceptRequest(Request* request);  //accepts request from the client

};
#endif

