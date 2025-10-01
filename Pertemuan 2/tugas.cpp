#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;

void push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << "Push: " << value << endl;
}

void pop() {
    if (top == nullptr) {
        cout << "Stack kosong!" << endl;
        return;
    }
    Node* temp = top;
    cout << "Pop: " << top->data << endl;
    top = top->next;
    delete temp;
}

void display() {
    Node* current = top;
    cout << "Isi stack: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    
    push(10);
    push(20);
    push(30);

    display();

    pop();

    display();

    return 0;
}