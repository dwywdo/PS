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
        for(int i=0; i<N; i++) cin >> arr[i];
        for(int i=0; i<N; i++) {
            cout << arr[i] << " ";
        }
        cout << "-> ";
        
        for(int loop=0; loop < N-1; loop++){
            for(int i=0; i<N-1-loop; i++){
                if(arr[i] > arr[i+1]){
                    int temp = arr[i+1];
                    arr[i+1] = arr[i];
                    arr[i] = temp;
                }
            }
        }
        for(int i=0; i<N; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }    
    return 0;
}