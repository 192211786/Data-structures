#include<stdio.h>
int main()
{
	int x=1,fact=1,n;
	printf("enter the number :");
	scanf("%d", &n);
	while(x<=n)
	{
		fact=fact*x;
		x++;
	}
	if (n>=1)
	{
	printf("factorial of the %d : %d",n,fact);
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
