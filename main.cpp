#include <iostream>
#include <string>
#include "MyLibrary.h"


using namespace std;


int main() {


    string filename;
    cout << "Enter filename to store book information: ";
    cin >> filename;
    filename.append(".bin");


    write_books(filename);


    string recent_books_filename;
    cout << "\nEnter filename to store recent books: ";
    cin >> recent_books_filename;
    recent_books_filename.append(".bin");

    copy_recent_books(filename, recent_books_filename);

    cout << "\nBooks that were published after being written 5 years or more later: \n" << endl;
    print_books(filename);

    cout << "\n" << filename << " file:" << endl;
    print_file(filename);

    cout << "\n\n" << recent_books_filename << " file:" << endl;
    print_file(recent_books_filename);


    return 0;
}
