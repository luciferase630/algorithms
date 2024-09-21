#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;

const int dx[8] = { +1  , +1, +2,  +2,  -1,  -1,  -2,  -2 };
const int dy[8] = { +2,  -2,  +1,  -1,  +2,  -2,  +1,  -1 };//��ǲ����ߵ�λ��,һ���������
bool blocked[21][21] = { false };
void initblocked(bool blocked[][21], int h1, int h2)//���Բ�ָ����
{
    blocked[h1][h2] = true;//�������������00��ʼ�����Ǹ�����һ��
    for (int i = 0; i < 8; i++)
    {
        if ((h1 + dx[i]) >= 0 && (h2 + dy[i]) >= 0 && (h1 + dx[i]) < 21 && (h2 + dy[i]) < 21)//������Ϸ�ʱ  //���ǲ���Խ��
            blocked[h1 + dx[i]][h2 + dy[i]] = true;//��������ʾΪ������
    }
}
/*
//�⺯����û��д���ˣ��ܲ���
int dfs(int b1, int b2)
{
    if (b1 == 0 && b2 == 0) {
        return 1;
    }
    else if (b1 == 0 && b2 != 0)//��һ��
    {
        if(blocked[b1][b2-1]==true)
        {
            return 0;
        }
        else
        {
            return dfs(b1, b2 - 1);
        }
    }
    else if (b1 != 0 && b2 == 0)//��һ��
    {
        if (blocked[b1-1][b2 ] == true)
        {
            return 0;
        }
        else
        {
            return dfs(b1 -1 , b2 );
        }
    }
    else
    {
        if (blocked[b1][b2] ==true )
        {
            return 0;
        }
        else if ((blocked[b1 - 1][b2] == false) && (blocked[b1][b2 - 1] == false))
        {
            return dfs(b1 - 1, b2) + dfs(b1, b2 - 1);

        }
        else if ((blocked[b1 - 1][b2] == false) && (blocked[b1][b2 - 1] == true))
        {
            return dfs(b1 - 1, b2);
        }
        else if ((blocked[b1 - 1][b2] == true) && (blocked[b1][b2 - 1] == false))
        {
            return dfs(b1, b2 - 1);
        } 
    }
    //������ڴ������̫����������Ӧ�õ�һ����Ԫ����
}
*/
int dfs(int b1, int b2)
{
    if (b1 < 0 || b2 < 0) {//b1 ��b 2��һ��С��0��ʱ���ֱ�ӷ����㣬��Ϊ��Ҫ����Խ��
        return 0;
    }
    if (b1 == 0 && b2 == 0) {//��������һ��Ԫ��
        return 1;
    }
    if (blocked[b1][b2]) {//�����λ�ñ��赲��ֱ�ӷ�����
        return 0;
    }
    return dfs(b1 - 1, b2) + dfs(b1, b2 - 1);
}
int main(){
    int b1, b2;
    cin >> b1 >> b2;
    int h1, h2;
    cin >> h1 >> h2;
    initblocked(blocked, h1, h2);
    int result = 0;
     result = dfs(b1, b2);
    cout << result;
	return 0;

}