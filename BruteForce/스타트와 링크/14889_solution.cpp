#include <iostream>
#include <vector>
using namespace std;
int answer = 2147483647;
int N;
int scoreMap[20][20];
void chooseTeam(int idx, vector<int> &first, vector<int> &second){
    if(idx == N){
        if(first.size() != N/2) return;
        if(second.size() != N/2) return;
        int firstScore = 0;
        int secondScore = 0;
        for(int i=0; i<N/2; i++){
            for(int j=0; j<N/2; j++){
                if(i==j) continue;
                firstScore += scoreMap[first[i]][first[j]];
                secondScore += scoreMap[second[i]][second[j]];
            }
        }
        int diff = firstScore - secondScore > 0 ? firstScore - secondScore : secondScore - firstScore;
        if(answer > diff) answer = diff;
        return;
    }

    if(first.size() > N/2) return;
    if(second.size() > N/2) return;
    
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