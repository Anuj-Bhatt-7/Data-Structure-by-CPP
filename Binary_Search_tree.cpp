// Binary Search Tree 

#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};


struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    cout << root->key << " -> ";
    inorder(root->right);
  }
}


struct node *insert(struct node *node, int key) {
  
  if (node == NULL) return newNode(key);

  
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}


struct node *minValueNode(struct node *node) {
  struct node *current = node;

 
  while (current && current->left != NULL)
    current = current->left;

  return current;
}


struct node *deleteNode(struct node *root, int key) {
 
  if (root == NULL) return root;

 
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
   
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

   
    struct node *temp = minValueNode(root->right);

    
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}


int searchNode(struct node *root,int data){
   if (root == NULL){
   	return -1;
   }
   else{
     cout <<"\nEnter data to search ";
  	 cin>>data;
    while (root != NULL) {
       
        if (data> root->key)
            root = root->right;
       
        else if (data < root->key)
            root = root->left;
            
        else
        	return 1;      
    	
    
		}
	}
	return 0;
}

int main() {
  int i,data=0,opt,check;
 
  struct node *root = NULL;
  
  while(1){
	cout<<"\n\n1.Insert Data";
  cout<<"\n2.Inorder Traversal";
  cout<<"\n3.Delete node";
  cout<<"\n4.Search";
  cout<<"\n5. Exit";
  cout<<"\nEnter your choice: ";
  cin>>opt;
  switch(opt){  
  case 1:	
  cout<<"\nEnter data to insert: ";
  cin>>data;
  root = insert(root,data);
  break;
  case 2:
  cout << "Inorder traversal: ";
  inorder(root);
  break;
  case 3:
  root = deleteNode(root, data);
  cout<<"\nAfter deleting: ";
  inorder(root);
  break;
  case 4:
  check = searchNode(root,data);
  if(check == 1)
	 cout<<"\nData Present";
  else if(check == 0)
  	 cout<<"Not present";
  else 
   cout<<"\nTree is Empty";
  break;
  case 5:
  exit(1);	 
  default:
  	cout<<"\nInvalid option";
		}
	}
	return 0;
}
