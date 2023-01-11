// C++UnionFind.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "UnionFind.cpp"
#include <random>
#include <chrono>
#include <functional>

bool LikesFood(int numberOfPeople)
{
    if (numberOfPeople < 0)
    {
        throw std::bad_exception();
    }
    return true;
}

int main()
{
    std::function<bool(int parameter)> function = &LikesFood;
    bool result = function(-100);
    while (true)
    {
        //std::string values[] = { "0", "1", "2", "3", "4", "5", };
        //QuickFind<std::string> quickFind = QuickFind<std::string>(values, 6);

        //bool result1 = quickFind.Union("1", "2"); //true
        //bool result2 = quickFind.AreConnected("1", "5"); //false
        //bool result3 = quickFind.Union("2", "5"); //true
        //bool result4 = quickFind.AreConnected("1", "5"); //true
        //int result5 = quickFind.Find("3"); // 3
        //int result6 = quickFind.Find("2"); // 5
        //bool result7 = quickFind.Union("0", "4"); //true
        //bool result8 = quickFind.AreConnected("4", "5"); //false
        //bool result9 = quickFind.Union("1", "2"); //false
        //bool result10 = quickFind.Union("1", "6"); //false
        //int result11 = quickFind.Find("20"); // -1



        int values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int length = 10;
        QuickUnion<int> quickUnion = QuickUnion<int>(values, length);
        quickUnion.Union(0, 1);
        quickUnion.Union(2, 3);
        quickUnion.Union(4, 5);
        quickUnion.Union(6, 7);
        quickUnion.Union(8, 9);
        quickUnion.Union(1, 2);
        quickUnion.Union(5, 6);
        quickUnion.Union(2, 5);
        quickUnion.Union(1, 9);

        //const int length = 200;
        //int values[length];
        //for (int i = 0; i < length; i ++)
        //{
        //    values[i] = i;
        //}
        //QuickUnion<int> quickUnion = QuickUnion<int>(values, length);

        //for (int i = 2; i < length -2; i += 3)
        //{
        //    quickUnion.Union(i, i - 1);
        //    quickUnion.Union(i - 1, i + 1);
        //    quickUnion.Union(i - 2, i + 2);
        //}

        //std::srand(std::chrono::system_clock::now().time_since_epoch().count());
        //for (int i = 0; i < 25; i ++)
        //{
        //    quickUnion.Union(std::rand() % length, std::rand() % length);
        //}

        int deepestDepth = 0;
        for (int i = 0; i < length; i ++)
        {
            std::pair<int, int> result = quickUnion.Find(i);
            if (result.second > deepestDepth)
            {
                deepestDepth = result.second;
            }
        }
    }
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
