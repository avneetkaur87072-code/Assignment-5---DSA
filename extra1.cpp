#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

Node* getIntersectionNode(Node* headA, Node* headB) {
    if (!headA || !headB) return NULL;

    Node* p1 = headA;
    Node* p2 = headB;

    while (p1 != p2) {
        p1 = (p1 == NULL) ? headB : p1->next;
        p2 = (p2 == NULL) ? headA : p2->next;
    }

    return p1;
}

int main() {
    Node* common = new Node(8);
    common->next = new Node(5);

    // List A: 4 -> 1 -> 8 -> 5
    Node* headA = new Node(4);
    headA->next = new Node(1);
    headA->next->next = common;
   

    // List B: 5 -> 6 -> 1 -> 8 -> 5
    Node* headB = new Node(5);
    headB->next = new Node(4);
    headB->next->next = new Node(1);
    headB->next->next->next = common;

    Node* intersection = getIntersectionNode(headA, headB);
    if(intersection) cout << intersection->data << endl;
    else cout << "no intersection." << endl;

    return 0;
}


