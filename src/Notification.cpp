#include <iostream>
#include "include/NotificationSystem/Notification.hpp"

using namespace std;
using namespace NotificationSystem;

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
int Notification::listen() {

}
int Notification::waitForRequest() {

}
int Notification::send() {

}
string Notification::get() {

}
int Notification::close() {

}
