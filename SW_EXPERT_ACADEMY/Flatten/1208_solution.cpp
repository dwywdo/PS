#include <iostream>
using namespace std;
int T = 10; int N = 0;
int main(){
    for(int test_case=1; test_case<=T; test_case++){
        int heights[100] = {0, };
        cin >> N;
        for(int i=0; i<100; i++){
            cin >> heights[i];
        }
        int answer = 0;
        for(int i=0; i<N; i++){
            int minindex = -1; int maxindex = -1;
            int minvalue = 101; int maxvalue = 0;
            for(int j=0; j<100; j++){
                if(heights[j] < minvalue){
                    minvalue = heights[j]; minindex = j;
                }
                if(heights[j] > maxvalue){
                    maxvalue = heights[j]; maxindex = j;
                }
                
            }
            heights[maxindex]--; heights[minindex]++;
        }

        int minindex = -1; int maxindex = -1;
        int minvalue = 101; int maxvalue = 0;
        for(int j=0; j<100; j++){
            if(heights[j] < minvalue){
                minvalue = heights[j]; minindex = j;
            }
            if(heights[j] > maxvalue){
                maxvalue = heights[j]; maxindex = j;
            }
        }
        answer = abs(maxvalue - minvalue);
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;
}