#pragma once

class ContainerClient
{
public:
    virtual ~ContainerClient() = default;
    virtual void createContainer() = 0;
    virtual void attachContainer() = 0;
};