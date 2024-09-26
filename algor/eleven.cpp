#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

bool ifprimenumber(int number)
{
	if (number < 2)
	{
		return false;
	}
	else {
		for (int i = 2; i * i <= number; i++)
		{
			if (number % i == 0)
			{
				return false;
			}

		}
		return true;
	}
}
bool state[25] = { false };//用来标明当前状态是否被记录
int path[25] = { 1 };//用来递归,里面存的数字是要进行相加的
int arr[25] = { 0 };//用来存数、一开始输入进去的数字
int c1, c2;
void dfs(int x);
int cnt = 0;
int len = 0;
int main() {
	cin >> c1 >> c2;//第一个数是要选的总共个数，第二个数是要选多少个数
	for (int  i = 1; i <= c1; i++)
	{
		cin >> arr[i];
	}
	dfs(1);
	cout << cnt;
/*	for (int i = 0; i < c1; i++)
	{
		cout <<  arr[i];//array居然是关键字、、、、
	}*/
	return 0;
}
void dfs(int x) {
	if (x > c2)//把三个位置都填满了
	{
		int sum=0;
		for (int i = 1; i <= c2; i++)//选三个位置
		{
			sum += arr[path[i]];//加和,路径从1开始
		}
		if (ifprimenumber(sum))//看这三个数的加和是不是素数
		{
			cnt++;
		}
		return;
	}
	for (int i = path[len]; i <= c1; i++)
	{
		if (!state[i] )
		{
			state[i] = true;
			len++;
			path[len] = i;//选定i
			dfs(x + 1);//向下深搜
			state[i] = false;//恢复现场
			//path可以覆盖，所以直接
			len--;//恢复现场
		}
	}
}
