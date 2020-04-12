/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;
#define MAXN 1000
int T, N, A, B;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N >> A >> B;
        int arrive_times[MAXN+1] = {0, };
        bool arrived[MAXN+1] = {false, };
        int oldest_time = 0;
        for(int i=0; i<N; i++){
            int time = 0; cin >> time;
            arrive_times[i] = time;
            arrived[time] = true;
        }
        int read_times[MAXN+1] = {0, };
        int ctime = 1;
        int amount = 0;
        int oldest_index = 0;
        int totalreadcount = 0;
        while(1){
            if(totalreadcount == N) break;
            if(arrived[ctime]) amount++;
            if(amount >= A || ctime - arrive_times[oldest_index] == B){
                int readcount = amount / 2 + amount % 2;
                while(readcount--){
                    oldest_index++;
                    amount--;
                    totalreadcount++;
                    read_times[oldest_index] = ctime;
                }
            }
            ctime++;
        }
        cout << "#" << test_case << " ";
        for(int i=1; i<=totalreadcount; i++){
            cout << read_times[i] << " ";
        }
        cout << "\n";
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}