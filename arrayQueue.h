/*
 * arrayQueue.h
 *
 *  Created on: Mar 19, 2019
 *      Author: smohammed730
 */

#ifndef ARRAYQUEUE_H_
#define ARRAYQUEUE_H_

template <class T>
class arrayQueue{
private:
	int maxSize;
	int size;
	int qFront; //points to the element at the front of the queue
	int qRear; //points to the element at the rear of the queue
	T *queue;


public:
	arrayQueue(int qSize = 100);
	bool isEmpty() const;
	bool isFull() const;
	T front() const;
	void enqueue(const T& qElem);
	void dequeue();
	~arrayQueue();
};

#endif /* ARRAYQUEUE_H_ */

//constructor
template <class T>
arrayQueue<T>::arrayQueue(int qSize)
{
	if(qSize <= 0)
	{
		throw "Array must be greater than zero. Creating an array of size 100.";
		maxSize = 100;
	}else
	{
		maxSize = qSize;
		qFront = 0;
		qRear = maxSize - 1;
		size = 0;
		queue = new T[maxSize];
	}
}

//is Empty
template <class T>
bool arrayQueue<T>::isEmpty() const
{
	return(size == 0);
}

//is Full
template <class T>
bool arrayQueue<T>::isFull() const
{
	return (size == maxSize);
}

// front
template <class T>
T arrayQueue<T>::front() const
{
	if(!isEmpty())
	{
		return queue[qFront];
	}else
	{
		throw "Queue is empty! Try adding some elements!";
	}
}

//enqueue
template <class T>
void arrayQueue<T>::enqueue(const T& qElem)
{
	if(isEmpty())
	{
		qRear = (qRear + 1) % maxSize;
		size++;
		queue[qRear] = qElem;
	}else if(isFull())
	{
		int* R = new int[2 * maxSize];
		for(int i = qFront; i < qRear; i++)
		{
			R[i - qFront] = queue[i % maxSize];

		}
		delete[] queue;
		queue = R;

		qRear = (qRear + 1) % maxSize;
		size++;
		queue[qRear] = qElem;
	}else
	{
		qRear = (qRear + 1) % maxSize;
		size++;
		queue[qRear] = qElem;
	}
}

//dequeue
template <class T>
void arrayQueue<T>::dequeue()
{
	if(!isEmpty())
	{
		size--;
		qFront = (qFront + 1) % maxSize;
	}else
	{
		throw "Queue is empty! Elements cannot be removed!";
	}
}

//destructor
template <class T>
arrayQueue<T>::~arrayQueue()
{
	delete[] queue;
}




