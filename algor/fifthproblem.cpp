#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
typedef long long ll;
using namespace std;
void findpartitions(int n,  vector<string>& result, vector<int>& path) {
	string partitions = "";
	if (n == 0) {
		//这是递归出口，他妈的怪说不得我看不懂
		for (int i = 0; i < path.size(); i++)
		{
			partitions += to_string(path[i]);
			if (i!=path.size()-1)
			{
				partitions += "+";
			}
			
		}
		result.push_back(partitions);
		return;//差点把返回给忘了


	}
	for (int i = 1; i <= n; i++)//递归的进行拆分的寻找，路径全部存储到path里
	{
		path.push_back(i);//把它压进去
		findpartitions(n - i,  result, path);
		path.pop_back();
	}
}
int main() {
	int n;
	cin >> n;
	vector<string>result;
	vector<int>path;
	findpartitions(n, result, path);
	sort(result.begin(), result.end());//迭代器的使用
/*	for (const string ai : result)
	{
		cout << ai << endl;
	}*/
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
	return 0;
}