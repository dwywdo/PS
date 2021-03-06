#include <iostream>
using namespace std;

const int MAXN = 11;
const int MAXT = MAXN * 2 + MAXN*MAXN;

struct PT{
    int r, c;
    PT(){};
    PT(int r, int c) : r(r), c(c) {}
} man[MAXN], stair[2];

int N, M, S;
int map[MAXN][MAXN];
int match[MAXN];
int answer;
int dist(int man_index, int stair_index){
    return abs(man[man_index].r - stair[stair_index].r) + abs(man[man_index].c - stair[stair_index].c);
}
void update(){
    int total_min_time = 0;
    for(int stair_index = 0; stair_index < 2; stair_index++){
        PT &now_stair = stair[stair_index];
        int arrival_time[MAXN*2] = {0, };
        int current_stair[MAXT] = {0, };
        for(int man_index = 0; man_index < M; man_index++){
            if(match[man_index] == stair_index){
                arrival_time[dist(man_index, stair_index) + 1]++;
            }
        }
        int now_min_time = 0;
        for(int time=1; time<=20; time++){
            while(arrival_time[time] > 0){
                arrival_time[time]--;

                int remain_time = map[now_stair.r][now_stair.c];
                for(int walk_time = time; walk_time < MAXT; walk_time++){
                    if(current_stair[walk_time] < 3){
                        current_stair[walk_time]++;
                        remain_time--;
                        if(remain_time == 0){
                            now_min_time = max(now_min_time, walk_time + 1);
                            break;
                        }
                    }
                }
            }
        }
        total_min_time = max(total_min_time, now_min_time);
    }
    answer = min(answer, total_min_time);
}
void DFS(int man_index){
    if(man_index == M){
        update();
        return;
    }
    for(int stair_index = 0; stair_index < 2; stair_index++){
        match[man_index] = stair_index;
        DFS(man_index + 1);
    }
    return;
}
int main(){
    int T; cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cin >> N; M = S = 0;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cin >> map[i][j];
                if(map[i][j]==1) man[M++] = PT(i, j);
                if(map[i][j]>=2) stair[S++] = PT(i, j);
            }
        }
        answer = 1e9;
        DFS(0);
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;
}