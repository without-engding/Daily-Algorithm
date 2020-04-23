#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
char number[5]={0};
int n;
int maxn,minn;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	cin>>n;
	while(1)
	{
		sprintf(number,"%04d",n);
		sort(number,number+4);
		sscanf(number,"%04d",&minn);
		sort(number,number+4,cmp);
		sscanf(number,"%04d",&maxn);
		n=maxn-minn;
		printf("%04d - %04d = %04d\n",maxn,minn,n);
		if(n==6174||n==0)
		break;	
	}
	return 0;
}
