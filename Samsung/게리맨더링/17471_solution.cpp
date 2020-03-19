#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N = 0; int peopleCnt[10]; bool chosen[10]; 
vector<vector<int>> links;
int answer = 987654321;
vector<int> BFS(vector<int> nodes){
    vector<int> result;
    bool visited[10]; for(int i=0;i<10;i++) visited[i] = false;
    for(int i=0; i<nodes.size(); i++){
        int node = nodes[i];
        if(visited[node]) continue;
        int sum = 0;
        visited[node] = true; sum += peopleCnt[node];
        queue<int> q; q.push(node);
        while(!q.empty()){
            int thisnode = q.front(); q.pop();
            for(int j=0; j<links[thisnode].size(); j++){
                int nextnode = links[thisnode][j];
                if(find(nodes.begin(), nodes.end(), nextnode) == nodes.end()) continue;
                if(visited[nextnode]) continue;
                visited[nextnode] = true;
                q.push(nextnode); sum += peopleCnt[nextnode];
            }
        }
        result.push_back(sum);
    }
    return result;
}
void pick(int currentCount, int pickcount, int totalcount, int start){
    if(currentCount == pickcount){
        vector<int> group1; vector<int> group2;
        for(int i=0; i<N; i++){
            if(chosen[i]) group1.push_back(i);
            else group2.push_back(i);
        }
        if(BFS(group1).size()==1 && BFS(group2).size()==1){
            int sum1 = 0; int sum2 = 0;
            for(auto p : group1) sum1 += peopleCnt[p];
            for(auto p : group2) sum2 += peopleCnt[p];
            // cout << "" << sum1 << " ,    " << sum2 << endl;
            int diff = abs(sum1 - sum2);
            if(diff < answer) answer = diff;
        }
        return;
    }
    for(int i=start; i<=totalcount; i++){
        if(chosen[i]) continue;
        chosen[i] = true;
        pick(currentCount + 1, pickcount, totalcount, i + 1);
        chosen[i] = false;
    }
}
int main(){
    cin >> N;
    vector<int> goos;
    for(int i=0; i<N; i++) cin >> peopleCnt[i];
    for(int i=0; i<N; i++){
        goos.push_back(i);
        int size = 0; cin >> size;
        vector<int> lnk;
        for(int j=0; j<size; j++){
            int n = 0; cin >> n;
            lnk.push_back(n-1);
        }
        links.push_back(lnk);
    }
    vector<int> initTest = BFS(goos);
    if (initTest.size() >= 3){
        cout << -1 << endl; return 0;
    }
    else if(initTest.size() == 2){
        cout << abs(initTest[0] - initTest[1]) << endl; return 0;
    }
    else if(initTest.size() == 1){
        for(int k=0; k<10; k++) chosen[k] = false;
        for(int j=1; j<=N/2; j++){
            pick(0, j, N-1, 0);
        }
        if(answer == 987654321){
            cout << -1 << endl; return 0;
        }
        else{
            cout << answer << endl; return 0;
        }
    }
    return 0;
}
