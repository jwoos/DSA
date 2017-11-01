#include "utils.hpp"

Timer::Timer() {
	start = clock();
}

double Timer::elapsed() const {
	return (clock() - start) / CLOCKS_PER_SEC;
}

void Timer::reset() {
	start = clock();
}
