#include<bits/stdc++.h>
using namespace std;


struct Arithmatics{
    int a, b;
    int c = 10;
    // Constructor
    Arithmatics(){}
    Arithmatics(int _a, int _b): a(_a), b(_b){}

    // Operator Overloading
    bool operator < (const Arithmatics  &rhs) const {
        return a > rhs.b;
    }
};


int main() {

    Arithmatics obj(10,20);

    cout<<obj.a<< " "<<obj.b<<endl;

    Arithmatics otherObj;

    otherObj.a = 100;
    otherObj.b = 200;
    cout<<otherObj.a<<" "<<otherObj.b<<endl;

	return 0;
}


