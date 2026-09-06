#include<iostream>
using namespace std;
class queue{
    public:
    int capacity;
    int i;
    int j;
    int a[];
    
    queue(int x){
        capacity=x;
        a[capacity];
        i=capacity-1;
        j=capacity-1;
    }
    
    void enque(int x){
        a[i]=x;
        i--;
    }
    void deque(){
        j--;
    }
    void printqueue(){
        int k = capacity-1;
        while(i<=k){
            cout<<a[k]<<endl;
            k--;
        }
    }
};
int main(){
    queue q(5);
    q.enque(2);
    q.enque(6);
    q.enque(7);
    q.enque(8);
    q.enque(10);
    q.printqueue();
}