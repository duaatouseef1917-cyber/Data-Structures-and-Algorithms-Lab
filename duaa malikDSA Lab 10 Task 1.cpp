#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front, rear, size;

public:
    CircularQueue(int s) {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Check if queue is full
    bool isFull() {
        return (front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1));
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Enqueue
    void enQueue(int value) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }

        // First element
        if (front == -1) {
            front = rear = 0;
        }
        // Circular condition
        else if (rear == size - 1 && front != 0) {
            rear = 0;
        }
        else {
            rear++;
        }

        arr[rear] = value;
        cout << value << " inserted\n";
    }

    // Dequeue
    void deQueue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << arr[front] << " removed\n";

        // Only one element
        if (front == rear) {
            front = rear = -1;
        }
        else if (front == size - 1) {
            front = 0;
        }
        else {
            front++;
        }
    }

    // Display
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
        } else {
            for (int i = front; i < size; i++)
                cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);
    
    cout << "---Enqueue Operations:\n";
    cout <<"Initially ";
    q.display();
    q.enQueue(10);
    q.display();
    q.enQueue(20);
    q.display();
    q.enQueue(30);

    q.display();

    cout << "---Dequeue Operation:\n";
    q.deQueue();

    q.display();

    cout << "---Enqueue Operations:\n";
    q.enQueue(40);
    q.display();
    q.enQueue(50);
    q.display();
    q.enQueue(60);

    q.display();

    return 0;
}