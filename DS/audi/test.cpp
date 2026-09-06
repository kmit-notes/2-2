#include <iostream>
#include <string>
#include<vector>//ds standard template
using namespace std;


class Medicine {
private:
    string name;
    double price;
    int quantity;
    
public:
    Medicine(string n = "Unknown", double p = 0.0, int q = 0) 
        : name(n), price(p), quantity(q) {}
    
    // Getters
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    
    void display(){
        cout<<name<<" "<<price<<" "<<quantity<<endl;
    }
    
    void operator*(){
        cout<<"WOW";
    }
   
    bool operator<(const Medicine& other) const {
        return price < other.price;
    }
    
    bool operator>(const Medicine& other) const {
        return price> other.price;
    }
   
    bool operator==(const Medicine& other) const {
        return name == other.name && price == other.price;
    }
    
    bool operator!=(const Medicine& other) const {
        return name != other.name;
    }
    
    
    Medicine operator+(const Medicine& other) const {
        if (name == other.name) {
            return Medicine(name, price, quantity + other.quantity);
        }
        cout << "Warning: Adding different medicines!" << endl;
        return *this;
    }
    
    Medicine operator-(const Medicine& other) const {
        if (name == other.name) {
            return Medicine(name, price, quantity - other.quantity);
        }
        cout << "Warning: Substracting different medicines!" << endl;
        return *this;
    }
    
    
    
    Medicine& operator+=(int amount) {
        quantity += amount;
        return *this;  
    }
    
  
    
  
    Medicine& operator++() {
        ++quantity;
        return *this;
    }
    
    // Postfix increment (med++)
    Medicine operator++(int) {  // int parameter distinguishes postfix
        Medicine temp = *this;  // Save current state
        ++quantity;
        return temp;  // Return old value
    }
};
int main()
{
     Medicine med1("Aspirin", 5.99, 100);
    Medicine med2("Aspirin", 5.99, 50);
    Medicine med3("Ibuprofen", 7.25, 75);
    if (med1 == med2) {
        cout << "Medicines are same type" << endl;
    }
    //med1 += 30;
    cout << "After restocking: " << med1.getName() << med1.getQuantity() << endl;
    vector<Medicine> list; 
    list.push_back(med1);
    list.push_back(med2);
    list.push_back(med3);
    /*Medicine m;
    for(size_t i=0; i<list.size();i++){
        if(m<list.at(i))
        m=list.at(i);
    }
    cout<< m.getName() << endl;*/
    //*med1;
    Medicine m4 = med1-med2;
    m4.display();
    Medicine m5 = med1 + med2;
    m5.display();
    ++med1;
    med1.display();
    Medicine m6 = med1++;
    m6.display();
    med1.display();
}