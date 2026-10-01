#include <iostream>
using namespace std;
struct Node{
    Node* add;
    int value;
};
int main(){
    Node* n1 = new Node();
    Node* n2 = new Node();
    Node* n3 = new Node();
    Node* n4 = new Node();
   n1->add = n2;
   n2->add = n3;
   n3->add = n4;
   n4->add = nullptr;   
    n1->value = 10;
    n2->value = 20;
    n3->value = 30;
    n4->value = 40;

    Node* n5 = new Node();
    n5->add = nullptr;
    n5->value = 50;

    Node* j = n1;
    while( j->add != nullptr){
        if(j->add->value == 20){
            cout << "Poch gaya" << endl;
            n5->add = j->add;
            j->add = n5;
        }
        j = j->add;
        
    }
    
    for(Node* i = n1 ; i != nullptr ; i = i->add ){
        cout << i->value << endl;
    }
    return 0;
}