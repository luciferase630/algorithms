#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;
// Ŀ�ģ���������
int path[22] = {1};
bool state[22] = { false };
int c1, c2;
int len = 0;
void dfs(int x)//x����ڼ���λ��
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
		if (!state[i])//���˵���λ��û�����
		{
			state[i] = true;//��ô�͸������
			len++;
			path[len] = i;//������һ��λ����i����1��ʼѭ����
			dfs(x + 1);
			state[i] = false;//�������ָ��ֳ�
		//���Ӧ�ÿ��Ը���	path[len] = 0;
			len--;//�ָ��ֳ�

		}
	}
}
int main()
{
	
	cin >> c1 >> c2;
	dfs(1);
	return 0;
}