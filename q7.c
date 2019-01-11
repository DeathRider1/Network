#include<stdio.h>

void encoded_message(int ans[]){
	int c,i=0,ind=0,space_num=0;
	int spaces[100]={0};
	while(ans[ind]!=0){
		if(ans[ind]==32){
			spaces[space_num]=ind;
			ans[ind]=32;
			++ind;
			continue;
		}

		if(i%2==0){
			if(ans[ind]+3>122)
				ans[ind] = 96+ans[ind]-122;
			else
				ans[ind] = ans[ind]+3;
		}
		++ind;
		++i;
	}
	i=0;
	while(ans[i]!=0){
		printf("%c",ans[i]);
		++i;
	}
}

int main(){
	freopen("input.txt", "r", stdin);
	//97-122
	int input[100]={0};
	int choice,c,i=0;
	printf("Enter 1 to encode or 2 to decode\n");
	scanf("%d",&choice);
	printf("Enter String:\n");
	while((c=getchar())!=-1){
		input[i]=c;
		++i;
	}
	if(choice==1)
		encoded_message(input);
	else if (choice==2);
		//decoded_messege(input);
	else
		printf("Enter a valid choice");
	return 0;
}