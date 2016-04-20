CC=clang
CCFLAGS=-c -g -Wall
LDFLAGS=
SOURCES=primes.c
OBJECTS=$(SOURCES:.c=.o)
EXE=primes

all: $(SOURCES) $(EXE) 

$(EXE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cc.o:
	$(CC) $(CCFLAGS) $< -o $@

clean:
	rm *.o primes
