#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
/*
// 递归函数，用于找到所有的组合
int dfs(int n, int max)
{
    if (n==0)
    {
        return 1;
    }
    if (n<0||max==0)
    {
        return 0;
    }
    return dfs(n - max, max) + dfs(n, max - 1);
}*/
//最重要的是知道，5的拆分过程中实际上是对f4 加到f1
/*int dfs2(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if(n < 0)
    {
        return 0;
    }
    int total=0;
    for (int i = 1; i <=n; i++)//太重要了，直接就是把i拆出去
    {
        total += dfs2(n - i);//dfs2(0)包含0的拆分，5，0 实际上是1，但是不能f(5)调用f(5)这™纯粹的bug
    }
    return total;
}*/

vector<int>path;//要用的是它的length
vector<string>partitions;
//递归加回溯
void dfs(int n) {
    string partition = "";
    if (n == 0)//递归结束条件
    {
        for (int i = 0; i < path.size(); i++)
        {
            partition += to_string(path[i]);
            if (i != path.size() - 1)//减法的优先级高于
            {
                partition += "+";
            }
        }
        partitions.push_back(partition);
    }
    for (int i = path.empty() ? 1 : path.back(); i <= n; i++)
    {
        path.push_back(i);
        cout << "dfs(" << n-i << ")"<<endl;
        dfs(n - i);//我没有进行判断n -i是否大于0,有点漏洞？也许这个n-i永远就不可能小于0，因为i是n里面拆出来的啊
        //这步要回溯
        path.pop_back();//最后一位给他pop了
        cout << "reverse for once" << endl;
    }
}
int main() {
    int n;
    cin >> n;
    dfs(n);
    for (int i = 0; i < partitions.size()-1; i++)
    {
  
        cout <<  partitions[i] << endl;
    }
    return 0;
}