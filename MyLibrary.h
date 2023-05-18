//
// Created by Legion on 5/14/2023.
//

#ifndef NEW_LAB_2_MYLIBRARY_H
#define NEW_LAB_2_MYLIBRARY_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Book;

bool is_valid_date(int day, int month, int year);
void write_books(string &filename);
void copy_recent_books(string& src_filename, string& dest_filename);
void print_books(string &filename);
void print_file(string& filename);

#endif //NEW_LAB_2_MYLIBRARY_H
