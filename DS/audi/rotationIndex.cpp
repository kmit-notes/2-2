/*
Find the rotation index that gives the smallest string
1. For each cut position i, build the rotation.
2. Keep the smallest rotation seen.
3. Return the index i that produced it.


Sample Input:
baca  
Sample Output:
3

*/

#include <string>
#include <iostream>
using namespace std;

int smallestIndex(string s) {
    int n = s.length();
    string s2 = s+s;
    int count=0;
    
}