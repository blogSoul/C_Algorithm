#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int maintoPoint10to1() {
	char arr[20], str[20];
	int i;
	scanf("%s", arr);
	for (i = 0; arr[i]; i++) {
		if (arr[i] > 'a'&&arr[i] < 'z') {
			printf("%c", arr[i]);
		}
	}
	return 0;
}

int main() {
	return 0;
}
