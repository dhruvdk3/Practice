#include<bits/stdc++.h>


class kQueue{
    public:
        int n;
        int k;
        int* rear;
        int* front;
        int* arr;
        int freespot;
        int* next;

        kQueue(int n, int k){
            this->n = n;
            this->k = k;
            rear = new int[k];
            front = new int[k];
            next = new int[n];
            arr = new int[n];
            freespot = 0;

            fill(rear, rear+k, -1);
            fill(front, front+k, -1);
            for(int i = 0; i<n; i++) next[i] = i+1;
            next[n-1] = -1;
        }

        void enqueue(int data, int qn){
            if(freespot == -1) {
                cout<<"No empty space is present"<<endl;
                return;
            }

            int index = freespot;
            freespot = next[index];
            if(front[qn-1] == -1){
                front[qn-1] = index;
            }
            else{
                next[rear[qn-1]] = index;
            }
            next[index] = -1;
            rear[qn-1] = index;
            arr[index] = data;
        }


        int dequeue(int qn){
            if(front[qn-1] == -1) {
                cout<<"No element present. Queue under flow"<<endl;
                return -1;
            }

            int index = front[qn-1];
            front[qn-1] = next[index];
            next[index] = freespot;
            freespot = index;
            return arr[index];
        }

};

int main(int argc, char const *argv[])
{
    kQueue q(5,3);
    q.enqueue(5,3);
    q.enqueue(4,2);
    q.enqueue(3,3);
    q.enqueue(2,1);
    q.enqueue(1,1);
    cout<<q.dequeue(3)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(3)<<endl;
    cout<<q.dequeue(1)<<endl;
    return 0;
}