#include<iostream>
#include<string>
#include<stdio.h> 
using namespace std;
const int maxn=100000;
char str[maxn];
int num_str[maxn]={0};
int Count=0;
int main()
{
	int len,k=0;
	cin>>len;
	scanf("%s",str);
	for(int i=0;i<len;i++)
	{
		num_str[str[i]-'a']++;
	}
	for(int i=0;i<26;i++)
	{
		if(num_str[i]&1)
		k++;
		if(k>=2)
		{
			cout<<"Impossible";
			return 0;
		} 
	}
	int i;
	int len_1=len;
	for(i=0;i<len/2;i++)
	{

		int j;
		for(j=len_1-1;j>i;j--)
		{
			if(str[i]==str[j])
			{
				char temp=str[j];
				for(int m=j;m<len_1-1;m++)
				{
					str[m]=str[m+1];
				}
				str[len_1-1]=temp;
				Count+=len_1-1-j;				
				len_1--;
				break;
			}
		}
		if(j==i)
		{
			Count+=(len-1)/2-i;
		}
	}
	cout<<Count;
	return 0;
}
