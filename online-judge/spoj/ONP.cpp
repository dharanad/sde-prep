#include <iostream>
#include <stack>
#include <string>
#define fast cin.sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int prec(char c){
    switch(c){
        case '^':
            return 5;
        case '/':
            return 4;
        case '*':
            return 3;
        case '+':
            return 2;
        case '-':
            return 1;
    }
    return -1; // to handle bracket
}
string rpn(string &exp){
    string res;
    stack<char> stk;
    for(char c : exp){
        if(c >= 'a' && c <= 'z'){
            res.push_back(c);
        }else if(c == '('){
            stk.push(c);
        }else if(c == ')'){
            while(!stk.empty() && stk.top() != '('){
                res.push_back(stk.top()); stk.pop();
            }
            if(!stk.empty()){
                stk.pop();
            }else{
                cout << "ERR" << "\n";
            }
        }else{
            while(!stk.empty() && prec(c) <= prec(stk.top())){ // execute all the opr with higher prec
                res.push_back(stk.top()); stk.pop();
            }
            stk.push(c);
        }
    }
    return res;
}

int main(){
    fast
    int t; cin >> t;
    string exp;
    while(t--){
        cin >> exp;
        cout << rpn(exp) << "\n";
    }
    return 0;
}

/*
(a+(b*c)) ->abc*+
((a+b)*(z+x))ab+zx+*
((a+t)*((b+(a+c))^(c+d)))
(a*b-c) ab*c-
*/