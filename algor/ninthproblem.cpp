#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool state[15] = { 0 };
int arr[15] = { 0 };
int n=0;
//x��ʾ�Ĳ���ö�ٵ��ڼ���λ��
void dfs(int x)//��lenΪstate�ĵڼ���//state 1 
{
	if (x > n)
	{
		for (int i = 1; i <=n; i++)
		{
		/*	if (state[i])//���ˣ���������ҵ�ֱ�Ӹ����������
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
			arr[x] = i;//��һ��������1��������0,����һ��ʼ�����xҲ��1
			dfs(x + 1);
			state[i] = false;//�ָ��ֳ�
		//	arr[x] = 0;
		}


	}
}
int main() {
	cin >> n;
	dfs(1);
	return 0;
}