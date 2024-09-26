#include <bits/stdc++.h>

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void insert(Node*& root, int data){
    if(root == NULL) {
        Node* temp = new Node(data);
        root = temp;
        return;
    }
    if(data <= root->data) insert(root->left, data);
    if(data > root->data) insert(root->right, data);
}

void preorder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    Node* root = new Node(5);
    insert(root, 2);
    insert(root, 12);
    insert(root, 1);
    insert(root, 3);
    insert(root, 9);
    insert(root, 21);
    insert(root, 19);
    insert(root, 25);
    preorder(root);
}