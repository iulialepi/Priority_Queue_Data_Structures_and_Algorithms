
#include "PriorityQueue.h"
#include <exception>
#include <iostream>
using namespace std;


PriorityQueue::PriorityQueue(Relation r) {
	this->head = nullptr;
	this->relation = r;
}

//Komplexitaet: Best: Theta(1); Worst:Theta(n); Avg:O(n)
void PriorityQueue::push(TElem e, TPriority p) {

	//1ten Fall: die Liste ist leer, also wir fuegen e auf die erste Position hinzu
	//Komplexitaet: Theta(1) - weil es keine Schleifen gibt
	//(V4 - SLL -  am Anfang einfuegen)

	if (this->head == nullptr) {

		Node* newNode = new Node;
		newNode->value.first = e;    
		newNode->value.second = p;
		newNode->next = nullptr;

		this->head = newNode;
	}
	else {
		//2ten Fall: man fuegt e am Anfang hinzu, weil es das kleinste Element ist
		//Komplexitaet: Theta(1) 
		if (relation(p, this->head->value.second) == true) {      //if p <= head.second  

			Node* newNode = new Node;
			newNode->value.first = e;
			newNode->value.second = p;
			newNode->next = this->head;             //nachdem wir die Kopie gemacht haben geben wir dem next pointer die Adressede von head

			this->head = newNode;                   //der neue Wert wird den head
		}
		else {
			//3ten Fall: man fuegt in der Mitte oder am ende an
			//Komplexitaet: worst:Theta(n), avg O(n)
			Node* copyHead = new Node;
			Node* copyHead2 = new Node;
			copyHead = this->head;

			while (relation(copyHead->value.second, p) == true && copyHead->next != nullptr) {
				//wir behalten diese fuer den Fall wo p negativ ist also wir bleiben auf den wert bevor das neue element
				copyHead2 = copyHead;          
				copyHead = copyHead->next;
			}
			Node* newNode = new Node;                       //wir kennen jetzt die Position wo wir den neuen Wert einfuegen sollen
			newNode->value.first = e;
			newNode->value.second = p;
			if (p >= 0) {
				copyHead->next = newNode;
				newNode->next = nullptr;
			}
			if (p < 0) {                                    //weil das von oben bei negativen Zahlen nicht geht
				newNode->next = copyHead;
				copyHead2->next = newNode;
			}
		}
	}
}

//throws exception if the queue is empty
//Komplexitaet: Theta(1)
Element PriorityQueue::top() const {
	exception except;

	if (isEmpty() == true) {
		throw except;
	}else {
		return this->head->value;
	}
	return NULL_TELEM;
}

//Komplexitaet: Theta(1)
Element PriorityQueue::pop() {
	exception except;
	if (isEmpty() == true) {
		throw except;
	}
	else {
		Node* deletedNode = new Node;
		deletedNode = this->head;
		this->head = this->head->next;
		return deletedNode->value;
	}
	return NULL_TELEM;
}

//Komplexitaet: Theta(1)
bool PriorityQueue::isEmpty() const {
	if (this->head == nullptr) {
		return true;
	}
	return false;
}

//Komplexitaet: Theta(1)
PriorityQueue::~PriorityQueue() {
	this->head = nullptr;
};

//Komplexitaet: Best: Theta(1); Worst:Theta(n); Avg:O(n)
void PriorityQueue::print() {
	Node* copyNode = new Node;
	copyNode = this->head;

	std::cout << "Elements & Priority: \n";
	
	while (copyNode!= nullptr) {
		std::cout << copyNode->value.first << ", " << copyNode->value.second << "; \n";
		copyNode = copyNode->next;
	}

	cout << "\n";

}


