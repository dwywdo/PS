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
        
        for(int i=0; i<N; i++){
            int min = i;
            for(int j = i + 1; j<N; j++){
                if(arr[min] > arr[j]) min = j;
            }
            if(min != i){
                int temp = arr[min];
                arr[min] = arr[i];
                arr[i] = temp;
            }
        }

        for(int i=0; i<N; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }    
    return 0;
}