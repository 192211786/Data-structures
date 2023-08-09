#include<stdio.h>
int fact(int);
int main()
{
    int n;
    printf(" Enter the Number to Find Factorial :");
    scanf("%d",&n);
	if(n>=1)
	{
    printf(" Factorial of %d is %d",n,fact(n));
    }
    else if(n<0)
    {
    	printf("You have entered negative number-invalid");
	}
	else
	{
    	printf("\n\tCharacters are not alowed..!!");
    	printf("\n\tEnter the valid input!");
	}
	return 0;
}
int fact(int n)
{
    if(n==0)
        return(1);
        else
    return(n*fact(n-1));
}
