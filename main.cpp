#pragma once
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    BinarySearchTree<int> N;

    N.Add(12);
    N.Add(8);
    N.Add(6);
    N.Add(20);
    N.Add(7);
    N.Add(13);
    N.Add(16);
    N.Add(21);

    N.print_tree_level(N.GetRoot(), 0);

    // N.Delete_element(7);

    /* cout << endl << endl;
     cout << "-----------------------------------------";
     cout << endl << endl;

     N.print_tree_level(N.GetRoot(), 0);

     cout << endl << endl;*/

     //N.Task();

    N.Delete_leafs();
   // N.print_tree_level(N.GetRoot(), 0);
    N.Print();
}