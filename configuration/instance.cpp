#include "instance.h"
#include "client.h"
#include "functions.h"
//all the instance methods are implemented here. Added the higher level functions, lower level functions to be added once hardware platform is decided.

Instance::Instance(int N, instance_config config, FunctionDef* f) {
    this.config = config;
    this.state = idle;
    //lower level instance spawning code
}

void Instance::stopInstance() {
    this.state = stopped;
    //lower level instance stopping code
}

void generateGraph(Client* client);  //method to generate graph and configure the client.candidates list during configuration. 