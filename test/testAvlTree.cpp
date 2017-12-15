#include "testAvlTree.h"
#include <memory>

using namespace std;

TEST(AvlTreeTest, Insert_Not_Exists) {
    AvlTree tree;
    EXPECT_TRUE(tree.insert(2));
}

TEST(AvlTreeTest, Insert_Exists) {
    AvlTree tree;
    EXPECT_TRUE(tree.insert(2));
    EXPECT_FALSE(tree.insert(2));
}

TEST(AvlTreeTest, Search_Empty) {
    AvlTree tree;
    EXPECT_FALSE(tree.search(2));
}

TEST(AvlTreeTest, Search_Not_Exists) {
    AvlTree tree;
    tree.insert(1);
    EXPECT_FALSE(tree.search(2));
}

TEST(AvlTreeTest, Search_Exists) {
    AvlTree tree;
    tree.insert(1);
    EXPECT_TRUE(tree.search(1));

}

TEST(AvlTreeTest, Insert_LeftRotateForce){
    AvlTree tree;
    for (int i = 1; i <= 30; i++) {
        tree.insert(i);
    }
    cout << tree;
    EXPECT_TRUE(tree.isBalanced());
}


TEST(AvlTreeTest, Insert_RightRotateForce){
    AvlTree tree;
    for (int i = 30; i > 0; i--) {
        tree.insert(i);
    }
    cout << tree;
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_Root){
    AvlTree tree;
    for (int i = 30; i > 0; i--) {
        tree.insert(i);
    }
    cout << tree;
    tree.remove(15);
    cout << tree;
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_Node_2Childs){
    AvlTree tree;
    for (int i = 30; i > 0; i--) {
        tree.insert(i);
    }
    cout << tree;
    tree.remove(11);
    cout << tree;
    EXPECT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_Node_1Childs){
    AvlTree tree;
    for (int i = 29; i > 0; i--) {
        tree.insert(i);
    }
    cout << tree;
    tree.remove(5);
    cout << tree;
    EXPECT_TRUE(tree.isBalanced());
}


TEST(AvlTreeTest, isFailing){
    AvlTree tree;
    for (int i = 16; i > 0; i--) {
        tree.insert(i);
    }

    cout<<tree;
    tree.remove(5);
    cout<<tree;
    ASSERT_TRUE(tree.isBalanced());

    tree.remove(16);
    cout<<tree;
    ASSERT_TRUE(tree.isBalanced());

    tree.remove(6);
    cout<<tree;
    ASSERT_TRUE(tree.isBalanced());

    tree.remove(9);
    cout<<tree;
    ASSERT_TRUE(tree.isBalanced());
}


TEST(AvlTreeTest, Remove_Multible) {
    int random_integer;
    for (int i = 10; i <= 300; i++) {
        AvlTree tree;
        for (int j = i; j > 0; j--) {
            tree.insert(j);
        }
        cout << i << ",";

        random_integer = rand()%i + 1;
        tree.remove(random_integer);
        cout << random_integer << ",";

        random_integer = rand()%i + 1;
        tree.remove(random_integer);
        cout << random_integer << ",";

        random_integer = rand()%i + 1;
        tree.remove(random_integer);
        cout << random_integer << ",";

        random_integer = rand()%i + 1;
        tree.remove(random_integer) + ",";
        cout << random_integer << ",";


        cout << tree.isBalanced() << ",";
        cout << tree;
        ASSERT_TRUE(tree.isBalanced());
    };
}
