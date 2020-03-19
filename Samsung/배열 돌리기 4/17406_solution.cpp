#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
int arr[51][51];
int copy_arr[51][51];
int N, M, K;
vector<tuple<int, int, int>> inst;
int answer = 987654321;
void rotation(int r, int c, int S){
	vector<vector<int>> groups;
	for(int s=S; s>=1; s--){
		vector<int> group;
		for(int i=r-s, j=c-s; j<c+s; j++) group.push_back(copy_arr[i][j]);
		for(int i=r-s, j=c+s; i<r+s; i++) group.push_back(copy_arr[i][j]);
		for(int i=r+s, j=c+s; j>c-s; j--) group.push_back(copy_arr[i][j]);
		for(int i=r+s, j=c-s; i>r-s; i--) group.push_back(copy_arr[i][j]);
		groups.push_back(group);
	}
	for(int s=S; s>=1; s--){
		vector<int> group = groups[S-s];
		rotate(group.rbegin(), group.rbegin() + 1, group.rend());
		int idx = 0;
		for(int i=r-s, j=c-s; j<c+s; j++) copy_arr[i][j] = group[idx++];
		for(int i=r-s, j=c+s; i<r+s; i++) copy_arr[i][j] = group[idx++];
		for(int i=r+s, j=c+s; j>c-s; j--) copy_arr[i][j] = group[idx++];
		for(int i=r+s, j=c-s; i>r-s; i--) copy_arr[i][j] = group[idx++];
	}
	return;
}
int main(){
	cin >> N >> M >> K;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			cin >> arr[i][j];
		}
	}
	for(int i=0; i<K; i++){
		int r = 0; int c = 0; int s = 0;
		cin >> r >> c >> s;
		inst.push_back(make_tuple(r,c,s));
	}

	sort(inst.begin(), inst.end());
	do{
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= M; j++) copy_arr[i][j] = arr[i][j];

		for(int i=0; i<inst.size(); i++){
			int r = get<0>(inst[i]); int c = get<1>(inst[i]); int s = get<2>(inst[i]);
			rotation(r, c, s);
			int temp = 0;
		}
		int value = 987654321;
		for(int i=1; i<=N; i++){
			int rowsum = 0;
			for(int j=1; j<=M; j++){
				rowsum += copy_arr[i][j];
			}
			if(value > rowsum) value = rowsum;
		}
		if(answer > value) answer = value;
	}while(next_permutation(inst.begin(), inst.end()));

	cout << answer << endl;
	return 0;
	
}
