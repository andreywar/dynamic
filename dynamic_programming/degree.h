#pragma once
#include <iostream>
#include <vector>

using namespace std;

vector<char> degree_path(int n, vector<char> current_path) {
    if (n == 0)
        return {};

    vector<char> regularity;
    if (current_path[n] != -1)
        return current_path;

    int minOperations = 99999;

    for (int i = 1; i <= 3; i++) {
        vector<char> current_regularity;

        if (i == 1 && n > 0) {
            current_regularity = degree_path(n - 1, current_path);
        }
        else if (i == 2 && n % 2 == 0) {
            current_regularity = degree_path(n / 2, current_path);
        }
        else if (i == 3 && n % 3 == 0) {
            current_regularity = degree_path(n / 3, current_path);
        }
        else continue;

        if (current_regularity.size() < minOperations) {
            minOperations = current_regularity.size();
            regularity = current_regularity;
        }
    }


    if (n % 2 == 0 && minOperations != 99999) regularity.push_back('2');
    else if (n % 3 == 0 && minOperations != 99999) regularity.push_back('3');
    else if (n % 1 >= 0 && minOperations != 99999) regularity.push_back('1');
    return regularity;
}

void degree_() {
    int n;
    cout << "Enter degree: ";
    cin >> n;

    vector<char> current_path(n + 1, -1);

    vector<char> regularity = degree_path(n, current_path);

    cout << "Operations count: " << regularity.size() << endl;
    cout << "Operations: ";
    for (char operation : regularity) {
        cout << "->" << operation;
    }
}