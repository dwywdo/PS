#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
bool visited[10001];
bool dist[10001];
char how[10001];
int from[10001];
int T = 0;
int main(){
    cin >> T;
    for(int t=0; t<T; t++){
        int start = 0; int target = 0;
        cin >> start >> target;
        memset(visited, false, sizeof(visited));
        memset(dist, 0, sizeof(dist));
        memset(how, 0, sizeof(how));
        memset(from, 0, sizeof(from));
        visited[start] = true;
        dist[start] = 0;
        from[start] = -1;
        queue<int> q; q.push(start);
        while(!q.empty()){
            int now = q.front(); q.pop();
            int next = (now*2)%10000;
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
                dist[next] = dist[now] + 1;
                from[next] = now;
                how[next] = 'D';
            }
            next = now - 1;
            if(next == -1) next = 9999;
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
                dist[next] = dist[now] + 1;
                from[next] = now;
                how[next] = 'S';
            }
            next = (now%1000)*10 + now/1000;
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
                dist[next] = dist[now] + 1;
                from[next] = now;
                how[next] = 'L';
            }
            next = (now/10) + (now%10)*1000;
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
                dist[next] = dist[now] + 1;
                from[next] = now;
                how[next] = 'R';
            }
        }
        string answer = "";
        while(start != target){
            answer += how[target];
            target = from[target];
        }
        reverse(answer.begin(), answer.end());
        cout << answer << endl;
    }
    return 0;
}