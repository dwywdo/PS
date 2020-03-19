#include <iostream>
#include <vector>
using namespace std;
int N;
int scoreMap[20][20];
int answer = 2147483647;
void chooseTeam(int idx, vector<int> &first, vector<int> &second){
    if(idx == N){
        if(first.size() == 0) return;
        if(second.size() == 0) return;
        int firstScore = 0;
        int secondScore = 0;
        for(int i=0; i<first.size(); i++){
            for(int j=0; j<first.size(); j++){
                if(i==j) continue;
                firstScore += scoreMap[first[i]][first[j]];
            }
        }
        for(int i=0; i<second.size(); i++){
            for(int j=0; j<second.size(); j++){
                if(i==j) continue;
                secondScore += scoreMap[second[i]][second[j]];
            }
        }
        int diff = firstScore - secondScore;
        if(diff < 0) diff = -diff;
        answer = answer > diff ? diff : answer;
        return;
    }

    first.push_back(idx);
    chooseTeam(idx + 1, first, second);
    first.pop_back();

    second.push_back(idx);
    chooseTeam(idx + 1, first, second);
    second.pop_back();
    
    return;
}
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> scoreMap[i][j];
        }
    }
    vector<int> first;
    vector<int> second;
    chooseTeam(0, first, second);
    cout << answer << endl;
    return 0;
}