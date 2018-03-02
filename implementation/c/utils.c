#include "utils.h"


void flush() {
	writeStdout("\n", 1);
}

void printError(char* message, int shouldExit) {
	perror(message);

	if (shouldExit) {
		_exit(EXIT_FAILURE);
	}
}

void writeStdout(char* message, int bytes) {
	if (write(STDOUT_FILENO, message, bytes) < 0) {
		printError("error writing - exiting", 1);
	}
}

// don't use this - use printError or perror
void writeStderr(char* message, int bytes) {
	if (write(STDERR_FILENO, message, bytes) < 0) {
		printError("error writing - exiting", 1);
	}
}

void freeArray(void** arr, int size) {
	for (int i = 0; i < size; i++) {
		free(arr[i]);
	}

	free(arr);
}

int min(int a, int b) {
	return a > b ? b : a;
}

int max(int a, int b) {
	return a > b ? a : b;
}

uint64_t randomNumber(uint64_t a, uint64_t b) {
	uint64_t random = rand();
	return a + random % ((b + 1) - a);
}

void errorExit(char* msg) {
	perror(msg);
	exit(EXIT_FAILURE);
}

/* HASHING FUNCTION
 * http://www.cse.yorku.ca/~oz/hash.html
 * djb2
 */
uint64_t hashJDB2(unsigned char* str) {
	uint64_t val = 5381;
	int c;

	while (c = *str++) {
		// val * 33 + c
		val = ((val << 5) + val) + c;
	}

	return val;
}

uint64_t hashSBDM(unsigned char* str) {
	uint64_t val = 0;
	int c;

	while (c = *str++) {
		val = c + (val << 6) + (val << 16) - val;
	}

	return val;
}
