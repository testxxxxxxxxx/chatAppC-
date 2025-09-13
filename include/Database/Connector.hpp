#ifndef ORM_HPP

#define ORM_HPP

#include <iostream>
#include <memory>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

namespace Database {

    class Connector {

        string host, user, password, dbname;
        int port;
        unique_ptr<connection> conn;

        void init();

        public:

            Connector(string host, string user, string password, int port, string dbname): host(host), user(user), password(password), dbname(dbname) {

            }
            ~Connector();

            result get(string sql);
            void exec(string sql);

    };

};

#endif
