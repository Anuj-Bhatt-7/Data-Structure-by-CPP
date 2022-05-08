#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node* link;
};

struct node* top = NULL;

void push(){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	cout<<"Enter Data: ";
	cin>>temp->data;
	temp->link = top;
	top = temp;
}

void pop(){
	struct node* temp = top;
	if(top == NULL)
	{
		cout<<"Stack is Empty";
	}
	
	else{
		cout<<temp->data<<"deleted";
		top = top->link;
		temp->link = NULL;
		free(temp);
	}
}

void printStack(){
	struct node* temp = top;
	if(top == NULL){
		cout<<"Stack is Empty";
	}
	else{
		while(temp != NULL){
			cout<<temp->data<<" ";
			temp = temp->link;
		}
	}
}

void peak(){
	struct node* temp = top;
	if(temp == NULL){
		cout<<"Stack is empty";
		
	}
	else{
		cout<<" Peak is: %d ", temp->data;
	}
}

void length(){
	struct node* temp = top;
	int count=0;
	while(temp != NULL){
		count++;
		temp = temp->link;
	}
	cout<<"Length of stack: %d ", count;
}

int main(){
	int choice;

	cout<<"\n\n\n1. Push Element ";
	cout<<"\n2. Pop Element ";
	cout<<"\n3. Print Stack Elements ";
	cout<<"\n4. Print Peak Element ";
	cout<<"\n5. Print length of stack ";
	cout<<"\n6. Exit ";
	while(1){
	    cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice){
			case 1: 
			   push();
			   break;
			case 2:
				pop();
				break;
			case 3:
				printStack();
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
				cout<<"Invalid option";
		}
	}
	return 0;
}
