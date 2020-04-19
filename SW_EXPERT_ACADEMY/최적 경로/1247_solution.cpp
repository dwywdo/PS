#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> cls;
int main(){
    int T = 0;
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cls.clear();
        int N = 0; cin >> N;
        int start_x = 0; int start_y = 0;
        int end_x = 0; int end_y = 0;
        cin >> start_x >> start_y;
        cin >> end_x >> end_y;
        for(int i=0; i<N; i++){
            int cl_x = 0 ; int cl_y = 0;
            cin >> cl_x >> cl_y;
            cls.push_back(make_pair(cl_x, cl_y));
        }
        sort(cls.begin(), cls.end());
        int answer = 987654321;
        do{
            int dist = 0;
            dist += (abs(start_x - cls[0].first) + abs(start_y - cls[0].second));
            for(int i=0; i<cls.size()-1; i++){
                dist += (abs(cls[i].first - cls[i+1].first) + abs(cls[i].second - cls[i+1].second));
            }
            dist += (abs(end_x - cls[cls.size()-1].first) + abs(end_y - cls[cls.size()-1].second));
            if(dist < answer) answer = dist;
        }while(next_permutation(cls.begin(), cls.end()));
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;
}