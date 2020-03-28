#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char map[15][15];
int N, M;
int limit = 0;

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
    int ans = 0;
    for(int y1=0; y1<N; y1++){
        for(int x1=0; x1<M; x1++){
            for(int s1=0; ; s1++){
                if(y1-s1 < 0 || y1+s1 >=N) break;
                if(x1-s1 < 0 || x1+s1 >=M) break;
                if(map[y1-s1][x1] != '#' || map[y1+s1][x1] != '#') break;
                if(map[y1][x1-s1] != '#' || map[y1][x1+s1] != '#') break;
                map[y1-s1][x1] = '*'; map[y1+s1][x1] = '*';
                map[y1][x1-s1] = '*'; map[y1][x1+s1] = '*';
                for(int y2=0; y2<N; y2++){
                    for(int x2=0; x2<M; x2++){
                        for(int s2=0;; s2++){
                            if(y2-s2 < 0 || y2+s2 >=N) break;
                            if(x2-s2 < 0 || x2+s2 >=M) break;
                            if(map[y2-s2][x2] != '#' || map[y2+s2][x2] != '#') break;
                            if(map[y2][x2-s2] != '#' || map[y2][x2+s2] != '#') break;
                            int area = (4*s1+1)*(4*s2+1);
                            if(ans < area) ans = area;
                        }
                    }
                }
            }
            for(int s1=0; ; s1++){
                if(y1-s1 < 0 || y1+s1 >=N) break;
                if(x1-s1 < 0 || x1+s1 >=M) break;
                if(map[y1-s1][x1] != '*' || map[y1+s1][x1] != '*') break;
                if(map[y1][x1-s1] != '*' || map[y1][x1+s1] != '*') break;
                map[y1-s1][x1] = '#'; map[y1+s1][x1] = '#';
                map[y1][x1-s1] = '#'; map[y1][x1+s1] = '#';
            }
        }
    }
    cout << ans << '\n';
    return 0;
}