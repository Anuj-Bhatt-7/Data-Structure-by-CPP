#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;


void displayMaxheap(vector<int> &maxheap){
    for(int i=0;i<maxheap.size();++i){
        cout<<maxheap[i]<<" " ;
    }
    cout<<endl;
    return;
}
void heapify(vector<int> &maxheap,int i){
    int n = maxheap.size();
    int lar = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && maxheap[l]>maxheap[lar]){
        lar = l;
    }
     if(r<n && maxheap[r]>maxheap[lar]){
        lar = r;
    }
    if(lar != i){
        int temp = maxheap[i];
        maxheap[i] = maxheap[lar];
        maxheap[lar] = temp;
        heapify(maxheap,lar);
    }
}

void insertMax(vector<int> &maxheap,int key){
    int n = maxheap.size();
    if(n == 0){
        maxheap.push_back(key);
    }
    else{
        maxheap.push_back(key);
        for(int i=n-1;i>=0;i--){
            heapify(maxheap,i);
        }
    }
}

void deleteMax(vector <int> &maxheap,int value){
    int n = maxheap.size();
    int i;
    for(i=0;i<n;i++){
        if(value == maxheap[i]){
            break;
        }
    }
    int temp = maxheap[i];
    maxheap[i] = maxheap[n-1];
    maxheap[n-1] = temp;
    maxheap.pop_back();
    for(int i=n-1;i>=0;i--){
        heapify(maxheap,i);
    }
}

int main(){
    vector <int> maxheap;
    int choice;
    do{
        cout<<"1. insert in Max heap"<<endl;
        cout<<"2. delete from the Max heap"<<endl;
        cout<<"3. Display The Max heap"<<endl;
        cout<<"0. For Exit"<<endl;
        cout<<"ENTER THE CHOICE : ";
        cin>>choice;
        switch(choice){
        case 0:
            break;
        case 1:
            int data;
            cout<<"Enter the data to insert: ";
            cin>>data;
            insertMax(maxheap,data);
            cout<<endl;
            break;

        case 2:
            int value;
            cout<<"Enter the value to delete: ";
            cin>>value;
            deleteMax(maxheap,value);
            cout<<endl;
            break;

        case 3:
            displayMaxheap(maxheap);
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

