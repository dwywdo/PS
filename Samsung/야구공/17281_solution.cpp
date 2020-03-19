#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int results[50][10];
bool base[3];
vector<int> order;
int answer = 0;
int baseChange(int result){
    int score = 0;
    if(result == 4){
        for(int i=0; i<3; i++){
            if(base[i]) {
                score++; base[i] = false;
            }
        }
        score++;
        return score;
    }
    else if(result >=1 && result<=3){
        for(int i=2; i>=0; i--){ // 뒤에서부터 출루를 시켜주어야 로직이 꼬이지 않음
            if(base[i]){
                if(i+result >= 3){
                    score++; base[i] = false;
                }
                else{
                    base[i+result] = base[i];
                    base[i] = false;
                }
            }
        }
        base[result-1] = true;
    }
    return score;
}
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=1; j<=9; j++){
            cin >> results[i][j];
        }
    }
    order.push_back(2); order.push_back(3);
    order.push_back(4); order.push_back(5);
    order.push_back(6); order.push_back(7);
    order.push_back(8); order.push_back(9);
    do{
        vector<int> realorder(order);
        realorder.insert(realorder.begin() + 3, 1);
        int playerIndex = 0;
        int totalScore = 0;
        // 이닝만큼 경기 진행
        for(int i=0; i<N; i++){
            for(int b=0; b<4; b++) base[b] = false;
            int outCount = 0; // 이닝 처음엔 아웃카운트 0
            while(1){
                if(playerIndex == 9) playerIndex = 0; // 플레이어 넘버가 9명을 넘어가면 0으로 초기화
                int playerNumber = realorder[playerIndex]; // 타순에 맞는 선수를 선택
                int result = results[i][playerNumber]; // 이닝 별 그 선수의 결과 가져오기
                if(result == 0){ // 아웃이면? 다음 타자로 넘어가고 아웃카운트 증가
                    outCount++;
                    playerIndex++;
                    if(outCount == 3) break; // 아웃카운트가 3이되면 해당 이닝 플레이 끝
                }
                else{
                    playerIndex++; // 아웃이 아니면 base의 상태를 바꾸어가며 득점한 점수를 더해줌
                    totalScore += baseChange(result);
                }
            }
        }
        if(answer < totalScore) answer = totalScore;
    }while(next_permutation(order.begin(), order.end()));
    cout << answer << endl;
    return 0;
}