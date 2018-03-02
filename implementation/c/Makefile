CC = gcc
CFLAGS = -Wall -Wextra -std=gnu11 -ggdb -O0
LDLIBS =
LDFLAGS =

# implicit rule for %.o
# $(CC) $(CPPFLAGS) $(CFLAGS) -c $@


OBJECT = utils.o

UNUSED_ALGORITHMS =
ALGORITHMS =

UNUSED_STRUCTURES = graph.o tree/binary-search.o
STRUCTURES = linked-list/double.o linked-list/single.o \
			 vector/vector.o \
			 hash-map/closed.o hash-map/open.o

default: clean datastructures

datastructures: ${OBJECTS} ${STRUCTURES}
	$(CC) datastructures.c $^ $(LDFLAGS) $(LDLIBS) -o $@

debug: default
	valgrind --leak-check=full -v ./datastructures

clean:
	touch ${OBJECTS} datastructures && rm ${OBJECTS} datastructures
