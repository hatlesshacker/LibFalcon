/* This File is Part of LibFalcon.

 * Copyright (c) 2020, Syed Nasim
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

#include <math.h>

static const float tiny = 1.0e-30;

float sqrtf(float x)
{
	float z;
	int32_t sign = (int)0x80000000;
	int32_t ix,s,q,m,t,i;
	uint32_t r;

	GET_FLOAT_WORD(ix, x);

	/* take care of Inf and NaN */
	if ((ix&0x7f800000) == 0x7f800000)
		return x*x + x; /* sqrt(NaN)=NaN, sqrt(+inf)=+inf, sqrt(-inf)=sNaN */

	/* take care of zero */
	if (ix <= 0) {
		if ((ix&~sign) == 0)
			return x;  /* sqrt(+-0) = +-0 */
		if (ix < 0)
			return (x-x)/(x-x);  /* sqrt(-ve) = sNaN */
	}
	/* normalize x */
	m = ix>>23;
	if (m == 0) {  /* subnormal x */
		for (i = 0; (ix&0x00800000) == 0; i++)
			ix<<=1;
		m -= i - 1;
	}
	m -= 127;  /* unbias exponent */
	ix = (ix&0x007fffff)|0x00800000;
	if (m&1)  /* odd m, double x to make it even */
		ix += ix;
	m >>= 1;  /* m = [m/2] */

	/* generate sqrt(x) bit by bit */
	ix += ix;
	q = s = 0;       /* q = sqrt(x) */
	r = 0x01000000;  /* r = moving bit from right to left */

	while (r != 0) {
		t = s + r;
		if (t <= ix) {
			s = t+r;
			ix -= t;
			q += r;
		}
		ix += ix;
		r >>= 1;
	}

	/* use floating add to find out rounding direction */
	if (ix != 0) {
		z = 1.0f - tiny; /* raise inexact flag */
		if (z >= 1.0f) {
			z = 1.0f + tiny;
			if (z > 1.0f)
				q += 2;
			else
				q += q & 1;
		}
	}
	ix = (q>>1) + 0x3f000000;
	ix += m << 23;
	SET_FLOAT_WORD(z, ix);
	return z;
}
