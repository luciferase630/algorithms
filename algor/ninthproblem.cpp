#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool state[15] = { 0 };
int arr[15] = { 0 };
int n=0;
//x表示的才是枚举到第几个位置
void dfs(int x)//，len为state的第几个//state 1 
{
	if (x > n)
	{
		for (int i = 1; i <=n; i++)
		{
		/*	if (state[i])//服了，这个好像找到直接给它输出就行
			{
				cout << arr[i]<< " ";
			}
		
		*/
			cout << arr[i] << " ";
		}

		cout << endl;
		return;
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (state[i] == false){
			state[i] = true;
			arr[x] = i;//第一个数得是1啊而不是0,而且一开始传入的x也是1
			dfs(x + 1);
			state[i] = false;//恢复现场
		//	arr[x] = 0;
		}


	}
}
int main() {
	cin >> n;
	dfs(1);
	return 0;
}