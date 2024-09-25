#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
//回来再写一遍自然数的拆分
int path[25] = { 1 };//同样有意思的初始化
int len = 0;//有意思的初始化
void  dfs(int n) {
	if (n == 0) {
		for (int i = 1; i <= len; i++)
		{
			cout << path[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++)//等于n还真有这种拆法//递增写法(int i = path[len]; i <= n; i++)
	{//尝龟写法（有重复）
		len++;
		path[len] = i;//把i记录
		dfs(n - i);//拆出去了i
		len--;//回溯
	}
}

int main() {
	int n;
	cin >> n;
	dfs(n);
	return 0;
}