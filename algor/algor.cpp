#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
/*
first A+B problem
int main()
{
    int a,b;
    cin >>a >>b;
    cout << a+b << endl;
    return 0;
}
*/

/*
///SECOND
//找到那个能算出最大值的人类
int  findtheone1(vector<int> vec, int l, int n)
{
    //  、、 vector<int>left(n);//没必要，本身就是left
    vector<int>right(n);
    for (int i = 0; i < n; i++)
    {
        right[i] = abs(vec[i] - (l + 1));
    }
    int a1 = *max_element(vec.begin(), vec.end());//本身是迭代器，返回的是该死的地址，也就是指针
    int a2 = *max_element(right.begin(), right.end());//漏掉括号
    if (a1 >= a2)
    {
        return a1;
    }
    else
    {
        return a2;
    }
}
//找到那个能算出最小值的人类，这个最小值应该是相对而言最大的啊？
//不然怎么包括自己，找左右里面最小的，然后再找最小里面最大的
int  findtheone2(vector<int> vec, int l, int n)
{
    //  、、 vector<int>left(n);//没必要，本身就是left
    vector<int>right(n);
    for (int i = 0; i < n; i++)
    {
        right[i] = abs(vec[i] - (l + 1));
    }
    int a1 = *max_element(vec.begin(), vec.end());//本身是迭代器，返回的是该死的地址，也就是指针
    int a2 = *max_element(right.begin(), right.end());//漏掉括号
    int a4 = 0;
    vector<int>final1(n);
    for (int i = 0; i < n; i++)
    {

        a4 = min(vec[i], right[i]);
        final1[i] = a4;
    }
    int a3 = *max_element(final1.begin(), final1.end());
    return a3;
}

int main()
{

    int L;
    int N;
    int a;
    cin >> L;
    cin >> N;
    if (N == 0)
    {
        cout << "0 0" << endl;
        return 0;
    }
    vector<int>myvector(N);//顺手帮我把动态数组复习了
    for (int i = 0; i < N; i++)//md这debug也是因为中文路径，无敌了、、我无法跳进函数里debug
    {
        cin >> myvector[i];

    }
    int maxresult = findtheone1(myvector, L, N);//最大值我找到了
    int minresult = findtheone2(myvector, L, N);
    cout << minresult << " ";
    cout << maxresult;

    return 0;
}
*/

int a1[21][21] = {1};// first  修改点，因为忘记包含2121了
void modifyhorse(int(* arr)[21], int h1, int h2)//对马的特殊操作
{
    arr[h1 + 1][h2 + 2] = 100;
    arr[h1 + 2][h2 + 1] = 100;
    if ((h1 - 1) >= 0)
    {
        arr[h1 - 1][h2 + 2] = 100;
    }
    if ((h2 - 2) >= 0) 
    {
        arr[h1 + 1][h2 - 2] = 100;
    }
    if ((h1 - 1) >= 0 && (h2 - 2) >= 0)
    {
        arr[h1 - 1][h2 - 2] = 100;
    }
    if ((h1 - 2) >= 0)
    {
        arr[h1 - 2][h2 + 1] = 100;
    }
    if ((h2 - 1) >= 0)
    {
        arr[h1 + 2][h2 - 1] = 100;
    }
    if ((h2 - 1) >= 0 && (h1 - 2) >= 0)
    {
        arr[h1 - 2][h2 - 1] = 100;
    }
    arr[h1][h2] = 100;
}
void finalends(int(*arr)[21])
{
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if (arr[i][j] == 100)
            {
                continue;
            }
            if (i == 0 && j == 0)
            {
                continue;
            }
            else if ((i - 1) < 0)
            {
                arr[i][j] = arr[i][j - 1];

            }
            else if ((j - 1) < 0)
            {
                arr[i][j] = arr[i - 1][j];

            }
            else
            {
                if (arr[i - 1][j] != 100 && arr[i][j - 1] != 100)
                {
                    arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
                }

                if (arr[i - 1][j] == 100)
                {
                    arr[i][j] = arr[i][j - 1];
                }
                if (arr[i][j - 1] == 100)
                {
                    arr[i][j] = arr[i - 1][j];
                }
            }
        }
    }
}
int main()
{
    int b1, b2;
    cin >> b1 >> b2;
    int h1, h2;
    cin >> h1 >> h2;
    modifyhorse(a1, h1, h2);
    finalends(a1);
 /*   for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cout << a1[i][j] << endl;

        }
    }
 
    
      for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cout << a1[i][j] << " ";

        }
        cout << endl;
    }
 */
    cout << a1[b1][b2];
    return 0;
}

//问题1 没有意识到20，20，实际上需要21个数组元素
//问题2 把动态规划用的数组和block的数组合在一起了
//问题3 没有考虑初始值，最开始的点要是被控制，应该就直接不能走
//对于累加理解不清晰