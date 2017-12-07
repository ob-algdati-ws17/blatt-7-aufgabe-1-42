#ifndef BLATT_7_AUFGABE_1_42_LIBRARY_H
#define BLATT_7_AUFGABE_1_42_LIBRARY_H

#include <ostream>

using namespace std;

class AvlTree {
private:

    struct Node {
        ~Node();

        Node(int const);

        Node(int const, Node *, Node *);

        int key;
        int balance = 0;
        Node *left = nullptr;
        Node *right = nullptr;
        Node *previous = nullptr;
    };

    Node *root = nullptr;

    Node* rotateLeft(Node*);

    Node* rotateRight(Node*);

    Node* rotateLeftRight(Node*);

    Node* rotateRightLeft(Node*);

    void upin(Node*);

    void display(Node*, int);

    int height(Node*);

    bool isBalanced(Node*);

public:

    ~AvlTree();

    bool search(int const) const;

    bool insert(int const);

    bool remove(int const);

    friend AvlTree &operator+=(AvlTree &, int const);

    friend AvlTree &operator-=(AvlTree &, int const);

    friend ostream &operator<<(ostream &, AvlTree &);

    void display();

    bool isBalanced();


};

#endif