#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
//���Ĳ�� 5���Բ�ֳɣ�1+1+1+1+1
//����˳�򣡣����ݣ�2��n-1�η�
int dfs(int n, int max) {
	if (n == 0) return 1; // �ҵ�һ����Ч�Ĳ��  
	if (n < 0 || max == 0) return 0; // ��Ч�Ĳ��  

	// ������ǰ������Ͳ�������ǰ������������  
	return dfs(n - max, max) + dfs(n, max - 1);
}//��tm�ǲ�����˳���

/*int dfs(int origin)
{
	int total=0;
	//����˼·��ÿ�β�ֶ��Ǵ�n��������ó�һ��m��m��0��n֮�䣩��Ȼ��ʣ����
	//n-m,����n-m�����������⡣m���Դ�1ȡ��n  ��Ϊʲô���Ǵ�0����Ϊȡ0��ȡn��һ���£�
	// f2=f1+f0  ����Ҫ��f0����1
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