#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;
int n;
vector<vector<int>> matrix;
// #################################################################################
// Hàm check_input dùng để kiểm tra xem số dòng của ma trận vừa nhập vào có thỏa mãn
// điều kiện (bằng số của cột của ma trận trước đó) để thực hiện phép nhân 2 ma trận.
bool check_input(int row)
{
	if (!matrix.size() || row == matrix[matrix.size() - 1][1]) return true;
	return false;
}
//###################################################################################
// Hàm input_matrix để nhập số ma trận và thông tin từng ma trận đó (gồm số dòng và 
// số cột của mỗi ma trận) cần thực hiện phép nhân. 
void input_matrix()
{
	cout << "Nhap so ma tran can thuc hien phep nhan: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int row, col;
		vector<int> sub_matrix;
		cout << "Nhap thong tin cua ma tran " << i << ":\n";
		cout << "\tNhap so dong va so cot cua ma tran " << i << ": ";
		cin >> row >> col;
		while (!check_input(row))
		{
			cout << "\tThong tin ban nhap khong thoa man de thuc hien phep nhan. ";
			cout << "Hay nhap lai so dong va so cot cua ma tran " << i << ": ";
			cin >> row >> col;
		}
		sub_matrix.push_back(row);
		sub_matrix.push_back(col);
		matrix.push_back(sub_matrix);
	}
}
//###################################################################################
// Hàm solve_cost_table để đi tìm bảng tổng số phép nhân cho việc nhân ma trận và vị 
// trí để tách phép nhân các ma trận.
void solve_cost_table(vector<vector<int>>& cost, vector<vector<int>>& par)
{
	for (int i = 0; i < n; i++) cost[i][i] = 0;
	int delta = 1; // delta = j - i
	while (delta <= n - 1)
	{
		for (int i = 0; i < n - delta; i++)
		{
			int MIN = INT_MAX;
			int j = i + delta;
			for (int k = i; k < j; k++)
			{
				int sum_cost = cost[i][k] + cost[k + 1][j] + matrix[i][0] * matrix[k][1] * matrix[j][1];
				if (sum_cost < MIN)
				{
					MIN = sum_cost;
					if (delta > 1) par[i][j] = k;
				}
			}
			cost[i][j] = MIN;
		}
		delta += 1;
	}
}
//###################################################################################
// Hàm set_ans thiết lập biến ans.
void set_ans(vector<string>& ans)
{
	for (int i = 0; i < n; i++)
		ans.push_back(to_string(i));
}
//###################################################################################
// Hàm solve_ans đi tìm cách đầu tiên thỏa mãn nhân các ma trận có chi phí ít nhất. 
void solve_ans(vector<string>& ans, int start, int end, vector<vector<int>> par)
{
	int k = par[start][end];
	if (k == -1) return;
	if (k > start)
	{
		ans[start] = "(" + ans[start];
		ans[k] += ")";
	}
	if (end > k + 1)
	{
		ans[k + 1] = "(" + ans[k + 1];
		ans[end] += ")";
	}
	solve_ans(ans, start, k, par);
	solve_ans(ans, k + 1, end, par);
}
//###################################################################################
// Hàm print_ans để in ra cách nhân các ma trận tìm được.
void print_ans(vector<string> ans)
{
	cout << "Mot trong cac cach thuc hien phep nhan la: ";
	for (int i = 0; i < n; i++)
		cout << ans[i];
}
//###################################################################################
// Hàm interface giúp hiển thị bảng cost (chi phí) dễ xem hơn cho người đọc, không 
// ảnh hưởng đến việc giải quyết bài toán.
void interface()
{
	cout << "Bang chi phi so phep nhan duoc thuc hien:\n";
	cout << "--------";
	for (int i = 0; i < n; i++)
		cout << "----------------";
	cout << "\n";
	cout << "|  cost  |";
	for (int i = 0; i < n; i++)
		cout << "\t" << i << "\t|";
	cout << "\n";
	cout << "--------";
	for (int i = 0; i < n; i++)
		cout << "----------------";
	cout << "\n";
}
//###################################################################################
// Hàm print_cost_table in ra bảng chi phi và chi phí tối thiểu.
void print_cost_table(vector<vector<int>> cost) {
	for (int i = 0; i < n; i++)
	{
		cout << "|   " << i << "    |";
		for (int j = 0; j < n; j++)
			cout << "\t" << cost[i][j] << "\t|";
		cout << "\n";
	}
	cout << "--------";
	for (int i = 0; i < n; i++)
		cout << "----------------";
	cout << "\nTong so phep nhan toi thieu su dung la: " << cost[0][n - 1] << endl;
}
//###################################################################################
int main()
{
	input_matrix();
	vector<vector<int>> cost(n, vector<int>(n, -1));
	vector<vector<int>> par(n, vector<int>(n, -1));
	vector<string> ans;
	solve_cost_table(cost, par);
	interface();
	print_cost_table(cost);
	set_ans(ans);
	solve_ans(ans, 0, n - 1, par);
	print_ans(ans);
	return 0;
}
