#include <bits/stdc++.h>

using namespace std;
//Similarly we can do for Linked List implementation but for it we have to use O(N) complexity to set the rear pointer at the end
struct MyQueue  {
    int size, cap;
    int *arr;
    int front, rear;
    MyQueue (int x) {
        cap = x;
        arr = new int[cap];
        front = -1;
        rear = -1;
        size = 0;  // Initialize size to 0
    }
    bool isFull() {
        return (size == cap);
    }
    bool isEmpty() {
        return (size == 0);
    }
    void enqueue(int x) {
        if (isFull()) {
            cout << "queue already full" << endl;
        } else {
            if (front == -1) {
                front++;
            }
            rear++;
            arr[rear] = x;
            size++;
        }
    }
    void deque() {
        if (isEmpty()) {
            cout << "queue already empty" << endl;
        } else {
            int x = arr[front];
            front++;
            size--; // Decrement size
            cout << x << " has been taken out of queue" << endl;
        }
    }
    int first() {
        if (!isEmpty()) {
            return arr[front];
        }
    }
    int back() {
        if (!isEmpty()) {
            return arr[rear];
        }
    }
    int sz() {
        return size;
    }
};

int main() {
    // Implement a queue using array
    MyQueue  q(5);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(7);
    q.deque();
    q.enqueue(8); // 4 7 8
    while (!q.isEmpty()) {
        cout << q.first() << " ";
        q.deque();
    }
    return 0;
}
