/*
 * log.h
 *
 *  Created on: May 24, 2018
 *      Author: mchen
 */

#ifndef LOG_H_
#define LOG_H_

#include <fstream>
#include <string>

class Log{
public:
  Log(std::string logpath)
    : logpath_(logpath), linecnt_(0), log_(logpath.c_str() ) {}

  void close();
  void readline(std::string &line); // Reads one line of the log.
  bool is_eof();    // is end of the log file
  bool is_open();   // is the log open

private:
  unsigned long long  linecnt_;
  std::ifstream       log_;
  std::string         logpath_;

  // Opens the log and prints line by line. For testing.
  void read();
};

#endif /* LOG_H_ */
