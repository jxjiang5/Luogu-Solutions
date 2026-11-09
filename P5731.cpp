#include<iostream>
using namespace std;
int a[15][15];
int main()
{
    int n; cin>>n;
    int x=1;int y=1;
    int d=0;//d代表方向，初始方向为右
    //定义方向向量。dx,dy分别为右下左上
    int dx[]={0,1,0,-1};
    int dy[]={1,0,-1,0};
    for(int i=1;i<=n*n;i++)//在 C++ 里，^ 是按位异或（一种二进制的位运算），根本不是 n 的平方！
    {
        a[x][y]=i;
        int nx=dx[d]+x;
        int ny=dy[d]+y;
        if(ny>n||nx>n||nx<1||ny<1||a[nx][ny]!=0) //还要判断有没有走到已经填过数字的格子上， || a[x][y] != 0)
        {
            d=(d+1)%4;
            nx=dx[d]+x;
            ny=dy[d]+y;
        }
        x=nx;
        y=ny;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%3d",a[i][j]);
        }
        cout<<endl;
    }
    return 0;
}