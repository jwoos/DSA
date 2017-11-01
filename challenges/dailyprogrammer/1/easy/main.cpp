#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	cout << "Enter your name" << endl;
	string name;
	cin >> name;

	cout << "Enter your age" << endl;
	int age;
	cin >> age;

	cout << "Enter your username" << endl;
	string username;
	cin >> username;

	cout << "Your name is " << name << ", you are " << age << " years old, and your username is " << username << endl;

	fstream file("log.txt", fstream::out);
	file << "Your name is " << name << ", you are " << age << " years old, and your username is " << username << endl;
	file.close();
}
