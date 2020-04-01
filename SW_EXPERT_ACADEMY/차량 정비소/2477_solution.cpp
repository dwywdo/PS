#include <iostream>
#include <queue>
using namespace std;
int T, N, M, K, A, B;
typedef struct history{
    int A = 0;
    int B = 0;
}HISTORY;
HISTORY history[1001];
typedef struct desk{
    int customer_id = 0;
    int end_time = 0;
} DESK;
DESK receptions[10];
DESK repairs[10];
int a[21]; int b[21]; int arrive_time[1001];

int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cin >> N >> M >> K >> A >> B;
        for(int i=1; i<=N; i++) cin >> a[i];
        for(int i=1; i<=M; i++) cin >> b[i];
        for(int i=1; i<=K; i++) cin >> arrive_time[i];

        queue<int> rec_q;
        queue<int> rep_q;
        int answer = 0; int time = 0; int cnt = 0;
        while(true){
            for(int i=1; i<=K; i++){
                if(arrive_time[i] == time){
                    rec_q.push(i);
                }
            }
            for(int i=1; i<=N; i++){
                if(receptions[i].customer_id != 0 && receptions[i].end_time == time){
                    rep_q.push(receptions[i].customer_id);
                    receptions[i].customer_id = 0;
                }
            }
            for(int i=1; i<=M; i++){
                if(repairs[i].customer_id != 0 && repairs[i].end_time == time){
                    repairs[i].customer_id = 0;
                    cnt++;
                }
            }
            for(int i=1; i<=N; i++){
                if(rec_q.empty()) break;
                if(receptions[i].customer_id == 0){
                    receptions[i].customer_id = rec_q.front();
                    receptions[i].end_time = time + a[i];
                    rec_q.pop();
                    history[receptions[i].customer_id].A = i;
                }
            }
            for(int i=1; i<=M; i++){
                if(rep_q.empty()) break;
                if(repairs[i].customer_id == 0){
                    repairs[i].customer_id = rep_q.front();
                    repairs[i].end_time = time + b[i];
                    rep_q.pop();
                    history[repairs[i].customer_id].B = i;
                }
            }
            if(cnt >= K){
                for(int i=1; i<=K; i++){
                    if(history[i].A == A && history[i].B == B){
                        answer += i;
                    }
                }
                break;
            }
            time++;
        }
        if(answer == 0) answer = -1;
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;
}