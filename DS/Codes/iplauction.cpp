/*

In IPL auction, a team has a budget of ₹80 crore. Players are being auctioned one by one, each with a bid price. 
The team wants to buy players greedily — always pick the cheapest available player until budget runs out, but must maintain a squad of exactly 11.

Twist: If a better (cheaper) player appears after buying an expensive one, swap if it saves money.

Input:

Budget = 80 crore
Players available (name, price in crore):
[Ravi(12), Priya(8), Arjun(15), Meena(6), Kiran(10),
 Player6(5), Player7(18), Player8(7), Player9(11), Player10(9), Player11(14)]
Expected: Select 11 cheapest players within budget

Which Heap? 



*/

#include <vector>
#include <iostream>
using namespace std;

class Player{
    public:
    string name;
    int price;
    
    Player(string s, int p) {
        name=s;
        price=p;
    }
};

class maxheap{
	public:
	vector<Player> elements;
	maxheap(Player root){
		elements.push_back(root->data);
	}
	int parent(int i){
		return (i-1)/2;
	}
	void insert(Player val){
		elements.push_back(val);
		int i = elements.size()-1;
		while(i>0 && elements[i]>elements[parent(i)]){
			swap(elements[i],elements[parent(i)]);
			i=parent(i);
		}
	}
  	void deleteElement(){
		swap(elements.front(),elements.back());
		elements.pop_back();
		int i=0;
		while(true){
			int leftchild = (2*i)+1;
			int rightchild = (2*i)+2;
			int largest = i;
			if(leftchild<elements.size() && elements[leftchild]>elements[largest])
				largest = leftchild;
			if(rightchild<elements.size() && elements[rightchild]>elements[largest])
				largest = rightchild;
			 if(largest == i) break; 
			swap(elements[i],elements[largest]);
			i = largest;
		}
	}
//   	void print(){
// 	  	for(int i:elements){
// 		  	cout<<i<<" ";
// 		}
// 		cout<<endl;
//   	}
	Player getmax(){
		return elements[0];
	}
	int getsize(){
		return elements.size();
	}
};

// void addChild(Node* root,int val){
//       if(root==NULL){
//           root = new Node(val);
//       }
//       addChild(root->left,val);
//       	cout<<root->data<<" ";
//       addChild(root->right,val);
//   }
  
int main(){
	Player p1("ravi",12);
	Player p2("Priya",8);
	Player p3("Arjun",15);
	Player p4("Meena",6);
	Player p5("Kiran",10);
	Player p6("Aran",50);
	
	maxheap mh(p1);
	mh.insert(p2);
	mh.insert(p3);
	if (p4.price<mh.getmax().price) {
	    mh.deleteElement();
	    mh.insert(p4);
	}
	if (p5.price<mh.getmax().price) {
	    mh.deleteElement();
	    mh.insert(p5);
	}
	if (p6.price<mh.getmax().price) {
	    mh.deleteElement();
	    mh.insert(p6);
	}
}