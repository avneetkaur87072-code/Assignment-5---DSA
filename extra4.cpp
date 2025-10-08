#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
// Rotate left by k
    Node* rotateLeft(int k) {
        if (!head || k == 0) return head;

        // Step 1: Find length
        Node* temp = head;
        int length = 1;
        while (temp->next) {
            temp = temp->next;
            length++;
        }
        // Step 2: Adjust k
        k = k % length;
        if (k == 0) return head;

        // Step 3: Connect last node to head (circular list)
        temp->next = head;

        // Step 4: Move to (k-th node)
        Node* newTail = head;
        for (int i = 1; i < k; i++) {
            newTail = newTail->next;
        }

        // Step 5: Break and set new head
        Node* newHead = newTail->next;
        newTail->next = NULL;

        head = newHead;
        return head;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);

    cout << "Original List: ";
    list.display();

    list.rotateLeft(2);

    cout << "After Left Rotate by 2: ";
    list.display();

    return 0;
}

