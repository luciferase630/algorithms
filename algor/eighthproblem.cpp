#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
//������дһ����Ȼ���Ĳ��
int path[25] = { 1 };//ͬ������˼�ĳ�ʼ��
int len = 0;//����˼�ĳ�ʼ��
void  dfs(int n) {
	if (n == 0) {
		for (int i = 1; i <= len; i++)
		{
			cout << path[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++)//����n���������ֲ�//����д��(int i = path[len]; i <= n; i++)
	{//����д�������ظ���
		len++;
		path[len] = i;//��i��¼
		dfs(n - i);//���ȥ��i
		len--;//����
	}
}

int main() {
	int n;
	cin >> n;
	dfs(n);
	return 0;
}