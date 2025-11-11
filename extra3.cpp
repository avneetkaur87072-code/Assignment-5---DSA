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

    // Detect loop and return start node
    Node* detectLoopStart() {
        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect if loop exists
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { // Loop detected
                // Step 2: Find start of loop
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // Start node of loop
            }
        }
        return NULL; 
    }

    // Remove loop
    void removeLoop() {
        Node* loopStart = detectLoopStart();
        if (loopStart == NULL) {
            cout << "No Loop Found!" << endl;
            return;
        }

        Node* temp = loopStart;
        while (temp->next != loopStart) {
            temp = temp->next;
        }
        temp->next = NULL; // Break loop
        cout << "Loop removed. It started at node: " << loopStart->data << endl;
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

    // Create a loop: 5 -> 3
    list.head->next->next->next->next->next = list.head->next->next;

    Node* loopStart = list.detectLoopStart();
    if (loopStart)
        cout << "Loop starts at node: " << loopStart->data << endl;
    else
        cout << "No Loop detected." << endl;

    list.removeLoop();  

    cout << "Linked List after loop removal: ";
    list.display();

    return 0;
}


