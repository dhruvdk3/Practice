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


Node* build_tree(Node* root){
    cout<<"Enter data : ";
    int data;
    cin>>data;
    if(data == -1) return NULL;
    root = new Node(data);

    cout<<"left of "<< data<<" : ";
    root->left =  build_tree(root->left);
    
    cout<<"right "<<data<<" : ";
    root->right =  build_tree(root->right);
    return root;
}




void level_order_traversal(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == nullptr) {
            cout << endl;
            if (!q.empty()) q.push(nullptr);
        } else {
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
}


void reverse_level_order_traversal(Node* root){
    stack<Node*>s;
    queue<Node*>q;
    
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp){
            s.push(temp);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        else{
            s.push(NULL);
            if(!q.empty()) q.push(NULL);
        }
    }
    while(!s.empty()){
        Node* topNode = s.top();
        s.pop();
        if(!topNode) cout<<endl;
        else cout<<topNode->data<<" ";
    }

}


void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}


void inorder_iteration(Node* root){
    stack<Node*>s;
    Node* temp = root;
    while(temp!= NULL || !s.empty()){
        while(temp!=NULL){
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();
        cout<<temp->data<<" ";
        temp = temp->right;
    }
}

void preorder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


// void preorder_iteration(Node* root){
//     stack<Node*>s;
//     Node* temp = root;
//     s.push(root);
//     while(temp!= NULL || !s.empty()){
//         cout<<temp->data<<" ";
//         while(temp!=NULL){
//             s.push(temp);
//             temp = temp->left;
//         }
//         temp = s.top();
//         s.pop();
//         temp = temp->right;
//     }
// }


void preorder_iteration(Node* root) {
    if (root == nullptr) return;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* temp = s.top();
        s.pop();
        cout << temp->data << " ";
        if (temp->right) {
            s.push(temp->right);
        }
        if (temp->left) {
            s.push(temp->left);
        }
    }
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void postorder_iteration(Node* root){
    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node* node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}



void build_tree_from_level_order(Node*& root){
    queue<Node*> q;
    cout<<"Enter data : ";
    int x;
    cin>>x;
    root = new Node(x);
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<"Enter left data for : "<<temp->data<<endl;
        int datal;
        cin>>datal;
        if(datal!=-1) {
            temp->left = new Node(datal);
            q.push(temp->left);
        }

        cout<<"Enter Right data for : "<<temp->data<<endl;
        int datar;
        cin>>datar;
        if(datar!=-1) {
            temp->right = new Node(datar);
            q.push(temp->right);
        }
    }
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
//          1 
//      3      5 
//    7  11  17 
int main(int argc, char const *argv[])
{
    Node* root = NULL;
    // root = build_tree(root);
    build_tree_from_level_order(root);
    level_order_traversal(root);

    // level_order_traversal(root);
    // cout<<endl;
    // // reverse_level_order_traversal(root);
    // inorder(root);
    // cout<<endl;
    // inorder_iteration(root);
    // cout<<endl;
    // preorder(root);
    // cout<<endl;
    // preorder_iteration(root);
    // cout<<endl;
    // postorder(root);
    // cout<<endl;
    // postorder_iteration(root);
    return 0;
}
