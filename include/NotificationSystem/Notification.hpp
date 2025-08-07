#ifndef NOTIFICATION_HPP

#define NOTIFICATION_HPP

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;

namespace NotificationSystem {

    class ANotification {
        virtual int init() = 0;
        virtual int listenOnPort() = 0;
        virtual int closeFd() = 0;
        public:
            virtual int waitForRequest() = 0;
            virtual void sendContent() = 0;
            virtual string get() = 0;
            virtual int closeNew() = 0;

    };
    class Notification : public ANotification {

        int serverFd, newSocket, port;
        struct sockaddr_in address;
        socklen_t addrlen = sizeof(address);
        string content;

        int init();
        int listenOnPort();
        int closeFd();

        public:

            Notification(string content, int port): content(content), port(port) {}
            ~Notification(); 

            int waitForRequest() override;
            void sendContent() override;
            string get() override;
            int closeNew() override;

        };

};

#endif
