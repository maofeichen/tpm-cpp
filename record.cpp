/*
 * record.cpp
 *
 *  Created on: Jun 4, 2018
 *      Author: mchen
 */

#include "flag.h"
#include "record.h"
#include "util.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

// Public ----- ----- ----- ----- ----- ----- ----- ----- ----- -----
Record::Record(const std::string &s_rec) : s_rec_(s_rec)
{
  // std::cout << s_rec_ << std::endl;
  isCtrlRec_ = false;
  flag_   = 0;
  s_addr_ = 0;
  s_val_  = 0;
  d_addr_ = 0;
  d_val_  = 0;
  bytesz_ = 0;
  ts_     = 0;
  group_mark_ = 0;

  parse_record();
}

bool Record::isCtrlRecord()
{
  return isCtrlRec_;
}

void Record::print_record()
{
  cout << "flag:0x"     << hex     << (unsigned)flag_
       << " saddr:0x"   << s_addr_ << " sval:"  << s_val_
       << " daddr:0x"   << d_addr_ << " dval:"  << d_val_
       << " bytesz:"  << dec     << (unsigned)bytesz_   << " ts:"    << ts_
       << " group mark:" << (unsigned)group_mark_ <<  endl;
}

// Private ----- ----- ----- ----- ----- ----- ----- ----- ----- -----
void Record::parse_record()
{
  vector<string> recs;
  Util::split_str(s_rec_.c_str(), '\t', recs);
//  for(auto it = recs.begin(); it != recs.end(); ++it)
//    cout << *it << " ";
//  cout << endl;

  string &flag = recs[0];
  if(Flag::isCtrlMark(flag) ) { // control records, skip parsing
//    cout << "Control: ";
//    for(auto it = recs.begin(); it != recs.end(); ++it)
//      cout << *it << " ";
//    cout << endl;
    isCtrlRec_ = true;
  }
  else {  // data records
//    cout << "Data: ";
//    for(auto it = recs.begin(); it != recs.end(); ++it)
//      cout << *it << " ";
//    cout << endl;
    if(Flag::isRecordMark(flag, TCG_QEMU_LD) ) {
//      parse_mem_load(recs);
    }
    else if(Flag::isRecordMark(flag, TCG_QEMU_LD_POINTER) ||
            Flag::isRecordMark(flag, TCG_QEMU_ST) ||
            Flag::isRecordMark(flag, TCG_QEMU_ST_POINTER) ) {
      parse_mem(recs);
    }
    else {
      parse_non_mem(recs);
    }
  }
}

// Parses the memory load record. The specialty is it might contain a group mark,
//   indicates it's split into 1 byte from 4-byte record.
void Record::parse_mem_load(std::vector<std::string> &recs)
{
  flag_   = strtoul(recs[0].c_str(), NULL, 16);
  s_addr_ = strtoul(recs[1].c_str(), NULL, 16);
  s_val_  = strtoul(recs[2].c_str(), NULL, 16);
  d_addr_ = strtoul(recs[4].c_str(), NULL, 16);
  d_val_  = strtoul(recs[5].c_str(), NULL, 16);
  bytesz_ = strtoul(recs[6].c_str(), NULL, 16) / 8;

  u32 ts  = strtoul(recs[8].c_str(), NULL, 10);
  if(ts > 0){ // contains group mark
    group_mark_ = (u8)strtoul(recs[7].c_str(), NULL, 10);
    ts_         = ts;
  }
  else
    ts_     = strtoul(recs[7].c_str(), NULL, 10);
}

void Record::parse_mem(std::vector<std::string> &recs)
{
  flag_   = strtoul(recs[0].c_str(), NULL, 16);
  s_addr_ = strtoul(recs[1].c_str(), NULL, 16);
  s_val_  = strtoul(recs[2].c_str(), NULL, 16);
  d_addr_ = strtoul(recs[4].c_str(), NULL, 16);
  d_val_  = strtoul(recs[5].c_str(), NULL, 16);
  bytesz_ = strtoul(recs[6].c_str(), NULL, 16) / 8;
  ts_     = strtoul(recs[7].c_str(), NULL, 10);
}

void Record::parse_non_mem(std::vector<std::string> &recs)
{
  flag_   = strtoul(recs[0].c_str(), NULL, 16);
  s_addr_ = strtoul(recs[1].c_str(), NULL, 16);
  s_val_  = strtoul(recs[2].c_str(), NULL, 16);
  d_addr_ = strtoul(recs[4].c_str(), NULL, 16);
  d_val_  = strtoul(recs[5].c_str(), NULL, 16);
  bytesz_ = 0;
  ts_     = strtoul(recs[6].c_str(), NULL, 10);
}
