#include <iostream>
#include "grid.h"
int main() {
    grid board = grid(10, 10);
    board.setCell(0, 0, 'A');
    board.setCell(0, 1, 'A');
    board.setCell(1, 0, 'A');
    board.show();
    cout << "Shown" << endl;
    board.refresh();
    cout << "Shown2" << endl;
    board.show();
    
    cout << "Done" << endl;
}