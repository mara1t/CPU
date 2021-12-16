#define DEF_CMD(name, num, ...)\
    CMD_##name = num ,

#define DEF_JMP(name, num, ...)\
    CMD_##name = num ,

#define DEF_FUN(name, num, ...)\
    CMD_##name = num ,

enum COMANDS {
    #include "cmd_def.h"
};

#undef DEF_FUN
#undef DEF_CMD
#undef DEF_JMP

enum REGISTER {
    RAX = 0,
    RBX = 1,
    RCX = 2,
    RDX = 3
};
