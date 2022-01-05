#include <bits/stdc++.h>
using namespace std;
bool issafe(int **arr, int x, int y, int n)
{
    if (x < n && y < n && arr[x][y]==1)
        return true;
    return false;
}
bool ratinMaze(int **arr, int x, int y, int n, int **soln)
{
    if (x == n - 1 && y == n - 1)
    {
        soln[x][y] = 1;
        return true;
    }
    if(issafe(arr,x,y,n))
    {
        soln[x][y] = 1;
        if (ratinMaze(arr, x + 1, y, n,soln))
            return true;
        if (ratinMaze(arr, x, y + 1, n,soln))
            return true;
        soln[x][y] = 0; //backtracking
        return false;
    }
     return false;
}
int main()
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
            cout<<endl;

    int **solnarr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solnarr[i] = new int[n];
        for (int j = 0; j < n; j++)
            solnarr[i][j] = 0;
    }

    if (ratinMaze(arr, 0, 0, n, solnarr))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solnarr[i][j] << " ";
            }
            cout << endl;
        }
    }
}