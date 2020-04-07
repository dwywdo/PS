#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string inputString = "line [plus]";
    int answer = -1;
    int cnt = 0;
    vector<char> pstack1;
    vector<char> pstack2;
    vector<char> pstack3;
    vector<char> pstack4;
    for(int i=0; i<inputString.size(); i++){
        char c = inputString[i];
        if(c == '(' || c == '{' || c == '[' || c == '<') {
            if(c == '(') pstack1.push_back(c); 
            if(c == '{') pstack2.push_back(c);
            if(c == '[') pstack3.push_back(c);
            if(c == '<') pstack4.push_back(c);
            cnt++;
        }
        else if(c == ')' || c == '}' || c == ']' || c == '>'){
            vector<char> *pstack; char rightpair;
            if(c == ')') {
                pstack = &pstack1;
                rightpair = '(';
            }
            else if(c == '}') {
                pstack = &pstack2;
                rightpair = '{';
            }
            else if(c == ']') {
                pstack = &pstack3;
                rightpair = '[';
            }
            else if(c == '>') {
                pstack = &pstack4;
                rightpair = '<';
            }
            
            if((*pstack).empty()){
                answer = -1;
                return answer;
            }
            
            else{
                char top = (*pstack).back();
                if(top != rightpair){
                    answer = -1;
                    return answer;
                }
                else{
                    (*pstack).pop_back();
                }
            }
        }       
    }
    if(pstack1.empty() && pstack2.empty() && pstack3.empty() && pstack4.empty()){
        cout << pstack3.size() << "\n";
        answer = cnt;
    }
    else{
        answer = -1;
    }
    cout << answer << "\n";
    return answer;
}