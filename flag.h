/*
 * flag.h
 *
 *  Created on: Sep 5, 2018
 *      Author: mchen
 */

#ifndef FLAG_H_
#define FLAG_H_
#include <string>

/* All XRay Taint record flags define here */

/* Mark */
const std::string INSN_MARK             = "32";

const std::string CALL_INSN             = "14";
const std::string CALL_INSN_SEC         = "15";
const std::string CALL_INSN_FF2         = "1a";
const std::string CALL_INSN_FF2_SEC     = "1b";

const std::string RET_INSN              = "18";
const std::string RET_INSN_SEC          = "19";

const unsigned int GROUP_START          = 100;
const unsigned int GROUP_MIDDLE         = 101;
const unsigned int GROUP_END            = 102;

/* Qemu IR */

const std::string TCG_QEMU_LD           = "52";
const std::string TCG_QEMU_LD_POINTER   = "56";
const std::string TCG_QEMU_ST           = "5a";
const std::string TCG_QEMU_ST_POINTER   = "5e";

// const std::string TCG_ADD              = "3b";
// const std::string TCG_XOR              = "47";
// const std::string TCG_DEPOSIT          = "4a";

/* as hex */
const unsigned int TCG_SHL_i32          = 0x36;
const unsigned int TCG_SHR_i32          = 0x37;
const unsigned int TCG_SAR_i32          = 0x38;
const unsigned int TCG_ROTL_i32         = 0x39;
const unsigned int TCG_ROTR_i32         = 0x3a;

const unsigned int TCG_ADD_i32          = 0x3b;
const unsigned int TCG_SUB_i32          = 0x3c;
const unsigned int TCG_MUL_i32          = 0x3d;
const unsigned int TCG_DIV_i32          = 0x3e;
const unsigned int TCG_DIVU_i32         = 0x3f;
const unsigned int TCG_REM_i32          = 0x40;
const unsigned int TCG_REMU_i32         = 0x41;
const unsigned int TCG_MUL2_i32         = 0x42;
const unsigned int TCG_DIV2_i32         = 0x43;
const unsigned int TCG_DIVU2_i32        = 0x44;

const unsigned int TCG_AND_i32          = 0x45;
const unsigned int TCG_OR_i32           = 0x46;
const unsigned int TCG_XOR_i32          = 0x47;
const unsigned int TCG_NOT_i32          = 0x48;
const unsigned int TCG_NEG_i32          = 0x49;

const unsigned int TCG_EXT8S_i32        = 0x4a;
const unsigned int TCG_EXT16S_i32       = 0x4b;
const unsigned int TCG_EXT8U_i32        = 0x4c;
const unsigned int TCG_EXT16U_i32       = 0x4d;
const unsigned int TCG_BSWAP16_i32      = 0x4e;
const unsigned int TCG_BSWAP32_i32      = 0x4f;

const unsigned int TCG_DEPOSIT_i32      = 0x50;
const unsigned int TCG_MOV_i32          = 0x51;

const unsigned int TCG_LD_i32           = 0x52;
const unsigned int TCG_LD_POINTER_i32   = 0x56;
const unsigned int TCG_ST_i32           = 0x5a;
const unsigned int TCG_ST_POINTER_i32   = 0x5e;

const unsigned int TCG_SETCOND_i32      = 0x62;

const unsigned int TCG_LD_MIN           = 0x52;
const unsigned int TCG_ST_MAX           = 0x61;

/* Qemu reg (global) temp */
const unsigned int G_TEMP_UNKNOWN       = 0xfff0;
const unsigned int G_TEMP_ENV           = 0xfff1;
const unsigned int G_TEMP_CC_OP         = 0xfff2;
const unsigned int G_TEMP_CC_SRC        = 0xfff3;
const unsigned int G_TEMP_CC_DST        = 0xfff4;
const unsigned int G_TEMP_CC_TMP        = 0xfff5;
const unsigned int G_TEMP_EAX           = 0xfff6;
const unsigned int G_TEMP_ECX           = 0xfff7;
const unsigned int G_TEMP_EDX           = 0xfff8;
const unsigned int G_TEMP_EBX           = 0xfff9;
const unsigned int G_TEMP_ESP           = 0xfffa;
const unsigned int G_TEMP_EBP           = 0xfffb;
const unsigned int G_TEMP_ESI           = 0xfffc;
const unsigned int G_TEMP_EDI           = 0xfffd;

class Flag{
public:
  static bool isCtrlMark(const std::string flag);
  static bool isRecordMark(const std::string flag, const std::string mark);
};

#endif /* FLAG_H_ */
