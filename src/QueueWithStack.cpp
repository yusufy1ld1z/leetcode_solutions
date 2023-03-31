#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
public:
    MyQueue();
    void push(int);
    int pop();
    int peek();
    bool empty();
    void printArray();

private:
    stack<int> myStack;
};

MyQueue::MyQueue()
{
    stack<int> myStack;
}

void MyQueue::push(int x)
{
    myStack.push(x);
}

int MyQueue::pop()
{
    int ret;
    stack<int> tempQueue;
    while (!myStack.empty())
    {
        if (myStack.size() == 1)
            ret = myStack.top();

        tempQueue.push(myStack.top());
        myStack.pop();
    }

    tempQueue.pop();

    while (!tempQueue.empty())
    {
        myStack.push(tempQueue.top());
        tempQueue.pop();
    }

    return ret;
}

int MyQueue::peek()
{
    int ret;
    stack<int> tempQueue;
    while (!myStack.empty())
    {
        if (myStack.size() == 1)
            ret = myStack.top();

        tempQueue.push(myStack.top());
        myStack.pop();
    }
    while (!tempQueue.empty())
    {
        myStack.push(tempQueue.top());
        tempQueue.pop();
    }

    return ret;
}

bool MyQueue::empty()
{
    return myStack.empty();
}

void MyQueue::printArray()
{
    stack<int> temp;
    int res;
    while (!myStack.empty())
    {
        temp.push(myStack.top());
        cout << myStack.top() << " "; // print in reverse order
        myStack.pop();
    }

    while (!temp.empty())
    {
        myStack.push(temp.top());
        temp.pop();
    }
}

int main()
{
    MyQueue *obj = new MyQueue();
    obj->push(31);
    obj->printArray();
    cout << endl;
    obj->push(69);
    obj->printArray();
    cout << endl;
    obj->peek();
    obj->printArray();
    cout << endl;
    obj->pop();
    obj->printArray();
    cout << endl;
    obj->empty();
}