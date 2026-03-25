INCLUDE_DIRS := Includes
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS) -g

OBJS 		 := mainRB.o rb.o customErrorClass.o
DEPS 		 := ${INCLUDE_DIRS}/rb.h ${INCLUDE_DIRS}/customErrorClass.h

.PHONY: clean all

all: rb.o mainRB.o customErrorClass.o rbTree

clean:
	rm $(OBJS) rbTree



rb.o: rb.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

mainRB.o: mainRB.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

rbTree: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)