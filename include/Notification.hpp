#ifndef CONNECT_HPP

#define CONNECT_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

namespace NotificationSystem {

    class Notification {

        int port;

        int init();
        int listen();
        int close();

        public:

            Notification(int port): port(port) {

            }
            ~Notification() {
                this->close();
            }

            int waitForRequest();
            int send();
            string get();

        };

};

#endif
