#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sys/types.h>
using namespace std;

/**
 * Each line consists of an array of int values(1-9), need to pick the two
 * highest values from each line Make then into highest 2 digit number Add them
 * for each line
 *
 * My initial approach:
 * Read each line -> convert them into a vector -> sort the vector -> get the
 * last 2 digits (using asc order) -> make it into number add them and return
 * the answer OR I could directly do char comparisons as the range is fixed,
 * directly sort the strings and it will produce a sorted order pick the last
 * two elements -> stoi(2chars) -> save it as sum and continue to the next line
 * Much better and TC: O(nlongn)
 *
 * I am not supposed to change order so sorting isn't allowed
 * Iterate through the string, get the first max value and second max value ->
 * create int and add them much simpler
 */

// ASCII RANGE: 49, 50, 51, 52, 53, 54, 55, 56, and 57 (1-9)
long long getMaxJoltValue(string digits) {
  long long val;
  // 0 -> n-2 check for the first highest digit
  //  from x(the index where the first highest digit was found) -> n-1 get the
  //  highest digit again in this range

  char firstDigit = digits[0];
  int firstIndex = 0;
  for (int i = 1; i < digits.length() - 1; i++) {
    if (firstDigit < digits[i]) {
      firstDigit = digits[i];
      firstIndex = i;
    }
  }
  // cout << firstDigit << endl;

  char secondDigit = digits[firstIndex + 1];
  for (int i = firstIndex + 2; i < digits.length(); i++) {
    if (secondDigit < digits[i])
      secondDigit = digits[i];
  }
  string tempVal;
  tempVal.push_back(firstDigit);
  tempVal.push_back(secondDigit);
  // cout << tempVal << endl;
  return stoll(tempVal);
}

long long getMaxjoltval2(string digits) {
  long long val;
  int n = digits.length();
  string finalString = "";
  int lastIndex = -1, remaining;
  int digitsNeeded = 12;
  for (int i = 0; i < digitsNeeded; i++) {
    remaining = digitsNeeded - i;
    int searchStart = lastIndex + 1;
    int searchEnd = n - remaining;

    char maxDigit = digits[searchStart];
    int maxIndex = searchStart;

    for (int j = searchStart + 1; j <= searchEnd; j++) {
      if (digits[j] > maxDigit) {
        maxDigit = digits[j];
        maxIndex = j;
      }
    }

    finalString += maxDigit;
    lastIndex = maxIndex;
  }

  return stoll(finalString);
}

int main() {
  ifstream input_file("input-3.txt");
  while (!input_file.is_open()) {
    cerr << "Error opening input file" << endl;
    return 1;
  }
  long long sum = 0;
  string line;

  while (getline(input_file, line)) {
    // sort(line.begin(), line.end());
    // cout << line << endl;
    // long long joltValue = getMaxJoltValue(line.substr(line.length() - 2));
    long long joltValue = getMaxjoltval2(line);

    cout << joltValue << endl;
    sum += joltValue;
    // break;
  }

  cout << "Sum of all jolt values: " << sum << endl;

  return 0;
}
