#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Box{
    private:
        ll l,b,h; // dai rong cao

    public:
        Box(): l(0), b(0), h(0){

        }

        Box(ll L, ll B, ll H){
            this->l = L;
            this->b = B;
            this->h = H;
        }

        ll getLength(){
            return l;
        }

        ll getBreadth(){
            return b;
        }

        ll getHeight(){
            return h;
        }

        ll CalculateVolume(){
            return l * b * h;
        }

        bool operator<(const Box& B) const {
        if (l < B.l) {
            return true;
            } 
        else if (l == B.l && b < B.b) {
            return true;
            } 
        else if (l == B.l && b == B.b && h < B.h) {
            return true;
            }
            return false;
        }



};

int main(){
    Box b1;

    Box b2(2,3,4);


    return 0;
}
// chuwa hoc xg OOP