#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next = nullptr;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue
{

private:
    Node *front;
    Node *rear;
    int count;

public:
    Queue()
    {
        this->front = nullptr;
        this->rear = nullptr;
        this->count = 0;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    int size()
    {
        return this->count;
    }

    int getFront()
    {
        if (this->isEmpty())
        {
            return -1;
        }
        return this->front->data;
    }
    int getRear()
    {
        if (this->isEmpty())
        {
            return -1;
        }
        return this->rear->data;
    }
    void enqueue(int data)
    {
        Node *curr = new Node(data);

        if (this->isEmpty())
        {
            front = rear = curr;
        }
        else
        {
            rear->next = curr;
            rear = curr;
        }
        count++;
    }

    int dequeue()
    {
        if (this->isEmpty())
        {
            cout << "\nQueue is empty\n";
            return INT_MIN;
        }

        int deleteItem = front->data;
        Node *temp = front;
        front = front->next;
        delete temp;

        count--;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        return deleteItem;
    }
};