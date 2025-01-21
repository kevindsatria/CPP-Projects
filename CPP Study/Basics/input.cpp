#include <iostream>
#include <string>


using namespace std;

int main(){

    int age;
    cout << "Enter your age: ";
    cin >> age;

    string full_name;
    cout <<"Enter your full name: ";
    getline(cin >> ws, full_name); //cin >> ws to clear input buffer whitespace
    // or you can do cin.ignore() after the "cin >> age" then do regular "getline(cin, full_name)""

    cout << "\nName:\t" << full_name << "\nAge:\t" << age << endl;


    return 0;
}