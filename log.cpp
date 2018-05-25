/*
 * log.c
 *
 *  Created on: May 24, 2018
 *      Author: mchen
 */
#include "log.h"
#include <iostream>

Log::Log(std::string log_path)
{
    log_path_ = log_path;
}

void Log::read_log()
{
  std::cout << "log: " << log_path_ << std::endl;
}
