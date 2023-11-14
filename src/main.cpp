#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{

    // объявляем переменные
    string uspath;
    string confirmed;

    cout << "Enter a valid path to delete file: ";
    cin >> uspath;

    cout << "Are you sure you wanna delete " << uspath << " (Yes / no)?: ";
    cin >> confirmed;

    // проверяем на уверенность в удалении файла
    if(confirmed == "Yes") {

        //проверяем на успех удаления
        if(remove(uspath.c_str()) == 0) {
            cout << "File deleted sucsessfuly\n";
        }
        else {
            cerr << "Error while deleting file\n";
        }
        
    }
    else {
        cout << "File deleting canceled\n";
    }

    return 0;

}