#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "LinkedList.h"
#include <iostream>
using namespace std;

// [] operator get
// push_back
// push
// int first
// int size
// void empty
// bool isEmpty
// FrontBackSplit
// insertAtIndex
// int pop()

// bool isEmpty()
TEST_CASE("isEmpty operation correctly returns whether a list is empty", "[LinkedList]"){
	LinkedList<int> a;
	REQUIRE(a.isEmpty());
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	REQUIRE_FALSE(a.isEmpty());
}

// [] operator
TEST_CASE("[] operator returns the correct value for position i", "[LinkedList]") {
	LinkedList<int> a;
	CHECK_THROWS(a[0]);
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	REQUIRE_THROWS(a[-1]);
	REQUIRE(a[2]== 30);
	REQUIRE(a[1] == 20);
	REQUIRE(a[0] == 10);
}

// void push_back(int)
TEST_CASE("push_back() correctly appends to the end of the list", "[LinkedList]") {
	LinkedList<int> a;
	REQUIRE(a.head == NULL);
	a.push_back(10);
	REQUIRE(a.length == 1);
	REQUIRE(a.head != NULL);
	REQUIRE(a[0] == 10);
	a.push_back(20);
	REQUIRE(a[1] == 20);
	a.push_back(30);
	REQUIRE(a[2] == 30);
	a.push_back(40);
	REQUIRE(a[3] == 40);
	REQUIRE(a.size() == 4);
	a.push_back(50);
	a.push_back(60);
	a.push_back(70);
	a.push_back(80);
	REQUIRE(a.size() == 8);
}

// void push(int)
TEST_CASE("push() correctly adds to the beginning of the list", "[LinkedList]") {
	LinkedList<int> a;
	a.push(10);
	REQUIRE(a.first() == 10);
	a.push(20);
	REQUIRE(a.first() == 20);
	a.push(30);
	REQUIRE(a.head->data == 30);
	REQUIRE(a.size() == 3);
}

// int first()
TEST_CASE("first() returns the first element of the list", "[LinkedList]") {
	LinkedList<int> a;
	REQUIRE(a.head == NULL);
	a.push_back(10);
	REQUIRE(a.head->data == a.first());	
	a.push_back(20);
	REQUIRE(a.head->data == a.first());	
}

// int size()
TEST_CASE("size() returns the correct size of the list", "[LinkedList]") {
	LinkedList<int> a;
	REQUIRE(a.size() == 0);
	a.push_back(10);
	REQUIRE(a.size() == 1);
	a.push_back(10);
	a.push_back(10);
	a.push_back(10);
	a.push_back(10);
	a.push_back(10);
	a.push_back(10);
	a.push_back(10);
	REQUIRE(a.size() == 8);
	a.pop();
	REQUIRE(a.size() == 7);
	a.push(10);
	REQUIRE(a.size() == 8);
	a.push(9);
	REQUIRE(a.size() == 9);
	a.empty();
	REQUIRE(a.size() == 0);
}

// void empty()
TEST_CASE("empty() correctly destroys the list and sets head to NULL", "[LinkedList]") {
	LinkedList<int> a;
	a.push_back(10);	
	a.push_back(20);	
	a.push_back(30);	
	REQUIRE(a.head != NULL);
	REQUIRE(a.size() != 0);
	a.empty();
	REQUIRE(a.size() == 0);
	REQUIRE(a.head == NULL);
}


// FrontBackSplit()
TEST_CASE("FrontBackSplit() correctly returns the two halves", "[LinkedList]") {
	LinkedList<int> a;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	a.push_back(40);
	// General test case for even-numbered lists
	Node<int> *x = new Node<int>();
	Node<int> *y = new Node<int>();
	a.frontBackSplit(&x, &y);
	REQUIRE(x->data == 10);
	REQUIRE(x->next->data == 20);
	REQUIRE(x->next->next == NULL);
	REQUIRE(y->data == 30);
	REQUIRE(y->next->data == 40);
	REQUIRE(y->next->next == NULL);

	// Case for length() == 1
	// cout << "FBSplit: Handle the case when length is 1 (both should point to the head)." << endl;
	a.empty();
	a.push_back(10);
	a.frontBackSplit(&x, &y);
	
	REQUIRE(x->data == 10);
	REQUIRE(x == y);
	REQUIRE(y->data == 10);
	REQUIRE(x->next == NULL);
	REQUIRE(y->next == NULL);

	// Clean up
	delete x;
	delete y;
	x = NULL;
	y = NULL;

}
TEST_CASE("FrontBackSplit(): in odd-numbered lists the extra element is in the front list", "[LinkedList]") {
	LinkedList<int> a;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	Node<int> * x = new Node<int>();
	Node<int> * y = new Node<int>();

	a.frontBackSplit(&x, &y);
	REQUIRE(x->data == 10);
	REQUIRE(x->next->data == 20);
	REQUIRE(y->data == 30);
	REQUIRE(y->next == NULL);

}

void insertAtIndex(int, int)
TEST_CASE("insertAtIndex(i) correctly inserts a new item at position i \n(provided i is in the range [0, length])", "[LinkedList]") {
	LinkedList<int> a;
	a.push_back(10);
	a.insertAtIndex(1, 20);
	REQUIRE(a.size() == 2);
	REQUIRE(a[1] == 20);
	a.insertAtIndex(1, 15);
	REQUIRE(a.size() == 3);
	REQUIRE(a[1] == 15);
	a.insertAtIndex(0, 200);
	REQUIRE(a[0] == 200);
	REQUIRE(a.first() == 200);
}

// int pop()
TEST_CASE("pop() correctly returns the first element", "[LinkedList]") {
	LinkedList<int> x;
	x.push_back(1);
	x.push_back(2);
	x.push_back(3);
	int a = x.pop();
	int b = x.pop();
	int c = x.pop();
	REQUIRE(a == 1);
	REQUIRE(b == 2);
	REQUIRE(c == 3);
	REQUIRE(x.size() == 0);
	REQUIRE(x.isEmpty());
}

TEST_CASE("pop() correctly removes the first element from the list", "[LinkedList]") {
	LinkedList<int> x;
	x.push_back(10);
	x.push(20);
	x.pop();
	REQUIRE(x.size() == 1);
	REQUIRE(x.first() == 10);
}

