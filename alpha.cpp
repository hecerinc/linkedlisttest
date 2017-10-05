#include <iostream>
#include "LinkedList.h"
using namespace std;
int main(){
	LinkedList<int> a;
	cout << a.length << endl;
	a.push_back(10);
	cout << a.length << endl;
}
