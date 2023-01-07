// C++UnionFind.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "UnionFind.cpp"

int main()
{
    int values[] = { 0, 1, 2, 3, 4, 5, };
    QuickFind<int> quickFind = QuickFind<int>(values);

    bool result1 = quickFind.Union(1, 2); //true
    bool result2 = quickFind.AreConnected(1, 5); //false
    bool result3 = quickFind.Union(2, 5); //true
    bool result4 = quickFind.AreConnected(1, 5); //true
    int result5 = quickFind.Find(3); // 3
    int result6 = quickFind.Find(2); // 5
    bool result7 = quickFind.Union(0, 4); //true
    bool result8 = quickFind.AreConnected(4, 5); //false
    bool result9 = quickFind.Union(1, 2); //false
    bool result10 = quickFind.Union(1, 6); //false
    int result11 = quickFind.Find(20); // -1
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
