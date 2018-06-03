/*
 * log.c
 *
 *  Created on: May 24, 2018
 *      Author: mchen
 */
#include "log.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void
Log::readlog()
{
  ifstream log(logpath_);
  if(log.is_open() )
  {
    std::cout << "reading log: " << logpath_ << std::endl;

    string rec;
    while(getline(log, rec) ) {
      cout << rec << endl;
      linecnt_++;
    }
    cout << "total lines: " << linecnt_ << endl;
    log.close();
  }
  else { cout << "error open log: " << logpath_ << endl; }
}
