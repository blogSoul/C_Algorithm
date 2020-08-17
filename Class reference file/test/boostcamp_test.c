#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// v_len은 배열 v의 길이입니다.
int* solution(int v[][2], size_t v_len) {
	// return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
	int* answer = (int*)malloc(2* sizeof(int));
	int i, j, x[3], y[3], num = 0;
	for (i = 0; i < v_len; i++) {
		x[i] = v[i][0];
		y[i] = v[i][1];
	}
	if (x[0] == x[1]) {
		answer[0] = x[2];
	}
	else if (x[0] == x[2]) {
		answer[0] = x[1];
	}
	else if (x[1] == x[2]) {
		answer[0] = x[0];
	}
	if (y[0] == y[1]) {
		answer[1] = y[2];
	}
	else if (y[0] == y[2]) {
		answer[1] = y[1];
	}
	else if (y[1] == y[2]) {
		answer[1] = y[0];
	}
	return answer;
}

int main() {
	char arr[100];
	int i, *q, check = 0, j = 0, p[3][2], number[6], num = 0, v_len = 3;
	scanf("%[^\n]", arr);
	printf("%s\n", arr);
	for (i = 0; i < strlen(arr); i++) {
		if (arr[i] == '0' || arr[i] == '1' || arr[i] == '2' || arr[i] == '3' || arr[i] == '4' || arr[i] == '5' || arr[i] == '6' || arr[i] == '7' || arr[i] == '8' || arr[i] == '9') {
			num = 10 * num + (arr[i] - '0');
		}
		else if (arr[i] == '[') {
			check++;
		}
		else if (arr[i] == ']') {
			check--;
		}
		if (arr[i] == ',' || check == 0) {
			number[j] = num;
			num = 0;
			j++;
		}
	}
	for (i = 0; i < 6; i++) {
		j = i % 2;
		num = i / 2;
		p[num][j] = number[i];
	}
	q = solution(p, v_len);
	printf("[%d, %d]", q[0], q[1]);
}
