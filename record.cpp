/*
 * record.cpp
 *
 *  Created on: Jun 4, 2018
 *      Author: mchen
 */

#include "record.h"
#include "util.h"
#include <iostream>
#include <vector>

using namespace std;

Record::Record(std::string &s_rec) : s_rec_(s_rec)
{
  // std::cout << s_rec_ << std::endl;
  analyze_record();
}

void Record::analyze_record()
{
  vector<string> recs;
  Util::split_str(s_rec_.c_str(), '\t', recs);
}
