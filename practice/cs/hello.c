#include <stdio.h>

#define MONTHS 12

int main()
{
	const int days[MONTHS]={30,30,30,30,30,30,30,30,30,30,30,30};
	int index;
	for (index=0;index<MONTHS;index++)
		printf("%d,%2d\n",index+1,days[index]);
	return 0;
}
