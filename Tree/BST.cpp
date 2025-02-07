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

Node* minval(Node* root){
    while (root->left != NULL) root = root->left;
    return root;
}



Node* maxval(Node* root){
    while (root->right != NULL) root = root->right;
    return root;
}


Node* deleteNode(Node*& root, int val){
    if (root == NULL) return root;
    if(root->data == val){
        // 0 child 
        if(root->right == NULL && root->left == NULL){
            delete root;
            return NULL;
        }

        // 1 child 
        if(root->right == NULL && root->left != NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->right != NULL && root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 CHILD 
        if(root->right != NULL && root->left != NULL){
            int mini = minval(root->right)->data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }
    else if(root->data > val){
        root->left = deleteNode(root->left, val);
        return root;
    }
    else {
        root->right = deleteNode(root->right, val);
        return root;
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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
    cout<<endl;
    inorder(root);
    deleteNode(root, 9);
    cout<<endl;
    inorder(root);
    cout<<endl;
    preorder(root);
}