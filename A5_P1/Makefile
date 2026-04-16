INCLUDE_DIRS := Includes
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS) -g

OBJS 		 := main.o binomial.o customErrorClass.o
DEPS 		 := ${INCLUDE_DIRS}/binomial.h ${INCLUDE_DIRS}/customErrorClass.h

.PHONY: clean all

all: binomial.o main.o customErrorClass.o binomialTree

clean:
	rm $(OBJS) trees



binomial.o: binomial.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

main.o: main.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

binomialTree: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)