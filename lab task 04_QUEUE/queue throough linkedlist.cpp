#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* link;
};

class queue {
private:
    int count;
    node* front;
    node* rear;

public:
    queue() {
        count = 0;
        front = NULL;
        rear = NULL;
    }

    void push(int x) {
        count++;
        node* temp = new node;
        temp->data = x;
        temp->link = NULL;
        if (front == NULL) {
            front = temp;
            rear = temp;
        }
        else {
            rear->link = temp;
            rear = temp;
        }
    }

    int pop() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return -1;
        }


        else if (front->link == NULL) {
            node* temp = front;
            int el = front->data;
            front = front->link;
            delete temp;
            count--;
            return el;
        }
        else {
            node* temp = front;
            int el = front->data;
            front = front->link;
            delete temp;
            count--;
            return el;
        }
    }

    bool empty() {
        return count == 0;
    }

    int size() {
        return count;
    }
    queue& operator=(queue& q1) {
        node* temp;
        temp = q1.front;
        while (temp != NULL) {
            this->push(temp->data);
            temp = temp->link;
        }
        return *this;
    }

    int frontelement() {
        if (front != NULL)
            return front->data;
        else {
            cout << "Queue is empty" << endl;
            return -1;
        }
    }

    int back() {
        if (rear!= NULL)
            return rear->data;
        else {
            cout << "Queue is empty" << endl;
            return -1;
        }
    }
    void display() {
        node*temp = front;
        while (temp != NULL) {
            cout << temp->data << "\t";
            temp = temp->link;
        }
    }
};

int main() {
    queue q1;
    queue q2;
    q1.push(23);
    q1.push(45);
    q1.push(97);
    q1.push(4);
    q1.push(67);
    q1.display();
    cout << endl;
    q2 = q1;
    q2.display();
    cout << "front of q1 is : " << q1.frontelement() << endl;
    cout << "back of q1 is : " << q1.back() << endl;
    cout << "size of q1 is: " << q1.size() << endl;
    cout <<"popped element of q1 is "<< q1.pop() << endl;

    cout << "front of q2 is: " << q2.frontelement() << endl;
    cout << "back of q2 is " << q2.back() << endl;
    cout << "size of q2 is " << q2.size() << endl;
    cout << "popped element pf q2 is " << q2.pop() << endl;


}
