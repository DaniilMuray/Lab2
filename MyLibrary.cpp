//
// Created by Legion on 5/14/2023.
//

#include "MyLibrary.h"

struct Book {
    string name;
    int written_day, written_month, written_year;
    int published_year;
};

bool is_valid_date(int day, int month, int year) {
    if (month < 1 || month > 12) {
        return false;
    }
    if (day < 1) {
        return false;
    }
    if (month == 2) {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            return day <= 29;
        } else {
            return day <= 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return day <= 30;
    } else {
        return day <= 31;
    }
}


void write_books(string &filename) {
    ofstream fout(filename, ios::binary);
    if (!fout) {
        cerr << "Error opening file!" << endl;
        return;
    }

//    int num_books;
//    cout << "How many books do you want to enter? ";
//    cin >> num_books;
    const int num_books = 50;


    Book book;

    cout << "If you want to stop, write - // " << endl;
    for (int i = 0; i < num_books; i++) {
        cout << "Enter book name:\n";

        cin.ignore(1, '\n');
        getline(cin, book.name);

        if (book.name.find("//") != std::string::npos) {
            break;  // Exit loop if user enters an empty title
        }


        cout << "Enter date written (DD MM YYYY): ";

        do{
            cin >> book.written_day >> book.written_month >> book.written_year;
            if (!is_valid_date(book.written_day, book.written_month, book.written_year))
                cout << "Invalid date. Please, try again." << endl;
        }while(!is_valid_date(book.written_day, book.written_month, book.written_year));



        cout << "Enter published year (0 if not published): ";
        cin >> book.published_year;

        fout.write(book.name.c_str(), book.name.size() + 1);
        fout.write(reinterpret_cast<char*>(&book.written_day), sizeof(int));
        fout.write(reinterpret_cast<char*>(&book.written_month), sizeof(int));
        fout.write(reinterpret_cast<char*>(&book.written_year), sizeof(int));
        fout.write(reinterpret_cast<char*>(&book.published_year), sizeof(int));


    }

    fout.close();
}


void copy_recent_books(string& src_filename, string& dest_filename) {
    ifstream fin(src_filename, ios::binary);
    if (!fin) {
        cerr << "Error opening file!" << endl;
        return;
    }

    ofstream fout(dest_filename, ios::binary);
    if (!fout) {
        cerr << "Error opening file!" << endl;
        return;
    }

    Book book;
    char buffer[1024];
    while (fin.getline(buffer, 1024, '\0')) {

        book.name = buffer;

        fin.read(reinterpret_cast<char*>(&book.written_day), sizeof(int)); // зчитуємо три числа типу int
        fin.read(reinterpret_cast<char*>(&book.written_month), sizeof(int));
        fin.read(reinterpret_cast<char*>(&book.written_year), sizeof(int));
        fin.read(reinterpret_cast<char*>(&book.published_year), sizeof(int));


        if (book.written_year >= 2020) {

            fout.write(book.name.c_str(), book.name.size() + 1);
            fout.write(reinterpret_cast<char*>(&book.written_day), sizeof(int)); // зчитуємо три числа типу int
            fout.write(reinterpret_cast<char*>(&book.written_month), sizeof(int));
            fout.write(reinterpret_cast<char*>(&book.written_year), sizeof(int));
            fout.write(reinterpret_cast<char*>(&book.published_year), sizeof(int));
        }

        if (fin.eof()) {
            break;
        }
    }

    fin.close();
    fout.close();
}



void print_books(string &filename) {
    ifstream fin(filename, ios::binary);
    if (!fin) {
        cerr << "Error opening file!" << endl;
        return;
    }

    Book book;
    char buffer[1024];
    while (fin.getline(buffer, 1024, '\0')) {
        book.name = buffer;

        fin.read(reinterpret_cast<char*>(&book.written_day), sizeof(int)); // зчитуємо три числа типу int
        fin.read(reinterpret_cast<char*>(&book.written_month), sizeof(int));
        fin.read(reinterpret_cast<char*>(&book.written_year), sizeof(int));
        fin.read(reinterpret_cast<char*>(&book.published_year), sizeof(int));



        if (book.published_year != 0 && book.published_year - book.written_year > 5) {
            cout << "Book Name: " << book.name << endl;
            cout << "Date Written: " << book.written_day << "/" << book.written_month << "/" << book.written_year << endl;
            cout << "Published Year: " << book.published_year << endl << endl;
        }
    }

    fin.close();
}

void print_file(string& filename){
    ifstream fin(filename, ios::binary);
    if (!fin) {
        cerr << "Error opening file!" << endl;
        return;
    }
    Book book;
    char buffer[1024];
    while (fin.getline(buffer, 1024, '\0')) {
        book.name = buffer;

        fin.read(reinterpret_cast<char *>(&book.written_day), sizeof(int)); // зчитуємо три числа типу int
        fin.read(reinterpret_cast<char *>(&book.written_month), sizeof(int));
        fin.read(reinterpret_cast<char *>(&book.written_year), sizeof(int));
        fin.read(reinterpret_cast<char *>(&book.published_year), sizeof(int));

        cout << book.name << " " << book.written_day << " " << book.written_month << " " << book.written_year << " " << book.published_year << endl;


    }

        fin.close();

}
