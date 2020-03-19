#include <iostream>
#include <queue>
#include <string>
using namespace std;
bool canGo[10000];
int dist[10000];
int T = 0;
int main(){
    for(int i=0; i<10000; i++){
        if(i<1000) canGo[i] = false;
        else{
            canGo[i] = true;
            for(int j=2; j<=i/2; j++){
                if(i%j == 0) canGo[i] = false;
            }
        }
    }

    cin >> T;
    for(int t=0; t<T; t++){
        for(int i=0; i<10000; i++) dist[i] = -1;
        string start = ""; string target = "";
        cin >> start >> target;
        queue<string> q;
        dist[atoi(start.c_str())] = 0;
        q.push(start);
        while(!q.empty()){
            string number = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                for(int j=0; j<=9; j++){
                    string nextNumber = number;
                    nextNumber[i] = j + '0';
                    if(number == nextNumber) continue;
                    int n = atoi(nextNumber.c_str());
                    if(canGo[n] && dist[n] == -1){
                        dist[n] = dist[atoi(number.c_str())] + 1;
                        q.push(nextNumber);
                    }
                }
            }
        }
        if(dist[atoi(target.c_str())] == -1) cout << "Impossible" << endl;
        else cout << dist[atoi(target.c_str())] << endl;
    }
    return 0;
}