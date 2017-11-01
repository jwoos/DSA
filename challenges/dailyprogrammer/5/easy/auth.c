#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int stringComparison(char* a, char* b) {
	int i = 0;

	while (a[i] != '\0' && b[i] != '\0') {
		if (a[i] != b[i]) {
			return 0;
		}

		i++;
	}

	return 1;
}

int main() {
	char user[30];
	char pass[30];

	char* AUTH_USER = "USERNAME";
	char* AUTH_PASS = "PASSWORD";

	printf("Username: ");
	scanf("%s", user);

	printf("Password: ");
	scanf("%s", pass);

	if (!stringComparison(user, AUTH_USER) || !stringComparison(pass, AUTH_PASS)){
		printf("Invalid user or password! \n");
	} else {
		printf("Authenticated \n");
	}
}
