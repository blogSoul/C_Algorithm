#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct complex {
	double real;
	double imag;
} complex;

complex addComplex(complex a, complex b) {
	complex c;
	double p, q, r;
	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	return c;
};

int maintoPoint11to1() {
	complex a, b, c;
	double p, q, r;
	scanf("%lf %lf", &a.real, &a.imag);
	scanf("%lf %lf", &b.real, &b.imag);
	
	c = addComplex(a, b);
	printf("%.2f + %.2fi", c.real, c.imag);
	return 0;
}

typedef struct result {
	int highScore;
	int lowScore;
	char pOrNp;
	int pOrNpInterval = 15;
	int interval;
} result;

void passorfail (struct result *a){
	a->interval = a->highScore - a->lowScore;
	if (a->interval > a->pOrNpInterval){
		a->pOrNp = 'F';
		return;
	}	
	else {
		a->pOrNp = 'P';
		return;
	};
};

int maintoPoint11to2() {
	struct result a;
	struct result *p = &a;
	scanf("%d", &p->highScore);
	scanf("%d", &p->lowScore);
	scanf("%d", &p->pOrNpInterval);

	passorfail(p);
	printf("%d %c\n", p->interval, p->pOrNp);
	return 0;
}

typedef struct studentArray {
	int score[3];
	char name[9];
	double scoreMin;
} studentArray;

void read_data(studentArray st[]) {
	int i;
	for (i = 0; i < 10; ++i) {
		scanf("%s %d %d %d", &st[i].name, &st[i].score[0], &st[i].score[1], &st[i].score[2]);
		getchar();
	}
}

void cal_avg(studentArray st[]) {
	int i;
	for (i = 0; i < 10; ++i) {
		st[i].scoreMin = (st[i].score[0] + st[i].score[1] + st[i].score[2]) / 3;
	}
}

void sort(studentArray st[]) {
	int i, j, num;
	for (j = 9; j > 0; --j) {
		for (i = j; i < 10; ++i) {
			if (st[i - 1].scoreMin <= st[i].scoreMin) {
				st[10] = st[i - 1];
				st[i - 1] = st[i];
				st[i] = st[10];
			}
		}
	};
}

void print_score(studentArray st[]) {
	int i;
	for (i = 7; i < 10; ++i) {
		printf("%s %.2f\n", st[i].name, st[i].scoreMin);
	}
}

int maintoPoint11to3() {
	struct studentArray st[11];
	int i;

	read_data(st);
	cal_avg(st);
	sort(st);

	printf("%s %.2f\n", st[0].name, st[0].scoreMin);
	printf("%s %.2f\n", st[9].name, st[9].scoreMin);
	print_score(st);
	return 0;
}
