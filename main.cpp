#include ".../configuration/instance.cpp"
#include ".../execution/scheduler.cpp"
#include ".../execution/scheduler.h"
#include ".../execution/client.cpp"
#include ".../configuration/client.h"
#include ".../execution.gateway.h"
#include ".../execution/gateway.cpp"
#include ".../execution"
#include <vector>
#include <iostream>
#include <fstream>
#include <ofstream>
#include <cstdlib>

int main()
{
    int N;
    std::cout << "Enter how many functions need to be configured" << std::endl;
    std:: cin >> N;
    Client* client = new Client(N);  //initialize client
    client->createManifest();  //create application manifest for the client
    client->configureEnv();  //configure the env to deteermine candidate types.
    std::cout << "Environment is configured" << std::endl;
    Scheduler* scheduler = new Scheduler(client->candidates, client);
    Gateway* gateway = new Gateway(scheduler, client);
    std::ofstream outdata;
    outdata.open("output.txt");
    std::cout << "Now ready to accept requests" << std::endl;
    for (auto it = client->manifest.begin(); it != client->manifest.end(); ++it) {
        FunctionDef* f = (*it);
        Request* client_request = new Request;
        client_request->f = f;
        std::cout << "Enter size of the input" << std::endl;
        std::cin >> client_request->size;
        outdata << double execution_time = gateway->acceptRequest(client_request) << std::endl;  //write execution time to file
        delete f;
        delete clieet_request;
    }
    outdata.close();
    std::cout <<"Cleaning up environment" << std::endl;
    delete gateway;
    delete client;
    delete scheduler;
    return 0;
}