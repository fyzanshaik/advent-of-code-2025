#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <sys/types.h>
#include <unordered_map>
using namespace std;

/**
 * Input: ID strings format: firstID-LastID at each line these are RANGES
 * Need to identify Invalid ID's, and add them all up
 * obtain ranges starting and ending from passing each line of string
 * then check which is an invalid id
 * Invalid ID has numbers with a frequency of 2 atleast, if an ID consists of
 * that then its an invalid ID
 *
 *
 * My approach:
 * Read the full line
 * Create a vector of pairs where each pair is an int that stores
 * [{firstID,lastID},{},{}......] First create the full data then for each pair
 * just need to check the pattern, if even length and the first substring and
 * second sunstring match then we know its an INVALID id so return that val add
 * it to sum else return 0
 */

/**
 * First part ans: 64215794229
 * second part ans:
 */

vector<string> split(const string &s, char delimiter) {
  vector<string> tokens;
  string token;
  istringstream tokenStream(s);

  while (getline(tokenStream, token, delimiter)) {
    tokens.push_back(token);
  }

  return tokens;
}

pair<string, string> getIDPair(string s) {
  pair<string, string> ids;
  string token;
  stringstream ss(s);
  int count = 0;
  while (getline(ss, token, '-')) {
    if (count == 0) {
      try {
        ids.first = token;
      } catch (const invalid_argument &e) {
        throw runtime_error("Invalid id: not a number");
      }
    } else if (count == 1) {
      try {
        ids.second = token;
      } catch (const invalid_argument &e) {
        throw runtime_error("Invalid id: not a number");
      }
    }
    count++;
  }
  return ids;
}
// Useful for first part
//  long long getInvalidID(long long id) {
//    string s = to_string(id);
//    int length = s.length();

//   if (length % 2 != 0) {
//     return 0;
//   }

//   int half = length / 2;
//   string firstHalf = s.substr(0, half);
//   string secondHalf = s.substr(half);

//   if (firstHalf == secondHalf) {
//     return id;
//   }

//   return 0;
// }

// second half
long long getInvalidID(long long id) {
  string s = to_string(id);
  int length = s.length();

  for (int patternLength = 1; patternLength <= length / 2; patternLength++) {
    if (length % patternLength != 0)
      continue;

    string pattern = s.substr(0, patternLength);

    string repeated = "";
    int repeatedTimes = length / patternLength;

    for (int i = 0; i < repeatedTimes; i++) {
      repeated += pattern;
    }

    if (s == repeated) {
      return id;
    }
  }
  return 0;
}

int main() {
  long long sum = 0;

  ifstream input_file("input-2.txt");
  string line;

  if (!input_file.is_open()) {
    cerr << "Error opening file" << endl;
    return 1;
  }

  getline(input_file, line);
  char delimiter = ',';

  vector<string> inputVector = split(line, delimiter);
  // for (string s : inputVector) {
  //   cout << s << endl;
  // }

  for (string s : inputVector) {
    pair<string, string> idRange = getIDPair(s);
    // cout << idRange.first << " " << idRange.second << endl;
    long long tempFirst = stoll(idRange.first);
    long long tempSecond = stoll(idRange.second);
    // cout << tempFirst << " " << tempSecond << endl;

    for (long long i = tempFirst; i <= tempSecond; i++) {
      sum += getInvalidID(i);
      // cout << getInvalidID(i) << endl;
    }
  }

  cout << "Invalid ID sum: " << sum << endl;
  return 0;
}
