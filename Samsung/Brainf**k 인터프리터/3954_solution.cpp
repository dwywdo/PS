#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
uint8_t mem[100000];
int Sm = 0; int Sc = 0; int Si = 0; int T = 0;
string code = "";
string input = "";
int loop[4096];
int main(){
    cin >> T;
    for(int t=0; t<T; t++){
        memset(mem, 0, sizeof(mem));
        memset(loop, 0, sizeof(loop));
        cin >> Sm >> Sc >> Si;
        cin >> code >> input;
        stack<int> pstack;
        for(int c=0; c<Sc; c++){
            char inst = code[c];
            if(inst == '['){
                pstack.push(c);
            }
            else if(inst == ']'){
                if(!pstack.empty()){
                    loop[pstack.top()] = c;
                    loop[c] = pstack.top();
                    pstack.pop();
                }
            }
        }
        int pointer = 0; int readIndex = 0; int operIndex = 0; int maxOperIndex = 0;
        int openCount = 0; int closeCount = 0; int loop_start = 0; int loop_end = 0;
        bool flag = false;
        for(int i=1; i<=50000000; i++){
            if(operIndex >= Sc){
                cout << "Terminates" << endl;
                flag = true;
                break;
            }
            char inst = code[operIndex];
            if(inst == '-') mem[pointer]--;
            else if(inst == '+') mem[pointer]++;
            else if(inst == '<'){
                pointer--; if(pointer < 0) pointer = Sm - 1;
            }
            else if(inst == '>'){
                pointer++; if(pointer > Sm - 1) pointer = 0;
            }
            else if(inst == '['){
                openCount++;
                if(mem[pointer] == 0){
                    operIndex = loop[operIndex]; continue;
                }
            }
            else if(inst == ']'){
                closeCount++;
                if(mem[pointer] != 0){
                    operIndex = loop[operIndex]; continue;
                }
            }
            else if(inst == '.') {

            }
            else if(inst == ','){
                if(readIndex > Si - 1){
                    mem[pointer] = 255;
                }
                else{
                    mem[pointer] = input[readIndex];
                    readIndex++;
                }
            }
            operIndex++;
            maxOperIndex = operIndex > maxOperIndex ? operIndex : maxOperIndex;
        }
        if(!flag){
            cout << "Loops "<< loop[maxOperIndex] << " " << maxOperIndex << endl;
        }
    }
    return 0;
}