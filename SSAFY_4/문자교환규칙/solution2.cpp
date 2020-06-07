#include <iostream>
using namespace std;
int N = 0;
#include <vector>
int main(){
    cin >> N;
    vector<int> ns;
    int sum = 0;
    for(int i=0; i<N; i++){
        int num = 0; cin >> num;
        ns.push_back(num);
        sum += num;
    }
    int average = sum / N;
    int answer = 0;
    for(int i=0; i<N; i++){
        answer += abs(ns[i] - average);
    }
    cout << answer << "\n";
    return 0;
}