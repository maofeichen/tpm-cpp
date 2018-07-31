/*
 * main.cpp
 *
 *  Created on: May 23, 2018
 *      Author: mchen
 */

#include "log.h"
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
	string rec;
	u64 rec_cnt = 0;

	while(log.readline(rec)) {
	  cout << rec << endl;
	  rec_cnt++;
	}
	cout << "total records: " << rec_cnt << endl;

	log.close();

	return 0;
}
