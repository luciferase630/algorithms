#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int statement[100] = {0};//0Ϊû�ҵ���1Ϊ�ҵ���2Ϊδȷ��
int x;
void dfs(int n) {//�����1��ʼ
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
	statement[n] = 1;//�ҵ�
	dfs(n + 1);//��������
	statement[n] = 2;//�ָ��ֳ�
	
	//����Ļָ��ֳ��ƺ�����ʡ�ԣ�
	statement[n] = 0;//û�ҵ�
	dfs(n + 1);//ͬ����������
	statement[n] = 2;
	

}


int main() {
	
	int len = 1;
	cin >> x;
	dfs(1);
	return 0;

}