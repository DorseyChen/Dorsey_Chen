#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

void insert(struct node **h, struct node **pre, int d){
	struct node *p=(struct node *)malloc(sizeof(struct node));
	p->data=d;
	if(*h==NULL){
		*pre=p;
		*h=p;
	}
	else{
		p->next=NULL;
		(*pre)->next=p;
		*pre=p;
	}
}

int minimum(struct node *p){
	int key, i=0,min=p->data;
	while(p!=NULL){
		i++;
		if((p->data)<min){
			key=i;
			min=p->data;
		}
		p=p->next;
	}
	return key;
}

void traverse(struct node **h){
	struct node *p=(struct node *)malloc(sizeof(struct node));
	if((*h)->data<0)
		*h=(*h)->next;
	struct node *pred=*h;
	p=*h;
	while(p!=NULL){
		if(p->data<0)
			pred->next=p->next;
		pred=p;
		p=p->next;
	}
}

void display(struct node *p){
	cout<<"Your linked list"<<endl;
	while(p!=NULL){
		cout<<p->data<<" ";
			p=p->next;
	}
	cout<<endl;
}

int main(){
	int d, key;
	struct node *head=NULL,*pre=NULL;
	while(cin>>d)
		insert(&head, &pre, d);
	display(head);
	key=minimum(head);
	cout<<"The minimum key value is: "<<key<<endl;
	traverse(&head);
	display(head);
	return 0;
}
