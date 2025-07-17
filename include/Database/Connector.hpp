#ifndef ORM_HPP

#define ORM_HPP

namespace Database {

    class Connector {

        string host, user, password;
        int port;

        public:

            Connector(string host, string user, string password, int port): host(host), user(user), password(password) {

            }
            ~Connector();

            void init();
            void close();

    };

};

#endif
