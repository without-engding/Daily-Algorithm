#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
const int maxn=100010;
const int mod=1000000007;
char str[maxn];
int leftNumP[maxn]={0};
int main()
{
	cin.geiline(str,maxn);
	int len=strlen(str);
	for(int i=0;i<len;i++)
	{
		if(i>0)
		{
			leftNumP[i]=leftNumP[i-1];
		}
		if(str[i]=='P')
		leftNumP[i]++;
	}
	int ans,rightNumT=0;
	for(int i=len-1;i>=0;i--)
	{
		if(str[i]=='T')
		rightNumT++;
		if(str[i]=='A')
		{
			ans=(ans+rightNumT*leftNumP[i])%mod;
		}
	}
	cout<<ans;
	return 0;
} 
