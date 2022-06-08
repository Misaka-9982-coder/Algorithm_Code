#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int h[N], cnt;

void down(int u) {
    int t = u;//t标记最小值

    if(u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
    if(u * 2 + 1 <= cnt && h[2 * u + 1] < h[t]) t = u * 2 + 1;

    //根结点不是最小值
    if(u != t) {
        swap(h[u], h[t]);
        down(t);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++ ) scanf("%d", &h[i]);
    cnt = n;

    for(int i = n / 2; i; i -- ) down(i);

    while(m -- ) {
        printf("%d ", h[1]);
        h[1] = h[cnt];
        cnt -- ;
        down(1);
    }
    return 0;
}

//    i为什么从n/2开始down？
//
//    首先要明确要进行down操作时必须满足左儿子和右儿子已经是个堆。
//
//    开始创建堆的时候，元素是随机插入的，所以不能从根节点开始down，而是要找到满足下面三个性质的结点：
//
//    1.左右儿子满足堆的性质。
//
//    2.下标最大（因为要往上遍历）
//
//    3.不是叶结点（叶节点一定满足堆的性质）