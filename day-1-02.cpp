#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/**
 * Its a circular queue of length 100 starts at 0 and ends at 99
 * Initial pointer is at 50 index
 * Output/ans : number of times the dial is left pointing at 0 after any
 * rotations in sequence Need to count the number of times it will point at 0
 * after performing the operations
 *
 * Read each line from input
 * Do string checks and perform operations according to whats given
 * Check the value of node after every operation
 * if node.value == 0 then count++
 *
 * return the count
 */

/**
 * This is a circular queue class for dial
 * Using an integer array and wrapping it around should suffice when doing
 * operations as its just 0-99 so a 100 size int array A control pointer
 * variable which keeps track of the current position initially at 50index
 * traverse left operation input the number of times to shift and the pointer of
 * position traverse right operation input the number of times to shift and the
 * pointer again
 *
 */

class Dial {
public:
  int position = 50;

  void traverseRight(int numberOfTimes, int *count) {
    for (int i = 0; i < numberOfTimes; i++) {
      if (position == 99) {
        position = 0;
      } else {
        position++;
      }
      if (position == 0) {
        *count = *count + 1;
      }
    }
  }

  void traverseLeft(int numberOfTimes, int *count) {
    for (int i = 0; i < numberOfTimes; i++) {
      if (position == 0) {
        position = 99;
      } else {
        position--;
      }
      if (position == 0) {
        *count = *count + 1;
      }
    }
  }
};

int main() {
  ifstream input_file("input.txt");
  string line;
  int count = 0;
  if (!input_file.is_open()) {
    cerr << "Error opening file" << endl;
    return 1;
  }
  char direction;
  int numberOfTimes = 0;

  Dial dial;
  cout << "Initial position: " << dial.position << endl;
  int countOfZero = 0;
  cout << "Initial count: " << countOfZero << endl;
  while (getline(input_file, line)) {
    count++;
    direction = line[0];
    numberOfTimes = stoi(line.substr(1));
    // cout << "Line: " << count << " Direction: " << direction
    //    << " Change in position: " << numberOfTimes << endl;

    if (direction == 'R') {
      dial.traverseRight(numberOfTimes, &countOfZero);
    } else {
      dial.traverseLeft(numberOfTimes, &countOfZero);
    }
  }

  cout << "Final Position: " << dial.position << endl;
  cout << "Number of lines: " << count << endl;
  cout << "Final count: " << countOfZero << endl;

  input_file.close();
  return 0;
}
