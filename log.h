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
  std::string log_path_;

public:
  Log(std::string log_path);

  void read_log();
};

#endif /* LOG_H_ */
