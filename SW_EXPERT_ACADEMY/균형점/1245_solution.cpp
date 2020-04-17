#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T = 0;
bool compare(pair<double, double> &a, pair<double, double> &b){
    return a.first < b.first;
}
int main(){
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        vector<pair<double, double>> infos;
        int N = 0; cin >> N;
        for(int i=0; i<N; i++){
            double loc = 0;
            cin >> loc;
            infos.push_back(make_pair(loc, 0));
        }
        for(int i=0; i<N; i++){
            double weight = 0;
            cin >> weight;
            infos[i].second = weight;
        }
        sort(infos.begin(), infos.end(), compare);
        vector<double> answers;
        for(int i=0; i<N-1; i++){
            double left = infos[i].first; double right = infos[i+1].first;
            double answer = -1;
            while(left < right){
                double mid = (left + right) / 2;
                double leftpower = 0;
                double rightpower = 0;
                for(int i=0; i<infos.size(); i++){
                    if(infos[i].first < mid){
                        double d = mid - infos[i].first;
                        leftpower += (infos[i].second)/(d*d);
                    }
                    else if(infos[i].first > mid){
                        double d = infos[i].first - mid;
                        rightpower += (infos[i].second)/(d*d);
                    }
                    else{
                        
                    }
                }
                double diff = right - left;
                if(diff < 0) diff = -diff;
                if(diff < 0.000000000001){
                    answer = mid; break;
                }
                if(leftpower > rightpower){
                    left = mid;
                }
                else if(leftpower < rightpower){
                    right = mid;
                }
                else{
                    answer = mid; break;
                }
            }
            answers.push_back(answer);
        }
        cout << "#" << test_case << " ";
        for(int i=0; i<answers.size(); i++){
            printf("%.10f ", answers[i]);
        }
        cout << "\n";
    }
    return 0;
}