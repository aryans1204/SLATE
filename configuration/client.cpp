#include "instance.h"
#include "client.h"
#include <iostream>
#include <vector>
#include "functions.h"
#include ".../execution/scheduler.cpp"
#include <cmath>

void Client::createManifest() {
    for (int i = 0; i < this->N; i++) {
        std::cout << "Enter function complexity class for manifest" << std::endl;
        char* func;
        std::cin >> func;
        double obj;
        std::cout << "Enter performance objective for function" << std::endl;
        std::cin >> obj;
        int max_domain, min_domain;
        std::cout << "Enter max and min domain for function" << std::endl;
        std::cin >> max_domain >> min_domain;
        FunctionDef* f = new FunctionDef(func, max_domain, min_domain, obj);
        this->manifest.push_back(f);
    }
}

Client::Client(int N) {
    this->N = N;
}

void Client::configureEnv() {
    //take all function types in the manifest and generate the minimum instance group. Each function must have one instance type
    //associated with it.
    FunctionDef* f;
    Instance* i = new Instance(1, CPU, f);
    for (auto it = this->manifest.begin(); it != this->manifest.end(); ++it) {
        f = (*it);
        i->f = f;
        double min_val = 100000;
        for (int N = 1; N <= 4; N++) {
            if (abs(timeSimulator(N, CPU, f->max_domain, f->min_domain, f->type) - f->p_objective) < min_val) {
                i->config = CPU;
                i->N = N;
            }
            if (abs(timeSimulator(N, GPU, f->max_domain, f->min_domain, f->type) - f->p_objective) < min_val) {
                i->config = CPU;
                i->N = N;
            }
            if (abs(timeSimulator(N, FPGA, f->max_domain, f->min_domain, f->type) - f->p_objective) < min_val) {
                i->config = CPU;
                i->N = N;
            }
        }
        f->optimal = i;
        this->candidates.push_back(i);
    }

}
