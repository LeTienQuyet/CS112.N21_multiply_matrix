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
  - **LƯU Ý: CÓ THỂ CÓ NHIỀU CÁCH NHÂN CÁC MA TRẬN CÓ CÙNG SỐ PHÉP NHÂN LÀ ÍT NHẤT. TA CHỈ CHỌN MỘT THỨ TỰ NHÂN ĐỂ IN RA.** 
- Ví dụ:
  - Input:  
4  
10 5  
5 10  
10 5  
5 10  
  - Output:  
1000  
(0)((12)(3)) hoặc (0(12))(3) 
## Mô tả các biến chính trong chương trình:  
- **int n**:   
  - Số ma trận cần thực hiện phép nhân.
- **vector<vector\<int\>> matrix**:  
  - Ma trận 2 chiều ($n$ dòng - 2 cột).  
  - Ở hàng thứ $i$ của matrix: Cột thứ nhất biểu thị số dòng, cột thứ hai biểu thị số cột của ma trận $i$.
- **vector<vector\<int\>> cost**:  
  - Ma trận 2 chiều ($n$ dòng - $n$ cột).  
  - cost[i][j] thể hiện chi phí số phép nhân khi thực hiện nhân ma trận i $\rightarrow$$ ma trận j.  
    - cost[i][j] = -1 $\leftrightarrow$ Không tồn tại phép nhân từ ma trận i $\rightarrow$$ ma trận j.  
    - cost[i][j] > -1 $\leftrightarrow$ Tồn tại phép nhân từ ma trận i $\rightarrow$$ ma trận j.  
- **vector<vector\<int\>> par**:  
  - Ma trận 2 chiều (n dòng - n cột).  
  - k = par[i][j] là vị trí tối ưu để tách phép nhân ma trận i $\rightarrow$$ ma trận j sao cho tổng số phép nhân thực hiện là ít nhất.  
- **vector\<string\> ans**:  
  - Dùng để lưu trữ một trong các lời giải của bài toán.  
 
