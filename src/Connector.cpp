#include <iostream>
#include "include/Database/Connector.hpp"

using namespace std;
using namespace Database;
using namespace pqxx;

Connector::~Connector() {

}
void Connector::init() {
    string conninfo = "host=" + this->host + " dbname=" + this->dbname + " user=" + this->user + " password=" + this->password;

    this->conn = make_unique<connection>();
}
