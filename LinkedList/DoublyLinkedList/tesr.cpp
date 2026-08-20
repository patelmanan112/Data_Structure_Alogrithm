#include <iostream>
using namespace std;
class Node{
    public :
    Node* next;
    Node* prev;
    int value;
    Node(int value){
        this->value = value;
        prev = nullptr;
        next = nullptr;

    }
};
class DLL{
    private :
    Node* head;
    public:
    DLL(){
        head = nullptr;
    }
    void insertAtFirst(int value){
        Node* newNode = new Node(value);
        newNode->next = head;
if (head != nullptr)
    head->prev = newNode;

head = newNode;
    }
    void deleteAtPositon(int position){
        if(head == nullptr){
            return ;
        }
        Node* curr = head;
        for(int i =0; i<position && curr !=nullptr ; i++){
            curr = curr->next;
        }
        if(curr == nullptr){
            return;
        }
        if (position == 0) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete curr;
            return;
    }
        Node* previous = curr->prev;
        previous->next = curr->next;
        if (curr->next != nullptr) {
            curr->next->prev = previous;
        }

        delete curr;
}
    void display(){
        Node* curr = head;
        cout << "Hello display called" << endl;
        while(curr != nullptr){
            cout << curr->value << endl;
            curr = curr->next;
        }
    }
};

int main(){
    DLL d1;
    d1.insertAtFirst(45);
    d1.insertAtFirst(65);
    d1.insertAtFirst(15);
    d1.insertAtFirst(25);
    d1.insertAtFirst(25);
    d1.display();
    d1.deleteAtPositon(1);
     d1.display();
    return 0;
}