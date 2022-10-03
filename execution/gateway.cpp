#include "configuration/functions.h"
#include "configuration/instance.h"
#include "gateway.h"
#include "scheduler.h"
#include "client.h"


Gateway::Gateway(Scheduler* scheduler, Client* client) {
    this.scheduler = scheduler;
    this.client = client;
}



