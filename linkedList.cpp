#include<iostream>
using namespace std;

class Node {
public:
	int value;
	Node* next;
};
void printLinkedList(Node* node)
{
	while (node != NULL)
	{
		cout << node->value << endl;
		node = node->next;
	}
}
void addNode(Node* &head,Node*& tail, int val)
{
	
	if (head == nullptr && tail==nullptr)
	{
		Node* node = new Node();
		node->value = val;
		node->next = nullptr;
		head = node;
		tail = node;
	}
	else
	{
		Node* node = new Node();
		node->value = val;
		node->next = nullptr;
		tail->next = node;
		tail = node;
	}
	
}
void insertNodeAtHead(Node* &head,int value) {
	
	Node* newNode = new Node();
	newNode->value = value;
	newNode->next = head;
	head = newNode;

}

void insertNodeAfter(Node* current, int targetValue, int newValue) {
	
	while (current != nullptr && current->value != targetValue) {
		current = current->next;
	}

	if (current != nullptr) {
		Node* newNode = new Node();
		newNode->value = newValue;
		newNode->next = current->next;
		current->next = newNode;
	}
	else {
		cout << "Node with value " << targetValue << " not found." << endl;
	}
}

void deleteNode(Node*& head, int key) {
	Node* temp = head;
	Node* prev = nullptr;

	if (temp != nullptr && temp->value == key) {
		head = temp->next;  
		delete temp;        
		return;
	}
	while (temp != nullptr && temp->value != key) {
		prev = temp;
		temp = temp->next;
	}
	if (temp == nullptr) return;

	prev->next = temp->next;

	delete temp;
}


int main() {

	
	Node* head=nullptr;
	Node* tail = nullptr;
   
	addNode(head, tail, 1);
	addNode(head, tail, 2);
	addNode(head, tail, 3);
	addNode(head, tail, 4);
	insertNodeAtHead(head, 5);
	insertNodeAtHead(head, 6);

	insertNodeAfter(head, 3, 100);

	printLinkedList(head);

	deleteNode(head, 3);
	printLinkedList(head);



}