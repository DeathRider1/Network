#include<stdio.h>
#include<stdlib.h>

typedef struct nodeType{
	int data;
	struct nodeType *next;
}Node;

void add(Node **head,int x){
	Node *tmp = (Node *)malloc(sizeof(Node));
	tmp->data = x;
	tmp->next = *head;
	*head = tmp;
}

int main(){
	freopen("input.txt", "r", stdin);
	int len,k;
	Node *head = NULL;
	printf("Enter the number of elements and value of k\n");
	scanf("%d%d",&len,&k);
	for (int i = 0; i < len; ++i)
	{
		int temp;
		scanf("%d",&temp);
		add(&head,temp);
	}
	Node *ele=head;
	for (int i = 0; i < k; ++i)
	{
		if(head==NULL){
			printf("Entered k is larger than the size of linked list");
			break;
		}
		head = head->next;
	}
	while(head!=NULL){
		head = head->next;
		ele = ele->next;
	}
	printf("%d\n",ele->data);
	return 0;
}