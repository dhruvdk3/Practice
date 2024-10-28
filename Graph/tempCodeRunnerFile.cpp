#include<bits/stdc++.h>
template <typename T>

class Graph{
public:
    unordered_map<T, list<T>> adj;
    void add_edge(T u, T v, bool direction){
        adj[u].push_back(v);
        if(!direction){
            adj[v].push_back(u);
        }
    }

    void print_adjlist(){
        for(auto i: adj){
            cout<<i.first<<" : ";
            for(auto j: i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};

int main(int argc, char const *argv[]){
    Graph<int> g;
    g.add_edge(0, 1,0);
    g.add_edge(0, 4,0);
    g.add_edge(1, 3,0);
    g.add_edge(1, 2,0);
    g.add_edge(2, 3,0);
    g.add_edge(3, 4,0);
    g.print_adjlist();
    return 0;
}