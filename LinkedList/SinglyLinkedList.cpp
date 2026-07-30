#include <iostream>
#include <string>
using namespace std;

class Node{
    public :
    int value;
    Node* next;

    Node(int value){
        this->value = value;
        next = nullptr;
    }
};
    class SLL{
        private:
        Node* head;
        public:
        SLL(){
            this->head = NULL;
        }
        void insertAtFirst(int data){
            Node* temp = new Node(data);

            // case handle
            temp->next = head;
            head = temp;

        }
        void insertAtEnd(int data){
            Node* temp = new Node(data);
               if(head == nullptr){
                 head = temp;
                    return;
            }
            Node* temp1 = head;
            while (temp1->next!=nullptr)
            {
               temp1 = temp1->next;
            }
            temp1->next = temp;

            
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
        void insertAtPosition(int data , int position){
            if(position <=0){
                cout << "It can not be added in this position as Likend list does not exists";
                return;
            }
            if(position ==1){
                insertAtFirst(data);
                return;
            }

            Node* newNode = new Node(data);
            Node* temp = head;

            for(int i=1; i< position -1 && temp!=nullptr ; i++){
                temp = temp->next;
            }
            
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        void deleteAtFirst(){
            if(head == nullptr){
                cout << "List is Empty";
                return;
            }
               Node *temp = head;
               head= temp->next;
               delete temp;   


            //    head = head->next; complex code in this we do not have to create a address  
       }

       void deleteAtEnd(){
         if(head == nullptr){
                cout << "List is Empty";
                return;
            }
            if(head->next == nullptr){
                delete head;
                head = nullptr;
                return;
            }
            Node* temp  = head;
            while(temp->next->next != nullptr){
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;

       }

       void deleteAtPosition(int value){
        if(head == nullptr){
             cout << "List is Empty";
                return;
        }
        Node* temp = head;
        while(temp->next!= nullptr && temp->next->value != value){
            temp = temp->next;
        }

        if(temp->next == nullptr){
            cout << "Target not found" << endl;   
        }
        temp->next = temp->next->next;
       }

    };
int main(){
    Node *temp = new Node(21);
    SLL dhe;
    dhe.insertAtFirst(32);
    dhe.insertAtFirst(42);
    dhe.insertAtFirst(52);
    dhe.insertAtFirst(62);
    dhe.insertAtEnd(90);
    dhe.display();
    dhe.deleteAtFirst();
    cout << "Deleted first node" << endl;
    dhe.display();
    return 0;
}