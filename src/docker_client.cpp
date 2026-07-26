#include <string>
#include <sys/socket.h>
#include <stdexcept>
#include <cstring>
#include <cerrno>
#include <iostream>
#include "../include/container_client.h"
#if __APPLE__
#include <Kernel/sys/un.h>
#elif __linux__
#include <sys/un.h>
#endif
#include <unistd.h>

const std::string DOCKER_SOCKET_PATH = "/Users/I753116/.colima/default/docker.sock";

class DockerClient : public ContainerClient
{
public:
    void createContainer() override
    {
        // Implementation for creating a Docker container
        int sock = connectToDocker();
    }

    void attachContainer() override
    {
        // Implementation for attaching to a Docker container
    }

private:
    int connectToDocker()
    {
        int sock = socket(AF_UNIX, SOCK_STREAM, 0);

        if (sock == -1)
        {
            throw std::runtime_error("Failed to create socket: " + std::string(strerror(errno)));
        }

        sockaddr_un addr{};
        addr.sun_family = AF_UNIX;
        strncpy(addr.sun_path, DOCKER_SOCKET_PATH.c_str(), sizeof(addr.sun_path) - 1);

        if (connect(sock, reinterpret_cast<sockaddr *>(&addr), sizeof(addr)) == -1)
        {
            close(sock);
            throw std::runtime_error("Failed to connect to Docker socket: " + std::string(strerror(errno)));
        }

        std::cout << "Connected to Docker socket at " << DOCKER_SOCKET_PATH << std::endl;
        return sock;
    }
};