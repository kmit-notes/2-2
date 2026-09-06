#include<iostream>
using namespace std;
int m1(int a){
	if(a==1){
		return 200;
	}
	cout<<"Val:- "<<a<<endl;
	int result= m1(a/10);
	return result;
}
int power(int base, int expo){
	if(expo==0){
		return 1;
	}
	int result = base*power(base, expo-1);
		return result;
}
int length(int x){
	if(x==0){
		return 0;
	}
	int result = length(x/10);
		return result+1;
}
int sum(int num){
	if(num==0){
		return 0;
	}
	int rem= num%10;
	int digit = sum(num/10);
	return rem+digit;
}
int reverse(int num, int reversed = 0) {
    if (num == 0)
        return reversed;

    reversed = reversed * 10 + num % 10;
    return reverse(num /10, reversed);
}
int main(){
	int k=m1(1000);
	cout<<"Value:- " <<k<<endl;
	cout<<power(10,4)<<endl;
	cout<<length(123412)<<endl;
	cout<<sum(1234)<<endl;
	cout<<reverse(241)<<endl;
}