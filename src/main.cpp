#define _GNU_SOURCE

#include <iostream>
#include <unistd.h>
#include <sched.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdio>
#include "docker_client.cpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
    string command = argv[1];
    string separator = argv[2];
    string codingAgent = argv[3];

    if (command == "init" && separator == "--")
    {
        DockerClient dockerClient;
        dockerClient.createContainer();
    }
    else
    {
        cout << "Invalid command or separator." << endl;
    }

    return 0;
}