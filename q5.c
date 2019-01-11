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
void Search(Node *tmp,int x);
void Delete(Node *tmp,int x);
void Swap(Node *tmp,int x);

int main(){
	freopen("input.txt", "r", stdin);
	int len;
	Node *head = NULL;
	printf("Enter the number of elements\n");
	scanf("%d",&len);
	for (int i = 0; i < len; ++i)
	{
		int temp;
		scanf("%d",&temp);
		add(&head,temp);
	}
	/*while(head!=NULL){
		printf("%d ",head->data);
		head = head->next;
	}*/
	int choice,ele;
	printf("Enter 1 to search an element\nEnter 2 to Delete an element\nEnter 3 to Swap an element\nEnter 0 to exit\n");
	
	scanf("%d",&choice);
	if(choice==0);
	else
		printf("Enter the element\n");
	scanf("%d",&ele);
	switch(choice){
		case 1:
			Search(head,ele);
			break;
		case 2:
			Delete(head,ele);
			break;
		case 3:
			Swap(head,ele);
			break;
		default:
			printf("Not a valid choice");
	}
	while(head!=NULL){
		printf("%d ",head->data);
		head = head->next;
	}
	return 0;
	
}

void Search(Node *tmp,int x){
	while (tmp!=NULL){
		if(tmp->data==x)
			printf("%d ",x);
		tmp = tmp->next;
	}
}

void Delete(Node *head,int x){
	Node *prev,*tmp = head;
	while (tmp!=NULL){
		if(tmp->data==x){
			break;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = tmp->next;
	free(tmp);
}

void Swap(Node *head,int x){
	Node *prev,*tmp = head;
	if(tmp->next==NULL)
		printf("Cannot Swap Element since it is the last element\n");
	while (tmp!=NULL){
		if(tmp->data==x){
			break;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	Node *temp = prev->next,*temp_next=tmp->next;
	prev->next = tmp->next;
	tmp->next = temp_next->next;
	temp_next->next = temp;
}