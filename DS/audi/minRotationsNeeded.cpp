/*

Minimum rotations needed to convert s into t

How to
1. If lengths differ → return -1.
2. Search t inside s+s.
3. If found at index idx, then minimum left rotations = idx (because shifting left by idx aligns it).
4. If not found → -1.


Sample Input:
abcde
cdeab  
Sample Output:
2
*/

#include <iostream>
#include <string>
using namespace std;

int minRotations(string s, string t) {
    if (s.length()!=t.length()) {
        return -1;
    }
    string s2 = s+s;
    size_t pos = s2.find(t);
    if (pos != string::npos) {
        return pos;
    }
    else {
        return -1;
    }
}

int main() {
    string s;
    string t;
    cin>>s;
    cin>>t;
    cout << minRotations(s,t);
}