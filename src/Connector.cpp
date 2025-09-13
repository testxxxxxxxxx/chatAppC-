#include <iostream>
#include "../include/Database/Connector.hpp"

using namespace std;
using namespace Database;
using namespace pqxx;

Connector::~Connector() {
    try {
        this->init();

    }
    catch(exception &e) {
        cerr<<"Error: "<<e.what()<<endl;
    }
}
void Connector::init() {
    string conninfo = "host=" + this->host + " dbname=" + this->dbname + " user=" + this->user + " password=" + this->password;

    this->conn = make_unique<connection>(conninfo);

    if(!conn->is_open()) 
        throw string("Database connection exception");
}
result Connector::get(string sql) {
    //select operations
    nontransaction txn(*this->conn);
    result r = txn.exec(sql);

    return r;
}
void Connector::exec(string sql) {
    //insert, update, delete operations
    work W(*this->conn);
    W.exec(sql);
    W.commit();
}
