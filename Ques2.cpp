#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	Node(int x){
		data = x;
		next = NULL;
	}
};

class List{
	Node* head;
	public:
		List(){
			head = NULL;
		}
		void insertEnd(int val){
			Node* newNode = new Node(val);
			if(head == NULL){
				head = newNode;
			}
			else {
			Node* temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->next = NULL;
	     	}
		}
		
		int deleteOccurances(int key){
			int count = 0;

        // Remove from beginning if key is at head
        while (head != NULL && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }

        // Remove from the rest of the list
        Node* curr = head;
        while (curr != NULL && curr->next != NULL) {
            if (curr->next->data == key) {
                Node* temp = curr->next;
                curr->next = temp->next;
                delete temp;
                count++;
            } else {
                curr = curr->next;
            }
        }
        return count;
		}
		
		void display(){
			if(head == NULL){
				cout << "List empty." << endl;
				return;
			}
			Node* temp = head;
			while(temp != NULL){
				cout << temp->data<<" ";
				temp = temp->next;
			}
		}
		
};
int main() {
    List l1;
    
    l1.insertEnd(1);
    l1.insertEnd(2);
    l1.insertEnd(1);
    l1.insertEnd(2);
    l1.insertEnd(1);
    l1.insertEnd(3);
    l1.insertEnd(1);

    int key = 1;
    int count = l1.deleteOccurances(key);

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    l1.display();
    cout << endl;

    return 0;
}

