/*
 *Write a function that takes an unsigned integer and returns the number of 1 bits it has.
 */
int numSetBits(unsigned int a) {
	int count = 0;
	unsigned int test = 1;
	int i;

	for (i; i < 32; i++) {
		count += a & test;
		a = a >> 1;
	}

	return count;
}
