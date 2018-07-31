/*
 * main.cpp
 *
 *  Created on: May 23, 2018
 *      Author: mchen
 */

#include "log.h"
#include "record.h"
#include "type.h"
#include <iostream>

using namespace std;

void usage()
{
  cout << "usage: tpm [log path]" << endl;
}

int main(int argc, char* argv[])
{
	cout << "tpm (cpp version)" << endl;

	if(argc != 2) {
	  usage();
	  return -1;
	}

	Log log(argv[1]);
	if(!log.is_open() )
	  return -1;

	// stage - opens log successfully
	string line;
	u64 lcnt = 0;

	while(log.readline(line)) {
	  // cout << line << endl;
	  Record rec(line);
	  lcnt++;
	}
	cout << "total records: " << lcnt << endl;

	log.close();

	return 0;
}
