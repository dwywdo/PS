#include <iostream>
using namespace std;
int N;
int series[10000];
int previousSeries(int series[10000]){
    int i = 0;
    for(int idx = 1; idx<N; idx++){
        if(series[idx-1] > series[idx]) i = idx;
    }
    if(i==0) return -1;

    int j = 0;
    for(int idx = i; idx < N; idx++){
        if(series[i-1] > series[idx]){
            j = idx;
        }
    }
    int temp = series[i-1];
    series[i-1] = series[j];
    series[j] = temp;
    
    j = N-1;
    while(i<j){
        int temp = series[i];
        series[i] = series[j];
        series[j] = temp;
        i+=1; j-=1;
    }
    return 0;
}
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> series[i];
    }
    if(previousSeries(series) == -1){
        cout << -1 << endl;
    }
    else{
        for(int i=0; i<N; i++){
            cout << series[i] << " ";
        }
        cout << endl;
    }
    return 0;
}