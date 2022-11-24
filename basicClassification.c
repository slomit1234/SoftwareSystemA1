#include<stdio.h>
#include "NumClass.h"

int factorial (int num);


int isPrime(int num)
{
	int i = 0;

	if (num <= 1) // negetive numbers cant be negetive, 0 or 1 - not prime nunbers
	{
		return 0;
	}

	for (i=2; i<=(num/2); i++)  // will check if num have a divider
	{
		if (num%i== 0)  //if we found one - not prime
		{
			return 0;
		}
	}

	return 1;
}

int isStrong(int num)
{
	int n = num;
	int temp = 0;

	while (n > 0)
	{
		temp += factorial(n % 10);
		n = n / 10;
	}

	return (num == temp ? 1 : 0); //short if like we saw in class
}

int factorial(int num)
{
	int i = 0;
	int fact = 1;

	if (num < 0)
	{
		printf("Error! Factorial of a negative number doesn't exist.");
	}
	else
	{
		for (i = 1; i <= num; ++i)
		{
			fact *= i;
		}
	}

	return fact;
}