#include<stdio.h>
void sub(void);
main()
{
	int i;
	for(i=1;i<=5;i++)
		sub();
}
void sub()
{
	static int times=1;
	printf("%d회 호출\n",times);
	times++;
}
