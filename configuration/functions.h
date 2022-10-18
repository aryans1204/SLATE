#include ".../configuration/instance.h"
#ifndef FUNCTION_HEADER
#define FUNCTION_HEADER
//current functions supported matmul, matrix_norm, dot, fft, svd, eig. List can be extended further
//represents a function in the application manifest, submitted by client during configuration-
class FunctionDef {
    public:
        char* type; //type is complexity class of function, from linear, quadratic, logarithmic, and linearithmic. 
        int max_domain, min_domain;
        double p_objective;
        Instance* optimal;
        FunctionDef(char* type, int min_domain, int max_domain, double p_objective); //constructor

};
#endif