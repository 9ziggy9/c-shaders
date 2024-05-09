#include "panic.h"

int main(void) {
  PANIC_WITH(WIN_INIT_FAIL);
  return 0;
}
