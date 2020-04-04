#include <iostream>
#include <cstring>
using namespace std;
int T; int N;
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cin >> N; 
        int arr[10001]; 
        int result[10001]; 
        int cnts[10001]; // 최솟값이 0, 최댓값이 10000의 범위 내에 정수 존재
        int maxValue = 0; 
        memset(arr, 0, sizeof(arr));
        memset(result, 0, sizeof(result));
        memset(cnts, 0, sizeof(cnts));
        for(int i=0; i<N; i++) cin >> arr[i];
        for(int i=0; i<N; i++) {
            cout << arr[i] << " ";
        }
        cout << "-> ";
        
        for(int i=0; i<N; i++){
            if(maxValue < arr[i]) maxValue = arr[i];
            cnts[arr[i]]++;
        }
        for(int i=0; i<=maxValue; i++){
            cnts[i] = cnts[i] + cnts[i-1];
        }
        for(int i=N-1; i>=0; i--){
            result[--cnts[arr[i]]] = arr[i];
        }
        for(int i=0; i<N; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
    }    
    return 0;
}