#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <map>

using namespace std;

float fToC(float currentTemp) {
	return (currentTemp - 32) * 5 / 9;
}

float fToK(float currentTemp) {
	return fToC(currentTemp) + 273.15;
}

float cToF(float currentTemp) {
	return (currentTemp * 9 / 5) + 32;
}

float cToK(float currentTemp) {
	return currentTemp + 273.15;
}

float kToC(float currentTemp) {
	return currentTemp - 273.15;
}

float kToF(float currentTemp) {
	return cToF(currentTemp - 273.15);
}

float tip(float total, float rate) {
	return total + (total * rate / 100);
}

map<char, map<char, float (*)(float currentTemp)> > constructMap() {
	map<char, map<char, float (*)(float currentTemp)> > conversions;

	conversions['c']['f'] = &cToF;
	conversions['c']['k'] = &cToK;
	conversions['f']['c'] = &fToC;
	conversions['f']['k'] = &fToK;
	conversions['k']['c'] = &kToC;
	conversions['k']['f'] = &kToF;

	return conversions;
}

int main() {
	string action;
	cout << "Temperature or tip?" << endl;
	cin >> action;

	if (action == "tip") {
		float total;
		float rate;

		cout << "What was the total?" << endl;
		cin >> total;

		cout << "What is the tipping rate?" << endl;
		cin >> rate;

		cout << tip(total, rate) << endl;
	} else {
		/* implicit call through to function
		 * it is actually:
		 * (*funcPtr)(currentTemp);
		 */
		float currentTemp;
		cout << "What is the current temperature?" << endl;
		cin >> currentTemp;

		char fromUnit;
		cout << "What is the current unit?" << endl;
		cin >> fromUnit;

		char toUnit;
		cout << "What unit are you converting to?" << endl;
		cin >> toUnit;

		map<char, map<char, float (*)(float currentTemp)> > conversions = constructMap();
		cout << conversions[fromUnit][toUnit](currentTemp) << endl;
	}

	return 0;
}
