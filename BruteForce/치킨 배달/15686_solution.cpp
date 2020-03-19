#include <iostream>
#include <vector>
using namespace std;
int map[51][51];
int N, M;
vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;
bool check[13];
int answer = 987654321;
void choose(int M, int N, int start, vector<pair<int, int>> chosen){
    if(chosen.size() == M){
        /*
        for(int i=0; i<chosen.size(); i++){
            cout << "(" << chosen[i].first << ", " << chosen[i].second << ") ";
        }
        cout << endl;
        */
       
        int cityDistance = 0;
        for(int i=0; i<houses.size(); i++){
            int houseDistance = 987654321;
            for(int j=0; j<chosen.size(); j++){
                int distance = 0;
                distance += abs(houses[i].first - chosen[j].first);
                distance += abs(houses[i].second - chosen[j].second);
                if(distance < houseDistance) houseDistance = distance;
            }
            cityDistance += houseDistance;
        }
        if(cityDistance < answer) answer = cityDistance;
        return;
    }
    for(int i=start; i<N; i++){
        if(check[i] == true) continue;
        check[i] = true;
        chosen.push_back(chickens[i]);
        choose(M, N, i+1, chosen);
        check[i] = false;
        chosen.pop_back();
    }
}
int main(){
    cin >> N; cin >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j];
            if(map[i][j] == 1) houses.push_back(make_pair(i, j));
            if(map[i][j] == 2) chickens.push_back(make_pair(i, j));
        }
    }
    for(int i=1; i<=M; i++){
        vector<pair<int, int>> chosen;
        choose(i, chickens.size(), 0, chosen);
    }

    cout << answer << endl;
    return 0;
}