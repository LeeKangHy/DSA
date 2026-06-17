1. D[u] là đường đi ngắn nhất từ đỉnh nguồn đến đỉnh u đã tìm được
2. P[u] nhận hai giá trị true, false cho biết đỉnh P_u đã được chọn để tối ưu chưa 

Các bước cài đặt (pseudo code) :
1. Khởi tạo : 
    D = [0,INF,INF,INF] , P = [false,false,false,false]
2. Tạo 1 vòng lặp để duyệt qua n đỉnh , khởi tạo u là đỉnh nguồn (đỉnh đầu tiên mà ta xét)
    for(int i = 0; i <n ; i++){
        int u ; 
    }
3. Tại mỗi đỉnh ta xét các cạnh nối với đỉnh đó, 
     if(D[i] ) 