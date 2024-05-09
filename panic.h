#ifndef PANIC_H_
#define PANIC_H_
#include <stdio.h>
#include <stdlib.h>

typedef enum {
  WIN_INIT_FAIL = 100,
} panic_codes;

#define CLRSTR(STR,CLR) "\033[38;5;" #CLR "m" STR "\033[32;0m"
#define C2STR(C) ""#C""
#define PANIC_WITH(C)                                      \
  do {                                                     \
    fprintf(stderr, CLRSTR("[PANIC]", 160)" %s() :: %s\n", \
            __func__, C2STR(C));                           \
    exit(C);                                               \
  } while(0)                                               \

#endif //PANIC_H_
