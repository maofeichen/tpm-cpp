/*
 * log.c
 *
 *  Created on: May 24, 2018
 *      Author: mchen
 */
#include "log.h"
#include <iostream>
#include <string>

using namespace std;

// ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- -----
// public functions
// ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- -----
void Log::close()
{
  log_.close();
}

void Log::readline(string &line)
{
  getline(log_, line);
}

bool Log::is_eof()
{
  return log_.eof();
}

bool Log::is_open()
{
  if(log_.is_open() )
  {
    std::cout << "reading log: " << logpath_ << std::endl;
    return true;
  }
  else
  {
    cout << "error opening log: " << logpath_ << endl;
    return false;
  }
}

// ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- -----
// private functions
// ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- ----- -----
void Log::read()
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
