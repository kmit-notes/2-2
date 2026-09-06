#include <vector>
#include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *left;
		Node *right;
		Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};
class minheap{
  	public:
  	vector<int> elements;
  	Node* root;
  	minheap(Node* root){
	  	this->root = root;
	  	elements.push_back(root->data);
  	}
  	int parent(int i){
	  	return (i-1)/2;
	}
	void insert(int val){
		elements.push_back(val);
		int i = elements.size()-1;
		while(i>0 && elements[i]<elements[parent(i)]){
			swap(elements[i],elements[parent(i)]);
			i=parent(i);
		}
	}
	void print(){
	  	for(int i:elements){
		  	cout<<i<<" ";
		}
		cout<<endl;
  	}
  	int getmin(){
	  	return elements[0];
  	}
  	int getsize(){
	  	return elements.size();
  	}
	void deleteElement(){
		swap(elements.front(),elements.back());
		elements.pop_back();
		int i=0;
		while(true){
			int leftchild = (2*i)+1;
			int rightchild = (2*i)+2;
			int smallest = i;
			if(leftchild<elements.size() && elements[leftchild]<elements[smallest])
				smallest = leftchild;
			if(rightchild<elements.size() && elements[rightchild]<elements[smallest])
				smallest = rightchild;s
			if(smallest == i) break; 
			swap(elements[i],elements[smallest]);
			i = smallest;
		}
	}
};

class maxheap{
	public:
	vector<int> elements;
	Node* root;
	maxheap(Node* root){
		this->root = root;
		elements.push_back(root->data);
	}
	int parent(int i){
		return (i-1)/2;
	}
	void insert(int val){
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
  	void print(){
	  	for(int i:elements){
		  	cout<<i<<" ";
		}
		cout<<endl;
  	}
	int getmax(){
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
	Node* n = new Node(5);
	minheap m(n);
	m.insert(1);
	m.insert(3);
	m.insert(8);
	m.insert(6);
	m.print();
	m.deleteElement();
	m.print();
	// addChild(n,5);
	// addChild(n,1);
	// addChild(n,3);
	// addChild(n,8);
	// addChild(n,6);
	
	Node* n1 = new Node(5);
	maxheap m1(n1);
	m1.insert(1);
	m1.insert(3);
	m1.insert(8);
	m1.insert(6);
	m1.print();
	m1.deleteElement();
	m1.print();
}