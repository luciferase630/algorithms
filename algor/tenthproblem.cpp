#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;
// 目的，输出组合数
int path[22] = {1};
bool state[22] = { false };
int c1, c2;
int len = 0;
void dfs(int x)//x代表第几个位置
{
	if (x > c2)
	{
		for (int i = 1; i <= c2; i++)
		{
			cout << setw(3) << path[i];
		}
		cout << endl;
		return;
	}
	for (int i = path[len]; i <=c1; i++)
	{
		if (!state[i])//如果说这个位置没有填东西
		{
			state[i] = true;//那么就给他填东西
			len++;
			path[len] = i;//给它第一个位置填i，从1开始循环嘛
			dfs(x + 1);
			state[i] = false;//这两步恢复现场
		//这个应该可以覆盖	path[len] = 0;
			len--;//恢复现场

		}
	}
}
int main()
{
	
	cin >> c1 >> c2;
	dfs(1);
	return 0;
}