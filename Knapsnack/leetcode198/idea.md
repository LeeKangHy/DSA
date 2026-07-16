


# Ý tưởng 

> **Đến mỗi ngôi nhà, bạn chỉ có 2 lựa chọn:**
> - **Không cướp** nhà hiện tại.
> - **Cướp** nhà hiện tại (thì không được cướp nhà trước đó).

Từ đó ta xây dựng quy hoạch động.

# Cách làm

## Định nghĩa

> `dp[i]` = **số tiền lớn nhất có thể cướp được khi xét các ngôi nhà có chỉ số từ `0` đến `i`.**

## Bước cơ sở  
```
dp[0] = nums[0]  : số tiền lớn nhất có thể cướp được tại ngôi nhà 0 là nums[0]

dp[1] = max(nums[0] , nums[1])  : số tiền lớn nhất có thể cướp được tại ngôi nhà có chỉ số từ 0 đến 1 là max(nums[0] , nums[1])
```
<br>

## Chuyển trạng thái 

Khi ta đứng ở nhà i sẽ có 2 trường hợp xảy ra : 

### Trường hợp 1: Không cướp nhà `i`

Vậy thì

```
dp[i] =  dp[i-1]
```

Vì ta chỉ lấy kết quả tốt nhất của các nhà trước đó.


### Trường hợp 2: Cướp nhà `i`

Nếu cướp nhà `i` thì **không được cướp nhà `i-1`**.

Do đó trước nhà `i` ta chỉ có thể lấy kết quả tốt nhất đến nhà `i-2`.

Vậy thì

```
dp[i] = nums[i] + dp[i-2]
```


## Kết luận 


Sau khi xét hai khả năng trên, ta nhận thấy **giá trị `dp[i]` đều phải rơi vào đúng một trong hai trường hợp**:

 - Không cướp nhà `i`, khi đó kết quả chính là `dp[i-1]`.
 - Cướp nhà `i`, khi đó do không được cướp nhà `i-1`, kết quả là `nums[i] + dp[i-2]`.



Ta chọn phương án tốt hơn:

```
dp[i] = max(dp[i-1],nums[i] + dp[i-2])
```
<br>

Kết quả cuối cùng là `nums[i] + dp[i-2]`
  (với n là số phần tử trong nums )

