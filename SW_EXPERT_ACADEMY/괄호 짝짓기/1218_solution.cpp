#include <iostream>
#include <stack>
using namespace std;

int main(){
    int T = 10;
    for(int test_case=1; test_case<=T; test_case++){
        stack<char> pstack;
        int len = 0; string str = "";
        cin >> len;
        cin >> str;
        int answer = -1;
        for(int i=0; i<len; i++){
            char c = str[i];
            if(c=='{' || c=='[' || c=='(' || c=='<'){
                pstack.push(c);
            }
            else{
                char top = pstack.top();
                if(c=='}' && top == '{'){
                    pstack.pop();
                }
                else if(c==']' && top =='['){
                    pstack.pop();
                }
                else if(c==')' && top == '('){
                    pstack.pop();
                }
                else if(c=='>' && top == '<'){
                    pstack.pop();
                }
                else{
                    answer = 0;
                    break;
                }
            }
        }
        if(pstack.empty() && answer == -1){
            answer = 1;
        }
        else if(!pstack.empty()){
            answer = 0;
        }
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;
}