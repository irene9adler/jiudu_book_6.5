//�Ŷ� ���� ��6.5������ �ݹ�+�������  ����
//�о���Щ�����ĵط�
#include <stdio.h>
#define M 18
int ans[M];//��������Щ��
int mark[M];
int n;//ȫ��
int prime[] = {2,3,5,7,11,13,17,19,23,29,31};

bool judge(int x)//�ж�һ�����Ƿ�Ϊ����
{
    int i;
    for(i = 0; i < 11; i++)
    {
        if(prime[i] == x) return true;
    }
    return false;
}

void check()//��� ��� ��
{
    if(judge(ans[n] + ans[1]) == false) return;//�ж����һ�����͵�һ�����Ƿ��������� ��ΪDFS��ֻ�ж�num��num-1

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
            return;//��num���ﲻ���� ����
    }

    if(num == n)
    {
        check();
        return;
    }

    int i;
    for(i = 2; i <= n; i++)//��2��n��һ����û����ǵĵ� �ŵ�����
    {
    if(mark[i] == false){
        mark[i] = true;
        ans[num + 1] = i;//�����û�����ʹ���i�ŵ�����
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

        ans[1] = 1;//��ʼ 1
        mark[1] = true;
        DFS(1);

    }
    return 0;
}
