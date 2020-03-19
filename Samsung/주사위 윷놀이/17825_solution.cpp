// 각 말들의 번호 별 위치
// 말이 있는지 없는지 체크하는 배열
// 칸이 파란색인지 아닌지 확인하는 배열 // 필요 없다
// 각 칸 별 주사위 1~5까지의 도착 위치
// 도착지: 32 시작지: 0
#include <iostream>
#include <vector>
using namespace std;
#define END 32
int next_loc[33][5] =
{
    {1, 2, 3, 4, 5},
    {2 ,3, 4, 5, 6},
    {3, 4, 5, 6, 7},
    {4, 5, 6, 7, 8},
    {5, 6, 7, 8, 9},
    {21, 22, 23, 24, 30},
    {7, 8, 9, 10, 11},
    {8, 9, 10, 11, 12},
    {9, 10, 11, 12, 13},
    {10, 11, 12, 13, 14},
    {28, 29, 24, 30, 31},
    {12, 13, 14, 15, 16},
    {13, 14, 15, 16, 17},
    {14, 15, 16, 17, 18},
    {15, 16, 17, 18, 19},
    {27, 26, 25, 24, 30},
    {17, 18, 19, 20, 32},
    {18, 19, 20, 32, 32},
    {19, 20, 32, 32, 32},
    {20, 32, 32, 32, 32},
    {32, 32, 32, 32, 32},
    {22, 23, 24, 30, 31},
    {23, 24, 30, 31, 20},
    {24, 30, 31, 20, 32},
    {30, 31, 20, 32, 32},
    {24, 30, 31, 20, 32},
    {25, 24, 30, 31, 20},
    {26, 25, 24, 30, 31},
    {29, 24, 30, 31, 20},
    {24, 30, 31, 20, 32},
    {31, 20, 32, 32, 32},
    {20, 32, 32, 32, 32},
    {32, 32, 32, 32, 32}
};
int score[33] = {
    0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20,
    22, 24, 26, 28, 30, 32, 34, 36, 38, 40,
    13, 16, 19, 25, 26, 27, 28, 22, 24, 30, 35, 0
};
bool check[33];
int loc[4] = {0, 0, 0, 0};
int answer = 0;
void go(vector<int> &numbers, int idx, int totalscore){
    if(idx == 10){
        if(totalscore > answer) answer = totalscore;
        return;
    }
    int dice = numbers[idx];
    for(int i=0; i<4; i++){
        // 말을 고른다
        // 현재 위치를 얻는다
        int start_loc = loc[i];
        if(start_loc == END) continue; // 이미 도착지에 있는 말인 경우
        int dst_loc = next_loc[start_loc][dice-1];
        if(dst_loc != END && check[dst_loc]) continue; // 다음 위치가 도착지점이 아니면서, 말이 있는 경우 이동 불가
        check[start_loc] = false; check[dst_loc] = true;
        loc[i] = dst_loc;
        totalscore += score[dst_loc];
        go(numbers, idx + 1, totalscore);
        check[dst_loc] = false; check[start_loc] = true;
        totalscore -= score[dst_loc];
        loc[i] = start_loc;
    }
}
int main(){
    vector<int> numbers(10);
    for(int i=0; i<10; i++){
        cin >> numbers[i];
    }
    go(numbers, 0, 0);
    cout << answer << '\n';
    return 0;
}