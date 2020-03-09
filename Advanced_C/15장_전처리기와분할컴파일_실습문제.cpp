#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ABS(a) (a>0?a:-a)
#define MAX(a,b) (a>b?a:b)

int main() {
	int num[6], i, max, abs;
	for (i = 0; i < 6; ++i) {
		scanf("%d", &num[i]);
	}
	max = num[0];
	abs = num[0];
	for (i = 0; i < 6; ++i) {
		max = MAX(max, num[i]);
		abs = (ABS(num[i]) > ABS(abs) ? num[i]:abs);
	}
	printf("%d %d", abs, ABS(abs));
	return 0;
}
