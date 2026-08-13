#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int value) {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DLL {
private:
    Node* head;
    Node* tail;

public:

    DLL() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert at first
    void insertAtFirst(int value) {
        Node* temp = new Node(value);

        if (head == nullptr) {
            head = temp;
            tail = temp;
            return;
        }

        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    // Display
    void display() {
        if (head == nullptr) {
            cout << "There is no node present in the list" << endl;
            return;
        }

        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // Insert at position
    void insertAtPosition(int value, int position) {

        // Position 1 means insert at first
        if (position == 1) {
            insertAtFirst(value);
            return;
        }

        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;

        // Reach node before the required position
        for (int i = 1; i < position - 1 && temp->next != nullptr; i++) {
            temp = temp->next;
        }

        Node* newNode = new Node(value);

        newNode->prev = temp;
        newNode->next = temp->next;

        // Connect previous node to new node
        temp->next = newNode;

        // Connect next node to new node
        if (newNode->next != nullptr) {
            newNode->next->prev = newNode;
        }
        else {
            // New node became the last node
            tail = newNode;
        }
    }

    // Delete first
    void deleteAtFirst() {

        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* toDele = head;

        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            // List became empty
            tail = nullptr;
        }

        delete toDele;
    }

    // Delete last
    void deleteAtLast() {

        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* toDele = tail;

        // Only one node
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
            delete toDele;
            return;
        }

        tail = tail->prev;
        tail->next = nullptr;

        delete toDele;
    }

    // Delete node by VALUE
    void deleteAtPosition(int target) {

        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        // Target is head
        if (head->value == target) {
            deleteAtFirst();
            return;
        }

        Node* current = head;

        // Search target
        while (current != nullptr && current->value != target) {
            current = current->next;
        }

        // Target not found
        if (current == nullptr) {
            cout << "Value not found" << endl;
            return;
        }

        // Target is tail
        if (current == tail) {
            deleteAtLast();
            return;
        }

        // Target is in middle
        Node* prev = current->prev;
        Node* next = current->next;

        prev->next = next;
        next->prev = prev;

        delete current;
    }
};

int main() {

    DLL s1;

    s1.insertAtFirst(10);
    s1.insertAtFirst(50);
    s1.insertAtFirst(30);
    s1.insertAtFirst(20);

    cout << "Original list: ";
    s1.display();

    s1.insertAtPosition(69, 3);

    cout << "After inserting 69 at position 3: ";
    s1.display();

    s1.deleteAtPosition(69);

    cout << "After deleting 69: ";
    s1.display();

    s1.deleteAtFirst();

    cout << "After deleting first: ";
    s1.display();

    s1.deleteAtLast();

    cout << "After deleting last: ";
    s1.display();

    return 0;
}