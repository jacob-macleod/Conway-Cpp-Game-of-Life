#ifndef GRID_H
#define GRID_H
#include "cell.h"

class grid {
  int x;
  int y;
  cell **data;
  cell **newData;

public:
  grid(int x, int y) : x(x), y(y) {
    data = new cell *[y];
    for (int i = 0; i < y; i++) {
      data[i] = new cell[x];
      for (int z = 0; z < x; z++) {
        data[i][z] = cell(i, z);
      }
    }
  }

  void show() {
    for (int i = 0; i < y; i++) {
      for (int z = 0; z < x; z++) {
        data[i][z].show();
      }
      cout << endl;
    }
  }

  int findNeighbours(int posX, int posY) {
    int neighbours = 0;

    for (int rotY = -1; rotY < 2; rotY++) {
      for (int rotX = -1; rotX < 2; rotX++) {
        if (data[posY + rotY][posX + rotX].status == 'A')
          neighbours++;
      }
    }

    return neighbours;
  };

  void setCell(int posY, int posX, char status) {
    data[posY][posX].status = status;
  }

  void refresh() {
    cout << "Refreshing" << endl;
    newData = data;
    for (int posY = 0; posY < y; posY++) {
      cout << posY << endl;
      for (int posX = 0; posX < x; posX++) {
        cout << "posX" << endl;
        int neighbours = findNeighbours(posY, posX);
        if (neighbours < 2) {
          // newData[posY][posX].status = 'D';
          cout << "INNER LOOP\n\n\n";
        } /*else if (neighbours > 3) {
          data[posY][posX].status = 'D';
        } else {
          data[posY][posX].status = 'A';
        }*/
        cout << "Inner loop" << endl;
      }
    }
    cout << "Refreshed" << endl;
  }
};
#endif