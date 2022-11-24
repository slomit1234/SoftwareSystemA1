#include<stdio.h>
#include<math.h>
#include "NumClass.h"

int findNumOfDigits(int num);

int isAmstrong(int num)
{
	int numOfDigits = findNumOfDigits(num);
	int n=num;
	int temp = 0 ;
	int t=0;
	
	while(n>0)
	{
		t=(n%10);
		t=pow(t,numOfDigits);
		//lm;
		temp = temp+t;
		n=n/10;
	}
	
	return (num == temp? 1: 0);//short if like we saw in class
}

int isPalindrome(int num)
{
	int n=num;
	int temp = 0 ;
	
	while(n>0)    
	{     
		temp=(temp*10)+(n%10);    
		n=n/10;    
	}    
	
	return (num==temp?1:0);//short if like we saw in class
}

int findNumOfDigits(int num)
{
	int count=0;
	int n=num;
	while(n>0)
	{
		count++;
		n = n/10;
	}
	
	return count;
}
