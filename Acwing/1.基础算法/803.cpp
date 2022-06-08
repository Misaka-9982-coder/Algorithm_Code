#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII;
int n;
vector<PII> seg;

void merge(vector<PII>& Seg) {
    vector<PII> res;
    int st = -2e9, ed = -2e9;
    sort(Seg.begin(), Seg.end());
    
    for(auto seg : Seg) {
        if(ed < seg.first) {
            if(ed != -2e9) {
                res.push_back({st, ed});
            }

            st = seg.first;
            ed = seg.second;
        } else {
            ed = max(ed, seg.second);
        }
    }

    if(st != -2e9) {
        res.push_back({st, ed});
    }
    Seg = res;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i ++ ) {
        int l, r; cin >> l >> r;
        seg.push_back({l, r});
    }
    merge(seg);
    cout << seg.size() << endl;
    return 0;
}