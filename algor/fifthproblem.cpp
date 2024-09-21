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
		//���ǵݹ���ڣ�����Ĺ�˵�����ҿ�����
		for (int i = 0; i < path.size(); i++)
		{
			partitions += to_string(path[i]);
			if (i!=path.size()-1)
			{
				partitions += "+";
			}
			
		}
		result.push_back(partitions);
		return;//���ѷ��ظ�����


	}
	for (int i = 1; i <= n; i++)//�ݹ�Ľ��в�ֵ�Ѱ�ң�·��ȫ���洢��path��
	{
		path.push_back(i);//����ѹ��ȥ
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
	sort(result.begin(), result.end());//��������ʹ��
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