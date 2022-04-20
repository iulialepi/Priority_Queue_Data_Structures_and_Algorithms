#pragma once
#include <vector>
#include <utility>

using namespace std;

//DO NOT CHANGE THIS PART
typedef int TElem;
typedef int TPriority;
typedef std::pair<TElem, TPriority> Element;
typedef bool (*Relation)(TPriority p1, TPriority p2);
#define NULL_TELEM pair<TElem, TPriority> (-11111,-11111);
struct Node{
	Node* next;
	pair<TElem, TPriority> value;
};

class PriorityQueue {
private:
	//TODO - Representation
	Node* head;
	Relation relation;

public:
	//implicit constructor
	PriorityQueue(Relation r);

	//Fuer den Testen, so dass ich sehen kann was zwischendurch passiert
	void print();

	//pushes an element with priority to the queue
	void push(TElem e, TPriority p);

	//returns the element with the highest priority with respect to the order relation
	//throws exception if the queue is empty
	Element top()  const;

	//removes and returns the element with the highest priority
	//throws exception if the queue is empty
	Element pop();

	//checks if the queue is empty
	bool isEmpty() const;

	//destructor
	~PriorityQueue();

};