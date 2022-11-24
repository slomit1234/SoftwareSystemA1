#include<stdio.h>
#include<math.h>
#include "NumClass.h"

int reverse(int num, int sum);
int sumDigits(int num, int numOfDigits, int sum);
int findNumOfDigits(int num);

int isAmstrong(int num)
{
	return(num == sumDigits(num, findNumOfDigits(num),0) ? 1 : 0);
}

int isPalindrome(int num)
{
	return(num == reverse(num,0) ? 1 : 0);
}

int reverse(int num, int sum)
{
	int temp = sum;
	if (num != 0)
	{
		temp = (temp * 10) + (num % 10);
		reverse(num / 10,temp);
	}
	else
	{
		return temp;
	}

	return temp;
}

int sumDigits(int num, int numOfDigits, int sum)
{
	int temp = sum;
	int t = 0;
	int n = num;
	if (n != 0)
	{
		t=(n%10);
		t=pow(t,numOfDigits);
		//lm;
		temp = temp + t;
		sumDigits(n/10, numOfDigits,temp);
	}
	else
	{
		return temp;
	}

	return temp;
}

int findNumOfDigits(int num)
{
	int count = 0;
	int n = num;

	while (n > 0)
	{
		count++;
		n = n / 10;
	}

	return count;
}