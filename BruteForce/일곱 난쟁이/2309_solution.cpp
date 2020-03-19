#include <iostream>
#include <algorithm>
using namespace std;
int heights[9];
int main(){
    int sum = 0;
    for(int i=0; i<9; i++){
        cin >> heights[i];
        sum += heights[i];
    }
    sort(heights, heights + 9);
    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            if(sum - heights[i] - heights[j] == 100){
                for(int k=0; k<9; k++){
                    if(i==k || j==k) continue;
                    cout << heights[k] << endl;
                }
                // 가능한 정답이 여러 가지인 경우에는 아무것이나 출력하므로, 하나 출력시 리턴한다
                return 0;
            }
        }
    }
    return 0;
}