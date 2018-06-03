/*
 * main.cpp
 *
 *  Created on: May 23, 2018
 *      Author: mchen
 */

#include "log.h"
#include <iostream>

void usage()
{
  std::cout << "usage: tpm [log path]" << std::endl;
}

int main(int argc, char* argv[])
{
	std::cout << "tpm (cpp version)" << std::endl;

	if(argc != 2) {
	  usage();
	  return -1;
	}

	Log log(argv[1]);
	if(log.is_open() )
	{
	  std::string rec;
	  unsigned long long rec_cnt = 0;

	  while(true) {
	    log.readline(rec);
	    if(log.is_eof() )
	      break;
	    std::cout << rec << std::endl;
	    rec_cnt++;
	  }
	  std::cout << "total recs: " << rec_cnt << std::endl;
	  log.close();
	}

	return 0;
}



