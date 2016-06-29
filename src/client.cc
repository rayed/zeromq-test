
#include <zmq.hpp>
#include <iostream>
#include <sstream>

int main (int argc, char *argv[])
{
    zmq::context_t context (1);

    //  Socket to talk to server
    std::cout << "Started ... \n" << std::endl;
    zmq::socket_t socket (context, ZMQ_PULL);
    // socket.connect("tcp://localhost:5556");
    socket.connect("ipc://weather.ipc");

    while(1) {
        zmq::message_t message;
        socket.recv(&message);
    }
    return 0;
}
