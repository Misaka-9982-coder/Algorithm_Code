#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int N = 100010;
int h[N], ph[N], hp[N], cnt;
/// hp是heap pointer的缩写，表示堆数组中下标到第k个插入的映射
/// ph是pointer heap的缩写，表示第k个插入到堆数组中的下标的映射
/// hp和ph数组是互为反函数的

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;
    if (u * 2 <= cnt && h[u * 2] < h[t])
        t = u * 2;
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t])
        t = u * 2 + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && h[u] < h[u / 2])
    {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

int main()
{
    int n, m = 0;
    scanf("%d", &n);
    while (n--)
    {
        char op[5];
        int k, x;
        scanf("%s", op);
        if (!strcmp(op, "I"))
        {
            scanf("%d", &x);
            cnt++;
            m++; ///记录第几次插入
            ph[m] = cnt, hp[cnt] = m;
            //每次插入都是在堆尾插入
            h[cnt] = x; ///记录插入的值
            up(cnt);
        }
        else if (!strcmp(op, "PM"))
            printf("%d\n", h[1]);
        else if (!strcmp(op, "DM"))
        {
            heap_swap(1, cnt);
            cnt--;
            down(1);
        }
        else if (!strcmp(op, "D"))
        {
            scanf("%d", &k);
            k = ph[k];
            ///必须要保存当前被删除结点的位置
            heap_swap(k, cnt); ///第k个插入的元素移到了堆尾，此时ph[k]指向堆尾
            cnt--;             ///删除堆尾
            up(k);             /// k是之前记录被删除的结点的位置
            down(k);
        }
        else
        {
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            up(k);
            down(k);
        }
    }
    return 0;
}