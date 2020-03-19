#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int A[100][100];
bool compare(pair<int, int> &a, pair<int, int> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    else return a.second < b.second;
}
int main(){
    int r, c, k;
    cin >> r >> c >> k; r-=1; c-=1;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> A[i][j];
        }
    }
    int t = 0; bool timeout = true; int R = 3; int C = 3;
    if(A[r][c] == k) {
        cout << 0 << '\n';
        return 0;
    }
    // R: 행의 갯수, C: 열의 갯수
    while(t < 100){
        t++;
        // R 연산
        if(R>=C){ // 행의 갯수가 열의 갯수보다 크거나 같은 경우
            int newC = C;
            // 모든 행에 대해
            for(int i=0; i<R; i++){
                vector<pair<int, int>> tmp;
                int cnt[101]; memset(cnt, 0, sizeof(cnt));
                for(int j=0; j<C; j++) cnt[A[i][j]]++;
                for(int j=1; j<=100; j++){
                    if(cnt[j] == 0) continue;
                    else{
                        tmp.push_back(make_pair(j, cnt[j]));
                    }
                }
                sort(tmp.begin(), tmp.end(), compare);
                int idx = 0;
                for(idx=0; idx<C; idx++) A[i][idx] = 0;
                idx = 0;
                for(auto &a : tmp){
                    A[i][idx] = a.first; idx++;
                    if(idx>=100) break;
                    A[i][idx] = a.second; idx++;
                    if(idx>=100) break;
                }
                if(newC < idx) newC = idx;
            }
            // 변경된 행마다의 최대 길이가 열의 최대 갯수가 되어버림
            C = newC;
        }
        // C 연산
        else if(R<C){ // 행의 갯수가 열의 갯수보다 작은 경우
            int newR = R;
            for(int j=0; j<C; j++){
                vector<pair<int, int>> tmp;
                int cnt[101]; memset(cnt, 0, sizeof(cnt));
                for(int i=0; i<R; i++) cnt[A[i][j]]++;
                for(int i=1; i<=100; i++){
                    if(cnt[i] == 0) continue;
                    else{
                        tmp.push_back(make_pair(i, cnt[i]));
                    }
                }
                sort(tmp.begin(), tmp.end(), compare);
                int idx = 0;
                for(idx=0; idx<R; idx++) A[idx][j] = 0;
                idx = 0;
                for(auto &a : tmp){
                    A[idx][j] = a.first; idx++;
                    if(idx>=100) break;
                    A[idx][j] = a.second; idx++;
                    if(idx>=100) break;
                }
                if(newR < idx) newR = idx;
            }
            R = newR;
        }

        if(A[r][c]==k){
            timeout = false; break;
        }
    }

    if(timeout) cout << -1 << '\n';
    else cout << t << '\n';
    
    return 0;
}

