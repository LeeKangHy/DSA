
# Ý Tưởng 


Gọi `dp[i]` là **số thao tác ít nhất để tạo ra `i` ký tự 'A'**. 

- Ta xét **các ước của `i`**.
- Với `i = i/j * j`

Ta thấy `j` và `i/j` là 2 ước của i. 

=> Ta tìm cách biểu diễn `dp[i]` theo `dp[j]` và `dp[i/j]`   
<br>
>**Chốt lại :**  
>Để tạo ra i ký tự, ta giả sử lần Copy All cuối cùng được thực hiện khi đang có j ký tự (với j là một ước của i). Trước hết cần dp[j] thao tác để tạo được j ký tự. Sau đó chỉ cần 1 lần Copy All và (i/j - 1) lần Paste để tăng từ j lên đúng i ký tự.

### Trường hợp 1
Ban đầu ta xác định được `dp[i/j]` 

Sau đó để tạo ra `dp[i]` ta thực hiện:
- Copy All : 1 lần
- Paste :  `j-1` lần

=> Tổng cộng thêm `j` thao tác.

Vì vậy:

```cpp
dp[i] = min(dp[i], dp[i/j] + j);
```

---

### Trường hợp 2
Ban đầu ta xác định được `dp[j]`

Sau đó để tạo ra `dp[i]` ta thực hiện:
- Copy All : 1 lần
- Paste :  `i/j - 1` lần

=> Tổng cộng thêm `i/j` thao tác.

Vì vậy:

```cpp
dp[i] = min(dp[i], dp[j] + i/j);
```


---
# Mã giả
Hàm MinSteps(n):
    
    tạo mảng dp[1..n]

    dp[1] = 0

    for i = 2 -> n:
        dp[i] = i          // ứng với ước bằng 1    

        for mỗi j từ 2 đến √i:
            nếu i chia hết cho j:
                dp[i] = min(dp[i], dp[i / j] + j)
                dp[i] = min(dp[i], dp[j] + i / j)

    trả về dp[n]

---

# Vì sao chỉ xét ước?

Lần **Copy All cuối cùng** luôn xảy ra khi số ký tự hiện tại là một **ước của số ký tự đích**. Nếu không phải ước thì sau các lần Paste sẽ không thể đạt đúng `i`.

---

### Độ phức tạp

Mỗi `i` chỉ duyệt các ước đến `√i`.

- **Time:** `O(n√n)`
- **Space:** `O(n)`


