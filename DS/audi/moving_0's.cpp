#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    vector<int> i = {1,0,2,4,0,1};
    for(int j=0;j<i.size();j++){
        if(i.at(j)==0){
            i.erase(i.begin()+j);
            i.push_back(0);
            j--;
        }
    }
    for(int j: i){
        cout<<j;
    }
    return 0;
}