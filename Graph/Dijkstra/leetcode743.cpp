class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF = 1e9+7 ; 
        vector<int> D ; 
        D.resize(n+1,INF) ; 
        D[k] = 0 ;
        
        vector<bool> P; 
        P.resize(n+1, false);
        
        //Find uBest, the node with the shortest distance from node k.
        for(int i = 1; i<= n ; i++){
            int uBest ;
            int minPath = INF ;
            for(int u = 1 ; u<= n ; u++){ 
                if(D[u] < minPath && P[u] == false ) {
                    minPath = D[u] ;
                    uBest = u ; 
                }
            }

            // Now we knew node uBest 
            // We consider nodes connected to node uBest 
            int u = uBest ; 
            P[u] = true; 
            for(int j = 0 ; j < size(times) ;j++){
                if(times[j][0] == u){
                    int v = times[j][1];
                    int w = times[j][2];
                    if(D[v] > D[u] + w){
                        D[v] = D[u] + w ; 
                    } 
                }
            }
        }

        int cnt = 0 ;
        for(int i = 1 ; i<= n ; i++){
            if(D[i] == INF) cnt++ ; 
        }
        if(cnt > 0 ) {
            return -1 ; 
        }
        int res = -1 ; 
        for(int i = 1 ; i <=n; i++){
            if(res < D[i]) 
                res = D[i] ;  
        }
        return res ;  
    }
};
