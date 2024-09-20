#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
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