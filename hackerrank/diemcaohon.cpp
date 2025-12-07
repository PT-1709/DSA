/*cho n là số học sinh trong lớp, n dòng tiếp theo là điểm của học sinh thứ i, PT luôn là học sinh đầu tiên, đếm xem có bao nhiêu học sinh có 
 tổng điểm 5 môn lớn hơn PT
3
30 40 45 10 10
40 40 40 10 10
50 20 30 10 10

1

*/

#include <bits/stdc++.h>
using namespace std;

class Student{
    public:
        vector<int> score;
        void nhap(){
            score.resize(5);
            for (int i = 0; i < 5; i++){
                cin >> score[i];
            }
        }

        int tongdiem(){
            int sum = 0;
            for (int x : score){
                sum += x;
            }
            return sum;
        }
        
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<Student> v(n);
    for (int i = 0; i < n; i++){
        v[i].nhap();
    }

    int demHer = v[0].tongdiem();

    int dem = 0;
    for (int i = 1; i < n; i++){
        if (v[i].tongdiem() > demHer){
            dem++;
        }
    }
    cout << dem << endl;
    
    return 0;
}