#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T = 0;
int N = 0;
typedef struct work{
    int time = 0;
    int due = 0;
}WORK;
bool compare(WORK &A, WORK &B){
    return A.due > B.due;
}
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cin >> N;
        vector<WORK> works;
        for(int i=0; i<N; i++){
            int time; int due;
            cin >> time >> due;
            WORK w; w.time = time; w.due = due; works.push_back(w);
        }
        sort(works.begin(), works.end(), compare);
        
        int x = works[0].due;
        for(int i=0; i<works.size() - 1; i++){
            x = x - works[i].time;
            if(x >= works[i+1].due) x = works[i+1].due;
        }
        x = x - works[works.size()-1].time;
        cout << "#" << test_case << " " <<  x << "\n";
    }
    return 0;
}