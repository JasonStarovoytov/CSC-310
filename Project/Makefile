CC 			 := g++

OBJS 		 := p_bst_1.o p_bst_2.o p_bst_fat.o p_queue.o

.PHONY: clean all

all: p_bst_1.o p_bst_2.o p_bst_fat.o p_queue.o

clean:
	rm $(OBJS)

p_bst_1.o: p_bst_1.cpp
	$(CC) -c -o $@ $(CFLAGS) $<

p_bst_2.o: p_bst_2.cpp
	$(CC) -c -o $@ $(CFLAGS) $<

p_bst_fat.o: p_bst_fat.cpp
	$(CC) -c -o $@ $(CFLAGS) $<

p_queue.o: p_queue.cpp
	$(CC) -c -o $@ $(CFLAGS) $<
