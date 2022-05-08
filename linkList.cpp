// Linked List and Insertion at tail
#include<stdlib.h>
#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* link;
};

struct node *root = NULL;

void addAtEnd(){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	cout<<("Enter data: ");
	cin>>temp->data;
	temp->link = NULL;
	if(root == NULL ){	
	root = temp;
    
 }
	else{
		struct node* p;
		p = root;
		while(p->link != NULL){
			p = p->link;
		}
		p->link = temp;
	
		
	}
	
	
}

void printList(){
	
	struct node* p;
	p = root;
	while(p!=NULL){
	
		cout<<"%d ",p->data;
	 	p = p->link;
	}
	
}

void addAtBeg(){
 	
struct node* temp = (struct node*)malloc(sizeof(struct node));
cout<<"Enter Data: ";
cin>> temp->data;
temp->link = root;
root = temp;
	
}

 int search(){
	int item,count=0;
	struct node* p = root;
	cout<<"Enter data to seach: ";
	cin>>item;
	while(p->link!=NULL)
	{   count++;
		
		if(p->data==item){
		return count;
	    }
	     p= p->link;
	}
		
	    cout<<"Data not present";
	
}

void addAtLoc(){
	int loc,i=1;
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	struct node* p = root;
	cout<<"Enter data: ";
	cin>>temp->data;
	cout<<("Enter location : ");
	cin>>loc;
	if(loc==i){
		temp->link = p;
		root= temp;
		
	}
	else{
	
    while((i<(loc-1))&&(p->link != NULL)){
    	p =p->link;
    	i++;
    	}
    if(i<(loc-1))
	cout<<"Invalid location";
	else
	{
	temp->link= p->link;
	p->link= temp;
    }
  }
}

void modify(){
	int newData, loc,count=0;
	struct node *p = root;
	cout<<"Enter updated data:";
	cin>>newData;
	
	cout<<("Enter location where data is to update: ");
	cin>>loc;
	
	while(p!=NULL)
	{
		count++;
		if(count==(loc))
		p->data = newData;
		p=p->link;
	}
	if(count<loc)
	cout<<("Invalid location");
	
}

void delNode(){
	int loc,i=2;
	struct node* p = root;
	struct node* q ;
	cout<<("Enter node location to delete: ");
	cin>>loc;
	if(loc== 1){
	 cout<<("%d data deleted",p->data);
	 root = p->link;
	 free(p);	
	}
	else{
		while(i<=loc){

		p = p->link;
		q = p->link;
		 }
		 cout<<("%d deleted",q->data);
		p->link = q->link;
		free(q);
	}
	if(i<(loc-1))
	cout<<("Invalid Data location");
}


int main(){
	int choice;
	cout<<"\n1. Add at begining ";
     cout<<"\n2. PrintList ";
     cout<<"\n3. Add at tail ";
     cout<<"\n4. Add at particular location ";
     cout<<"\n5. Search ";
     cout<<"\n6. Modify ";
     cout<<"\n7. Delete ";
     cout<<"\n8. Exit ";
	cout<<"\nEnter your choice: ";
	cin>>choice;
	while(1){
	 
	 switch(choice){
	 	case 1: 
	 		addAtBeg(); 
	 	break;
	 	case 2:
	 		printList();
	 	break;
	 	case 3:
	 		addAtEnd();
	 	break;
	 	case 4:
	 		addAtLoc();
	 		break;
	 	case 5:
	 		cout<<"\nData present at: %d location",search();
	 	break;
	 	case 6:
		    modify();
		break;
		case 7:
			delNode();
			break;	
	 	case 8:
	 		exit(0);
	 	break;

	 	default:cout<<"Wrong choice";
	 		
	 }
		}
	
	
return 0;	
}
