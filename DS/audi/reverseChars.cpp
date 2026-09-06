/*
Problem:
Reverse characters in each word but maintain word order.
Examples:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Input: "Hello World"
Output: "olleH dlroW"
*/

#include <string>
#include <iostream>
using namespace std;

void reversal(string& s) {
    int n = s.length();
    int start = 0;

    for (int end=0; end<=n; end++) {
        if (end==n || s[end]==' ') {
            int i = start;
            int j = end-1;
            start = end+1;
            while(i<j) {
                swap(s[i],s[j]);
                i++;
                j--;
            } 
        }
    }
    cout << s;

}

int main() {
    string s = "hello world";
    reversal(s);
}