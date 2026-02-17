INCLUDE_DIRS := Includes
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS) -g

OBJS 		 := main.o dsw.o customErrorClass.o
DEPS 		 := ${INCLUDE_DIRS}/dsw.h ${INCLUDE_DIRS}/customErrorClass.h

.PHONY: clean all

all: dsw.o main.o customErrorClass.o dswTree

clean:
	rm $(OBJS) trees



dsw.o: dsw.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

main.o: main.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

dswTree: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)