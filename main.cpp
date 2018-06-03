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
	std:: cout << "size of log object: " << sizeof(log) << std::endl;
	// log.readlog();

	return 0;
}



