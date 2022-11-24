#include<stdio.h>
#include "NumClass.h"

int main()
{
	int num1;
	int num2;
	int i=0;
	int smaller=0;
	int bigger=0;

	printf("please enter 2 numbers:");
	scanf("%d",&num1);
	scanf("%d",&num2);
	
	if (num1<num2)
	{
		smaller=num1;
		bigger=num2;
	}
	else
	{
		smaller=num2;
		bigger=num1;
	}

   printf("\nThe Armstrong numbers are:");
   for(i=smaller; i<=bigger; i++)
   {
        if(isAmstrong(i)==1)
        {
            printf("%d ",i);
        }
    }
   printf("\nThe Palindromes are:");
   for(i=smaller; i<=bigger; i++)
   {
        if(isPalindrome(i)==1)
        {
            printf("%d ",i);
        }
    }
   printf("\nThe Prime numbers are:");
   for(i=smaller; i<=bigger; i++)
    {
        if(isPrime(i)==1)
        {
            printf("%d ",i);
        }
    }
    printf("\nThe Strong numbers are:");
   for(i=smaller; i<=bigger; i++)
    {
        if(isStrong(i)==1)
        {
            printf("%d ",i);
        }
    }
    printf("\n");
    return 0;
}