#include <vector>
#include "instance.h"
#include "client.h"
#include "functions.h"
#include <stdlib.h>
//all the instance methods are implemented here. Added the higher level functions, lower level functions to be added once hardware platform is decided.

Instance::Instance(int N, instance_config config, FunctionDef* f) {
    this->config = config;
    this->state = (instance_state) 1;
    this->resetTime();
    //lower level instance spawning code
}

void Instance::stopInstance() {
    this->state = (instance_state) 2;
}

void Instance::resetTime() {
    this->idle_time = 0;
}
time_t Instance::checkTime() {
    this->idle_time++;
    return this->idle-time;
}
 