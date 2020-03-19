#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
string input = "";
int answer = -2147483648;
bool visited[10];
vector<char> ops;
vector<long long> numbers;
int calculate(vector<int> opIndex){
    vector<long long> copy = numbers;
    vector<char> op_copy = ops;
    for(int i=0; i<N/2; i++){
        if(find(opIndex.begin(), opIndex.end(), i) != opIndex.end()){
            long long result = 0;
            if(ops[i] == '*'){
                result = copy[i] * copy[i+1];
            }
            else if(ops[i] == '-'){
                result = copy[i] - copy[i+1];
            }
            else if(ops[i] == '+'){
                result = copy[i] + copy[i+1];
            }
            op_copy[i] = '+';
            copy[i] = result;
            copy[i+1] = 0;
        }
    }
    long long cand = copy[0];
    for(int i=0; i<copy.size() - 1; i++){
        char op = op_copy[i];
        if(op == '*'){
            cand *= copy[i+1];
        }
        else if(op == '-'){
            cand -= copy[i+1];
        }
        else if(op == '+'){
            cand += copy[i+1];
        }
    }
    
    return cand;
}
void go(int index, int count, vector<int> opIndex){
    if(opIndex.size() == count){
        // for(int i=0; i<opIndex.size(); i++) cout << opIndex[i] << " ";
        // cout << endl;
        long long cand = calculate(opIndex);
        if(cand > answer) answer = cand;
        return;
    }
    for(int i=index; i<N/2; i++){
        if(visited[i]) continue;
        visited[i] = true;
        if(i-1>=0) visited[i-1] = true;
        if(i+1< N) visited[i+1] = true;
        opIndex.push_back(i);

        go(i + 1, count, opIndex);

        visited[i] = false;
        if(i-1>=0) visited[i-1] = false;
        if(i+1< N) visited[i+1] = false;
        opIndex.pop_back();
    }
}
int main(){
    cin >> N;
    cin >> input;
    int opCount = N/2;
    for(int i=0; i<input.size(); i++){
        if(input[i] >= '0' && input[i] <= '9') numbers.push_back(input[i] - '0');
        else ops.push_back(input[i]);
    }
    for(int i=0; i<=(opCount/2)+1; i++){
        vector<int> opIndex;
        go(0, i, opIndex);
    }
    cout << answer;
    return 0;
}