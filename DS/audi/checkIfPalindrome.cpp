/*
Check if any rotation is a palindrome
1. Generate each rotation.
2. For each rotation, check palindrome:
Two-pointer check from ends inward.
3. If any rotation passes → true; else false.

Sample Input:
a  
Sample Output:
true



*/
#include <string>
#include <iostream>
using namespace std;

bool checkPalindrome(string s) {
    int n = s.length();
    string s2 = s+s;
    int j=n-1;
    for (int i=0; i<n; i++) {

        int left = i;
        int right = j;
        int count = 0;

        while(left<right) {
            if (s2[left]==s2[right]) {
                count++;
            }
            left++;
            right--;
        }
        if (count==(n/2)) {
            return true;
        }
        j++;  
    }
    return false;
}

int main() {
    cout << checkPalindrome("nigga");
}


// #include <bits/stdc++.h>
// using namespace std;

// bool isPalindrome(const string &s) {
//     int l = 0, r = s.size() - 1;
//     while (l < r) {
//         if (s[l] != s[r]) return false;
//         l++;
//         r--;
//     }
//     return true;
// }

// bool isAnyRotationPalindrome(string s) {
//     int n = s.size();

//     for (int i = 0; i < n; i++) {
//         if (isPalindrome(s)) return true;
//         s = s.substr(1) + s[0];
//     }
//     return false;
// }

// int main() {
//     string s;
//     cin >> s;

//     cout << (isAnyRotationPalindrome(s) ? "true" : "false");
//     return 0;
// }