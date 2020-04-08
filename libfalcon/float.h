/* This File is Part of LibFalcon.

 * Copyright (c) 2018, Syed Nasim
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright notice, this
     list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.

   * Neither the name of LibFalcon nor the names of its
     contributors may be used to endorse or promote products derived from
     this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef _FLOAT_H
#define _FLOAT_H

#define DECIMAL_DIG      17
#define FLT_EVAL_METHOD  (-1)
#define FLT_RADIX        2
#define FLT_ROUNDS       (-1)

#define FLT_DECIMAL_DIG  9
#define FLT_DIG          6
#define FLT_EPSILON      0x1P-23F
#define FLT_HAS_SUBNORM  1
#define FLT_MANT_DIG     24
#define FLT_MAX          0x1.fffffeP127F
#define FLT_MAX_10_EXP   38
#define FLT_MAX_EXP      128
#define FLT_MIN          0x1P-126F
#define FLT_MIN_10_EXP   (-37)
#define FLT_MIN_EXP      (-125)
#define FLT_TRUE_MIN     0x1P-149F

#define DBL_DECIMAL_DIG  17
#define DBL_DIG          15
#define DBL_EPSILON      0x1P-52
#define DBL_HAS_SUBNORM  1
#define DBL_MANT_DIG     53
#define DBL_MAX          0x1.fffffffffffffP1023
#define DBL_MAX_10_EXP   308
#define DBL_MAX_EXP      1024
#define DBL_MIN          0x1P-1022
#define DBL_MIN_10_EXP   (-307)
#define DBL_MIN_EXP      (-1021)
#define DBL_TRUE_MIN     0x1P-1074

#define LDBL_DECIMAL_DIG DBL_DECIMAL_DIG
#define LDBL_DIG         DBL_DIG
#define LDBL_EPSILON     DBL_EPSILON
#define LDBL_HAS_SUBNORM DBL_HAS_SUBNORM
#define LDBL_MANT_DIG    DBL_MANT_DIG
#define LDBL_MAX         DBL_MAX
#define LDBL_MAX_10_EXP  DBL_MAX_10_EXP
#define LDBL_MAX_EXP     DBL_MAX_EXP
#define LDBL_MIN         DBL_MIN
#define LDBL_MIN_10_EXP  DBL_MIN_10_EXP
#define LDBL_MIN_EXP     DBL_MIN_EXP
#define LDBL_TRUE_MIN    DBL_TRUE_MIN

#endif
