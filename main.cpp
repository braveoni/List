#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


class Node {
public:

    Node(Node* prev, Node* next, int data) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

    void set_prev(Node* node) {
        this->prev = node;
    }

    void set_next(Node* node) {
        this->next = node;
    }

    Node* get_prev() {
        return this->prev;
    }

    Node* get_next() {
        return this->next;
    }

    int get_data() {
        return this->data;
    }

    bool remove() {
        assert(this->prev != nullptr);
        this->prev->next = this->next;
        this->next->prev = this->prev;
        delete(this);
        return true;
    }

private:
    Node* prev;
    Node* next;
    int data;
};

class List {
public:
    List() {
        this->head = new Node(nullptr, nullptr, 10);
        this->tail = this->head;
    }

    void remove(int index) {
        Node* p = head;

        while (index--) {
            p = p->get_next();
        }

        p->remove();
    }

    void insert_head(int data) {
        Node* p = new Node(nullptr, head, data);
        this->head->set_prev(p);
        this->head = p;
    }

    void insert_tail(int data) {
        Node* p = new Node(tail, nullptr, data);
        this->tail->set_next(p);
        this->tail = p;
    }

    void find(int data) {
        int i = 0;
        Node* p = head;
        while (p->get_data() != data) {
            p = p->get_next();
            i++;
        }

        cout << "Index: " << p << endl;
    }

    void print() {
        Node* p = head;
        do {
            cout << p->get_data() << ' ';
            p = p->get_next();
        } while (p != nullptr);
    }

private:
    Node* head;
    Node* tail;
};


int main() {
    List list = *new List();
    list.insert_head(12);
    list.insert_tail(9);
    list.print();
}
