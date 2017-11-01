CPP_ARGS = -Wall -std=c++1y -ggdb -O0
C_ARGS = -Wall -std=gnu11 -ggdb -O0

BASE = $(basename $(FILE))
DIRECTORY =
FILE =
LINK =

CPP:
	$(CXX) $(CPP_ARGS) $(DIRECTORY)/$(FILE) $(LINK) -o $(BASE).out
	./$(BASE).out

C:
	$(CC) $(C_ARGS) $(DIRECTORY)/$(FILE) $(LINK) -o $(BASE).out
	./$(BASE).out
