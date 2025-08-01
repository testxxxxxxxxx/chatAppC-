#ifndef NOTIFICATION_HPP

#define NOTIFICATION_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>

namespace NotificationSystem {

    class ANotification {
        virtual int init() = 0;
        virtual int listen() = 0;
        virtual int closeFd() = 0;
        public:
            virtual int waitForRequest() = 0;
            virtual void send() = 0;
            virtual string get() = 0;
            virtual int closeNew() = 0;

    };
    class Notification : public ANotification {

        int serverFd, newSocket, port;
        struct sockaddr_in address;
        socklen_t addrlen = sizeof(address);
        string content;

        int init();
        int listen();
        int closeFd();

        public:

            Notification(string content, int port): content(content), port(port) {}
            ~Notification() {
                this->closeNew();
                this->closeFd();
            }

            int waitForRequest() override;
            void send() override;
            string get() override;
            int closeNew() override;

        };

};

#endif
