#include<stdio.h>
#include<stdlib.h>

struct Nodeptr{
    int data;
    struct Nodeptr* lchild;
    struct Nodeptr* rchild;
};

struct Nodeptr* create(int ele ){
    struct Nodeptr* newn=(struct Nodeptr*)malloc(sizeof(struct Nodeptr));

    newn->data=ele;
    newn->lchild=NULL;
    newn->rchild=NULL;

    return newn;

}

struct Nodeptr* create_bst(struct Nodeptr* root,int ele){
    if(root==NULL){
        root=create(ele);
    }
    else if(root->data>ele){
        root->lchild=create_bst(root->lchild,ele);
    }
    else if(root->data<ele){
        root->rchild=create_bst(root->rchild,ele);
    }
    else{
        printf("Duplicate values not allowed!");
    }

    return root;
}

void inorder(struct Nodeptr* root){
    if(root!=NULL){
      inorder(root->lchild);
      printf("%d ",root->data);
      inorder(root->rchild);  
    }
}

void insert(struct Nodeptr* root,int ele){
    struct Nodeptr* temp=create(ele);

    if(root==NULL){
        root=temp;
        return;
    }
    
    struct Nodeptr* parent = NULL;
    struct Nodeptr* cur = root;

    while(cur){
        parent=cur;
        if(cur->data==ele){
            printf("Duplicates Not allowed!");
            free(temp);
            return;
        }
        else if(cur->data>ele){
            cur=cur->lchild;
        }
        else{
            cur=cur->rchild;
        }
    }

    if(ele<parent->data){
        parent->lchild=temp;
    }
    else{
        parent->rchild=temp;
    }

}

int search(struct Nodeptr* root, int ele) {
    if (root == NULL) {
        return 0;
    } else if (root->data == ele) {
        return 1;
    } else if (root->data > ele) {
        return search(root->lchild, ele);
    } else {
        return search(root->rchild, ele);
    }
}

void main() {
    struct Nodeptr* root=create(56);
    create_bst(root,45);
    create_bst(root,72);
    create_bst(root,32);
    create_bst(root,52);
    insert(root,24);

    int found = search(root, 24);
    if (found) {
        printf("Node found!\n");
    } else {
        printf("Node not found!\n");
    }

    inorder(root);
}