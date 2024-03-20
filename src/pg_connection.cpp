#include "pg_connection.h"

PGConnection::PGConnection()
{
    connection = nullptr;
}

PGConnection::~PGConnection()
{
    disconnect();
}

bool PGConnection::connect(const char *host, const char *dbname, const char *user, const char *password, int port)
{
    connection = PQsetdbLogin(host, std::to_string(port).c_str(), nullptr, nullptr, dbname, user, password);
    if (PQstatus(connection) != CONNECTION_OK)
    {
        std::cerr << "Connection to database failed: " << PQerrorMessage(connection) << std::endl;
        disconnect();
        return false;
    }
    return true;
}

void PGConnection::disconnect()
{
    if (connection != nullptr)
    {
        PQfinish(connection);
        connection = nullptr;
    }
}

PGconn *PGConnection::getConnection()
{
    return connection;
}
