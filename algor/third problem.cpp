#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
// #define ll longlong
typedef long long ll;
using namespace std;

const int dx[8] = { +1  , +1, +2,  +2,  -1,  -1,  -2,  -2 };
const int dy[8] = { +2,  -2,  +1,  -1,  +2,  -2,  +1,  -1 };//��ǲ����ߵ�λ��,һ���������
bool blocked[21][21] = { false };
//��ʼ��������
void initblocked(bool blocked[][21], int h1, int h2)//���Բ�ָ����
{
    blocked[h1][h2] = true;//�������������00��ʼ�����Ǹ�����һ��
    for (int i = 0; i < 8; i++)
    {
        if ((h1 + dx[i]) >= 0 && (h2 + dy[i]) >= 0 && (h1 + dx[i]) < 21 && (h2 + dy[i]) < 21)//������Ϸ�ʱ  //���ǲ���Խ��
            blocked[h1 + dx[i]][h2 + dy[i]] = true;//��������ʾΪ������
    }
}
void problemfixer(ll arr[][21], int b1, int b2)//�������д�Ĳ��ã���ǰ��ĳ�ʼ��û����
{
    for (int i = 0; i <= b1; i++)
    {
        for (int j = 0; j <= b2; j++)//ѭ����b1 b2Ӧ�þ���
        {
            if (blocked[i][j] == true)//�����ƾ�����
            {
                continue;
            }
            if (i == 0 && j == 0)//��һ��Ҫ����
            {
                continue;
            }//���Ǵ����￪ʼ�߼���ʼ���˵�
            if (i > 0)//��֮һ��
            {
                arr[i][j] += arr[i - 1][j];
            }
            if (j > 0)
            {
                arr[i][j] += arr[i][j - 1];
            }
        }
    }
}
int main() {
    int b1, b2;
    cin >> b1 >> b2;
    int h1, h2;
    cin >> h1 >> h2;
    ll arr[21][21] = { 0 };//������ʼ��
    arr[0][0] = 1;//������ǳ�ʼ������
    initblocked(blocked, h1, h2);
    if (blocked[0][0] == true)
    {
        cout << 0;
    }
    else
    {
        problemfixer(arr, b1, b2);
        cout << arr[b1][b2] << endl;
    }
    int a2;
    int a3;
    return 0;
}