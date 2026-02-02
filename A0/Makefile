INCLUDE_DIRS := Includes
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := mainbst.o bst.o customErrorClass.o
DEPS 		 := ${INCLUDE_DIRS}/bst.h ${INCLUDE_DIRS}/customErrorClass.h

.PHONY: clean all

all: bst.o mainbst.o customErrorClass.o trees

clean:
	rm $(OBJS) trees



bst.o: bst.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

mainbst.o: mainbst.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

trees: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)