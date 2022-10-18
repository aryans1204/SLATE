#ifndef INSTANCE_H
#define INSTANCE_H

#include <vector>
#include <stdlib.h>
#include "functions.h"
enum instance_state{busy, idle, stopped};
enum instance_config{GPU, CPU, FPGA};

//representing a function instance.....of type (N, PE, Func, D)
class Instance {

    public:
        instance_state state;  //method to generate graph and update the candidate list of the client based on performance Models.
        instance_config config;
        int N;
        FunctionDef* f;
        Instance(int N, instance_config PE, FunctionDef* f); //constructor for spawning a new instance. Implemented based on the lower level API used (AWS SDK, CUDA etc.)

        void stopInstance(); //method to delete the given instance and stop it. Implemented based on lower level API used (AWS SDK, CUDA etc.)
        void resetTime(); //method to reset idle time of instance upon scheduling
        time_t checkTime(); //method to periodically check if idle_time has passed threshold
        

    private:
        time_t idle_time; //time spent idle by the instance.

};
#endif