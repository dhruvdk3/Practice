#include<bits/stdc++.h>


class Heap{
    public:
        int arr[100];
        int size = 0;


        void insert(int data){
            size++;
            int index = size;
            arr[index] = data;
            while(index > 1){
                int parent = index/2;
                if(arr[parent]<arr[index]){
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else return;
            }
        }



        void deletion(){
            if(size == 0) {
                cout<<"Nothing to delete";
                return;
            }
            arr[1] = arr[size--];
            int i = 1;
            while(i<size){
                int leftInd = 2*i;
                int righttInd = 2*i+1;
                if(leftInd <size && arr[i]<arr[leftInd]) {
                    swap(arr[leftInd], arr[i]);
                    i = leftInd;
                }
                else if(righttInd <size && arr[i]<arr[righttInd]){
                    swap(arr[righttInd], arr[i]);
                    i = righttInd;
                }
                else return;
            }
        }




        void print(){
            for(int i = 1; i<=size; i++) cout<<arr[i]<<" ";
            cout<<endl;
        }
};

int main(int argc, char const *argv[]){
    Heap p;
    p.insert(60);
    p.insert(50);
    p.insert(40);
    p.insert(30);
    p.insert(20);
    p.print();
    p.deletion();
    p.print();
    return 0;
}
