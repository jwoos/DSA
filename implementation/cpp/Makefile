WARNING = -Wall
DEBUG = -g
VERSION = -std=c++14
OPTIMIZE = -O0

ALL = utils.o

default: clean main

debug: default
	valgrind --leak-check=full -v ./main

main: ${ALL}
	$(CXX) ${VERSION} ${WARNING} ${OPTIMIZE} ${DEBUG} $@.cpp $^ -o $@
	./$@

utils.o:
	$(CXX) ${VERSION} ${WARNING} ${OPTIMIZE} ${DEBUG} -c utils.cpp -o $@

clean:
	rm ${ALL} main
