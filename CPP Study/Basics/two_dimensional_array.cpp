#include <iostream>

using namespace std;

int main(){

    int **array2d = new int*[10];
    for(int i = 0; i < 10; i++)
        array2d[i] = new int[10];

    int temp = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++)
            array2d[i][j] = j + temp;
        temp+=10;
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++)
            if(i == 0)
                cout << array2d[i][j] << "  ";
            else   
                cout << array2d[i][j] << " ";
        cout << endl;
    }

    cout << array2d[1][0] << endl;

    // to delete
    for(int i = 0; i < 10; i++)
        delete [] array2d[i];
    delete [] array2d;

    return 0;
}