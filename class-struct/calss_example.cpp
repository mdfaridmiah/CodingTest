#include<bits/stdc++.h>
using namespace std;


class Arithmatics{
    public:

    int a, b;
    int c = 10;

    // Default constructor
    Arithmatics() {
        cout<<"Default constructor called"<<endl;
    }

    // Parameterized constructor
    Arithmatics(int _a, int _b) {
        cout<<"Parameterized constructor called"<<endl;
        a = _a;
        b = _b;
    }


    /*
    // Copy constructor
    Arithmatics(Arithmatics &obj){
        cout<<"Copy constructor called"<<endl;
        a = obj.a
        b = obj.b
    }
    */

    int add(int n1, int n2) {
        return n1 + n2;
    }

    int add() {
        return a + b;
    }

    // Member Function
    sub();

};

int Arithmatics :: sub() {
   return a - b;
}


int main() {

    Arithmatics arith;
    arith.a = 10;
    arith.b = 20;

    cout<< arith.add(5,10) <<endl;
    cout<< arith.add() <<endl;
    cout<<arith.sub()<<endl;

    // copy
    Arithmatics otherObj = arith;

    otherObj.a = 100;
    otherObj.b = 500;
    cout<<otherObj.add()<<endl;
    cout<<arith.add()<<endl;


	return 0;
}

