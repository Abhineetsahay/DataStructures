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
class Stack
{
private:
    Node *head;
    int count;

public:
    Stack()
    {
        this->head = nullptr;
        this->count=0;
    }
    const bool isEmpty()
    {
        return this->head == nullptr;
    }
    void push(int data)
    {
        Node *newNode = new Node(data);
        if (!newNode)
        {
            cout << "Overflow...";
            return;
        }
        count++;
        newNode->next = head;
        head = newNode;
    }
    const int top()
    {
        if (this->isEmpty())
        {
            cout << "\nStack is empty";
            return INT_MIN;
        }

        return head->data;
    }
    const int size()
    {
        return this->count;
    }
    int pop()
    {
        if (this->isEmpty())
        {

            cout << "\nStack is empty";
            return INT_MIN;
        }
        int tp = this->top();
        Node *temp = head;
        head = head->next;
        count--;
        delete temp;

        return tp;
    }
};
