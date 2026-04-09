INCLUDE_DIRS := AVL
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS) -g

OBJS 		 := mainHash.o avl.o hash.o
DEPS 		 := ${INCLUDE_DIRS}/avl.h hash.h

.PHONY: clean all

all: mainHash.o hash.o avl.o hashing

clean:
	rm $(OBJS) hashing



mainHash.o: mainHash.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

hash.o: hash.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

avl.o: $(INCLUDE_DIRS)/avl.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

hashing: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)