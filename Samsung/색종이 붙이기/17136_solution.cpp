#include <iostream>
using namespace std;
#define MAP_SIZE 10
int map[MAP_SIZE][MAP_SIZE];
int paperlen[6] = {0, 1, 2, 3, 4, 5};
int paperCount[6] = {0, 5, 5, 5, 5, 5};
int oneCount = 0;
int cnt = 987654321;
int attachRemove(bool attach, int y, int x, int paperSize)
{
    int howmany = 0;
    for (int i = y; i <= y + paperSize - 1; i++)
    {
        for (int j = x; j <= x + paperSize - 1; j++)
        {
            if (attach)
                map[i][j] = 0;
            else
                map[i][j] = 1;
            howmany++;
        }
    }
    return howmany;
}
bool canAttach(int y, int x, int size){
    bool possible = true;
    for(int i=y; i<y+size; i++){
        for(int j=x; j<x+size; j++){
            if(map[i][j] == 0){
                possible = false;
                break;
            }
        }
    }
    return possible;
}
void DFS(int y, int x, int attachedCount, int usedCount)
{
    if (attachedCount == oneCount){
        cnt = usedCount < cnt ? usedCount : cnt;
        return;
    }
    if (usedCount > cnt) return;

    bool found = false;
    for (int i = 0; i < MAP_SIZE; i++){
        for (int j = 0; j < MAP_SIZE; j++){
            if (map[i][j] == 1){
                y = i;
                x = j;
                found = true;
                break;
            }
        }
        if (found) break;
    }
    for (int s = 5; s > 0; s--){
        // x가 5이라고 해보자. s가 5이면 5,6,7,8,9(범위 초과)
        // s가 4이면 6,7,8,9(범위 안에 있음)
        if (x + s > MAP_SIZE || y + s > MAP_SIZE) continue;
        if (paperCount[s] == 0) continue;
        if(canAttach(y, x, s)){
            int papers = attachRemove(true, y, x, s);
            paperCount[s]--;
            DFS(y, x, attachedCount + papers, usedCount + 1);
            attachRemove(false, y, x, s);
            paperCount[s]++;
        }
    }
}
int main()
{
    for (int i = 0; i < MAP_SIZE; i++){
        for (int j = 0; j < MAP_SIZE; j++){
            cin >> map[i][j];
            if (map[i][j] == 1)
                oneCount++;
        }
    }
    DFS(0, 0, 0, 0);
    if(cnt == 987654321) cnt = -1;
    cout << cnt << endl;
}