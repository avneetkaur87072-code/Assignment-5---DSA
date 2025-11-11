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
		void insertBegin(int val){
			Node *newNode =  new Node(val);
			newNode->next = head;
			head = newNode;
			return;
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
		void insertAfterVal(int val,int x){
			Node* newNode = new Node(x);
			
			if(head == NULL){
				head = newNode;
			}
			else{
				Node* temp = head;
				while(temp != NULL && temp->data != val){
					temp = temp->next;
				}
				newNode->next = temp->next;
				temp->next = newNode;
			}
		}
		void insertAfterPosition(int pos, int val){
			if(pos < 0){
				cout << "Invalid position." << endl;
				return;
			}
			Node* newNode = new Node(val);
			if(head == NULL){
				head = newNode;
			}
			else{
				int count = 0;
				Node* temp = head;
				while(temp != NULL && count < pos-1){
					temp = temp->next;
					count++;
				}
				if(temp == NULL){
					cout<<"position out of range."<< endl;
					return;
				}
				newNode->next = temp->next;
				temp->next = newNode;
			}
		}
		
		void deleteBegin(){
			if(head == NULL){
				cout <<"underflow."<< endl;
				return;
			}
			else{
				Node* temp = head;
			    head = head->next;
			    delete temp;
			}
		}
		
		void deleteEnd(){
			if(head == NULL){
				cout <<"underflow."<< endl;
				return;
			}
			else if(head->next == NULL){
				delete head;
				head = NULL;
				return;
			}
			else{
				Node* temp = head;
				while(temp->next->next != NULL){
					temp= temp->next;
				}
				delete temp->next;
				temp->next = NULL;
			}
		}
		
		void deleteSpecificNode(int val){
			if(head == NULL){
				cout <<"underflow."<< endl;
				return;
			}
			else{
				Node* temp = head;
				Node* pre = NULL;
				while(temp!= NULL && temp->data != val){
					pre = temp;
					temp = temp->next;
				}
				if(temp == NULL){
					cout <<"element not found."<< endl;
					return;
				}
				if(temp == head){
					head = head->next;
				}
				else if(temp->next == NULL){
					pre->next == NULL;
				}
				else{
					pre->next = temp->next;
				}
				
				delete temp;
			}
		}
		bool search(int key){
			if(head == NULL){
				cout << "List is empty." << endl;
				return false;
			}
			Node* temp = head;
			int count = 0;
			while(temp != NULL){
				count++;
				if(temp->data == key){
					cout <<"key found at "<< count << endl;
					return true;
				}
				temp = temp->next;
			}
			return false;
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
int main(){
	List l1;
	l1.insertBegin(1);
	l1.insertBegin(2);
	l1.insertEnd(3);
	l1.insertEnd(4);

	l1.insertAfterVal(2,5);
	l1.insertAfterPosition(3,6);
    l1.search(3);
    cout << endl;
    l1.display();
    cout << endl;
    l1.deleteBegin();
    l1.deleteEnd();
    l1.deleteSpecificNode(6);
    cout << "After deletions : "<< endl;
    l1.display();
    
	return 0;
}


