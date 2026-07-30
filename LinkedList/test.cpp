#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Node{
    public:
    int value;
    Node* next;

    Node(int value){
        this->value = value;
        next = nullptr;
    }
};

class SLL{
    private:
    Node* head = nullptr;

    public:
    SLL(){
        this->head = nullptr;
    }

    void insertAtFirst(int value){
        Node* NewNode = new Node(value);
        NewNode->next = head;
       head = NewNode;
    }
    void insertInBetween(int value , int position){
        if(head == nullptr && position == 1){
            insertAtFirst(value);
        }

        Node* temp = head;
        for(int i=0; i<position -1 && temp->next != nullptr ; i++){
            temp = temp->next;
        }
        if(temp->next == nullptr){
            cout <<  "No valid position" << endl;
        }
        Node* NewNode = new Node(value);
          NewNode->next = temp->next;
        temp->next = NewNode;
      
    }
    void display(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->value << endl;
            temp = temp->next;
            }

    }
    void deleteAtPosition(int position){
        if(head == nullptr){
            cout << "There is no node in Singly LinkedList " << endl;

        }

        Node* temp  = head;
        for(int i=1; i<position -1 && temp!=nullptr; i++){
            temp = temp->next;
        }
        Node* temp1 = temp->next->next;
        temp->next = temp1;
    }
};
int main(){
    vector<int> arr = {-2, 1 , -3 , 4 , 7 , 2, -2};
    int sum =0;
    int maxium = 0;
    int k =2;
    for(int i =0; i< k ; i++){
        sum = sum + arr[i];
    }
    maxium = sum;
    for(int i= k; i<arr.size() ; i++){
        sum = sum - arr[i -k] + arr[i];
        maxium = max(maxium , sum);
    }
    cout << "Maximum Sum : " <<  maxium << endl;

    SLL s1;
    s1.insertAtFirst(12);
    s1.insertAtFirst(22);
    s1.insertAtFirst(32);
    s1.insertAtFirst(42);
    s1.insertAtFirst(52);
    s1.insertInBetween(25 , 3);
    s1.display();
    s1.deleteAtPosition(2);
      cout << "After Deletion "  << endl;
        s1.display();
    return 0;
}
// Array vs LinkedList 

// Array :- it is a contigous memory alocation data-structure which stores homogennous data-types value . It has fixed size . Iteration or deletion takes o(n) time complexity 
// LinkedList :- A dynamic memory alocation has node  to iterate which stores value and the address of next node no contiguous memory requires .  It can store efficiently insertation and deletion in it 
