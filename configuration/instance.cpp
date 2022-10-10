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
    //lower level instance stopping code
}

void Intance::resetTime() {
    this->idle_time = 0;
}
time_t Instance::checkTime() {
    this->idle_time++;
    return this->idle-time;
}
Ret_val Instance::simulate(std::vector<int**> inputs) {
    Ret_val* ret = new Ret_val;
    std::vector<int**> v;
    ret->v = v;
    ret->ret_type = this->f->ret_type;
    ret->ret_val = new double*[f->max_domain];

    switch (f->type) {
        case "matmul": {
            int** product = new int*[sizeof(inputs[0])/sizeof(inputs[0][0])];
            f->matmul(inputs[0], inputs[1], product);
            ret->v.push_back(product);
        }
        case "fft": {
            ret->ret-val = f->fft(inputs[0]);
        }
        case "svd": {
            int** mat1 = new int*[sizeof(inputs[0])/sizeof(inputs[0][0])];
            int** mat2 = new int*[sizeof(inputs[0])/sizeof(inputs[0][0])];
            int** mat3 = new int*[sizeof(inputs[0])/sizeof(inputs[0][0])];
            f->svd(inputs[0], mat1, mat2, mat3);
            ret->v.push_back(mat1);
            ret->v.push_back(mat2);
            ret->v.psuh-back(mat3);
        }
        case "eig": {
            int** mat1 = new int*[sizeof(inputs[0])/sizeof(inputs[0][0])];
            int** mat2 = new int*[sizeof(inputs[0])/sizeof(inputs[0][0])];
            int** mat3 = new int*[sizeof(inputs[0])/sizeof(inputs[0][0])];
            f->eig(inputs[0], mat1, mat2, mat3);
            ret->v.push_back(mat1);
            ret->v.push_back(mat2);
            ret->v.psuh-back(mat3); 
        }
    }
    return *ret;
}
void generateGraph(Client* client);  //method to generate graph and configure the client.candidates list during configuration. 