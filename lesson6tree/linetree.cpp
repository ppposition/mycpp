#include<iostream>
using namespace std;
struct linetree
{
    /* data */
    int val;
    int lazy;
    linetree* left;
    linetree* right;
    int b_left;
    int b_right;
    linetree(int _val,int _left,int _right){
        val=_val;
        lazy=0;
        left=nullptr;
        right=nullptr;
        b_left=_left;
        b_right=_right;
    }
};

linetree* init_tree(int left,int right,int *num){
    if(left==right)
        return new linetree(num[left],left,right);
    int mid=(left+right)/2;
    linetree* ans=new linetree(0,left,right);
    ans->left=init_tree(left,mid,num);
    ans->right=init_tree(mid+1,right,num);
    ans->val=ans->left->val+ans->right->val;
    return ans;
}

inline void lazy_tag(linetree* tree){
    int temp=tree->lazy;
    tree->lazy=0;
    if(tree->left!=nullptr){
        tree->left->lazy+=temp;
        tree->left->val=temp*(tree->left->b_right-tree->left->b_left);
    }
    if(tree->right!=nullptr){
        tree->right->lazy+=temp;
        tree->right->val=temp*(tree->right->b_right-tree->right->b_left);
    }
}
void update(linetree* tree,int left,int right,int k){
    if(tree==nullptr||(left>tree->b_right)||(right<tree->b_left))
        return;
    if(left<=tree->b_left&&right>=tree->b_right){
        tree->lazy+=k;
        tree->val+=k*(tree->b_right-tree->b_left+1);
    }
    else{
        if (tree->lazy!=0)
        {
            lazy_tag(tree);
        }
        update(tree->left,left,right,k);
        update(tree->right,left,right,k);
        tree->val=tree->left->val+tree->right->val;
    }
}
int search(linetree* tree,int left,int right){
    if(tree==nullptr||(left>tree->b_right)||(right<tree->b_left))
        return 0;
    if(left<=tree->b_left&&right>=tree->b_right){
        return tree->val;
    }
    else{
        if(tree->lazy!=0)
            lazy_tag(tree);
        return search(tree->left,left,right)+search(tree->right,left,right);
    }
}
int main(){
    int n;
    cin>>n;
    int *num=new int [n];
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    linetree* tree=init_tree(0,n-1,num);
    cout<<tree->right->val<<endl;
    update(tree,1,5,3);
    update(tree,0,3,2);
    cout<<tree->right->val<<endl;
    cout<<search(tree,0,3);
    return 0;
}