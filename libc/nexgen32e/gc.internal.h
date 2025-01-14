#ifndef COSMOPOLITAN_LIBC_NEXGEN32E_GC_INTERNAL_H_
#define COSMOPOLITAN_LIBC_NEXGEN32E_GC_INTERNAL_H_
#include "libc/nexgen32e/stackframe.h"
#if !(__ASSEMBLER__ + __LINKER__ + 0)
COSMOPOLITAN_C_START_

struct Garbage {
  struct StackFrame *frame;
  intptr_t fn;
  intptr_t arg;
  intptr_t ret;
};

struct Garbages {
  int i, n;
  struct Garbage *p;
};

int64_t __gc(void);

COSMOPOLITAN_C_END_
#endif /* !(__ASSEMBLER__ + __LINKER__ + 0) */
#endif /* COSMOPOLITAN_LIBC_NEXGEN32E_GC_INTERNAL_H_ */
