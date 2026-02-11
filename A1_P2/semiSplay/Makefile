INCLUDE_DIRS := Includes
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS) -g

OBJS 		 := mainsplay.o splay.o customErrorClass.o
DEPS 		 := ${INCLUDE_DIRS}/splay.h ${INCLUDE_DIRS}/customErrorClass.h

.PHONY: clean all

all: splay.o mainsplay.o customErrorClass.o splayTree

clean:
	rm $(OBJS) trees



splay.o: splay.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

mainsplay.o: mainsplay.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

splayTree: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)