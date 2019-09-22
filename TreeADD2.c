#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char op[100]; // 문자를 입력 받는 함수 입니다.
	int find; // 경로 탐색 횟수입니다.
	int num_op; // 입력받는 노드 문장의 개수입니다.
	int left, data, right; // 각각 노드별로 왼쪽에 있는 자식, 부모, 오른쪽에 있는 자식으로 받습니다.
	
	int c, i;
	int a = 1;
	int b = 0;
	int ar[100];// 트리를 배열로 생각해서 만들었습니다.
	int arr[100];// 결과값을 넣기 위해 만들었습니다.
	int N = 100;
	
	for (i = 0; i < N; i++) {
		ar[i] = 0;
	}// 모든 배열을 0으로 만들었습니다.

	scanf("%d", &num_op); // 연산 개수를 입력합니다.
	for (int i = 0; i < num_op; ++i) {
		scanf("%d %d %d", &data, &left, &right);
		if (i == 0) {
			ar[1] = data;
			ar[2] = left;
			ar[3] = right;// 첫 부분은 직접 배열에 넣어주고
		}
		else {
			for (int j = 1; j <= 100; j++) {
				if (data == ar[j]) {
					ar[j] = data;
					ar[2 * j] = left;
					ar[2 * j + 1] = right;
					if (b <= 2 * j + 1) {
						c = 2 * j + 1;
						b = c;
					}// 트리 구조상 맞은 위치에 배열해주었습니다.
					break;
				}
			}
		}
	}

	scanf("%d", &find); // 경로 설정 횟수를 지정합니다.

	for (int i = 0; i < find; i++) {
		scanf("%s", &op);
		printf(" %d", ar[a]);
		for (int j = 0; j < strlen(op); j++) {
			if (op[j] == 'L') {
				a = 2 * a;
				printf(" %d", ar[a]);
			}
			if (op[j] == 'R') {
				a = 2 * a + 1;
				printf(" %d", ar[a]);
			}
		}
		printf("\n");
		a = 1;
	}//R로 가면 2배만큼 L로 가면 2배에서 +1한 만큼 갈 수 있도록 만들었습니다.
	
	return 0;
}
