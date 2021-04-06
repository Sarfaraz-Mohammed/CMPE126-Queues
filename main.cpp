//============================================================================
// Name        : LAB7-CMPE126-main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "arrayQueue.h"
using namespace std;

int main() {


	try{

		arrayQueue<int> q;

		q.enqueue(23);
		q.enqueue(7);
		q.enqueue(34);
		q.dequeue();
		q.enqueue(55);
		q.enqueue(4);
		q.enqueue(11);
		q.dequeue();
		q.dequeue();
		q.enqueue(90);
		q.enqueue(83);
		q.enqueue(63);
		q.dequeue();
		q.dequeue();

		cout << "Queue: ";
		while(!q.isEmpty())
		{
			cout << q.front() << " ";
			q.dequeue();

		}
		cout << endl;

	}catch(const char* e){
		cout << e << endl;
	}


	return 0;
}
