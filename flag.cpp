/*
 * flag.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: mchen
 */

#include "flag.h"

using namespace std;

bool
Flag::isCtrlMark(const std::string flag)
{
  if(flag.compare(INSN_MARK) == 0 ||
      flag.compare(CALL_INSN) == 0 ||
      flag.compare(CALL_INSN_SEC) == 0 ||
      flag.compare(CALL_INSN_FF2) == 0 ||
      flag.compare(CALL_INSN_FF2_SEC) == 0 ||
      flag.compare(RET_INSN) == 0 ||
      flag.compare(RET_INSN_SEC) == 0)
    return true;
  else return false;
}

bool
Flag::isRecordMark(const std::string& flag, const std::string& mark)
{
  if(flag.compare(mark) == 0)
    return true;
  else
    return false;
}



