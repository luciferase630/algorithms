#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;

const int dx[8] = { +1  , +1, +2,  +2,  -1,  -1,  -2,  -2 };
const int dy[8] = { +2,  -2,  +1,  -1,  +2,  -2,  +1,  -1 };//标记不能走的位置,一共八种组合
bool blocked[21][21] = { false };
void initblocked(bool blocked[][21], int h1, int h2)//可以不指定行
{
    blocked[h1][h2] = true;//正好它的坐标从00开始，就是跟数组一样
    for (int i = 0; i < 8; i++)
    {
        if ((h1 + dx[i]) >= 0 && (h2 + dy[i]) >= 0 && (h1 + dx[i]) < 21 && (h2 + dy[i]) < 21)//当坐标合法时  //忘记不能越界
            blocked[h1 + dx[i]][h2 + dy[i]] = true;//此坐标显示为被控制
    }
}
/*
//这函数是没法写对了，受不了
int dfs(int b1, int b2)
{
    if (b1 == 0 && b2 == 0) {
        return 1;
    }
    else if (b1 == 0 && b2 != 0)//第一行
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
    else if (b1 != 0 && b2 == 0)//第一列
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
    //问题出在处理过程太辣鸡，本身应该当一个单元来看
}
*/
int dfs(int b1, int b2)
{
    if (b1 < 0 || b2 < 0) {//b1 和b 2有一个小于0的时候就直接返回零，因为它要避免越界
        return 0;
    }
    if (b1 == 0 && b2 == 0) {//如果是最后一个元素
        return 1;
    }
    if (blocked[b1][b2]) {//如果该位置被阻挡则直接返回零
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