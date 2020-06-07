#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> ans;
int main(){
    int N = 0;
    int M = 0;
    cin >> N;
    cin >> M;
    int tempN = N;
    int len = 0;
    while(tempN > 0){
        len++;
        ans.push_back(tempN % 10);
        tempN = tempN / 10;
    }
    int temp = 0;
    int sum = 0;
    for(int k=1; k<=len; k++){
        int first = (N / pow(10, k));
        int ak = ans[k-1];
        int second = 0;
        if(ak >= M) second = 1;
        else second = 0;
        int result = first + second;
        result = result * pow(10, k-1);
        sum += result;
    }
    cout << sum << "\n";
    return 0;
}