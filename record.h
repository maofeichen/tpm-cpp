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
#include <vector>

class Record{
public:
  Record(const std::string &s_rec);

  u8    get_flag() { return flag_; }
  void  print_record();

private:
  const std::string &s_rec_;
  u8  flag_;
  u32 s_addr_;
  u32 s_val_;
  u32 d_addr_;
  u32 d_val_;
  u8  bytesz_;
  u64 ts_;  // time stamp (seq No.)
  u8  group_mark_;

  enum m_type {
    ld,     // load
    ld_ptr, // load pointer
    st,     // store
    st_ptr  // store pointer
  };
//  bool is_ld_;      // load
//  bool is_ld_ptr_;  // load pointer
//  bool is_st_;      // store
//  bool is_st_ptr_;  // store pointer

  void parse_record();
  void parse_mem_load(std::vector<std::string> &recs);
  void parse_mem(std::vector<std::string> &recs);
  void parse_non_mem(std::vector<std::string> &recs);
};

#endif /* RECORD_H_ */
