# Phân tích và thiết kế thuật toán CS112.N21
## Thành viên nhóm: ##
|     Họ và tên     |    MSSV    |
| :---------------: | :--------: |
| Nguyễn Nhật Minh  | 21521135   |
| Lê Tiến Quyết     | 21520428   |
## Yêu cầu của bài toán:  
- **Input**: 
  - Một số nguyên dương $n$ ($0 < n <= 20$) cho biết số ma trận cần thực hiện phép nhân.  
  - $n$ dòng tiếp theo, mỗi dòng gồm 2 số nguyên dương $r_i$ và $l_i$ ($0 < r_i, l_i <= 100$) cho biết số hàng và số cột của ma trận $i$.
- **Output**:  
## Mô tả các biến chính trong chương trình:  
- **int n**:   
  - Số ma trận cần thực hiện phép nhân.
- **vector<vector\<int\>> matrix**:  
  - Ma trận 2 chiều (n dòng - 2 cột).  
  - Ở hàng thứ i của matrix: Cột thứ nhất biểu thị số dòng, cột thứ hai biểu thị số cột của ma trận i.
- **vector<vector\<int\>> cost**:  
  - Ma trận 2 chiều (n dòng - n cột).  
  - cost[i][j] thể hiện chi phí số phép nhân khi thực hiện nhân ma trận i -> ma trận j.  
    - cost[i][j] = -1 <-> Không tồn tại phép nhân từ ma trận i -> ma trận j.  
    - cost[i][j] > -1 <-> Tồn tại phép nhận từ ma trận i -> ma trận j.  
- **vector<vector\<int\>> par**:  
  - Ma trận 2 chiều (n dòng - n cột).  
  - k = par[i][j] là vị trí tối ưu để tách phép nhân ma trận i - > ma trận j sao cho tổng số phép nhân thực hiện là ít nhất.  
- **vector\<string\> ans**:  
  - Dùng để lưu trữ một trong các lời giải của bài toán.  
 
