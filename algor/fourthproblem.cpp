#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
//数的拆分 5可以拆分成：1+1+1+1+1
//考虑顺序！！！草，2的n-1次方
int dfs(int n, int max) {
	if (n == 0) return 1; // 找到一个有效的拆分  
	if (n < 0 || max == 0) return 0; // 无效的拆分  

	// 包含当前最大数和不包含当前最大数两种情况  
	return dfs(n - max, max) + dfs(n, max - 1);
}//这tm是不考虑顺序的

/*int dfs(int origin)
{
	int total=0;
	//核心思路，每次拆分都是从n这个数里拿出一个m（m在0到n之间），然后剩下来
	//n-m,考虑n-m的这个组合问题。m可以从1取到n  （为什么不是从0，因为取0和取n是一回事）
	// f2=f1+f0  最重要，f0等于1
	if (origin == 0)
		return 1;
	else
	{
		for (int i = 1; i <=origin ; i++)
		{
			total += dfs(origin - i);
		}
		return total;
	}
}*/
int main() {
	int origin;
	int result;
	cin >> origin;
	result=dfs(origin,origin);
	cout << result;
	return 0;
}