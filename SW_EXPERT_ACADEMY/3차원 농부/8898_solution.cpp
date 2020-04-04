#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int T = 0;
int N, M, c1, c2;
int c[500000];
int h[500000];
int main(){
    scanf("%d", &T);
    for(int test_case=1; test_case<=T; test_case++){
        scanf("%d %d", &N, &M);
        scanf("%d %d", &c1, &c2);
        memset(c, 0, sizeof(c));
        memset(h, 0, sizeof(h));
        for(int i=0; i<N; i++) scanf("%d", &c[i]);
        for(int i=0; i<M; i++) scanf("%d", &h[i]);
        sort(c, c+N); sort(h, h+M);
        int answer = 987654321;
        int cnt = 0;
        for(int i=0; i<N; i++){
            int left = 0; int right = M - 1;
            if(h[left] == c[i] || h[right] == c[i]){
                int dist = abs(c1-c2);
                if(dist < answer){
                    answer = dist; cnt = 1;
                }
                else if(dist == answer) cnt++;
                continue;
            }
            else if((h[left] > c[i] && h[right] > c[i]) || (h[left] < c[i] && h[right] < c[i])){
                int dist = abs(c2-c1) + min(abs(h[left] - c[i]), abs(h[right] - c[i]));
                if(dist < answer){
                    answer = dist; cnt = 1;
                }
                else if(dist == answer) cnt++;
                continue;
            }
            else{
                int dist = 0;
                while(left <= right){
                    int mid = (left + right) / 2;
                    dist = abs(c2-c1) + abs(h[mid] - c[i]);
                    if(h[mid] == c[i]) {
                        if(dist < answer){
                            answer = dist; cnt = 1;
                        }
                        else if(dist == answer) cnt++;
                        break;
                    }
                    else if(h[mid] > c[i]) right = mid - 1;
                    else if(h[mid] < c[i]) left = mid + 1;
                    if(dist < answer){
                        answer = dist; cnt = 1;
                    }
                    else if(dist == answer) cnt++;
                }
            }
        }
        cout << "#" << test_case << " " << answer << " " << cnt << "\n";
    }
    return 0;
}