#ifndef PG_CONNECTION_H
#define PG_CONNECTION_H

#include <iostream>
#include <libpq-fe.h> 

class PGConnection
{
private:
    PGconn *connection;

public:
    PGConnection();
    ~PGConnection();

    bool connect(const char *host, const char *dbname, const char *user, const char *password, int port);
    void disconnect();
    PGconn *getConnection();
};

#endif // PG_CONNECTION_H
