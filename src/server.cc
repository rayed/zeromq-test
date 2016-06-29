
#include <zmq.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

int main () {

    //  Prepare our context and publisher
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_PUSH);
    // socket.bind("tcp://*:5556");
    socket.bind("ipc://weather.ipc");

    std::cout << "Sending: " << std::fixed << 1e6 << " messages\n";
    for (int i=0 ; i < 1e6; i++) {
        zmq::message_t message(5);
        strcpy((char *) message.data(), "hello");
        socket.send(message);
    }
    return 0;
}
