#include <bits/stdc++.h>

using namespace std;


int main() {
    deque<int>dq;
    dq.push_front(4);
    dq.push_front(5);
    dq.push_back(2);
    dq.push_back(1); //5 4 2 1 
    while(!dq.empty()){
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
    return 0;
}
