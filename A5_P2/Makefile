CC 			 := g++
CFLAGS 		 := -g

OBJS 		 := main.o mst.o binaryHeap.o binomialHeap.o customErrorClass.o
DEPS 		 := mst.h binaryHeap.h binomialHeap.h customErrorClass.h

.PHONY: clean all

all: main.o mst.o binaryHeap.o binomialHeap.o customErrorClass.o program

clean:
	rm $(OBJS) trees



main.o: main.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

mst.o: mst.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

binaryHeap.o: binaryHeap.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

binomialHeap.o: binomialHeap.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

program: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)