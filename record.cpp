/*
 * record.cpp
 *
 *  Created on: Jun 4, 2018
 *      Author: mchen
 */

#include "flag.h"
#include "record.h"
#include "util.h"
#include <iostream>
#include <vector>

using namespace std;

Record::Record(const std::string &s_rec) : s_rec_(s_rec)
{
  // std::cout << s_rec_ << std::endl;
  parse_record();
}

void Record::parse_record()
{
  vector<string> recs;
  Util::split_str(s_rec_.c_str(), '\t', recs);
//  for(auto it = recs.begin(); it != recs.end(); ++it)
//    cout << *it << " ";
//  cout << endl;

  string &flag = recs[0];
  if(Flag::isCtrlMark(flag) ) { // control records
    cout << "Control: ";
    for(auto it = recs.begin(); it != recs.end(); ++it)
      cout << *it << " ";
    cout << endl;
  }
  else {  // data records
    cout << "Data: ";
    for(auto it = recs.begin(); it != recs.end(); ++it)
      cout << *it << " ";
    cout << endl;

  }
}
