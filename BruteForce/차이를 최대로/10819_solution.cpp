#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> series;
int getSum(vector<int> series){
    int sum = 0;
    for(int i=0; i<N-1; i++){
        sum += abs(series[i] - series[i+1]);
    }
    return sum;
}
int main(){
    cin >> N;
    int answer = 0;
    for(int i=0; i<N; i++){
        int number;
        cin >> number;
        series.push_back(number);
    }
    
    sort(series.begin(), series.end());
    
    do{
        int temp = getSum(series);
        answer = temp > answer ? temp : answer;
    }while(next_permutation(series.begin(), series.end()));
    
    cout << answer << endl;
    return 0;
}