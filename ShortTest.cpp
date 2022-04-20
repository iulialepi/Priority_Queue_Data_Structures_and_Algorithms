#include "PriorityQueue.h"
#include "ShortTest.h"
#include <assert.h>
#include <iostream>
using namespace std;

bool rel(TPriority p1, TPriority p2) {
	if (p1 <= p2) {
		return true;
	}
	else {
		return false;
	}
}




void testAll() { //call each function and see if it exists
	PriorityQueue pq(rel);
	
	assert(pq.isEmpty() == true);
	
	//adaugam 5, 3, 10, 2, 12 -> rezultat: 2, 3, 5, 10, 12
	pq.push(5, 5);
	assert(pq.top().first == 5);
	assert(pq.top().second == 5);

	cout << pq.top().first << "\n";

	pq.push(3, 3);
	
	assert(pq.top().first == 3);
	assert(pq.top().second == 3);

	cout << pq.top().first << "\n";
	
	pq.push(10, 10);
	cout << pq.top().first << "\n";

	assert(pq.top().first == 3);
	assert(pq.top().second == 3);

	pq.push(2, 2);
	assert(pq.top().first == 2);
	assert(pq.top().second == 2);

	cout << pq.top().first << "\n";

	pq.push(12, 12);
	assert(pq.top().first == 2);
	assert(pq.top().second == 2);

	cout << pq.top().first << "\n add ok; pop: \n";

	assert(pq.isEmpty() == false);

	pq.print();


	assert(pq.pop().second == 2);
	cout << pq.top().first << "\n";
	assert(pq.top().second == 3);
	assert(pq.pop().second == 3);
	cout << pq.top().first << "\n";
	assert(pq.top().second == 5);
	
	pq.print();

	assert(pq.pop().second == 5);
	pq.print();
	
	assert(pq.top().second == 10);
	assert(pq.pop().second == 10);
	pq.print();
	assert(pq.top().second == 12);
	assert(pq.pop().second == 12);
	pq.print();
	
	assert(pq.isEmpty() == true);
}

