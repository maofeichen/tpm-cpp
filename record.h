/*
 * record.h
 *
 *  Created on: Jun 4, 2018
 *      Author: mchen
 */

#ifndef RECORD_H_
#define RECORD_H_

#include "type.h"
#include <string>

class Record{
public:
  Record(std::string s_rec);
  u8  get_flag() { return flag_; }

private:
  u8  flag_;
  u32 s_addr_;
  u32 s_val_;
  u32 d_addr_;
  u32 d_val_;
  u8  bytesz_;
  u64 ts_;  // time stamp (seq No.)
  bool is_ld_;      // load
  bool is_ld_ptr_;  // load pointer
  bool is_st_;      // store
  bool is_st_ptr_;  // store pointer

  void  analyze_record();
};

#endif /* RECORD_H_ */
