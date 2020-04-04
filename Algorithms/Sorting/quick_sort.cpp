#include <iostream>
#include <cstring>
using namespace std;
int T; int N;
int partiton(int list[], int left, int right){
    int pivot; int temp;
    int low, high;
    low = left;
    high = right + 1;
    pivot = list[left];
    do{
        do{
            low++;   
        }while(low<=right && list[low]<pivot);
        do{
            high--;
        }while(high>=left && list[high]>pivot);
        if(low < high){
            temp = list[low];
            list[low] = list[high];
            list[high] = temp;
        }
    }while(low < high);

    temp = list[left];
    list[left] = list[high];
    list[high] = temp;

    return high;
}
void quick_sort(int list[], int left, int right){
    if(left < right){
        int q = partiton(list, left, right);
        quick_sort(list, left, q-1);
        quick_sort(list, q+1, right);
    }
}
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
        
        quick_sort(arr, 0, N-1);

        for(int i=0; i<N; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }    
    return 0;
}