/*
Pattern exists in a circular string
1. If pattern length > string length → usually false (depends on rules, but typical).
2. Search pattern in s+s.
3. If found within the first n start positions, then pattern occurs in some rotation.


Sample Input:
abcde
cdeab  
Sample Output:
true

*/
#include <string>
#include <iostream>
using namespace std;


void circString(string s, string t) {
    int n = s.length();
    int m = t.length();
    string s2 = s+s;
    if (t<s) {
        cout << "false";
        return;
    }
    size_t pos = s2.find(t);
    if (pos<n) {
        cout << "true";
        return;
    }
    cout << "false";
    return;
}

int main() {
    circString("abcde","cdeab");
}