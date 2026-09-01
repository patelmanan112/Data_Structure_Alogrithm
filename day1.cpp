#include <iostream>
using namespace std;

struct Box
{
    int value;
    Box* address;
};

int main(){
    int a = 30;
    Box* b1 = new Box();
    Box* b2= new Box();
    b1->value = a;
    b1->address = b2;
    cout << b1->value << endl;
    cout << b1->address;
    // int x =10;
    // int *y = &x;
    // float a = 4.5;
    // float *b = &a;
    // int *c = &a;
    // cout << b << endl;
    // cout << c << endl;
    // cout << &x ;
    
    return 0;
}