#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>> &image, int r, int c, int oc, int newColor) {
    if (r>=image.size() || r<0 || c>=image[0].size() || c<0) {
        return;
    }
    if(image[r][c]!=oc) return;
    if(image[r][c]==oc) {
        image[r][c]=newColor;
    }
    dfs(image,r,c+1,oc,newColor);
    dfs(image,r+1,c,oc,newColor);
    dfs(image,r,c-1,oc,newColor);
    dfs(image,r-1,c,oc,newColor);
}


int main() {
    vector<vector<int>> image={
        {1,1,0,1},
        {1,1,0,1},
        {0,0,1,0},
        {1,1,0,1}
    };
    dfs(image,0,0,1,10);
    dfs(image,0,0,0,9);
    for(auto it: image) {
        for (auto it1:it) {
            cout<<it1<<" ";
        }
        cout<<endl;
    }
}