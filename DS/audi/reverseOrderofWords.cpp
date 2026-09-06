/*

Problem:
Reverse the order of words in a string. Words are separated by spaces.
Examples:
Input: "the sky is blue"
Output: "blue is sky the"

Input: "  hello world  "
Output: "world hello"
(Note: Remove extra spaces)

Input: "a good   example"
Output: "example good a"
(Note: Reduce multiple spaces to single space)
Constraints:

Remove leading/trailing spaces
Reduce multiple spaces between words to single space
*/

#include <string>
#include <iostream>
using namespace std;

void wordReverse(string& s) {
    int start = 0;
    string s1 = "";
    int end = s.length()-1;
    for (;end>=0;end--) {
        if(s.at(end)==' ') {
            s.erase(end);
        }
        
    }

}