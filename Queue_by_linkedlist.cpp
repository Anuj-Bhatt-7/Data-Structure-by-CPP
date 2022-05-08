

#include<stdlib.h>
#include<iostream>
using namespace std;

 struct node{

	int data;
	struct node* link;
 };

struct node* front = NULL;
struct node* rare = NULL;

void enqueue(){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter data: ");
	scanf("%d",&temp->data);
	temp->link = NULL;

	if(front == NULL && rare == NULL){
		front = temp;
		rare = temp;
		return;
	}
	
	rare->link = temp;
	rare = temp;
}

void dequeue(){
	struct node* temp = front;
	if(front == NULL && rare == NULL){
		cout<<"\nQueue is empty";
		return;
	}
	if(front == rare)
	{
		cout<<temp->data<<" deleted";
		front = NULL;
		rare = NULL;
		return;
	}
	cout<<temp->data<<" deleted";
	front = front->link;
	temp->link=NULL;
	free(temp);
}



void print(){
	struct node* temp = front;
	if(front == NULL && rare == NULL){
		cout<<"\nQueue is empty.";
	}
	else{
		cout<<"\nQueue elements are:";
		while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->link;
	    }
	}
}

void peak(){
	struct node* temp = front;
	if(front == NULL){
		cout<<"\nQueue is empty";
		
	}
	else{
		cout<<"\nPeak Element is:"<<temp->data;	
	}	
}

void length(){
	struct node* temp = front;
	int count=0;

		while(temp!=NULL){
		count++;
		temp = temp->link;
	   }
	
	cout<<"\nLength of list: "<< count;
}

int main(){
	int opt;
	cout<<"1.Enqueue\n";
	cout<<"2.Dequeue\n";
	cout<<"3.Display Queqe\n";
	cout<<"4.Peak Element\n";
	cout<<"5.Length\n";
	cout<<"6.Exit\n";
	while(1){
		cout<<"\nEnter your choice: ";
		cin>>opt;
		switch(opt){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				print();
				break;
			case 4:
				peak();
				break;
			case 5:
				length();
				break;
			case 6:
				exit(1);
				break;
			default:
				printf("\nWrong choice.");
		}
	}
}
