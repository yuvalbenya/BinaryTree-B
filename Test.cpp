#include "BinaryTree.hpp"
#include "doctest.h"
using namespace ariel;

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
using namespace std;


TEST_CASE("check"){
    BinaryTree<int> t;
    t.add_root(1);
    t.add_left(1, 2);
    t.add_left(2, 3);
    t.add_right(2, 4);
    t.add_right(1, 5);
    // CHECK(t.root->left->left->data == 3);
    // for(auto it = t.begin_preorder();it != t.end_preorder();it++){
    //     cout << *it << endl;
    // }
    BinaryTree<int> t2;
    t2.add_root(1);
    t2.add_left(1, 2);
    t2.add_left(2, 4);
    t2.add_right(2, 5);
    t2.add_right(1, 3);
    for(auto it = t2.begin_inorder();it != t2.end_inorder();it++){
        cout << *it << endl;
    }
    cout << "finished" << endl;
    BinaryTree<int> t3;
    t3.add_root(1);
    t3.add_left(1, 2);
    t3.add_left(2, 4);
    t3.add_right(2, 5);
    t3.add_right(1, 3);
    for(auto it = t2.begin_postorder();it != t2.end_postorder();it++){
     cout << *it << endl;
    }
    cout << "finished" << endl;
    // BinaryTree<char> t2;
    // t2.add_root('a');
    // t2.add_left('a', 'b');
    // t2.add_left('b', 'c');
    // t2.add_right('b', 'd');
    // t2.add_right('a', 'e');
    // CHECK(t2.root->left->right->data == 'd');
}













// class testObject
// {
// private:
//     int num;
//     char c;

// public:
//     testObject(int j, char d)
//     {
//         num = j;
//         c = d;
//     }
//     bool operator==(const testObject &a) const
//     {
//         return (this->num == a.num && this->c == a.c);
//     }
// };
// TEST_CASE("naive iterator check ")
// {
//     BinaryTree<int> t;
//     //preorder
//     t.add_root(1);
//     t.add_left(1, 2);
//     t.add_left(2, 3);
//     t.add_right(2, 4);
//     t.add_right(1, 5);
//     auto it = t.begin_preorder();
//     for (int i = 0; i < 5; i++)
//     {
//         CHECK(i == *it);
//         it++;
//     }
//     CHECK(it == t.end_inorder());
//     //inorder
//     t.add_root(4);
//     t.add_left(4, 2);
//     t.add_left(2, 1);
//     t.add_right(2, 3);
//     t.add_right(4, 5);
//     auto it = t.begin_inorder();
//     for (int i = 0; i < 5; i++)
//     {
//         CHECK(i == *it);
//         it++;
//     }
//     CHECK(it == t.end_inorder());
//     //postorder
//     t.add_root(5);
//     t.add_left(5, 3);
//     t.add_left(3, 1);
//     t.add_right(3, 2);
//     t.add_right(5, 4);
//     auto it = t.begin_postorder();
//     for (int i = 0; i < 5; i++)
//     {
//         CHECK(i == *it);
//         it++;
//     }
//     CHECK(it == t.end_postorder());
// }
// TEST_CASE("Left Tree check")
// {
//     BinaryTree<testObject> tree_of_ints;

//     testObject obj1(1, 'a');
//     testObject obj2(2, 'b');
//     testObject obj3(3, 'c');
//     testObject obj4(4, 'd');
//     testObject obj5(5, 'e');
//     testObject obj6(6, 'f');
//     testObject obj7(7, 'g');
//     testObject obj8(8, 'h');
//     testObject obj9(9, 'i');
//     testObject obj10(10, 'j');

//     tree_of_ints.add_root(obj1);
//     tree_of_ints.add_left(obj1, obj2);
//     tree_of_ints.add_left(obj2, obj3);
//     tree_of_ints.add_left(obj3, obj4);
//     tree_of_ints.add_left(obj4, obj5);
//     tree_of_ints.add_left(obj5, obj6);
//     tree_of_ints.add_left(obj6, obj7);
//     tree_of_ints.add_left(obj7, obj8);
//     tree_of_ints.add_left(obj8, obj9);
//     tree_of_ints.add_left(obj9, obj10);

//     vector<testObject> values = {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}, {6, 'f'}, {7, 'g'}, {8, 'h'}, {9, 'i'}, {10, 'j'}};
//     auto itPre = tree_of_ints.begin_preorder();
//     unsigned int i = 0;
//     while (itPre != tree_of_ints.end_preorder())
//     {
//         CHECK((*itPre) == values[i]);
//         i++;
//         itPre++;
//     }

//     vector<testObject> values = {{10, 'j'}, {9, 'i'}, {8, 'h'}, {7, 'g'}, {6, 'f'}, {5, 'e'}, {4, 'd'}, {3, 'c'}, {2, 'b'}, {1, 'a'}};

//     auto itIn = tree_of_ints.begin_inorder();
//     i = 0;
//     while (itIn != tree_of_ints.end_inorder())
//     {
//         CHECK((*itIn) == values[i]);
//         i++;
//         itIn++;
//     }

//     auto itPost = tree_of_ints.begin_postorder();
//     i = 0;
//     while (itPost != tree_of_ints.end_postorder())
//     {
//         CHECK((*itPost) == values[i]);
//         i++;
//         itPost++;
//     }
// }

// TEST_CASE("Right Tree check")
// {
//     BinaryTree<testObject> tree_of_ints;

//     testObject obj1(1, 'a');
//     testObject obj2(2, 'b');
//     testObject obj3(3, 'c');
//     testObject obj4(4, 'd');
//     testObject obj5(5, 'e');
//     testObject obj6(6, 'f');
//     testObject obj7(7, 'g');
//     testObject obj8(8, 'h');
//     testObject obj9(9, 'i');
//     testObject obj10(10, 'j');

//     tree_of_ints.add_root(obj1);
//     tree_of_ints.add_right(obj1, obj2);
//     tree_of_ints.add_right(obj2, obj3);
//     tree_of_ints.add_right(obj3, obj4);
//     tree_of_ints.add_right(obj4, obj5);
//     tree_of_ints.add_right(obj5, obj6);
//     tree_of_ints.add_right(obj6, obj7);
//     tree_of_ints.add_right(obj7, obj8);
//     tree_of_ints.add_right(obj8, obj9);
//     tree_of_ints.add_right(obj9, obj10);

//     vector<testObject> values = {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}, {6, 'f'}, {7, 'g'}, {8, 'h'}, {9, 'i'}, {10, 'j'}};
//     auto itPre = tree_of_ints.begin_preorder();
//     unsigned int i = 0;
//     while (itPre != tree_of_ints.end_preorder())
//     {
//         CHECK((*itPre) == values[i]);
//         i++;
//         itPre++;
//     }

//     auto itIn = tree_of_ints.begin_inorder();
//     i = 0;
//     while (itIn != tree_of_ints.end_inorder())
//     {
//         CHECK((*itIn) == values[i]);
//         i++;
//         itIn++;
//     }

//     vector<testObject> values = {{10, 'j'}, {9, 'i'}, {8, 'h'}, {7, 'g'}, {6, 'f'}, {5, 'e'}, {4, 'd'}, {3, 'c'}, {2, 'b'}, {1, 'a'}};
//     auto itPost = tree_of_ints.begin_postorder();
//     i = 0;
//     while (itPost != tree_of_ints.end_postorder())
//     {
//         CHECK((*itPost) == values[i]);
//         i++;
//         itPost++;
//     }
// }

// TEST_CASE("throws and functionality")
// {
//     BinaryTree<int> t;
//     //preorder
//     t.add_root(10);
//     t.add_left(10, 2);
//     t.add_left(2, 4);
//     t.add_right(2, 5);
//     t.add_right(10, 3);
//     CHECK_NOTHROW(t.add_root(1)); //replacing root should not throw an error
//     CHECK_NOTHROW(t.add_root(1));
//     CHECK_THROWS(t.add_right(10, 8)); //10 is no longer a vertex in the tree
//     CHECK_THROWS(t.add_right(15, 8)); //15 never were a vertex in the tree
//     CHECK_THROWS(t.add_left(10, 8));  //10 is no longer a vertex in the tree
//     CHECK_THROWS(t.add_left(15, 8));  //15 never were a vertex in the tree
//     CHECK_THROWS(t.add_left(15, 2));  //for checking if the vertex 2 is not messed up
//     CHECK_THROWS(t.add_right(15, 2)); //for checking if the vertex 2 is not messed up
//     int i = 0;
//     auto it = t.begin_preorder();
//     vector<int> v = {1, 2, 4, 5, 3};
//     for (int i = 0; i < 5; i++)
//     {
//         CHECK(*it == v[i]);
//     }
//     CHECK(*it == t.end_preorder());
// }