
CXXFLAGS=-Wall -O3 -std=c++11 -I. `pkg-config --cflags libzmq`
LDLIBS=`pkg-config --libs libzmq `

all: server client

server: server.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

client: client.o
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: clean
clean:
	-rm server client *.o
