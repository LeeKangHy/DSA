DIJKSTRA(n,S,E)

Input: 

    n : số đỉnh 
    S : đỉnh bắt đầu
    E : danh sách kề 
        E[u] chứa các cạnh (v,w) : nghĩa là mô tả các đỉnh v kề với đỉnh u có trọng số là w  

Output: 

    D[u] : Khoảng cách ngắn nhất từ S đến u 
    trace[u] : các đỉnh trước của u trên đường đi ngắn nhất  


Chú thích :   
D[u] : ban đầu khởi tạo nghĩa là khoảng cách từ S đến u  
P[u] là mảng đánh dấu các đỉnh u đã được xử lí chưa

--------------------------------------------------------------------------------------
Khởi tạo : 

    Với mọi đỉnh u : 
        D[u] <- INF 
        trace[u] <- -1 
        P[u] <- false 
    
    D[S] <- 0 

Lặp n lần : 
    
    Tìm đỉnh chưa xét có khoảng cách nhỏ nhất
        uBest <- chưa xác định
        minDist <- INF 
        
        Với mọi đỉnh u : 
            Nếu P[u] = false và D[u] < minDist thì : 
                minDist <- D[u] 
                uBest <- u 
    
    /* Ta vừa tìm được đỉnh u chưa xét có khoảng cách nhỏ nhất
       Do các cạnh đều > 0 nên chắc chắn rằng : D[u] hiện tại là nhỏ nhất 
       Vì vậy : 
         - Đánh dấu u là đã xử lý xong 
         - Dùng u là 1 đỉnh trung gian để thử cải thiện đường đi tới các đỉnh kề của nó 
    */
    u <- uBest
    P[u] <- true 
    Với mỗi cạnh (v,w) kề với u : 
        Nếu D[v] > D[u] + w thì : 
            D[v] <- D[u] + w
            trace[v] <- u 


Kết thúc
