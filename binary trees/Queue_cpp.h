#ifndef QUEUE_CPP_H_INCLUDED
#define QUEUE_CPP_H_INCLUDED
#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
};
class Queue
{
    int front;
    int rear;
    int size;
    Node **Q;
public:
    Queue()
    {
        front=rear=-1;
        size=10;
        Q=new Node*[size];
    }
    Queue(int size)
    {
        front=rear=-1;
        this->size=size;
        Q=new Node*[size];
    }
    void enqueue(Node *x);
    Node * dequeue();
    void display();
    int isEmpty()
    {
        return rear==front;
    }
};
void Queue::enqueue(Node *x)
{
    if(rear==size-1)
        cout<<"queue is full\n";
    else
    {
        rear++;
        Q[rear]=x;
    }
}
Node * Queue::dequeue()
{
    Node *x=NULL;
    if(front==rear)
        cout<<"queue is empty\n";
    else
    {
        x=Q[front+1];
        front++;
    }
    return x;
}
void Queue::display()
{
    for(int i=front+1;i<=rear;i++)
        cout<<Q[i]<<" ";
    cout<<endl;
}
class mstack
{
    int size;
    int top;
    Node **Q;
public:
    mstack(){size=10;top=-1;Q=new Node*[size];}
    mstack(int size)
    {
        this->size=size;
        top=-1;
        Q=new Node*[this->size];
    }
    void push(Node *x);
    void display();
    int isEmpty(){return top==-1;}
    Node * pop();
};

void mstack::push(Node *x)
{
    if(top==size-1)
        cout<<"stack is full\n";
    else
    {
        top++;
        Q[top]=x;
    }
}
Node * mstack::pop()
{
    Node *x=NULL;
    if(top==-1)
        cout<<"stack is empty\n";
    else
    {
        x=Q[top];
        top--;
    }
    return x;
}
void mstack::display()
{
    for(int i=0;i<=top;i++)
        cout<<Q[i]<<" ";
    cout<<endl;
}
#endif // QUEUE_CPP_H_INCLUDED
