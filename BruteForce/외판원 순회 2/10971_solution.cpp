#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int costMap[10][10];
vector<int> order;
int main(){
    int answer = 987654321;
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> costMap[i][j];
        }
    }

    for(int i=0; i<N; i++){
        order.push_back(i);
    }
    
    do{
        int cost = 0;
        bool possible = true;
        for(int i=0; i<order.size(); i++){
            int currentCity = order[i];
            int nextCity = 0;
            if(i == order.size() - 1){
                nextCity = order[0];
            }
            else{
                nextCity = order[i+1];
            }
            if(costMap[currentCity][nextCity] == 0){
                possible = false;
                break;
            }
            cost += costMap[currentCity][nextCity];
        }

        if(possible == false){
            continue;
        }

        if(answer > cost) answer = cost;

    }while(next_permutation(order.begin(), order.end()));

    cout << answer << endl;

    return 0;
}