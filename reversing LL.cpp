#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

typedef enum {FAILURE,SUCCESS} statuscode;

struct node *head=NULL,*lptr=NULL;

struct node* createlist(int n)
{
	
	struct node *ptr;
	int i=1;
	ptr = (struct node*) malloc(sizeof(struct node));
	ptr->data=0;
	ptr->next=NULL;
	lptr=ptr;
	while(i<n)
	{
		head=(struct node*)malloc(sizeof(struct node));
		head->data=i;
		head->next=ptr;
		ptr=head;
		i++;
	}
	
	return ptr;
}

statuscode reverselist(struct node *PREV,struct node *CURR)
{
	statuscode sc=SUCCESS;
	struct node *NEXT;
	
	NEXT=CURR;
	
	if((head==NULL)||(head->next==NULL))
	{
		sc=FAILURE;
	}
	else
	{
	
		while(NEXT!=NULL)
		{
			NEXT=CURR->next;
			CURR->next=PREV;
			PREV=CURR;
			CURR=NEXT;
			
			reverselist(PREV,CURR);
			
		}
	}
	
	return sc;
}

int main()
{
	struct node *ptr;
	
	int i;

	int n;
	printf("enter no. of nodes in linked list : ");
	scanf("%d",&n);
	
	printf("created list with values upto n : ");
	ptr=createlist(n);
	
	for(i=0;i<n;i++)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	
	
	
	reverselist(NULL,head);
	
	ptr=lptr;
	printf("\nReverse list : ");
	for(i=0;i<n;i++)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	
	return 0;
}
