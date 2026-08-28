

// queue implemtation with simple array.

#include<iostream>
using namespace std;

const int SIZE = 6;

class queue {
public:
	int arr[SIZE];
	int front, rear;
	int count;

	queue() {
		front = 0;
		rear = 0;
		count = 0;
	}

	void push(int x) {
		if (!full()) {
			arr[rear] = x;
			rear++;
			count++;
		}
		else {
			cout << "queue is full" << endl;
		}
	}

	int pop() {
		if (!empty()) {
			int element = arr[front];
			front++;
			count--;
			return element;
		}
		else {
			cout << "queue is empty" << endl;
			return -1;
		}
	}

	int getfront() {
		if (!empty())
			return arr[front];
		else {
			cout << "queue is empty" << endl;
			return -1;
		}
	}

	int back() {
		if (!empty())
			return arr[rear - 1];
		else {
			cout << "queue is empty" << endl;
			return -1;
		}
	}

	int size() {
		return count;
	}

	bool empty() {
		return count == 0;
	}

	bool full() {
		return count == SIZE;
	}

	queue& operator=(const queue& q) {
		front = q.front;
		rear = q.rear;
		count = q.count;
		for (int i = front; i < rear; i++) {
			arr[i] = q.arr[i];
		}
		return *this;
	}

	void display() {
		for (int i = front; i < rear; i++) {
			cout << arr[i] << "\t";
		}
		cout << endl;
	}
};

int main() {
	queue q1;
	queue q2;

	q1.push(32);
	q1.push(85);
	q1.push(2);
	q1.push(96);
	q1.push(75);
	q1.push(5);

	q2 = q1;

	cout << "Queue 1 is  " << endl;
	q1.display();

	cout << "Queue 2 is  " << endl;
	q2.display();

	cout << "Size of queue 1 is " << q1.size() << endl;
	cout << "Size of queue 2 is " << q2.size() << endl;
	cout << "first element of queue 1 is " << q1.getfront() << endl;
	cout << "first element of queue 2 is " << q2.getfront() << endl;
	cout << "Last element of queue 1: " << q1.back() << endl;
	cout << "Last element of queue 2: " << q2.back() << endl;

	cout << "Queue 1 is " << (q1.empty() ? "empty" : "not empty") << endl;
	cout << "Queue 2 is " << (q2.empty() ? "empty" : "not empty") << endl;

	cout << "Queue 1 is " << (q1.full() ? "full" : "not full") << endl;
	cout << "Queue 2 is " << (q2.full() ? "full" : "not full") << endl;

	return 0;
}
