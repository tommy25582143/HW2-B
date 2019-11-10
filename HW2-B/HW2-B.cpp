// HW2-B.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int least_cost(int m, int n, int& a, int& b, int& y, string& test1, string& test2, int** DP_table) {

	if (DP_table[m][n] >= 0) {
		return DP_table[m][n];
	}
	if (m == 0 && n == 0) {
		return DP_table[m][n] = 0;
	}

	if (m == 0) {
		return DP_table[m][n] = least_cost(m, n - 1, a, b, y, test1, test2, DP_table) + a;
	}

	if (n == 0) {
		return DP_table[m][n] = least_cost(m - 1, n, a, b, y, test1, test2, DP_table) + b;
	}

	int diogonal = (test1[m - 1] == test2[n - 1]) ? least_cost(m - 1, n - 1, a, b, y, test1, test2, DP_table) \
		: least_cost(m - 1, n - 1, a, b, y, test1, test2, DP_table) + y;

	int temp = min(least_cost(m - 1, n, a, b, y, test1, test2, DP_table) + b,
		least_cost(m, n - 1, a, b, y, test1, test2, DP_table) + a);

	return DP_table[m][n] = min(temp, diogonal);
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	int a, b, y;
	string test1, test2;
	int ans[10]{ 0 };

	cin >> t;
	int count = 0;
	while (count < t) {

		if (count != 0) {
			cout << endl;
		}

		cin >> a >> b >> y;
		cin >> test1;
		cin >> test2;

		int** DP_table = new int* [test1.length() + 1];
		for (int i = 0; i < test1.length() + 1; i++) {
			DP_table[i] = new int[test2.length() + 1];
		}

		for (int i = 0; i < test1.length() + 1; i++) {
			for (int j = 0; j < test2.length() + 1; j++) {
				DP_table[i][j] = -1;
			}
		}

		ans[count] = least_cost(test1.length(), test2.length(), a, b, y, test1, test2, DP_table);

		for (int i = 0; i < test1.length() + 1; i++) {
			delete[]DP_table[i];
		}
		delete[]DP_table;

		count++;
	}

	for (int i = 0; i < t; i++) {
		if (i != 0) {
			cout << endl;
		}

		cout << ans[i];
	}

	return 0;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
