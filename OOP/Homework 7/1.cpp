#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

void Push(struct node **h, int d)
{
	struct node *p=(struct node *)malloc(sizeof(struct node));
		p->data=d;
		p->next=*h;
		*h=p;
}

void pop(struct node **h)
{
	struct node *p;
	if(h==NULL)
		cout<<"Cannot delete."<<endl;
	else{
		p=*h;
		*h=p->next;
		free(p);
	}
}

void Display(struct node *p){
	while(p!=NULL){
		cout<<p->data<<" ";
			p=p->next;
	}
	cout<<endl;
}

int main(){
	struct node *head=NULL, *p;
	int y=1, choice, num;
	do{
		cout<<"Please choose the next step: "<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Please enter a data you want to push: ";
				cin>>num;
				Push(&head, num);
				p=head;
				break;
			case 2:
				pop(&head);
				break;
			case 3:
				Display(head);
				break;
			case 4:
				y=0;
				break;
			default:
				cout<<"Error input."<<endl;
				break;
		}
	}while(y);
	return 0;
}
