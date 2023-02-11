#include <bits/stdc++.h>

using namespace std;

vector<int> slidingMaximum(const vector<int> &A, int B) {
    int i = 0;
    int j = 0;
    vector<int> v;
    priority_queue<int> pq;
   while(j<A.size()){
        if (j - i + 1 < B) {
            j++;
            pq.push(A[i]);
        } else {
            int ans = pq.top();
            while (j - i + 1 > B) {
                i++;
                if (A[i] == pq.top()) {
                    pq.pop();
                }
            }
            if (j - i + 1 == B) {
                ans = max(ans, pq.top());
                v.push_back(ans);
            }
            j++;
            pq.push(A[i]);
        }
    }
    return v;
}

void printvec(const vector<int> &v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main() {
    vector<int> v = {1, 3, -1, -3, 5, 3, 6, 7};
    printvec(slidingMaximum(v, 3));
    return 0;
}
