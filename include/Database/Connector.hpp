#ifndef ORM_HPP

#define ORM_HPP
#include <memory>
#include <pqxx/pqxx>

using namespace pqxx;

namespace Database {

    class Connector {

        string host, user, password, dbname;
        int port;
        connection *conn;
        unique_ptr<connection> conn;

        public:

            Connector(string host, string user, string password, int port, string dbname): host(host), user(user), password(password), dbname(dbname) {

            }
            ~Connector();

            void init();

    };

};

#endif
