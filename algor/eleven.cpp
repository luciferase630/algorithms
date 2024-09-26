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
bool state[25] = { false };//����������ǰ״̬�Ƿ񱻼�¼
int path[25] = { 1 };//�����ݹ�,������������Ҫ������ӵ�
int arr[25] = { 0 };//����������һ��ʼ�����ȥ������
int c1, c2;
void dfs(int x);
int cnt = 0;
int len = 0;
int main() {
	cin >> c1 >> c2;//��һ������Ҫѡ���ܹ��������ڶ�������Ҫѡ���ٸ���
	for (int  i = 1; i <= c1; i++)
	{
		cin >> arr[i];
	}
	dfs(1);
	cout << cnt;
/*	for (int i = 0; i < c1; i++)
	{
		cout <<  arr[i];//array��Ȼ�ǹؼ��֡�������
	}*/
	return 0;
}
void dfs(int x) {
	if (x > c2)//������λ�ö�������
	{
		int sum=0;
		for (int i = 1; i <= c2; i++)//ѡ����λ��
		{
			sum += arr[path[i]];//�Ӻ�,·����1��ʼ
		}
		if (ifprimenumber(sum))//�����������ļӺ��ǲ�������
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
			path[len] = i;//ѡ��i
			dfs(x + 1);//��������
			state[i] = false;//�ָ��ֳ�
			//path���Ը��ǣ�����ֱ��
			len--;//�ָ��ֳ�
		}
	}
}
