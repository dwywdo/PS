#include <iostream>
using namespace std;
typedef struct gild_type {
    int r, c, cnt;
}GLID_TYPE;
int S, N, Map[100][100], Cost[4], AnsCnt, Answer[10000][3];
int countDamage(int row, int col, int size){
    int cnt = 0;
    for(int i=row; i<row + size; i++){
        for(int j=col; j<col+size; j++){
            if(Map[i][j] == 1) ++cnt;
        }
    }
    return cnt;
}
GLID_TYPE findOptimal(int row, int col, int size, int glidsize){
    int maxCnt = 0; int maxR = -1; int maxC = -1;
    for(int i=row; i<=row+size-glidsize; ++i){
        for(int j=col; j<=col+size-glidsize; ++j){
            int cnt = countDamage(i, j, glidsize);
            if(cnt > maxCnt){
                maxCnt = cnt;
                maxR = i;
                maxC = j;
            }
        }
    }
    GLID_TYPE result = {};
    result.c = maxC; result.r = maxR; result.cnt = maxCnt;
    return result;
}
void setMark(int row, int col, int size, int curValue, int newValue){
    for(int i=row; i<row+size; i++){
        for(int j=col; j<col+size; j++){
            if(Map[i][j] == curValue){
                Map[i][j] = newValue;
            }
        }
    }
}
int solve(int row, int col, int size, int glidSize, bool first){
    int sumCost = 0; int cost1, cost2;
    while(glidSize > 1){
        GLID_TYPE glid1 = findOptimal(row, col, size, glidSize);
        if(glid1.cnt == 0) break;
        cost1 = Cost[glidSize];
        if(first && glidSize == 3 && glid1.cnt <= 6){
            int totalCost1 = solve(row, col, size, 3, false);
            int totalCost2 = solve(row, col, size, 2, false);
            if(totalCost2 < totalCost1){
                glidSize = 2; continue;
            }
        }
        cost2 = 0;
        if(glidSize > 2){
            GLID_TYPE glid2 = findOptimal(glid1.r, glid1.c, glidSize, glidSize - 1);
            cost2 = Cost[glidSize - 1];
            setMark(glid2.r, glid2.c, glidSize - 1, 1, 2);
            // find 2x2
            GLID_TYPE glid3;
            do{
                glid3 = findOptimal(glid1.r, glid1.c, glidSize, 2);
                if(glid3.cnt  > 1){
                    cost2 += Cost[2];
                    setMark(glid3.r, glid3.c, 2, 1, 2);
                }
            }while(glid3.cnt > 1);
        }
        // find 1x1
        cost2 += Cost[1] * countDamage(glid1.r, glid1.c, glidSize);
        setMark(glid1.r, glid1.c, glidSize, 2, 1); // restore;

        if(cost1 <= cost2){
            setMark(glid1.r, glid1.c, glidSize, 1, first ? 3 : 4);
            sumCost += cost1;
            if(first){
                Answer[AnsCnt][0] = glid1.r + 1;
                Answer[AnsCnt][1] = glid1.c + 1;
                Answer[AnsCnt++][2] = glidSize;
            }
        }
        else{
            --glidSize;
        }
    }
    for(int i=row; i<row+size; ++i){
        for(int j=col; j<col+size; j++){
            if(Map[i][j] == 1){
                sumCost += Cost[1];
                if(first){
                    Answer[AnsCnt][0] = i + 1;
                    Answer[AnsCnt][1] = j + 1;
                    Answer[AnsCnt++][2] = 1;
                }
            }
        }
    }
    if(!first) setMark(row, col, size, 4, 1);
    return sumCost;
}

int main(){
    Cost[1] = 2; Cost[2] = 4; Cost[3] = 7;
    int tcCnt, r, c; cin >> tcCnt;
    for(int t=1; t<=tcCnt; ++t){
        cin >> S >> N;
        for(int i=0; i<S; i++){
            for(int j=0; j<S; j++){
                Map[i][j] = 0;
            }
        }
        for(int i=0; i<N; i++){
            cin >> r >> c;
            Map[r - 1][c - 1] = 1;
        }
        AnsCnt = 0;
        solve(0, 0, S, 3, true);
        cout << "#" << t << ' ' << AnsCnt;
        for(int i=0; i<AnsCnt; ++i){
            cout << ' ' << Answer[i][0] << ' ' << Answer[i][1] << ' ' << Answer[i][2];
        }
        cout << "\n";
    }
    return 0;
}