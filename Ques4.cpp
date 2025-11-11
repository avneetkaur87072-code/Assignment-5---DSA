#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class LinkedList {
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void reverse() {                          
        Node* prev = NULL;                     
        Node* curr = head;          
        Node* nextNode = NULL;

        while (curr != NULL) {
            nextNode = curr->next; // save next
            curr->next = prev;     // reverse link
            prev = curr;           // move prev forward
            curr = nextNode;       // move curr forward
        }

        head = prev; // new head is last node
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList l;

    l.insertEnd(1);
    l.insertEnd(2);
    l.insertEnd(3);
    l.insertEnd(4);
    l.insertEnd(5);

    cout << "Original List: ";
    l.display();

    l.reverse();

    cout << "Reversed List: ";
    l.display();

    return 0;
}


