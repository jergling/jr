CC=g++
JRDIR=./jr
CFLAGS=-c -Wall -I$(JRDIR) -g
LDFLAGS=-lBox2D -lsfml-graphics -lsfml-window -lsfml-system -L$(JRDIR)/jr/lib -ljr
SOURCES=$(wildcard Entity/*.cpp) $(wildcard Physics/*.cpp) $(wildcard Graphics/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=out

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) main.o
	$(CC) $(OBJECTS) main.o -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(EXECUTABLE) *.o Physics/*.o Entity/*.o Graphics/*.o
