#include<stdio.h>
#define SIZE 10
int sum(int ar[],int n);
int main()
{
	int marbles[SIZE]={20,10,5,39,4,16,19,26,31,20};
	long answer;
	answer=sum(marbles,SIZE);
	printf("%ld\n",answer);
	printf("%zd\n",sizeof marbles);
	return 0;
}
int sum (int ar[],int n)
{
	int total=0;
	int i;
	for (i=0;i<n;i++)
		total+=ar[i];
	printf("%zd\n",sizeof ar);

return total;
}
