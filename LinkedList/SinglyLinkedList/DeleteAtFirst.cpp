#include <iostream>
using namespace std;
class Node{
    public :
    int value;
    Node* next;
    Node(int value ){
        this->value = value;
        next = nullptr;
        
    }
};
class SLL{
    private:
    Node * head ;
    public:
    SLL(){
        this->head = nullptr;
        
    }
    
    void deleteAtFirst(int x){
        if(head == nullptr){
            cout << "There is no Node present" << endl;
        
            return;
        }
        
        if(head->value == x){
            Node* temp = head;
            head = temp->next;
         delete temp;
        }
        
    }
    void insertAtFirst(int value){
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void display(){
          if(head == nullptr){
                cout << "No node created " << endl;
                return;
                
            }
            Node* temp =head;
            while (temp != nullptr)
            {
                cout << temp->value << endl;
                    temp =temp->next;
            }
            
    }
};

int main()
{
    SLL s1;
    s1.insertAtFirst(10);
    s1.insertAtFirst(40);
    s1.insertAtFirst(20);
    s1.deleteAtFirst(20);
    s1.display();

    return 0;
}