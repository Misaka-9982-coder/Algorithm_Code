#include<iostream>
#include<vector>
using namespace std;

vector<int> mul(vector<int>& A, vector<int>& B) {
    vector<int> C(A.size() + B.size());
    for(int i = 0; i < A.size(); i ++ ) 
        for(int j = 0; j < B.size(); j ++ )
            C[i + j] += A[i] * B[j];
    
    for(int i = 0, t = 0; i < C.size() || t; i ++ ) {
        t += C[i];
        if(i >= C.size()) C.push_back(t % 10);
        else C[i] = t % 10;
        t /= 10;
    }
    
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    string a, b; cin >> a >> b;
    vector<int> A, B;
    
    for(int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');

    auto C = mul(A, B);
    for(int i = C.size() - 1; i >= 0; i -- ) cout << C[i];
    cout << endl;

    return 0;
}