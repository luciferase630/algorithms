#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
// #define ll longlong
typedef long long ll;
using namespace std;

const int dx[8] = { +1  , +1, +2,  +2,  -1,  -1,  -2,  -2 };
const int dy[8] = { +2,  -2,  +1,  -1,  +2,  -2,  +1,  -1 };//标记不能走的位置,一共八种组合
bool blocked[21][21] = { false };
//初始化格挡数组
void initblocked(bool blocked[][21], int h1, int h2)//可以不指定行
{
    blocked[h1][h2] = true;//正好它的坐标从00开始，就是跟数组一样
    for (int i = 0; i < 8; i++)
    {
        if ((h1 + dx[i]) >= 0 && (h2 + dy[i]) >= 0 && (h1 + dx[i]) < 21 && (h2 + dy[i]) < 21)//当坐标合法时  //忘记不能越界
            blocked[h1 + dx[i]][h2 + dy[i]] = true;//此坐标显示为被控制
    }
}
void problemfixer(ll arr[][21], int b1, int b2)//还是这块写的不好，这前面的初始化没问题
{
    for (int i = 0; i <= b1; i++)
    {
        for (int j = 0; j <= b2; j++)//循环到b1 b2应该就行
        {
            if (blocked[i][j] == true)//被控制就跳过
            {
                continue;
            }
            if (i == 0 && j == 0)//第一个要跳过
            {
                continue;
            }//就是从这里开始逻辑开始乱了的
            if (i > 0)//神之一手
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
    ll arr[21][21] = { 0 };//两步初始化
    arr[0][0] = 1;//这就算是初始化好了
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