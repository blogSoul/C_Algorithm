#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *input, *output;
	int i, n = 0, count;
	char *temp, arr[100];
	input = fopen("input2.txt", "r");
	output = fopen("output2.txt", "w");
	while (fgets(arr, sizeof(arr), input) != NULL) {
		fputs(arr, stdout);
		n++;
		if (n > 1) {
			count = strlen(arr) - 11;
			printf("%d\n", count);
			for (i = 11; i < count; i++) {
				arr[i] = '*';
			}
			fprintf(output, "%s", arr);
		}
		else {
			fprintf(output, "%s", arr);
		}
	}
	fclose(input);
	fclose(output);
	return 0;
}
