# Thuật Toán Quy Hoạch Động - Bài Toán Target Sum

## 1. Ý tưởng
Đặt `dp[i][s]` là số cách dùng `i` phần tử đầu tiên để tạo ra tổng `s`.

Vì tổng có thể mang giá trị âm (khi gán nhiều dấu trừ), ta cần sử dụng một biến dịch chuyển `OFFSET = tổng tất cả các phần tử` để ánh xạ các chỉ số âm sang chỉ số mảng dương hợp lệ:
$$\text{chỉ số lưu} = s + \text{OFFSET}$$

## 2. Khởi tạo
Khi chưa dùng phần tử nào (`i = 0`), cách duy nhất là tạo ra tổng bằng `0` với đúng 1 cách:
* `dp[0][0 + OFFSET] = 1`
* Tất cả các trạng thái khác khởi tạo ban đầu bằng `0`.

## 3. Chuyển trạng thái
Xét phần tử thứ `nums[i]`. Nếu đã có `dp[i][s]` cách tạo ra tổng `s`, từ trạng thái này ta có thể mở rộng theo 2 hướng gán dấu cho phần tử tiếp theo:

* **Gán dấu cộng (`+`):**
  $$dp[i + 1][s + \text{nums}[i] + \text{OFFSET}] \mathrel{+}= dp[i][s + \text{OFFSET}]$$
* **Gán dấu trừ (`-`):**
  $$dp[i + 1][s - \text{nums}[i] + \text{OFFSET}] \mathrel{+}= dp[i][s + \text{OFFSET}]$$

Mỗi trạng thái hiện tại sẽ sinh ra 2 trạng thái mới tương ứng với hai cách gán dấu cho phần tử tiếp theo. Nhờ đó, mọi khả năng đều được xét đầy đủ và không bị đếm trùng.

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
