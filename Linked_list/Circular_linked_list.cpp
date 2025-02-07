#include <bits/stdc++.h>

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
    }
};


void insert_node(Node* &tail, int element, int value){
    if (tail == NULL){
        Node* temp = new Node(value);
        tail = temp;
        temp->next = temp;
    }
    else{
        Node* temp = tail;
        while(true){
            if(temp == tail) break;
            if (temp->next->data <= element) temp = temp->next;
            else break;
        }
        Node* newnode = new Node(value);
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void print(Node* &tail){
    Node* temp = tail;
    while(true){
        cout<<temp->data<<" ";
        temp = temp->next;
        if (temp == tail) return;
    }
}

void delete_node(Node* &tail, int value){
    if (tail == NULL) return;
    Node* prev = tail;
    Node* curr = tail->next;
    while(curr->data != value){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    if(curr == prev) tail = NULL;
    if (tail == curr) tail = prev; 
    curr->next = NULL;

    delete curr;
    
}

int main(int argc, char const *argv[])
{
    Node* tail = NULL;
    insert_node(tail, 0, 5);
    insert_node(tail, 5, 7);
    insert_node(tail, 5, 6);
    insert_node(tail, 5, 5);
    print(tail);
    cout<<endl;
    delete_node(tail, 7);
    delete_node(tail, 5);
    delete_node(tail, 5);
    print(tail);
    return 0;
}
