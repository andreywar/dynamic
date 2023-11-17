#pragma once
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;


void triangle_path(vector<vector<int>> triangle, int& max_loads, vector<int>& path) {

    int triangle_size = triangle.size();
    vector<vector<int>> current_path(triangle_size, vector<int>(triangle_size));

    for (int i = 0; i < triangle_size; i++) {
        current_path[triangle_size - 1][i] = triangle[triangle_size - 1][i];
    }

    for (int i = triangle_size - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            current_path[i][j] = triangle[i][j] + max(current_path[i + 1][j], current_path[i + 1][j + 1]);
        }
    }

    max_loads = current_path[0][0];

    int current_count = max_loads;
    for (int i = 0; i < triangle_size - 1; i++) {
        for (int j = 0; j <= i; j++) {
            if (triangle[i][j] + current_path[i + 1][j] == current_count) {
                path.push_back(triangle[i][j]);
                current_count -= triangle[i][j];
                break;
            }
            else if (triangle[i][j] + current_path[i + 1][j + 1] == current_count) {
                path.push_back(triangle[i][j]);
                current_count -= triangle[i][j];
                break;
            }
        }
    }

    path.push_back(triangle[triangle_size - 1][0]);
    reverse(path.begin(), path.end());
}

void triangle() {

    int n;
    int max_loads;
    vector<int> path;



    cout << "Enter triangle size: ";
    cin >> n;
    vector<vector<int>> triangle(n);



    for (int i = 0; i < n; i++) {
        triangle[i].resize(i + 1);

        for (int j = 0; j < i + 1; j++) {
            triangle[i][j] = rand() % 10;
        }
    }

    cout << "Triangle array:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }

    triangle_path(triangle, max_loads, path);

    cout << "Max loads: " << max_loads << endl;

    cout << "path: ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i != path.size() - 1) {
            cout << " ";
        }
    }
}