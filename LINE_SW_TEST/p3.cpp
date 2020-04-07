#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
queue<int> idx;
int main() {
    string road = "111011110011111011111100001111";
    int n = 3;
    int answer = -1;
    int broken = 0;
    int energy = n;
    for(int i=0; i<road.size(); i++) if(road[i] == '0') broken++;
    if(broken < n) {
        answer = road.size();
        return answer;
    }
    int length = 0;
    for(int i=0; i<road.size(); i++){
        if(road[i] == '1'){
            length++;
        }
        else{
            if(energy == 0){
                int k = idx.front(); idx.pop();
                road[k] = '0'; road[i] = '1';
                length = i-k;
                idx.push(i);
            }
            else{
                energy--; road[i] = '1'; idx.push(i); length++;
            }
        }
        if(answer < length) answer = length;
    }
    cout << answer << "\n";
    return answer;
}