#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* prev;
    Node* next;

    Node(int value) {
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
};

class CLL {
private:
    Node* head;
    Node* tail;

public:

    CLL() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtFirst(int value) {

        Node* newNode = new Node(value);

        // Empty list
        if (head == nullptr) {
            head = newNode;
            tail = newNode;

            head->next = head;
            head->prev = head;

            return;
        }

        newNode->next = head;
        newNode->prev = tail;

        head->prev = newNode;
        tail->next = newNode;

        head = newNode;
    }

    void insertAtPosition(int value, int position) {

        if (position == 1) {
            insertAtFirst(value);
            return;
        }

        if (head == nullptr) {
            return;
        }

        Node* curr = head;
        for (int i = 1; i < position - 1; i++) {
            curr = curr->next;
            if (curr == head) {
                return;
            }
        }

        Node* newNode = new Node(value);
        newNode->prev = curr;
        newNode->next = curr->next;
        curr->next->prev = newNode;
        curr->next = newNode;

        if (curr == tail) {
            tail = newNode;
        }
    }

    void display() {

        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* curr = head;

        do {
            cout << curr->value << " ";
            curr = curr->next;
        } while (curr != head);

        cout << endl;
    }
};

int main() {

    CLL c1;

    c1.insertAtFirst(10);
    c1.insertAtFirst(20);
    c1.insertAtFirst(30);
    c1.insertAtFirst(40);
    c1.insertAtFirst(50);

    c1.insertAtPosition(90, 1);

    c1.display();

    return 0;
}