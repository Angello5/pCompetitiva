#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 100000000;

struct Arista {
    int from, to, weight;
};

int main(){
    int V,E;
    cin>>V>>E;

    vector<Arista> aristas(E);
    for(int i = 0;i < E; i++){
        int from, to, weight;
        cin>>from>>to>>weight;
        aristas[i] = {from, to, weight};
    }

    vector<vector<int>> graph(V, vector<int>(V,INF));

    for(const auto & arista : aristas){
        graph[arista.from][arista.to] = min(graph[arista.from][arista.to], arista.weight);

    }

    vector<int> dist(V,INF);
    queue<int> q;
    dist[0]=  0;
    q.push(0);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v = 0; v < V; v++){
            if(graph[u][v]== INF) continue;
            if(dist[v] >dist[u] + graph[u][v]){
                dist[v] = dist[u] + graph[u][v];
                q.push(v);
            }
        }
    }
    for(int i = 0;i < V; i++){
        cout<<"dist["<<i<<"] ="<< dist[i]<<endl;
    }

    return 0;
}