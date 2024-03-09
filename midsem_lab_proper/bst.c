#include<stdio.h>
#include<stdlib.h>

struct Nodeptr{
    int data;
    struct Nodeptr* lchild;
    struct Nodeptr* rchild;

};

struct Nodeptr* create(int ele){
    struct Nodeptr* newn=(struct Nodeptr *)malloc(sizeof(struct Nodeptr));

    newn->data=ele;
    newn->lchild=NULL;
    newn->rchild=NULL;

    return newn;
}

struct Nodeptr* createBst(struct Nodeptr* root,int ele){
    if(root==NULL){
        root=create(ele);
    }

    else if(ele<root->data){
        root->lchild=createBst(root->lchild,ele);
    }

    else if(ele>root->data){
        root->rchild=createBst(root->rchild,ele);
    }

    else{
        printf("Duplicate Values Not Allowed !");
    }

    return root;
}

int search (struct Nodeptr* root,int ele){
    if(root==NULL){
        return 0;
    }

    else if(root->data==ele){
        return 1;
    }

    else if(root->data>ele){
        return search(root->lchild,ele);
    }

    else if(root->data<ele){
        return search(root->rchild,ele);
    }

}

void inorder(struct Nodeptr* root){
    if(root!=NULL){
        inorder(root->lchild);
        printf("%d ",root->data);
        inorder (root->rchild);
    }
}

void main(){
    struct Nodeptr* root= create(50);
    createBst(root,45);
    createBst(root,72);
    createBst(root,32);
    createBst(root,52);
    createBst(root,24);

    int found = search(root, 24);
    if (found) {
        printf("Node found!\n");
    } else {
        printf("Node not found!\n");
    }

    inorder(root);
}
