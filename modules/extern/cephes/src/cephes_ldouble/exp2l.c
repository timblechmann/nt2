/*							exp2l.c
 *
 *	Base 2 exponential function, long double precision
 *
 *
 *
 * SYNOPSIS:
 *
 * long double x, y, cephes_exp2l();
 *
 * y = cephes_exp2l( x );
 *
 *
 *
 * DESCRIPTION:
 *
 * Returns 2 raised to the x power.
 *
 * Range reduction is accomplished by separating the argument
 * into an integer k and fraction f such that
 *     x    k  f
 *    2  = 2  2.
 *
 * A Pade' form
 *
 *   1 + 2x P(x**2) / (Q(x**2) - x P(x**2) )
 *
 * approximates 2**x in the basic range [-0.5, 0.5].
 *
 *
 * ACCURACY:
 *
 *                      Relative error:
 * arithmetic   domain     # trials      peak         rms
 *    IEEE      +-16300     300000      9.1e-20     2.6e-20
 *
 *
 * See exp.c for comments on error amplification.
 *
 *
 * ERROR MESSAGES:
 *
 *   message         condition      value returned
 * exp2l underflow   x < -16382        0.0
 * exp2l overflow    x >= 16384       MAXNUM
 *
 */


/*
Cephes Math Library Release 2.7:  May, 1998
Copyright 1984, 1991, 1998 by Stephen L. Moshier
*/



#include "mconf.h"

#ifdef UNK
static long double P[] = {
 6.0614853552242266094567E1L,
 3.0286971917562792508623E4L,
 2.0803843631901852422887E6L,
};
static long double Q[] = {
/* 1.0000000000000000000000E0,*/
 1.7492876999891839021063E3L,
 3.2772515434906797273099E5L,
 6.0027204078348487957118E6L,
};
#endif


#ifdef IBMPC
static short P[] = {
0xffd8,0x6ad6,0x9c2b,0xf275,0x4004, XPD
0x3426,0x2dc5,0xf19f,0xec9d,0x400d, XPD
0x7ec0,0xd041,0x02e7,0xfdf4,0x4013, XPD
};
static short Q[] = {
/*0x0000,0x0000,0x0000,0x8000,0x3fff,*/
0x575b,0x9b93,0x34d6,0xdaa9,0x4009, XPD
0xe38d,0x6d74,0xa4f0,0xa005,0x4011, XPD
0xb37e,0xcfba,0x40d0,0xb730,0x4015, XPD
};
#endif

#ifdef MIEEE
static long P[] = {
0x40040000,0xf2759c2b,0x6ad6ffd8,
0x400d0000,0xec9df19f,0x2dc53426,
0x40130000,0xfdf402e7,0xd0417ec0,
};
static long Q[] = {
/*0x3fff0000,0x80000000,0x00000000,*/
0x40090000,0xdaa934d6,0x9b93575b,
0x40110000,0xa005a4f0,0x6d74e38d,
0x40150000,0xb73040d0,0xcfbab37e,
};
#endif

#define MAXL2L 16384.0L
#define MINL2L -16382.0L


extern long double MAXNUML;
#ifdef ANSIPROT
extern long double cephes_polevll ( long double, long double *, int );
extern long double cephes_p1evll ( long double, long double *, int );
extern long double cephes_floorl ( long double );
extern long double cephes_ldexpl ( long double, int );
extern int cephes_isnanl ( long double );
#else
long double cephes_polevll(), cephes_p1evll(), cephes_floorl(), cephes_ldexpl(), cephes_isnanl();
#endif
#ifdef INFINITIES
extern long double INFINITYL;
#endif

long double cephes_exp2l(x)
long double x;
{
long double px, xx;
int n;

#ifdef NANS
if( cephes_isnanl(x) )
	return(x);
#endif
if( x > MAXL2L)
	{
#ifdef INFINITIES
	return( INFINITYL );
#else
	cephes_mtherr( "exp2l", OVERFLOW );
	return( MAXNUML );
#endif
	}

if( x < MINL2L )
	{
#ifndef INFINITIES
	cephes_mtherr( "exp2l", UNDERFLOW );
#endif
	return(0.0L);
	}

xx = x;	/* save x */
/* separate into integer and fractional parts */
px = cephes_floorl(x+0.5L);
n = px;
x = x - px;

/* rational approximation
 * exp2(x) = 1.0 +  2xP(xx)/(Q(xx) - P(xx))
 * where xx = x**2
 */
xx = x * x;
px = x * cephes_polevll( xx, (long double*)P, 2 );
x =  px / ( cephes_p1evll( xx, (long double*)Q, 3 ) - px );
x = 1.0L + cephes_ldexpl( x, 1 );

/* scale by power of 2 */
x = cephes_ldexpl( x, n );
return(x);
}
