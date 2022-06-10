#include<iostream>
#include<cstring>
using namespace std;

const int N = 510, M = 1e5 + 10;
int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool find(int x) {
    //遍历自己喜欢的女孩
    for(int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];

        //如果在这一轮模拟匹配中,这个女孩尚未被预定
        if(!st[j]) {
            st[j] = true;//那x就预定这个女孩了

            //如果女孩j没有男朋友，
            //或者她原来的男朋友能够预定其它喜欢的女孩。
            //配对成功,更新match
            if(match[j] == 0 || find(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }

    //自己中意的全部都被预定了。配对失败。
    return false;
}

int main() {
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof h);

    while(m -- ) {
        int a, b; cin >> a >> b;
        add(a, b);
    }

    int res = 0;
    for(int i = 1; i <= n1; i ++ ) {
        //因为每次模拟匹配的预定情况都是不一样的
        //所以每轮模拟都要初始化
        memset(st, false, sizeof st);
        if(find(i)) res ++;
    }

    cout << res << endl;
    return 0;
}