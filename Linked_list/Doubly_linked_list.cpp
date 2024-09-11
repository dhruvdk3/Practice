#include <bits/stdc++.h>

class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node (int data){
        this ->data = data;
        this ->next = NULL;
        this ->prev = NULL;
    }

};

void insert_at_head(Node* &head, Node* &tail, int d){
    if (head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    Node* temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insert_at_tail(Node* &tail, Node* &head, int d){
    if(tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void printlist(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" "<< temp->next<<" "<<temp->prev<<" "<<temp<<endl;
        temp = temp->next;
    }
}

void insert_middle(Node* & head, Node* &tail, int data, int pos){
    if (pos == 1){
        insert_at_head(head, tail, data);
        return;
    }
    Node* temp = head;
    int i = 1;
    while(i<pos-1){
        temp = temp->next;
        i++;
    }
    if (temp->next == NULL) {
        insert_at_tail(tail, head, data);
        return;
    }
    Node* nodetoinsert = new Node(data);
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
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
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }

    else{
        Node* curr = head;
        Node* pr = NULL;
        int i = 1;
        while(i<pos){
            pr = curr;
            curr = curr->next;
            i++;
        }
        if(curr->next != NULL){
            curr->next->prev = pr;
        }
        curr->next = NULL;
        pr->next = curr->next;
        curr->prev = NULL;
        if (pr->next == NULL) {
            tail = pr;
            }
        delete curr;

    }
}


int main(int argc, char const *argv[])
{
    // --------- singly linked list ----------------
    Node* newnode = new Node(10);
    Node* head = newnode;
    Node* tail = newnode;
    insert_at_head(head, tail, 9);
    insert_at_head(head, tail, 8);
    insert_at_tail(tail, head, 12);
    insert_at_tail(tail, head, 13);
    insert_middle(head, tail, 11, 4);
    printlist(head);
    delete_node(head, tail, 6);
    printlist(head);
    return 0;
}

