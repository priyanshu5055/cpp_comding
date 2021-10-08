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
class node{
public:
    int data;
    node *left;
    node *right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

node * rt = NULL;
bool searchNode(node *root, int value){
    node *tmp = root;
    if (tmp == NULL){
        return false;
    }
    if (tmp->data == value){
        rt = tmp;
        return true;
    }
    bool is_left = searchNode(tmp->left, value);
    if (is_left)
        return true;

    bool is_right = searchNode(tmp->right, value);
    if (is_right)
        return true;

    return false;
}

void insertNode(node *root, int ro, int le, int ri){
    bool v = searchNode(root, ro);
    bool l = searchNode(root,le);
    bool r = searchNode(root,ri);
    if (v == true){
        if (l && le!=0){
            cout << "Left node is already a child node" << endl;
            exit(0);
        }
        else if (r && ri!=0){
            cout << "Right node is already a child node" << endl;
            exit(0);
        }
        else{
            if(ri!=0){
                rt->right = new node(ri);
            }
            if(le!=0){
                rt->left = new node(le);
            }
        }
    }
}

void inorder(node*root){if(root==NULL){
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

void postorder(node*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    int nodenum;
    cin >> nodenum;

    int rootval, leftval, rightval;
    cin >> rootval >> leftval >> rightval;

    node *root = new node(rootval);
    root->left = new node(leftval);
    root->right = new node(rightval);
    if (rootval == leftval || rightval == rootval){
        cout << "Tree can not contain loop";
        exit(0);
    }
    
    for (int i = 1; i < nodenum; i++){
        cin >> rootval >> leftval >> rightval;
        if (leftval == 0 && rightval == 0){
            continue;
        }
        else if (rootval == leftval || rootval==rightval){
            cout << "Tree can not contain loop";
            exit(0);
        }
        else{
            insertNode(root, rootval, leftval, rightval);
        }
    }

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);

    return 0;
}
