#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* lchild;
    struct node* rchild;
    int height;
};

int height(struct node* temp){
    if(temp==NULL){
        return 0;
    }
    return temp->height;
}

int max(int a,int b){
    return (a>b)?a:b;
}


struct node* newNode(int ele){
    struct node* newn=(struct node*)malloc(sizeof(struct node));

    newn->data=ele;
    newn->rchild=NULL;
    newn->lchild=NULL;
    newn->height=1;

    return newn;
}

struct node* rightRotate(struct node* y){
    struct node* x=y->lchild;
    struct node* T2=x->rchild;

    x->rchild=y;
    y->lchild=T2;

    y->height=max(height(y->lchild),height(y->rchild))+1;
    x->height=max(height(x->lchild),height(x->rchild))+1;

    return x;
}

struct node *leftRotate(struct node*x){
    struct node *y = x->rchild;
    struct node *T2 = y->lchild;

    y->lchild=x;
    x->rchild=T2;

    x->height=max(height(x->lchild),height(x->rchild))+1;
    y->height=max(height(y->lchild),height(y->rchild))+1;

    return y;
}
int getBalance(struct node* temp){
    if(temp==NULL)
        return 0;
    
    return height(temp->lchild)-height(temp->rchild);
}

struct node* insert(struct node* temp,int ele){
    if(temp==NULL)
        return temp->data;
    
    if(ele<temp->data)
        temp->lchild=insert(temp->rchild,ele);

    else if(ele>temp->data)
        temp->rchild=insert(temp->lchild,ele);
    
    else
        return temp;
    
    temp->height=1+max(height(temp->lchild),height(temp->rchild));

    int balance=getBalance(temp);

    if(balance>1 && ele<temp->lchild->data)
            return rightRotate(temp);
    if(balance<-1 && ele>temp->rchild->data)
            return leftRotate(temp);
    
    if(balance>1 && ele<temp->lchild->data){
        temp->lchild=leftRotate(temp->lchild);
        return rightRotate(temp);
    }

    if(balance<-1 && ele>temp->rchild->data){
        temp->rchild=rightRotate(temp->rchild);
        return leftRotate(temp);
    }

    return temp;

}

void preOrder(struct node *root) 
{ 
    if(root != NULL) 
    { 
        printf("%d ", root->data); 
        preOrder(root->lchild); 
        preOrder(root->rchild); 
    } 
} 

int main() 
{ 
  struct node *root = NULL; 

  root = insert(root, 10); 
  root = insert(root, 20); 
  root = insert(root, 30); 
  root = insert(root, 40); 
  root = insert(root, 50); 
  root = insert(root, 25); 
  
  /* The constructed AVL Tree would be 
            30 
           /  \ 
         20   40 
        /  \     \ 
       10  25    50 
  */
  
  printf("Preorder traversal of the constructed AVL"
         " tree is \n"); 
  preOrder(root); 
  
  return 0; 
} 

