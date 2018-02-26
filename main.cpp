//九度 搜索 例6.5素数环 递归+深度优先  回溯
//感觉有些不理解的地方
#include <stdio.h>
#define M 18
int ans[M];//环里有哪些数
int mark[M];
int n;//全局
int prime[] = {2,3,5,7,11,13,17,19,23,29,31};

bool judge(int x)//判断一个数是否为素数
{
    int i;
    for(i = 0; i < 11; i++)
    {
        if(prime[i] == x) return true;
    }
    return false;
}

void check()//检查 输出 解
{
    if(judge(ans[n] + ans[1]) == false) return;//判断最后一个数和第一个数是否满足条件 因为DFS里只判断num和num-1

    int i;
    for(i = 1; i <= n; i++)
    {
        printf("%d ",ans[i]);
    }
    printf("\n");
}

void DFS(int num)
{
    if(num > 1)
    {
        if(judge(ans[num-1] + ans[num]) == false)
            return;//到num这里不满足 回溯
    }

    if(num == n)
    {
        check();
        return;
    }

    int i;
    for(i = 2; i <= n; i++)//从2到n找一个还没被标记的点 放到环里
    {
    if(mark[i] == false){
        mark[i] = true;
        ans[num + 1] = i;//把这个没被访问过的i放到环里
        DFS(num + 1);
        mark[i] = false;
      }
   }
}
int main()
{
//int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i;
        for(i = 0;i < 17;i++)
            mark[i] = false;

        ans[1] = 1;//起始 1
        mark[1] = true;
        DFS(1);

    }
    return 0;
}
