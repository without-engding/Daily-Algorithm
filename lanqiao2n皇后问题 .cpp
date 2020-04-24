#include<iostream>
#include<math.h> 
using namespace std;
int count=0;
const int maxn=2000;
int num[maxn][maxn];
int result[maxn][maxn];
int n,hashTable[maxn]={false},P[maxn];
int k=0;
void permutation(int index)
{
	if(index==n+1)
	{
		for(int i=1;i<index;i++)
		{
			result[k][i]=P[i];
		} 
		k++;
		return;
	}
	for(int x=1;x<=n;x++)
	{
			if(num[x][index]==0)
			{
			continue;
			}	
		if(hashTable[x]==false)
		{
			int temp=true;
			for(int per=1;per<index;per++)
			{
				if(fabs(index-per)==fabs(x-P[per]))
				{
					temp=false;
					break;					
				}

			}
			if(temp)
		{
			P[index]=x;
			hashTable[x]=true;
			permutation(index+1);
			hashTable[x]=false;
		}
		
		}
	}
}
int main()
{
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>num[i][j];
		}
	}
	permutation(1);

	for(int i=0;i<k-1;i++)
	{
		
		for(int j=i+1;j<k;j++)
		{
		int m=1;
		int temp=0;
			while(m<=n)
			{
				if(result[i][m]==result[j][m])
			temp=1;
			if(m==n&&temp==0)
			count++;	
			m++;
			}
			
		}
	}
	cout<<count*2;
	return 0;
}
