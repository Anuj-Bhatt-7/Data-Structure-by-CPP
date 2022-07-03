
#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;


void displayMinheap(vector<int> &minHeap){
    for(int i=0;i<minHeap.size();++i){
        cout<<minHeap[i]<<" " ;
    }
    cout<<endl;
    return;
}
void heapify(vector<int> &minHeap,int i){
    int n = minHeap.size();
    int small = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && minHeap[left]<minHeap[small]){
        small = left;
    }
     if(right<n && minHeap[right]<minHeap[small]){
        small = right;
    }
    if(small != i){
        int temp = minHeap[i];
        minHeap[i] = minHeap[small];
        minHeap[small] = temp;
        heapify(minHeap,small);
    }
}

void insertMin(vector<int> &minHeap,int key){
    int n = minHeap.size();
    if(n == 0){
        minHeap.push_back(key);
    }
    else{
        minHeap.push_back(key);
        for(int i=n-1;i>=0;i--){
            heapify(minHeap,i);
        }
    }
}

void deleteMin(vector <int> &minHeap,int value){
    int n = minHeap.size();
    int i;
    int flag = 0;
    for(i=0;i<n;i++){
        if(value == minHeap[i]){
            flag++;
            break;
        }
    }
    if(flag==0){
        cout<<value<<" is not present in heap!"<<endl;
        return;
    }
    int temp = minHeap[i];
    minHeap[i] = minHeap[n-1];
    minHeap[n-1] = temp;
    minHeap.pop_back();
    for(int i=n-1;i>=0;i--){
        heapify(minHeap,i);
    }
}

int main(){
    vector <int> minHeap;

    int choice;
    do{
        cout<<"1. insert in Min heap"<<endl;
        cout<<"2. delete from the Min heap"<<endl;
        cout<<"3. Display The Min heap"<<endl;
        cout<<"0. For Exit"<<endl;
        cout<<"ENTER THE CHOICE : ";
        cin>>choice;
        switch(choice){
        case 0:
            break;
        case 1:
            int data;
            cout<<"Enter the data: ";
            cin>>data;
            insertMin(minHeap,data);
            cout<<endl;
            break;

        case 2:
            int value;
            cout<<"Enter the value: ";
            cin>>value;
            deleteMin(minHeap,value);
            cout<<endl;
            break;

        case 3:
            displayMinheap(minHeap);
            cout<<endl;
            break;

        default:
            cout<<"Invalid Input"<<endl;
            cout<<endl;
            break;
        }
    }while(choice!=0);
    return 0;
}

