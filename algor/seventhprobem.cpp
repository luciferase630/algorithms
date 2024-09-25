#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int statement[100] = {0};//0为没找到，1为找到，2为未确定
int x;
void dfs(int n) {//传入从1开始
	if (n > x)
	{
		for (int i = 1; i <= x; i++)
		{
			if (statement[i]==1) {
				cout << i  << " ";
			}
			
		}
		cout << endl;
		return;
	}
	statement[n] = 1;//找到
	dfs(n + 1);//向下深搜
	statement[n] = 2;//恢复现场
	
	//这里的恢复现场似乎可以省略？
	statement[n] = 0;//没找到
	dfs(n + 1);//同样向下深搜
	statement[n] = 2;
	

}


int main() {
	
	int len = 1;
	cin >> x;
	dfs(1);
	return 0;

}