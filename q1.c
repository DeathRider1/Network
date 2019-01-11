#include<stdio.h>

int main(){
	freopen("input.txt", "r", stdin);

	int n,saddle;
	scanf("%d",&n);
	int a[n][n];
	int flag=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for(int i=0;i<n;i++)
	{
		int col=0;
		saddle=a[i][0];
		//gives the min of respective row
		for(int j=0;j<n;j++)
		{
			if(a[i][j]<saddle)
			{
				saddle=a[i][j];
				col=j;
			}
		}
		//saddle now = min of row
		for(int j=0;j<n;j++)
		{
			if(i==j)
				continue;
			if(a[j][col]>saddle){
				flag=0;
				break;
			}
			else flag=1;
		}
		//if(flag) break;
	}
	if(flag)
		printf("%d",saddle);
	else 
		printf("No saddle point.");
	return 0;
}