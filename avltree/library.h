#ifndef BLATT_7_AUFGABE_1_42_LIBRARY_H
#define BLATT_7_AUFGABE_1_42_LIBRARY_H

using namespace std;

class AvlTree {
private:

    struct Node {
        ~Node();

        Node(int const);

        Node(int const, Node *, Node *);

        int key;
        Node *left = nullptr;
        Node *right = nullptr;
        Node *previous = nullptr;
    };

    Node *root = nullptr;

public:

    ~AvlTree();

    bool search(int const) const;

    bool insert(int const);

    bool remove(int const);

};

#endif