#include<iostream>
using namespace std;
#define CAPACITY 5
void display();
void peek();
void push();
void pop();
int top=-1,p,i,stack[CAPACITY],e,choice;

int main()
{
cout<<"\n1.Insert (push) an element into stack:\n";
cout<<"2.Pop an element from stack\n";
cout<<"3.Display all elements:\n";
cout<<"4.Peek\n";
cout<<"5.exit\n";
while(1)
	{
	cout<<"\nEnter your choice:";
	cin>>choice;

	switch(choice)
		{
		case 1:
		push();
		break;
		case 2:
		pop();
		break;
		case 3:
		display();
		break;
		case 4:
		peek();
		break;
		case 5: exit(1);
		break;
		default: cout<<"\nWrong choice\n";
		}
	}
return 0;
}
 //........................PUSH................................................
 void push()
 {
  int element;
 if(top==CAPACITY-1)
 {
  cout<<"\nStack is overflowed\n";
 }
 else
 {
  cout<<"Enter number to Push: ";
  cin>>element;
 top++;
 stack[top]=element;
 }
 }
 //...............................POP.......................................................
 void pop()
 {
 int data=0;
 if(top==-1)
 {
 cout<<"Stack is Empty";
 }
 else
 {
  data=stack[top];
 top--;
 cout<<data<<" Deleted";
}
 //return top;

 }
 //.......................................DISPLAY..............................
 void display()
 {
 if(top==-1)
 {
 cout<<"\nStack is emepty\n";
 }

 else
 {
 cout<<"\nElement are:\n";

 for(i=0;i<=top;i++)
 {
 cout<<stack[i]<<" ";
 }
 }
 }
 //...............................PEEK.......................................
 void  peek()
 {
 if(top==-1)
 {
 return ;
 }
 else
 {
 cout<<stack[top];
 }
 }

