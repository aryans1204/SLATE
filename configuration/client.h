#include <vector>
#include "instance.h"
#include "functions.h"

class Client {
    public:
        std::vector<FunctionDef*> manifest;
        std::vector<Instance*> candidates;

        int N;
        void createManifest());  //method to createManifest by taking input from client through stdin....the input stream can be modified other than stdin.

        Client(int N); //class constructor for Client, takes in input N of the number of functions to be defined.

}