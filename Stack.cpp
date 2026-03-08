#include <iostream>
#include <stack>
#include <cctype>
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

// Function to convert Infix to Postfix
string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";

    for (char c : infix)
    {
        if (isalpha(c))
            postfix += c;

        else if (c == '(')
            s.push(c);

        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }

        else
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(string exp)
{
    stack<int> s;

    for (char c : exp)
    {
        if (isdigit(c))
            s.push(c - '0');

        else
        {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();

            switch (c)
            {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }

    return s.top();
}

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.pop();
    s.pop();

    string infixExp = "(A+B)*(C-D)+E";
    cout << "Postfix: " << infixToPostfix(infixExp) << endl;

    string postfixExp = "523*+9-";
    cout << "Result: " << evaluatePostfix(postfixExp) << endl;

    return 0;
}
