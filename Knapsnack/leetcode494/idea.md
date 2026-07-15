# Thuật Toán Quy Hoạch Động - Bài Toán Target Sum

## 1. Ý tưởng
Đặt `dp[i][s]` là số cách dùng `i` phần tử **đầu tiên** để tạo ra tổng `s`.

Với sum = tổng trị tuyệt đối các phần tử trong mảng.

Ta thấy khoảng giá trị của s là [-sum , sum ]  , mà dp[i][s] với s > 0 (s không được âm)

Vậy thì ta cho 

OFFSET = sum 

Bây giờ thì khoảng giá trị của s+OFFSET là $$[0 , 2 \cdot sum]$$ 

Chốt lại khi cài đặt thì : dp[i][s+OFFSET] :   số cách dùng i phần tử đầu tiên để tạo ra tổng s.

## 2. Khởi tạo
Khi chưa dùng phần tử nào (`i = 0`), cách duy nhất là tạo ra tổng bằng `0` với đúng 1 cách:
* `dp[0][0 + OFFSET] = 1`
* Tất cả các trạng thái khác khởi tạo ban đầu bằng `0`.

## 3. Chuyển trạng thái

Xét phần tử thứ i có giá trị nums[i]. Giả sử đã có dp[i][s + OFFSET], tức là có dp[i][s + OFFSET] cách gán dấu cho i phần tử đầu tiên để thu được tổng bằng s.

Khi xét phần tử nums[i], ta có hai lựa chọn:

* **Gán dấu cộng (`+`):**
  $$dp[i + 1][s + \text{nums}[i] + \text{OFFSET}] \mathrel{+}= dp[i][s + \text{OFFSET}]$$
* **Gán dấu trừ (`-`):**
  $$dp[i + 1][s - \text{nums}[i] + \text{OFFSET}] \mathrel{+}= dp[i][s + \text{OFFSET}]$$

Mỗi trạng thái hiện tại sinh ra hai trạng thái mới, tương ứng với hai cách gán dấu cho phần tử nums[i]. Nhờ đó, thuật toán duyệt đầy đủ mọi cách gán dấu cho các phần tử mà không bỏ sót hay đếm trùng.


## 4. Đáp án
Sau khi duyệt và xét hết tất cả `n` phần tử, số cách để đạt được tổng mong muốn (`target`) chính là:
$$\text{Đáp án} = dp[n][\text{target} + \text{OFFSET}]$$

## 5. Mã giả (Pseudocode)

```python
sum = tổng các phần tử
OFFSET = sum

# Khởi tạo bảng dp với các giá trị ban đầu bằng 0
# Kích thước mảng: (n + 1) x (2 * sum + 1)
khởi tạo dp = 0 
dp[0][OFFSET] = 1

for i = 0 -> n - 1:
    for s = -sum -> sum:
        nếu dp[i][s + OFFSET] == 0:
            continue

        # Hướng 1: Gán dấu cộng (+) cho nums[i]
        dp[i + 1][s + nums[i] + OFFSET] += dp[i][s + OFFSET]
        
        # Hướng 2: Gán dấu trừ (-) cho nums[i]
        dp[i + 1][s - nums[i] + OFFSET] += dp[i][s + OFFSET]

trả về dp[n][target + OFFSET]
