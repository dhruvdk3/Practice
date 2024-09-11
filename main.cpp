#include <bits/stdc++.h>


class Stack{
    public:
    int* arr;
    int top;
    int size;
    Stack(int size){
        this->size = size;
        arr = new int[size];
        this->top = 0;
    }

    void push(int data){
        if(top<size){
            arr[top++] = data;
        }
        else cout<<"Stack over flow"<<endl;
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else cout<<"stack underflow"<<endl;

    }
    void peek(){
        if(top>1){
            cout<<arr[top-1];
        }
    }

    bool empty(){
        if(top == 0) return true;
        return false;
    }

};

int main(int argc, char const *argv[])
{
    Stack s(3);
    s.push(1);
    s.push(3);
    s.push(4);
    s.pop();
    s.peek();

    return 0;
}
