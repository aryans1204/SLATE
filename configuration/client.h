#include <vector>

typedef struct FunctionDef {
    //describes a function representation in the application manifest
    void *(function)(double);
    double p_objective;
    int min_domain, max_domain;
}

class Client {
    public:
        vector<*FunctionDef> manifest;
        int N;
        void createManifest();  //method to createManifest by taking input from client through stdin....the input stream can be modified other than stdin.

        Client(int N); //class constructor for Client, takes in input N of the number of functions to be defined.

}