/* clang-format off */
/* ===-- fixunssfsi.c - Implement __fixunssfsi -----------------------------===
 *
 *                     The LLVM Compiler Infrastructure
 *
 * This file is dual licensed under the MIT and the University of Illinois Open
 * Source Licenses. See LICENSE.TXT for details.
 *
 * ===----------------------------------------------------------------------===
 *
 * This file implements __fixunssfsi for the compiler_rt library.
 *
 * ===----------------------------------------------------------------------===
 */

__static_yoink("huge_compiler_rt_license");

#define SINGLE_PRECISION
#include "third_party/compiler_rt/fp_lib.inc"
typedef su_int fixuint_t;
#include "third_party/compiler_rt/fp_fixuint_impl.inc"

COMPILER_RT_ABI su_int
__fixunssfsi(fp_t a) {
    return __fixuint(a);
}

#if defined(__ARM_EABI__)
#if defined(COMPILER_RT_ARMHF_TARGET)
AEABI_RTABI su_int __aeabi_f2uiz(fp_t a) {
  return __fixunssfsi(a);
}
#else
AEABI_RTABI su_int __aeabi_f2uiz(fp_t a) COMPILER_RT_ALIAS(__fixunssfsi);
#endif
#endif
