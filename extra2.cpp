#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() { head = NULL; }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    Node* reverseKGroup(Node* head, int k) {
        if (!head) return NULL;

        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

        // Check if there are at least k nodes left
        Node* check = head;
        for (int i = 0; i < k; i++) {
            if (!check) return head; // not enough nodes ? leave as-is
            check = check->next;
        }

        // Reverse k nodes
        int count = 0;
        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Recur for the remaining list
        if (next) {
            head->next = reverseKGroup(next, k);
        }

        // prev is the new head of this reversed block
        return prev;
    }

    void display(Node* head) {
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
    for (int i = 1; i <= 9; i++) list.insertAtEnd(i);

    cout << "Original List: ";
    list.display(list.head);

    int k = 3;
    list.head = list.reverseKGroup(list.head, k);

    cout << "Reversed in groups of " << k << ": ";
    list.display(list.head);

    return 0;
}

