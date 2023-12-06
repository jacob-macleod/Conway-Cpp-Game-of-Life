#ifndef CELL_H
#define CELL_H
#include <iostream>
using namespace std;

class cell {
public:
    int x;
    int y;
    // Can be A for alive or D for dead
    char status;
    cell() {};
    cell(int x, int y) : x(x), y(y) {
        status = 'D';
    };

    cell(int x, int y, char status) : x(x), y(y), status(status) {};

    void setCoords(int locX, int locY) {
        x = locX;
        y = locY;
    }

    void show() {
        cout << status;
    }
};

#endif