#include<stdio.h>
#include<math.h>
int main(){
	freopen("input.txt", "r", stdin);
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=a;i<=b;i++){
		int flag=1;
		for(int j=2;j<sqrt(i);j++){
			if(i%j==0){
				flag=0;
				break;
			}
		}
		if(flag==1) printf("%d ",i);
	}
	return 0;
	
}