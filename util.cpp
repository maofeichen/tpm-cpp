/*
 * util.cpp
 *
 *  Created on: Jul 31, 2018
 *      Author: mchen
 */

#include "util.h"

using namespace std;

void Util::split_str(const char *s, const char c, vector<string> &res)
{
  do {
    const char *b = s;
    while (*s != c && *s)
      s++;

    res.push_back(string(b, s));
  }
  while (*s++ != 0);
}

