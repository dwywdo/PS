#include <iostream>
#include <vector>
using namespace std;
int N, M, H;
bool go(vector<vector<bool>> &lines){
    bool ok = true;
    for(int i=1; i<=N; i++){
        int loc = i;
        for(int j=1; j<=H; j++){
            if(lines[loc][j]) loc++;
            else if(lines[loc-1][j]) loc--;
        }
        if(loc != i){
            ok = false; break;
        }
    }
    return ok;
}
int main(){
    cin >> N >> M >> H;
    vector<pair<int, int>> targets;
    vector<vector<bool>> lines(N+1, vector<bool>(H+1, false));
    for(int i=0; i<M; i++){
        int a, b; cin >> a >> b;
        lines[b][a] = true;
    }
    for(int i=1; i<=N-1; i++){
        for(int j=1; j<=H; j++){
            if(!lines[i][j]) targets.push_back(make_pair(i, j));
        }
    }
    if(go(lines)){
        cout << 0 << '\n'; return 0;
    }
    int len = targets.size();
    int answer = -1;
    for(int i=0; i<len; i++){
        int b = targets[i].first; int a = targets[i].second;
        if(lines[b-1][a] || lines[b+1][a]) continue;
        lines[b][a] = true;
        if(go(lines)){
            if(answer == -1 || answer > 1) answer = 1;
        }
        for(int j=i+1; j<len; j++){
            int b2 = targets[j].first; int a2 = targets[j].second;
            if(lines[b2-1][a2] || lines[b2+1][a2]) continue;
            lines[b2][a2] = true;
            if(go(lines)){
                if(answer == -1 || answer > 2) answer = 2;
            }
            for(int k=j+1; k<len; k++){
                int b3 = targets[k].first; int a3 = targets[k].second;
                if(lines[b3-1][a3] || lines[b3+1][a3]) continue;
                lines[b3][a3] = true;
                if(go(lines)){
                    if(answer == -1 || answer > 3) answer = 3;
                }
                lines[b3][a3] = false;
            }
            lines[b2][a2] = false;
        }
        lines[b][a] = false;
    }
    cout << answer << '\n';
    return 0;
}