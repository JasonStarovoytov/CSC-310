CC 			 := g++
CFLAGS 		 := -g

OBJS 		 := mainSamples.o geneBank.o customErrorClass.o
DEPS 		 := geneBank.h customErrorClass.h

.PHONY: clean all

all: mainSamples.o geneBank.o customErrorClass.o program

clean:
	rm $(OBJS) trees



mainSamples.o: mainSamples.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

geneBank.o: geneBank.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

program: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)