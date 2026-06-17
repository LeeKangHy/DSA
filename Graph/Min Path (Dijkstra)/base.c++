#include <bits/stdc++.h>
#define int long long 
using namespace std ; 

const int INF = 1e9+7 ; 

struct Edge {
    int v;
    int w; 
};

void Dijkstra(int n,int S, vector<vector<Edge>> E , vector<int>&D , vector<int>&trace ){
    D.resize(n,INF); 
    trace.resize(n,-1);
    vector<bool>P ;  
    P.resize(n,false);
    D[S] = 0 ; 
    for(int i = 1; i<=n ; i++){
        int uBest ;
        int minDist = INF ; 
        for(int u = 0 ; u<n;u++){
            if(P[u] == false && D[u] < minDist){
                minDist = D[u];
                uBest = u ; 
            }
        }
        int u = uBest; 
        P[u] = true ; 
        for(auto x : E[u]){
            int v = x.v ; 
            int w = x.w;
            if(D[v] > D[u] + w){
                D[v] = D[u] + w; 
                trace[v] = u ;     
            }
         
        }
    }
}

void input(int&n , int &m , int& S, vector<vector<Edge>> & E){
    cin >> n >> m >> S ; 
    E.resize(n); 
    for(int i = 1 ; i<= m ;i++){
        int u , v , w;
        cin >> u >> v >> w; 
        E[u].push_back({v,w});
    }
}

signed main(){
    int n , m ,S ; 
    vector<int> D; 
    vector<vector<Edge>> E ;
    vector<int> trace;
    input(n, m, S, E);
    Dijkstra(n, S, E, D, trace);
    for (auto x : D) { 
        if(x == INF)
         cout << -1 ;
        else 
         cout << x <<endl ; 
    }
}   