// #define _WINSOCK_DEPRECATED_NO_WARNINGS
// #pragma comment(lib, "ws2_32.lib");
// #include <iostream>
// #include <WinSock2.h>
// #include <string>
// using namespace std;

// int main()
// {
//     cout << "Hello" << endl;

//     SOCKET wsocket;
//     SOCKET new_socket;
//     WSADATA wsadata;

//     struct sockaddr_in server;
//     int server_size;
//     int BUFFER_SIZE = 37020;

//     if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
//     {
//         cout << "COuld not initialize socket" << endl;
//     }

//     wsocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//     if (wsocket == INVALID_SOCKET)
//     {
//         cout << "Couldn't create socket" << endl;
//     }

//     server.sin_family = AF_INET;
//     server.sin_addr.s_addr = inet_addr("127.0.0.1");
//     server.sin_port = htons(8000);
//     server_size = sizeof(server);

//     if (bind(wsocket, (SOCKADDR *)&server, server_size) != 0)
//     {
//         cout << "Couldn't bind to socket" << endl;
//     }

//     if (listen(wsocket, 20) != 0)
//     {
//         cout << "Couldn't listen port 8000" << endl;
//     }

//     cout << "Server listening on port 8000..." << endl;

//     int bytes = 0;
//     while (true)
//     {
//         new_socket = accept(wsocket, (SOCKADDR *)&server, &server_size);

//         if (new_socket == INVALID_SOCKET)
//         {
//             cout << "Couldn't accept socket" << endl;
//         }

//         char buff[30720] = {0};
//         bytes = recv(new_socket, buff, BUFFER_SIZE, 0);

//         if (bytes < 0)
//         {
//             cout << "Couldn't read from socket" << endl;
//         }

//         string message = "HTTP/1.1 200 OK\r\nContent-Type: text/html\nContent-Length: ";
//         string response = "<html><h1>Hello client....</h1></html>";
//         message.append(to_string(response.size()));
//         message.append("\n\n");
//         message.append(response);

//         int bytesSent = 0;
//         int totalBytesSent = 0;

//         while (totalBytesSent < message.size())
//         {
//             bytesSent = send(new_socket, message.c_str(), message.size(), 0);

//             if (bytesSent < 0)
//             {
//                 cout << "Error sending message" << endl;
//             }

//             totalBytesSent += bytesSent;
//         }

//         cout << "Response sent to client!" << endl;

//         closesocket(new_socket);
//         WSACleanup();
//     }
//     closesocket(wsocket);
//     return 0;
// }

#include <iostream>
#include "pg_connection.h"

int main()
{
    // Initialize PostgreSQL connection
    PGConnection pgConnection;
    if (!pgConnection.connect("localhost", "cpp_learn", "postgres", "Password@2001", 5432))
    {
        std::cerr << "Failed to connect to PostgreSQL." << std::endl;
        return 1;
    }

    // Use the connection...

    // Disconnect from PostgreSQL
    pgConnection.disconnect();

    return 0;
}
