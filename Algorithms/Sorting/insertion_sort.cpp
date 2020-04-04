#include <iostream>
#include <cstring>
using namespace std;
int T; int N;
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cin >> N; 
        int arr[10001];
        memset(arr, 0, sizeof(arr));
        for(int i=0; i<N; i++) cin >> arr[i];
        for(int i=0; i<N; i++) {
            cout << arr[i] << " ";
        }
        cout << "-> ";
        
        int i, j, key;
        for(int i=1; i<N; i++){
            key = arr[i];
            for(j=i-1; j>=0 && arr[j] > key ; j--){
                arr[j+1] = arr[j];
            }
            arr[j+1] = key;
        }

        for(int i=0; i<N; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }    
    return 0;
}