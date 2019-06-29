cc=g++
server=ChatServer
client=ChatClient
INCLUDE=-I./lib/include -L./lib/lib
LDFLAGS=-std=c++11 -lpthread -ljsoncpp

.PHONY:all
all:$(server) $(client)

$(server):ChatServer.cc
	$(cc) -o $@ $^ $(INCLUDE) $(LDFLAGS)
$(client):ChatClient.cc
	$(cc) -o $@ $^ $(INCLUDE) $(LDFLAGS)
.PHONY:clean
clean:
	rm -f $(server) $(client)
