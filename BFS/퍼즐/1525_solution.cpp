#include <iostream>
#include <queue>
#include <map>
using namespace std;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
// 상태를 어떻게 정의할 것인가?
int main(){
    int start = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int temp = 0;
            cin >> temp;
            if(temp == 0) temp = 9;
            start = start * 10 + temp;
        }
    }
    queue<int> q;
    map<int, int> dist;
    q.push(start);
    while(!q.empty()){
        int cur_num = q.front(); q.pop();
        string now = to_string(cur_num);
        int z = now.find('9');
        int z_y = z/3; int z_x = z%3;
        for(int k=0; k<4; k++){
            int ny = z_y + dy[k]; int nx = z_x + dx[k];
            if(ny>=0 && ny<3 && nx>=0 && nx<3){
                string next = now;
                swap(next[z_y*3+z_x], next[ny*3+nx]);
                int next_num = stoi(next);
                if(dist.count(next_num) == 0){
                    dist[next_num] = dist[cur_num] + 1;
                    q.push(next_num);
                }
            }
        } 
    }
    if(dist.count(123456789) == 0){
        cout << -1 << '\n';
    }
    else{
        cout << dist[123456789] << '\n';
    }
    return 0;
}