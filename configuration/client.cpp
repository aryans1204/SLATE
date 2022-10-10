#include "instance.h"
#include "client.h"
#include <iostream>
#include <vector>
#include "functions.h"
#include <string>

void Client::createManifest() {
    for (int i = 0; i < this->N; i++) {
        std::cout << "Enter function name for manifest" << std::endl;
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
