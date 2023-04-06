#include <iostream>
#include <chrono>

using namespace std;

// Node class for linked list
class Node {
public:
    int data; // Data of the node
    Node* next; // Pointer to the next node

    // Constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Stack class using linked list
class StackLinkedList {
private:
    Node* top; // Pointer to the top of the stack

public:
    StackLinkedList() {
        top = nullptr; // Initialize top to nullptr to indicate an empty stack
    }

    // Function to check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Function to pop the top element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }


    // Function to display the elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Linked List Stack: ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
// Create stack using linked list
StackLinkedList stackLinkedList;

auto start_time = chrono::high_resolution_clock::now();

// Push elements onto the linked list stack
stackLinkedList.push(8);
stackLinkedList.push(10);
stackLinkedList.push(5);
stackLinkedList.push(11);
stackLinkedList.push(15);
stackLinkedList.push(23);
stackLinkedList.push(6);
stackLinkedList.push(18);
stackLinkedList.push(20);
stackLinkedList.push(17);

// Display linked list stack
stackLinkedList.display();

// Pop elements from the linked list stack
stackLinkedList.pop();
stackLinkedList.pop();
stackLinkedList.pop();
stackLinkedList.pop();
stackLinkedList.pop();

// Display linked list stack
stackLinkedList.display();

// Push elements onto the linked list stack
stackLinkedList.push(4);
stackLinkedList.push(30);
stackLinkedList.push(3);
stackLinkedList.push(1);

stackLinkedList.display();

auto end_time = chrono::high_resolution_clock::now();
auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
cout << "Execution time for Linked List Stack: " << duration.count() << "ms" << endl;
return 0;
}