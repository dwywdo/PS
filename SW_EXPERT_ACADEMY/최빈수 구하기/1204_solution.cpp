#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T = 0;
bool compare(pair<int, int> &a, pair<int, int> &b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    else{
        return a.first > b.first;
    }
}
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        int counts[101] = {0, };
        vector<pair<int, int>> lst;
        int tc = 0; cin >> tc;
        for(int i=0; i<1000; i++){
            int score = 0; cin >> score;
            counts[score]++;
        }
        for(int i=0; i<=100; i++) {
            if(counts[i] != 0) lst.push_back(make_pair(counts[i], i));
        }
        sort(lst.begin(), lst.end(), compare);
        cout << "#" << tc << " " << lst[0].second << "\n";
        int temp = 0;
    }
    return 0;
}