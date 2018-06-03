/*
 * log.h
 *
 *  Created on: May 24, 2018
 *      Author: mchen
 */

#ifndef LOG_H_
#define LOG_H_

#include <string>

class Log{
private:
  std::string         logpath_;
  unsigned long long  linecnt_;

public:
  Log(std::string logpath) : logpath_(logpath), linecnt_(0) {}

  void readlog();

  // Reads a record (one line) of the log.
  // Returns:
  //  normal: a record (one line), or
  //  end:    special if end of file or
  //  except: opening log error
  std::string read_record();
};

#endif /* LOG_H_ */
