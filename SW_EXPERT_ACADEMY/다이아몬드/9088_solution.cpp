#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T, N, K;
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        vector<int> diamonds;
        cin >> N >> K; 
        for(int i=0; i<N; i++){
            int size = 0; cin >> size;
            diamonds.push_back(size);
        }
        sort(diamonds.begin(), diamonds.end());
        int left = 0; int right = 0;
        int answer = 0;
        while(left <= right && right < diamonds.size()){
            if((diamonds[right] - diamonds[left]) <= K){
                right++;
            }
            else{
                int cnt = right - left;
                if(answer < cnt) answer = cnt;
                left++; right = left;
            }
        }
        int cnt = right - left;
        if(answer < cnt) answer = cnt;
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;
}