#include<bits/stdc++.h>

class Graph{
public:
    vector<vector<pair<int,int>>> adj;
    Graph(int n){
        adj.resize(n);
    }
    void addEdge(int u, int v, int w){
        pair<int, int> p = make_pair(v,w);
        adj[u].push_back(p);
    }

    void print_adjlist(){
        int x = 0;
        for(auto i: adj){
            cout<<x++<<" : ";
            for(auto j: i){
                cout<<"["<<j.first<<" "<<j.second<<"]";
            }
            cout<<endl;
        }
    }



    void dfs(int node, vector<bool>& visited, stack<int>& s){
        visited[node] = true;
        for(auto i: adj[node]){
            if(!visited[i.first]) dfs(i.first, visited, s);
        }
        s.push(node);
    }


    void get_shortest_path(int src, vector<int>& dist, stack<int>& s){
        dist[src] = 0;
        while(!s.empty()){
            int top = s.top();
            s.pop();
            if(dist[top]!= INT_MAX){
                for(auto i: adj[top]){
                    if(dist[top]+i.second<dist[i.first]){
                        dist[i.first] = dist[top]+i.second;
                    }
                }
            }
        }
    }
};


int main(int argc, char const *argv[]){
    int n = 6;
    Graph g(n);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    g.print_adjlist();

    stack<int> s;
    vector<bool> visited(n, false);
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            g.dfs(i, visited, s);
        }
    }


    int src = 1;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    g.get_shortest_path(src, dist, s);
    for(auto i:dist) cout<<i<<" ";
    cout<<endl;
    cout<<dist[5];
    return 0;
}