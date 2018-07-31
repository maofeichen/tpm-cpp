/*
 * util.h
 *
 *  Created on: Jul 31, 2018
 *      Author: mchen
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <string>
#include <vector>

class Util{
public:
  static void
  split_str(const char *s, const char c, std::vector<std::string> &res);
};

#endif /* UTIL_H_ */
