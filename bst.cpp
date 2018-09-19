#include <iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* newNode(int data){
    node* temp=new node();
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

int checkThesum(node* root,int path[],int i,int sum){
    int sum1=0,x,j;
    if(root==NULL)
    return 0;
    path[i]=root->data;
    if(root->left==NULL&&root->right==NULL){
        for(j=0;j<=i;j++)
        sum1+=path[j];
        if(sum==sum1)
        return 1;
        else
        return 0;
    }
    x=checkThesum(root->left,path,i+1,sum);
    if(x==1)
    return 1;
    else
    return checkThesum(root->right,path,i+1,sum);
}

int main(){
    int path[100],sum=164;
    node* root=NULL;
    root=newNode(45);
    root->left=newNode(38);
    root->right=newNode(50);
    root->left->left=newNode(33);
    root->left->right=newNode(41);
    root->left->left->left=newNode(31);
    root->left->left->right=newNode(35);
    root->left->right->left=newNode(40);
    root->left->right->right=newNode(44);
    root->right->left=newNode(47);
    root->right->right=newNode(52);
    root->right->left->left=newNode(46);
    root->right->left->right=newNode(48);
    //root->right->right=newNode(52);
    root->right->right->left=newNode(51);
    root->right->right->right=newNode(55);
    if(checkThesum(root,path,0,sum)==1)
    cout<<"YES YOU HAVE DONE IT"<<endl;
    else
    cout<<"NO "<<endl;
}

/*int main()
{
    node* root=NULL;
    root=newNode(45);
    root->left=newNode(38);
    root->left->left=newNode(33);
    root->left->right=newNode(41);
    root->left->left->left=newNode(31);
    root->left->left->right=newNode(35);
    root->left->right->left=newNode(40);
    root->left->right->right=newNode(44);
    
}*/
