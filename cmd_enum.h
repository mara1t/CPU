#define DEF_CMD(name, num, ...)\
    CMD_##name = num ,

enum COMANDS {
    #include "cmd_def.h"
};

#undef DEF_CMD

enum REGISTER {
    RAX = 0,
    RBX = 1,
    RCX = 2,
    RDX = 3
};

/*CMD_PUSH     =  1,
    CMD_POP      =  3,
    CMD_OUT      =  5,
    CMD_ADD      =  6,
    CMD_SUB      =  4,
    CMD_MUL      =  2,
    CMD_DIV      =  7,
    CMD_SQRT     =  8,
    CMD_HLT      = -1,
    CMD_IN       =  9,
    CMD_MINUS    = 10,
    CMD_REGPUSH  = 11,
    CMD_MOV      = 12,
    CMD_ZERO_POP = 13,
    CMD_JMP      = 14,
    CMD_JA       = 15,
    CMD_JAE      = 16,
    CMD_JB       = 17,
    CMD_JBE      = 18*/