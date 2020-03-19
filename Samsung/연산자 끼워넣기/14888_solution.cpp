#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int a[100];
int opcount[4]; 
// 0: + 
// 1: - 
// 2: x 
// 3: /
vector<char> ops;
int main(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> a[i];
    for(int i=0; i<4; i++) cin >> opcount[i];
    for(int i=0; i<4; i++){
        int cnt = opcount[i];
        for(int j=0; j<cnt; j++){
            if(i==0) ops.push_back('+');
            else if(i==1) ops.push_back('-');
            else if(i==2) ops.push_back('x');
            else if(i==3) ops.push_back('/');
        }
    }
    sort(ops.begin(), ops.end());
    int max = -1000000000;
    int min = 1000000000;
    do{
        int result = a[0];
        for(int i=0; i<ops.size(); i++){
            if(ops[i] == '+'){
                result += a[i+1];
            }
            else if(ops[i] == '-'){
                result -= a[i+1];
            }
            else if(ops[i] == 'x'){
                result *= a[i+1];
            }
            else if(ops[i] == '/'){
                result /= a[i+1];
            }
        }
        if(result > max) max = result;
        if(result < min) min = result;
    }while(next_permutation(ops.begin(), ops.end()));
    cout << max << '\n';
    cout << min << '\n';
    return 0;
}