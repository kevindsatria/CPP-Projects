#include <iostream>
#include "Scores.h"

using namespace std;

int main()
{
    GameEntry jose("Jose", 100);
    GameEntry clara("Clara", 95);
    GameEntry sara("Sara", 20);
    GameEntry kevin("Kevin", 85);
    GameEntry john("John", 30);
    GameEntry wilson("Wilson", 45);
    GameEntry nancy("Nancy", 35);
    GameEntry paul("Paul", 55);


    Scores test(5);

    cout << "1. List: \n\n";
    test.add(sara);
    test.add(jose);
    test.add(kevin);
    test.add(clara);
    test.printAll(); cout << endl;


    cout << "2. After adding 3 more entries\n\n";

    test.add(john);
    test.add(nancy);
    test.add(paul);
    test.printAll(); cout << endl;

    cout << "3. Removing the index 0 and 3\n\n";

    test.remove(0);
    test.remove(3);
    test.printAll();

    return 0;
}
