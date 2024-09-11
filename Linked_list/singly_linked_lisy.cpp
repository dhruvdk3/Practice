#include <bits/stdc++.h>

// ---------------------------------- Singly linked list ------------------------------

class Node{
    public:
    int data;
    Node *next;
    Node (int data){
        this ->data = data;
        this ->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};

void insert_at_head(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insert_at_tail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void printlist(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void insert_middle(Node* & head, Node* &tail, int data, int pos){
    if (pos == 1){
        insert_at_head(head, data);
        return;
    }
    Node* temp = head;
    int i = 1;
    while(i<pos-1){
        temp = temp->next;
        i++;
    }
    if (temp->next == NULL) {
        insert_at_tail(tail, data);
        return;
    }
    Node* nodetoinsert = new Node(data);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}

void delete_head(Node* &head){
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}


void delete_node(Node* &head, Node* &tail, int pos){
    if (pos == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    else{
        Node* curr = head;
        Node* prev = NULL;
        int i = 1;
        while(i<pos){
            prev = curr;
            curr = curr->next;
            i++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        if (prev->next == NULL) tail = prev;
        delete curr;

    }
}


int main(int argc, char const *argv[])
{
    // --------- singly linked list ----------------
    Node* newnode = new Node(10);
    Node* head = newnode;
    Node* tail = newnode;
    insert_at_tail(tail, 11);
    insert_at_head(head, 9);
    insert_at_head(head, 8);
    insert_at_tail(tail, 12);
    insert_at_head(head, 7);
    insert_middle(head, tail, 69, 3);
    delete_node(head, tail, 6);
    insert_at_tail(tail, 12);
    printlist(head);
    return 0;
}
