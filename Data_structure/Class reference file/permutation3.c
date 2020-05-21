#include <stdio.h>
#include <stdlib.h>
void permutation();
void swap();
void reverse();
int main (void)
{
	int *a,i,times=0;
	a=(int*)malloc(7*sizeof(int));
	a--;
	for(i=1;i<=7;i++)
		a[i]=i;
	printf("(a, b, c, d, e, f, g)\n");
	permutation(a,1,7,&times);
	printf("순서쌍의 개수 : %d\n",times);
	free(a+1);
	return 0;
}
void permutation(int *a, int i, int n, int *times)
{
	static int k=0;
	int j;
	if(i!=n){
		for(j=i;j<=n;j++){
			permutation(a,i+1,n,times);
			if(j!=n){
				swap(a,i,n-j+i);
				reverse(a,i+1,n);
			}
		}
	}
	else if(a[1]+a[4]==a[5]+a[6] && a[2]+a[5]==a[4]+a[7]){
		for(j=1;j<=n;j++){
			if(j==1)
				printf("(%d, ",a[j]);
			else if(j<n)
				printf("%d, ",a[j]);
			else
				printf("%d)",a[j]);
		}
		k++;
		printf("\n");
	}
	*times=k;
}
void swap(int *a, int i, int j)
{
	int temp;
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
void reverse(int *a, int i, int n)
{
	int k,m,s;
	int temp;
	s=i+n;
	m=s/2;
	for(k=i;k<=m;k++){
		temp=a[k];
		a[k]=a[s-k];
		a[s-k]=temp;
	}
}
