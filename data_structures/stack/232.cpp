// https://leetcode.com/problems/implement-queue-using-stacks/description/
// ko đc dùng queue hãy dùng stack để giải quyết

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution{
    private:
        stack <int> st1;
        stack <int> st2;

        void move(){
            if (!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }

    public:
        
        void push(int x){
            st1.push(x);
        }

        int pop(){
           if (st2.empty()){
            move();
           }
           int top = st2.top();
           st2.pop();
           return top;
        }

        int peek(){
            if (st2.empty()){
                move();
            }
            return st2.top();
        }
        
        bool check(){
           return st1.empty() && st2.empty();
        }
};

