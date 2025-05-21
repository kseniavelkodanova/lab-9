#include <iostream>
#include "FindLastOf.h"
#include "PathUtilities.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// ── Task 1 ───────────────────────────────────────────────────
void run_task1()
{
    cout << "\n=== Task 1: find_last_of demo ===\n"
        "src string : ";
    string src; 
    getline(cin, src);

    cout << "chars to find : ";
    string chars; getline(cin, chars);

    size_t pos_my = my_find_last_of(src.c_str(), chars.c_str());
    size_t pos_std = src.find_last_of(chars);

    cout << "my_find_last_of  -> " << pos_my << '\n'
        << "std::string ver. -> " << pos_std << '\n';
}

// ── Task 2 ───────────────────────────────────────────────────
void run_task2()
{
    cout << "\n=== Task 2: process file paths ===\n"
        "Input file (default \"input.txt\"): ";
    string inName; getline(cin, inName);
    if (inName.empty()) inName = "input.txt";

    ifstream fin(inName);
    if (!fin) { cerr << "Cannot open " << inName << '\n'; return; }

    ofstream fout("output.txt");

    string line;
    while (getline(fin, line))
    {
        if (is_valid_path(line))
            fout << last_directory(line) << '\n';
        else
            fout << "[invalid]\n";
    }
    cout << "Done. See output.txt\n";
}



int main()
{
    int choice = -1;

    do
    {
        cout << "\n========== MENU ==========\n"
            "1. Task 1  – my_find_last_of demo\n"
            "2. Task 2  – file-path processing\n"
            "0. Exit\n"
            ">>> ";
        if (!(cin >> choice)) break;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush

        switch (choice)
        {
        case 1: run_task1(); break;
        case 2: run_task2(); break;
        case 0: break;
        default: cout << "Unknown option\n";
        }
    } while (choice != 0);

    return 0;
}
