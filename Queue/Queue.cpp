#include <bits/stdc++.h>
#include "./include/Queue.hpp"

using namespace std;

int main()
{
    Queue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;
    cout << "Size of queue: " << q.size() << endl;

    cout << "Dequeued element: " << q.dequeue() << endl;

    cout << "Front element after dequeue: " << q.getFront() << endl;
    cout << "Rear element after dequeue: " << q.getRear() << endl;
    cout << "Size of queue after dequeue: " << q.size() << endl;

    q.dequeue();
    q.dequeue();

    cout << "Dequeuing from empty queue: " << q.dequeue() << endl;

    if (q.isEmpty())
    {
        cout << "Queue is empty now." << endl;
    }
    else
    {
        cout << "Queue is not empty." << endl;
    }

    return 0;
}
