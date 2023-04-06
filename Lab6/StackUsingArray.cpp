#include <iostream>
#include <chrono>
using namespace std;

// Stack class using array
class StackArray {
private:
    static const int MAX_SIZE = 100; // Maximum size of the stack
    int arr[MAX_SIZE]; // Array to store stack elements
    int top; // Index of the top of the stack

public:
    StackArray() {
        top = -1; // Initialize top to -1 to indicate an empty stack
    }

    // Function to check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to check if stack is full
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = value;
    }

    // Function to pop the top element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }

    // Function to display the elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Array Stack: ";
        for (int i = top; i >= 0; i--) {
           cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
// Create stack using array
StackArray stackArray;

auto start_time = chrono::high_resolution_clock::now();

// Push elements onto the array stack
stackArray.push(8);
stackArray.push(10);
stackArray.push(5);
stackArray.push(11);
stackArray.push(15);
stackArray.push(23);
stackArray.push(6);
stackArray.push(18);
stackArray.push(20);
stackArray.push(17);

// Display array stack
stackArray.display();

// Pop elements from the array stack
stackArray.pop();
stackArray.pop();
stackArray.pop();
stackArray.pop();
stackArray.pop();

// Display array stack
stackArray.display();

// Push elements onto the array stack
stackArray.push(4);
stackArray.push(30);
stackArray.push(3);
stackArray.push(1);

stackArray.display();

auto end_time = chrono::high_resolution_clock::now();
auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
cout << "Execution time for Array Stack: " << duration.count() << "ms" << endl;

return 0;
}