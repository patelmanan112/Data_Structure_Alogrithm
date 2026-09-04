#include <iostream>
using namespace std;

struct Box
{
    int value;
    Box *address;
};

struct Node
{
    int value;
    Node *address;
};
int main()
{
    int a = 30;
    // Box* b1 = new Box();
    // Box* b2= new Box();
    // b1->value = a;
    // b1->address = b2;
    // cout << b1->value << endl;
    // cout << b1->address;
    // int x =10;
    // int *y = &x;
    // float a = 4.5;
    // float *b = &a;
    // int *c = &a;
    // cout << b << endl;
    // cout << c << endl;
    // cout << &x ;

    Node *n0 = new Node();
    Node *n1 = new Node();
    Node *n2 = new Node();
    Node *n3 = new Node();
    Node *n4 = new Node();
    Node *n5 = new Node();
    Node *n6 = new Node();
    n0->address = n1;
    n1->address = n2;
    n2->address = n3;
    n3->address = n4;
    n4->address = n5;
    n5->address = n6;
    n6->address = nullptr;
    n0->value = 0;
    n1->value = 10;
    n2->value = 20;
    n3->value = 30;
    n4->value = 40;
    n5->value = 50;
    n6->value = 60;

    Node *curr = n0;
    // while(curr){
    //     cout << curr->value << endl;
    //     curr = curr->address;
    // }
    for (Node *i = n0; i != nullptr; i = i->address)
    {
        cout << i->value << endl;
    }

    // cout << curr << endl;
    return 0;
}