#include <iostream>
#include <vector>
using namespace std;
int main(){
    for(int test_case=1; test_case<=10; test_case++){
        int N = 0; cin >> N; vector<int> h; 
        for(int i=0; i<N; i++){
            int height = 0;
            cin >> height;
            h.push_back(height);    
        }
        int answer = 0;
        for(int i=2; i<N-2; i++){
            int diff = 0; bool ok = true;
            int lefth1 = h[i-1]; int lefth2 = h[i-2];
            int righth1 = h[i+1]; int righth2 = h[i+2];
            if(lefth1 >= h[i] || lefth2 >= h[i]) continue;
            if(righth1 >= h[i] || righth2 >= h[i]) continue;
            int left_diff = min(h[i] - lefth1, h[i] - lefth2);
            int right_diff = min(h[i] - righth1, h[i] - righth2);
            answer += min(left_diff, right_diff);
        }
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;
}