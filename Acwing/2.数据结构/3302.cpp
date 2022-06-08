#include<iostream>
#include<stack>
#include<string>
#include<unordered_map>
using namespace std;

stack<int> num;
stack<char> op;

//优先级表
unordered_map<char, int> h{
    {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}
};

void eval() {
    int b = num.top(); num.pop(); //第二个操作数
    int a = num.top(); num.pop(); //第一个操作数
    char p = op.top(); op.pop();  //运算符
    int r = 0;
    
    switch(p) {
        case '+': r = a + b; break;
        case '-': r = a - b; break;
        case '*': r = a * b; break;
        case '/': r = a / b; break;
    }
    num.push(r);   //结果入栈
}


int main() {
    string s; cin >> s;

    for (int i = 0; i < s.size(); i ++ ) {
        if (isdigit(s[i])) { //数字入栈
            int x = 0, j = i;//计算数字
            while (j < s.size() && isdigit(s[j])) {
                x = x * 10 + s[j] - '0';
                j ++ ;
            }
            num.push(x);//数字入栈
            i = j - 1;
        } else if (s[i] == '(') {//左括号无优先级，直接入栈
            op.push(s[i]);
        } else if (s[i] == ')') {//括号特殊，遇到左括号直接入栈，遇到右括号计算括号里面的
            //一直计算到左括号
            while(op.top() != '(') eval();
            op.pop();//左括号出栈
        } else {
            //待入栈运算符优先级低，则先计算    
            while (op.size() && h[op.top()] >= h[s[i]]) eval();
            op.push(s[i]);  //操作符入栈
        }
    }

    while (op.size()) eval();//剩余的进行计算
    cout << num.top() << endl;//输出结果
    return 0;
}