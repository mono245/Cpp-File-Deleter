#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

int main()
{

    // объявляем переменные
    string uspath;
    string confirmed;

    cout << "Enter a valid path to delete file: ";
    cin >> uspath;

    cout << "Are you sure you want to delete " << uspath << " (Yes / no)?: ";
    cin >> confirmed;

    // проверяем на правильность потдверждения
    if(!(confirmed == "Yes" || confirmed == "no")) {
        cout << "Error: invalid argument while confirm deleting\n";
        return 1;
    }

    // проверяем на уверенность в удалении файла
    else if(confirmed == "Yes") {
        
        // проверяем на существование файла
        if(ifstream(uspath)) {
        //проверяем на успех удаления
            if(remove(uspath.c_str()) == 0) {
                cout << "File deleted sucsessfuly\n";
            }
            else {
                cerr << "Error: (" << remove(uspath.c_str()) << " code)\n";
                return 1;
            }
        }
        else {
            cerr << "Error: file don't exist\n";
            return 1;
        }
    }
    else {
        cerr << "File deleting canceled\n";
    }

    return 0;

}