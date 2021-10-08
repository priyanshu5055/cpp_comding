/*
    PRIYANSHU IS A PEACEFULL SOUL
*/
#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii> 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ll long long
#define ss second
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node*inorderSucc(node*root){
    node*curr=root;
    while (curr&&curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}
node* minValue(node* root){
    node* temp = root;
    while(temp && temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

bool ifNodeExists(struct node* node, int key)
{
    if (node == NULL)
        return false;
 
    if (node->data == key)
        return true;

    bool res1 = ifNodeExists(node->left, key);
    if(res1) return true;
 
    bool res2 = ifNodeExists(node->right, key);
 
    return res2;
}

node* deleteBST(node* root,int x){
    if(root==NULL){
        return root;
    }
    if(ifNodeExists(root, x)){
        
    if(x<root->data){
        root->left=deleteBST(root->left,x);
    }else if(x>root->data){
        root->right=deleteBST(root->right,x);
    }else{
        if(root->left==NULL && root->right==NULL){
            return NULL;
        }else if(root->left==NULL){
            node* temp=root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            node* temp=root->left;
            free(root);
            return temp;
        }
        node* temp=minValue(root->right);
        root->data=temp->data;
        root->right=deleteBST(root->right,temp->data);
    }
    return root;
    }else{
        cout<<"Node "<<x<<" is not found in the tree";
        exit(0);
    }
}

node* insertBST(node*root,int val){
    if(root==NULL){
        return new node(val);
    }
    if(val<root->data){
        root->left=insertBST(root->left,val);
    }else{
        root->right=insertBST(root->right,val);
    }
    return root;
}
void inorder(node*root){
    if(root==NULL){
        return;

    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node*root){
    if(root==NULL){
        return;

    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    node *root = NULL;
    int n;cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    root=insertBST(root,arr[0]);
    for (int i = 1; i < n; i++)
    {
        insertBST(root,arr[i]);
    }
    int m;cin>>m;
    int arr2[m];
    for (int i = 0; i < m; i++)
    {
        cin>>arr2[i];
    }
    
    root=deleteBST(root,arr2[0]);
    for (int i = 1; i < m; i++)
    {
        deleteBST(root,arr2[i]);
    }
    
    
    inorder(root);
    cout<<endl;
    preorder(root);
      

    return 0;
}
