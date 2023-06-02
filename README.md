# Phân tích và thiết kế thuật toán CS112.N21
## Thành viên nhóm: ##
|     Họ và tên     |    MSSV    |
| :---------------: | :--------: |
| Nguyễn Nhật Minh  | 21521135   |
| Lê Tiến Quyết     | 21520428   |
# Bài toán nhân chuỗi dãy/ma trận 
## Yêu cầu của bài toán:  
- **Input**: 
  - Một số nguyên dương $n$ ($0 < n <= 20$) cho biết số ma trận cần thực hiện phép nhân.  
  - $n$ dòng tiếp theo, mỗi dòng gồm 2 số nguyên dương $r_i$ và $l_i$ ($0 < r_i, l_i <= 100$) cho biết số hàng và số cột của ma trận $i$.
- **Output**:
  - Dòng đầu tiên cho biết số phép nhân thực hiện là ít nhất.
  - Dòng thứ hai là thứ tự nhân các ma trận để đạt được số phép nhân trên.
  - **LƯU Ý: CÓ THỂ CÓ NHIỀU CÁCH NHÂN CÁC MA TRẬN MÀ CÁC CÁCH ĐÓ ĐỀU CÓ CÙNG SỐ PHÉP NHÂN LÀ ÍT NHẤT. TA CHỈ CHỌN MỘT CÁCH NHÂN ĐỂ IN RA.** 
- Ví dụ:
  - Input:  
4  
10 5  
5 10  
10 5  
5 10  
  - Output:  
1000  
0((12)3) hoặc (0(12))3
## Mô tả các biến chính trong chương trình:  
- **int $n$**:   
  - Số ma trận cần thực hiện phép nhân.
- **vector<vector\<int\>> $matrix$**:  
  - Ma trận 2 chiều ($n$ dòng - 2 cột).  
  - Ở hàng thứ $i$ của $matrix$: Cột thứ nhất biểu thị số dòng, cột thứ hai biểu thị số cột của ma trận $i$.
- **vector<vector\<int\>> $cost$**:  
  - Ma trận 2 chiều ($n$ dòng - $n$ cột).  
  - $cost[i][j]$ thể hiện chi phí số phép nhân khi thực hiện nhân ma trận $i$ $\rightarrow$ ma trận $j$.  
    - $cost[i][j]$ = -1 $\leftrightarrow$ Không tồn tại phép nhân từ ma trận $i$ $\rightarrow$ ma trận $j$.  
    - $cost[i][j]$ > -1 $\leftrightarrow$ Số phép nhân được sử dụng khi nhân từ ma trận $i$ $\rightarrow$ ma trận $j$.  
- **vector<vector\<int\>> $par$**:  
  - Ma trận 2 chiều ($n$ dòng - $n$ cột).  
  - $k = par[i][j]$ là vị trí tối ưu để tách phép nhân ma trận $i$ $\rightarrow$ ma trận $j$ sao cho tổng số phép nhân thực hiện là ít nhất.  
- **vector\<string\> $ans$**:  
  - Dùng để lưu trữ một trong các lời giải của bài toán.  
 ## Mã giả giải quyết bài toán:
 
**optimal_solution**(matrix, cost, n, ans, par) {

&emsp;Gán tất cả các cost[i][i]=0 với i chạy từ 0 đến n-1   &emsp;   // *Số phép nhân thực hiện khi chỉ có một ma trận là 0*
  
&emsp;delta = 1;     &emsp;  // *(delta + 1) là số lượng ma trận trong chuỗi ma trận con mà ta muốn xét* 
  
&emsp;while (delta < n) {
  
&emsp;&emsp;    for(i = 0; i + delta < n; i++) {
    
&emsp;&emsp;&emsp;    Gán j = i + delta;
      
&emsp;&emsp;&emsp;    for(k = i; k < j; k++) { &emsp;  // *k là biến lần lượt duyệt qua các vị trí có thể phân chia (đặt dấu ngoặc)*
      
&emsp;&emsp;&emsp;&emsp;    Gán sum_cost = số phép nhân sẽ được thực hiện với vị trí k phân chia hiện tại;
      
&emsp;&emsp;&emsp;&emsp;    if(sum_cost < min) { &emsp;  // *Số phép nhân tối thiểu cần thực hiện với chuỗi ma trận con tính đến thời điểm so sánh*
      
&emsp;&emsp;&emsp;&emsp;&emsp;    Gán lại min = sum_cost;
        
&emsp;&emsp;&emsp;&emsp;&emsp;    if(delta > 1) Gán par[i][j] = k;  &emsp;// *Lưu trữ vị trí phân chia của ma trận con (bao gồm ma trận i đến ma trận j)*

&emsp;&emsp;&emsp;&emsp;&emsp;    }

&emsp;&emsp;&emsp;      }
      
&emsp;&emsp;&emsp;    cost[i][j] = min;   &emsp; // *Lưu số phép nhân tối thiểu khi thực hiện nhân các ma trận trong chuỗi ma trận con*

&emsp;&emsp;    }
      
&emsp;&emsp;    delta++; &emsp;// *Tăng số lượng ma trận trong chuỗi ma trận con thêm 1*
    
&emsp;    }
  
&emsp;    Xuất ra màn hình số phép nhân tối thiểu cần thực hiện để nhân chuỗi ma trận 
  
&emsp;    Xuất ra màn hình một cách đặt các dấu ngoặc thể hiện thứ tự các phép nhân 
  
}
## Chạy thử chương trình  
Test case được sử dụng nằm ở phần Ví dụ của mục [**Yêu cầu của bài toán**](https://github.com/LeTienQuyet/CS112.N21_multiply_matrix#y%C3%AAu-c%E1%BA%A7u-c%E1%BB%A7a-b%C3%A0i-to%C3%A1n) ở trên.  
Và hình ảnh dưới đây là kết quả của chương trình khi chạy test case đó.  
![image](https://github.com/LeTienQuyet/CS112.N21_multiply_matrix/assets/97799935/e06a3745-8cdb-4bbd-9983-d8f9a44f7b34)

