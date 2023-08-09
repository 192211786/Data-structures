#include<stdio.h>
int main()
{
	int n;
	printf("enter any number:\n");
	scanf("%d",&n);
	if(n>0||n<0)
	{
	if(n%2==0)
	{
	printf("The given number is even number");
    }
	else
	{
	printf("The given number is odd number");
    }
    }
    else {
    	printf("\n\tCharacters are not alowed..!!");
    	printf("\n\tEnter the valid input!");
	}
	return 0;
}
