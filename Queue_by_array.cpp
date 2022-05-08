#include<iostream>
#define CAPACITY 5
using namespace std;

void peak(int);
int enqueue(int ,int);
int dequeue(int,int);
void display(int, int);
int queqe[CAPACITY],i,choice;
int main()
{

int rare=0,front=0;

cout<<"1.Enqueue\n";
cout<<"2.Dequeue\n";
cout<<"3.Display Queqe\n";
cout<<"4.Peak Element\n";
cout<<"5.Exit\n";
while(1)
{
cout<<"\nEnter your choice: ";
cin>>choice;
switch(choice)
{
case 1:
rare=enqueue(front,rare);
break;
case 2:
rare=dequeue(front,rare);
break;
case 3:
display(front,rare);
break;
case 4:
	peak(front);
	break;
case 5:
exit(1);
break;
default:
cout<<"Wrong choice\n";
}
}
return 0;
}



//...................................enqueue ...............................................

int enqueue(int front,int rare)
{
if(rare==CAPACITY)
{
cout<<"Queqe is full\n";
}
else
  {
cout<<"Enter element to enqueue: ";
cin>>queqe[rare];
rare++;
  }
  return rare;
}

//................................dequeueETE..........................................

int dequeue(int front,int rare)
{
if(front==rare)
    {
cout<<"Queqe is Empty";
    }
else
  {
cout<<queqe[front]<<" deleted";
for(i=0;i<rare-1;i++)
    {
queqe[i]=queqe[i+1];
    }
}
   return rare-1;
}

     //...............................DISPLAY..............................................

     void display(int front,int rare)
     {
     if(front==rare)
		{
     cout<<"Queue is empty";
		}
     else
      {
     for(i=front;i<rare;i++)
	{
     cout<<queqe[i]<<" ";
	}
       }
     }
     
     //...............................Peak...........................
     
     void peak(int front){
     	if(front==rare)
    	{
		cout<<"Queqe is Empty";
    	}
    	else
     	cout<<"Peak element is :"<<queqe[front];
	 }
