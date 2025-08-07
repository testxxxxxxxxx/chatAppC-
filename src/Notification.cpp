#include <iostream>
#include "../include/NotificationSystem/Notification.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;
using namespace NotificationSystem;

Notification::~Notification() {
    this->closeNew();
    this->closeFd();
}
int Notification::init() {
    //creating, setup and init notification

    if(this->serverFd = socket(AF_INET, SOCK_STREAM, 0) < 0)
        return -1; //return -1 when socket cannot be created

    int opt = 1;

    if(setsockopt(this->serverFd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
        return -1;

    this->address.sin_family = AF_INET;
    this->address.sin_addr.s_addr = INADDR_ANY;
    this->address.sin_port = htons(this->port);

    if(bind(this->serverFd, (struct sockaddr *)& address, sizeof(address)) < 0)
        return -1;

    return 1;
}
int Notification::listenOnPort() {
    //start listening at port X
    if(listen(this->serverFd, 3) < 0)
        return -1;
    return 1;
}
int Notification::waitForRequest() {
    //wait for notification
    if(this->newSocket = accept(this->serverFd, (struct sockaddr* )& address, &this->addrlen) < 0)
        return -1;
    return 1;
}
void Notification::sendContent() {
    send(this->newSocket, this->content.c_str(), this->content.length(), 0);
}
string Notification::get() {
    //get notification about new message
    string response;
    ssize_t readv = read(this->newSocket, &response, 1024 - 1);

    return response;
}
int Notification::closeNew() {
    return close(this->newSocket);
}
int Notification::closeFd() {
    return close(this->serverFd);
}
