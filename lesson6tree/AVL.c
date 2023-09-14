#include<stdio.h>
#include<malloc.h>
typedef struct AVL *Tree;
struct AVL
{
    int element;
    Tree left;
    Tree right;
    int height;
};

int Max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}
int height(Tree temp){
    if(temp==NULL)
        return -1;
    else
        return temp->height;
}

Tree SingleRotateWithLeft(Tree tree){
    Tree temp;
    temp=tree->left;
    tree->left=temp->right;
    temp->right=tree;
    tree->height=Max(height(tree->left),height(tree->right))+1;
    temp->height=Max(height(temp->left),height(temp->right))+1;
    return temp;
}
Tree SingleRotateWithRight(Tree tree){
    Tree temp;
    temp=tree->right;
    tree->right=temp->left;
    temp->left=tree;
    tree->height=Max(height(tree->left),height(tree->right))+1;
    temp->height=Max(height(temp->left),height(temp->right))+1;
    return temp;
}
Tree DoubleRotateWithLeft(Tree tree){
    Tree temp=SingleRotateWithRight(tree->left);
    return SingleRotateWithLeft(temp);
}
Tree DoubleRotateWithRight(Tree tree){
    Tree temp=SingleRotateWithLeft(tree->right);
    return SingleRotateWithRight(temp);
}
Tree insert(int x, Tree T){
    if(T==NULL){
        T=(struct AVL *)malloc(sizeof(struct AVL));
        if(T==NULL){
            printf("out of space");
            return NULL;
        }
        else{
            T->element=x;
            T->left=NULL;
            T->right=NULL;
            T->height=0;
        }
    }
    else if(x<T->element){
        T->left=insert(x,T->left);
        if(height(T->left)-height(T->right)==2){
            if(x<T->left->element)
                T=SingleRotateWithLeft(T);
            else
                T=DoubleRotateWithLeft(T);
        }
    }
    else if(x>T->element){
        T->right=insert(x,T->right);
        if(height(T->right)-height(T->left)==2){
            if(x>T->right->element)
                T=SingleRotateWithRight(T);
            else
                T=DoubleRotateWithRight(T);
        }
    }
    T->height = Max(height(T->left),height(T->right))+1;
    return T;
}
void mid(Tree tree){
    if(tree==NULL){
        return;
    }
    printf("%d",tree->element);
    mid(tree->left);
    mid(tree->right);
}
int main(){
    struct AVL *AVLtree;
    AVLtree=NULL;
    int array[]={2,1,4,5,9,3,6,7};
    for(int i=0;i<8;i++){
        AVLtree=insert(array[i],AVLtree);
        mid(AVLtree);
        printf("\n");
    }
    return 0;
}