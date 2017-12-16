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
    for (int i = 26; i > 0; i--) {
        tree.insert(i);
    }
    cout << tree;
    tree.remove(2);
    cout << tree;
    EXPECT_TRUE(tree.isBalanced());
}


//fails 21,6,18,1,14,15,9,3,7,1,16,0
TEST(AvlTreeTest, isFailing){
    AvlTree tree;
    for (int i = 21; i > 0; i--) {
        tree.insert(i);
    }

    cout<<tree;
    tree.remove(6);
    cout<<tree;
    ASSERT_TRUE(tree.isBalanced());

    tree.remove(18);
    cout<<tree;
    ASSERT_TRUE(tree.isBalanced());

    tree.remove(4);
    cout<<tree;
    ASSERT_TRUE(tree.isBalanced());

    tree.remove(14);
    cout<<tree;
    ASSERT_TRUE(tree.isBalanced());

    tree.remove(15);
    cout<<tree;
    ASSERT_TRUE(tree.isBalanced());

    tree.remove(9);
    cout<<tree;
    ASSERT_TRUE(tree.isBalanced());

    tree.remove(3);
    cout<<tree;
    ASSERT_TRUE(tree.isBalanced());

    tree.remove(7);
    cout<<tree;
    ASSERT_TRUE(tree.isBalanced());

    tree.remove(1);
    cout<<tree;
    ASSERT_TRUE(tree.isBalanced());

    tree.remove(16);
    cout<<tree;
    ASSERT_TRUE(tree.isBalanced());

    tree.remove(15);
    cout<<tree;
    ASSERT_TRUE(tree.isBalanced());

    tree.remove(12);
    cout<<tree;
    ASSERT_TRUE(tree.isBalanced());

    tree.remove(2);
    cout<<tree;
    ASSERT_TRUE(tree.isBalanced());

    tree.remove(2);
    cout<<tree;
    ASSERT_TRUE(tree.isBalanced());

    tree.remove(5);
    cout<<tree;
    ASSERT_TRUE(tree.isBalanced());
}

TEST(AvlTreeTest, Remove_Multible) {
    int random_integer;
    for (int i = 10; i <= 1562; i++) {
        AvlTree tree;
        for (int j = i; j > 0; j--) {
            tree.insert(j);
        }
        cout << "Tree with " << i << " Nodes" << endl;
        bool test = false;
        //srand(time(nullptr));
        for (int k = i/2; k>0; k--){
            random_integer = rand()%i + 1;
            if(test) {
                cout << "int to delete:" << random_integer << " ,";
                cout << tree;
            }
            tree.remove(random_integer);
            //cout << "Remove Node no. : "<< random_integer << endl;
            if(random_integer == 1069 && i == 1561) {
                test = true;
            }
        }

        cout << "Balanced ? : " << tree.isBalanced() << endl;
        //cout << tree;
        EXPECT_TRUE(tree.isBalanced());
    };
}
