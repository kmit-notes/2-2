/*

Lexicographically smallest rotation of a string
1. Generate every rotation:
For each cut position i, rotation = suffix starting at i + prefix ending at i-1.
2. Keep the smallest rotation using lexicographic comparison.
3. Return the best one.


Sample Input:
acb  
Sample Output:
acb

*/

#include <string>
#include <iostream>
using namespace std;



string lex(string s) {
    int n = s.length();
    string min=s;
    string rsrc=s;
    for (int i=0;i<n;i++) {
        char temp = rsrc.at(n-1);
        for (int j=n-1;j>0;j--) {
            rsrc[j]=rsrc[j-1];
        }
        rsrc[0]=temp;
        if (rsrc<min) {
            min=rsrc;
        }
    }
    return min;
}

int main() {
    cout << lex("acb");
}