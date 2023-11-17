#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string max_chain_search(string &str1, string &str2) {
    string path;
    int i = 0, j = 0;
    int n1 = str1.length();
    int n2 = str2.length();

    vector<vector<int>> current_chain(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {
            if (str1[i] == str2[j]) {
                current_chain[i][j] = current_chain[i + 1][j + 1] + 1;
            }
            else {
                current_chain[i][j] = max(current_chain[i + 1][j], current_chain[i][j + 1]);
            }
        }
    }

    while (i < n1 && j < n2)
    {
        if (str1[i] == str2[j]) {
            path += str1[i];
            i++;
            j++;
        }
        else if (current_chain[i + 1][j] >= current_chain[i][j + 1]) i++;

        else j++;
    }
    return path;
}

void chain_of_str() 
{
    string str1, str2;
    cout << "Enter first oreder of symbols: ";
    getline(cin, str1);
    cout << "Enter second oreder of symbols: ";
    getline(cin, str2);
    string max_chain = max_chain_search(str1, str2);
    cout << "Maximum matching sub-chain: " << max_chain << endl;
}