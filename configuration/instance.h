#include <vector>
#include "functions.h"
enum instance_state = {busy, idle, stopped};
enum instance_config = {GPU, CPU, FPGA};
//defining instance. 
class Instance {

    public:
        instance_state state;  //method to generate graph and update the candidate list of the client based on performance Models.
        instance_config config;

        Instance(int N, instance_config PE, FunctionDef* f); //constructor for spawning a new instance. Implemented based on the lower level API used (AWS SDK, CUDA etc.)

        void stopInstance() //method to delete the given instance and stop it. Implemented based on lower level API used (AWS SDK, CUDA etc.)
}