#ifndef CLIENT_HPP
# define CLIENT_HPP

#include <iostream>
#include <HttpRequest.hpp>
#include <HttpResponse.hpp>

//these are possible states (these can change still)
enum ClientState {
    READING_HEADERS,   // POST Master is waiting for \r\n\r\n
    READING_BODY,      // POST Master is reading chunks/data
    PROCESSING,        // GET Master is matching routing rules / opening files
    WAITING_FOR_CGI,   // CGI Master is waiting for the pipe to have data
    WRITING_RESPONSE,  // Sending the formatted data back to the browser
    FINISHED           // Flag to tell the main loop to close the socket
};

class Client 
{
    // What do we need to store in client object? 
    private:
            int         _fd; // Client socker
            ClientState _state; // Store the client state
            
            std::string request_buffer; //where we append the request

    public:
            Client(int fd); // constructor sets state = Reading headears on default



};

#endif