#include <iostream>
using namespace std;
int T = 10;
int map[100][100];
int main(){
    for(int test_case=1; test_case<=T; test_case++){
        int tc = 0; cin >> tc;
        for(int i=0; i<100; i++){
            for(int j=0; j<100; j++){
                cin >> map[i][j];
            }
        }
        // 행 합
        int answer = 0;
        for(int i=0; i<100; i++){
            int sum = 0;
            for(int j=0; j<100; j++){
                sum += map[i][j];
            }
            if(answer < sum) answer = sum;
        }
        for(int j=0; j<100; j++){
            int sum = 0;
            for(int i=0; i<100; i++){
                sum += map[i][j];
            }
            if(answer < sum) answer = sum;
        }
        int rightdiagsum = 0;
        int leftdiagsum = 0;
        int y = 0; int x = 0;
        while(y>=0 && y<100 && x>=0 && x<100){
            rightdiagsum += map[y][x];
            y++;
            x++;
        }
        if(answer < rightdiagsum) answer = rightdiagsum;
        y = 0; x = 99;
        while(y>=0 && y<100 && x>=0 && x<100){
            leftdiagsum += map[y][x];
            y++;
            x--;
        }
        if(answer < leftdiagsum) answer = leftdiagsum;
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;
}