#include<stdio.h>
int main()
{
	char ch;
	while((ch=detchar())!='#')
	{
		putchar(ch);
	}
	return 0;
}
