#include "../configuration/functions.h"
#include "../configuration/instance.h"
#include "gateway.h"
#include "scheduler.h"
#include "../configuration/client.h"
#include <random>
#include <cmath>
const double CPU_TIME = 5.0;
const double GPU_TIME = 2.5;

Gateway::Gateway(Scheduler* scheduler, Client* client) {
    this->scheduler = scheduler;
    this->client = client;
}

double timeSimulator(Instance* instance, Request* request) {
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(2.0, 3.0);

    double w = distribution(generator);

    std::default_random_engine generator2;
    std::normal_distribution<double> distro(0.0, 1.0);

    double z = distro(generator2);

    double ret_time = (((1-log(request->size1/instance->f->min_domain))*CPU_TIME + log(request->size1/instance->f->min_domain)*GPU_TIME)*pow(request->size1, w) + z)/instance->N;
    return ret_time;
}

double Gateway::acceptRequest(Request* client_request) {
    Instance* i = this->scheduler->schedule(client_request);
    return timeSimulator(i, client_request);
}


