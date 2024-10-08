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
	for (int i = path[len]; i <=c1; i++)//经典字典序
	{
		if (!state[i])//如果说这个位置没有填东西
		{
			state[i] = true;//那么就给他填东西
			len++;
			path[len] = i;//给它第一个位置填i，从i开始循环嘛//i一定要从path[len]开始
			//这一步隐形给这个玩意递增了，因为它在循环里
			//cout << "dfs(" << x + 1 << ")"<< endl;//没法调试会被顶掉
			dfs(x + 1);
			//cout << "回溯"<< " "<< endl;
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