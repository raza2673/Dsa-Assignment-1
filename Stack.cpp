#include <iostream>
using namespace std;

#define SIZE 5

class Stack
{
private:
    int arr[SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isFull()
    {
        return (top == SIZE - 1);
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    void push(int x)
    {
        if (isFull())
            cout << "Stack is Full\n";
        else
        {
            top++;
            arr[top] = x;
            cout << x << " pushed\n";
        }
    }

    void pop()
    {
        if (isEmpty())
            cout << "Stack is Empty\n";
        else
        {
            cout << arr[top] << " popped\n";
            top--;
        }
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.pop();
    s.pop();

    return 0;
}