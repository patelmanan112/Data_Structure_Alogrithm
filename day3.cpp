#include <iostream>
#include <string>
using namespace std;

class Node{
    public :
    int value;
    Node* prev;
    Node* next;

    Node(int value){
        this->value = value;
        this->prev = nullptr;
        this->next = nullptr;

    }
};
class DLL{
    private :
    Node* head ;

    public:
    DLL(){
        head = nullptr;
    }

    void insertAtFirst(int value){
        Node* newNode = new Node(value);

        newNode->next = head;
        head->prev = newNode;
        head = newNode;

    }
    void insertAtEnd(int value){
        Node* curr = head;
        Node* newNode = new Node(value);
        while(curr->next->next !=nullptr){
            curr = curr->next;
        }

        newNode->prev = curr;
        curr->next->prev = newNode;
        newNode->next = curr->next->next;
    }
    
};
int main(){
    Node*  n0 =  new  Node(10);
    Node* n1 = new Node(20);
    Node* n2 = new Node(30);
    Node* n3 = new Node(40);

    n0->prev = nullptr;
    n0->next = n1;
    n1->prev = n0;
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    

    return 0;
}