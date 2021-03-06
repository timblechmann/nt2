/*
 *   This file was automatically generated by version 1.7 of cextract.
 *   Manual editing not recommended.
 *
 *   Created: Fri Feb 23 20:31:13 1996
 */
#ifdef ANSIC

#include <boost/config.hpp>

#ifdef NT2_EXTERN_CEPHES_DYN_LINK
#  ifdef NT2_EXTERN_CEPHES_SOURCE
#    define NT2_EXTERN_CEPHES_DECL BOOST_SYMBOL_EXPORT
#  else
#    define NT2_EXTERN_CEPHES_DECL BOOST_SYMBOL_IMPORT
#  endif
#else
#  define NT2_EXTERN_CEPHES_DECL
#endif

extern NT2_EXTERN_CEPHES_DECL float cephes_acosf ( float x );
extern NT2_EXTERN_CEPHES_DECL float cephes_acoshf ( float xx );
extern NT2_EXTERN_CEPHES_DECL int cephes_airyf ( float xx, float *ai, float *aip, float *bi, float *bip );
extern NT2_EXTERN_CEPHES_DECL float cephes_asinf ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_asinhf ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_atan2f ( float y, float x );
extern NT2_EXTERN_CEPHES_DECL float cephes_atanf ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_atanhf ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_bdtrcf ( int k, int n, float pp );
extern NT2_EXTERN_CEPHES_DECL float cephes_bdtrf ( int k, int n, float pp );
extern NT2_EXTERN_CEPHES_DECL float cephes_bdtrif ( int k, int n, float yy );
extern NT2_EXTERN_CEPHES_DECL float cephes_betaf ( float aa, float bb );
extern NT2_EXTERN_CEPHES_DECL float cephes_cabsf ( cmplxf *z );
extern NT2_EXTERN_CEPHES_DECL void cephes_cacosf ( cmplxf *z, cmplxf *w );
extern NT2_EXTERN_CEPHES_DECL void cephes_caddf ( cmplxf *a, cmplxf *b, cmplxf *c );
extern NT2_EXTERN_CEPHES_DECL void cephes_casinf ( cmplxf *z, cmplxf *w );
extern NT2_EXTERN_CEPHES_DECL void cephes_catanf ( cmplxf *z, cmplxf *w );
extern NT2_EXTERN_CEPHES_DECL float cephes_cbrtf ( float xx );
extern NT2_EXTERN_CEPHES_DECL void cephes_cchshf ( float xx, float *c, float *s );
extern NT2_EXTERN_CEPHES_DECL void cephes_ccosf ( cmplxf *z, cmplxf *w );
extern NT2_EXTERN_CEPHES_DECL void cephes_ccotf ( cmplxf *z, cmplxf *w );
extern NT2_EXTERN_CEPHES_DECL void cephes_cdivf ( cmplxf *a, cmplxf *b, cmplxf *c );
extern NT2_EXTERN_CEPHES_DECL float cephes_ceilf ( float x );
extern NT2_EXTERN_CEPHES_DECL void cephes_cexpf ( cmplxf *z, cmplxf *w );
extern NT2_EXTERN_CEPHES_DECL float cephes_chbevlf ( float x, float *array, int n );
extern NT2_EXTERN_CEPHES_DECL float cephes_chdtrcf ( float dff, float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_chdtrf ( float dff, float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_chdtrif ( float dff, float yy );
extern NT2_EXTERN_CEPHES_DECL void cephes_clogf ( cmplxf *z, cmplxf *w );
extern NT2_EXTERN_CEPHES_DECL void cephes_cmovf ( short *a, short *b );
extern NT2_EXTERN_CEPHES_DECL void cephes_cmulf ( cmplxf *a, cmplxf *b, cmplxf *c );
extern NT2_EXTERN_CEPHES_DECL void cephes_cnegf ( cmplxf *a );
extern NT2_EXTERN_CEPHES_DECL float cephes_cosdgf ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_cosf ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_coshf ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_cotdgf ( float x );
extern NT2_EXTERN_CEPHES_DECL float cephes_cotf ( float x );
extern NT2_EXTERN_CEPHES_DECL void cephes_csinf ( cmplxf *z, cmplxf *w );
extern NT2_EXTERN_CEPHES_DECL void cephes_csqrtf ( cmplxf *z, cmplxf *w );
extern NT2_EXTERN_CEPHES_DECL void cephes_csubf ( cmplxf *a, cmplxf *b, cmplxf *c );
extern NT2_EXTERN_CEPHES_DECL void cephes_ctanf ( cmplxf *z, cmplxf *w );
extern NT2_EXTERN_CEPHES_DECL float cephes_ctansf ( cmplxf *z );
extern NT2_EXTERN_CEPHES_DECL float cephes_dawsnf ( float xxx );
extern NT2_EXTERN_CEPHES_DECL int cephes_dprec ( void );
extern NT2_EXTERN_CEPHES_DECL float cephes_ellief ( float phia, float ma );
extern NT2_EXTERN_CEPHES_DECL float cephes_ellikf ( float phia, float ma );
extern NT2_EXTERN_CEPHES_DECL float cephes_ellpef ( float xx );
extern NT2_EXTERN_CEPHES_DECL int cephes_ellpjf ( float uu, float mm, float *sn, float *cn, float *dn, float *ph );
extern NT2_EXTERN_CEPHES_DECL float cephes_ellpkf ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_erfcf ( float aa );
extern NT2_EXTERN_CEPHES_DECL float cephes_erff ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_exp10f ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_exp2f ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_expf ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_expnf ( int n, float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_facf ( int i );
extern NT2_EXTERN_CEPHES_DECL float cephes_fdtrcf ( int ia, int ib, float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_fdtrf ( int ia, int ib, int xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_fdtrif ( int ia, int ib, float yy );
extern NT2_EXTERN_CEPHES_DECL float cephes_floorf ( float x );
extern NT2_EXTERN_CEPHES_DECL void cephes_fresnlf ( float xxa, float *ssa, float *cca );
extern NT2_EXTERN_CEPHES_DECL float cephes_frexpf ( float x, int *pw2 );
extern NT2_EXTERN_CEPHES_DECL float cephes_gammaf ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_gdtrcf ( float aa, float bb, float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_gdtrf ( float aa, float bb, float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_hyp2f0f ( float aa, float bb, float xx, int type, float *err );
extern NT2_EXTERN_CEPHES_DECL float cephes_hyp2f1f ( float aa, float bb, float cc, float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_hypergf ( float aa, float bb, float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_i0ef ( float x );
extern NT2_EXTERN_CEPHES_DECL float cephes_i0f ( float x );
extern NT2_EXTERN_CEPHES_DECL float cephes_i1ef ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_i1f ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_igamcf ( float aa, float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_igamf ( float aa, float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_igamif ( float aa, float yy0 );
extern NT2_EXTERN_CEPHES_DECL float cephes_incbetf ( float aaa, float bbb, float xxx );
extern NT2_EXTERN_CEPHES_DECL float cephes_incbif ( float aaa, float bbb, float yyy0 );
extern NT2_EXTERN_CEPHES_DECL float cephes_incbpsf ( float aa, float bb, float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_ivf ( float v, float x );
extern NT2_EXTERN_CEPHES_DECL float cephes_j0f ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_j1f ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_jnf ( int n, float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_jvf ( float nn, float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_k0ef ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_k0f ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_k1ef ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_k1f ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_knf ( int nnn, float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_ldexpf ( float x, int pw2 );
extern NT2_EXTERN_CEPHES_DECL int cephes_ldprec ( void );
extern NT2_EXTERN_CEPHES_DECL float cephes_lgamf ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_log10f ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_log2f ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_logf ( float xx );
extern NT2_EXTERN_CEPHES_DECL int cephes_mtherr ( char *name, int code );
extern NT2_EXTERN_CEPHES_DECL float cephes_nbdtrcf ( int k, int n, float pp );
extern NT2_EXTERN_CEPHES_DECL float cephes_nbdtrf ( int k, int n, float pp );
extern NT2_EXTERN_CEPHES_DECL float cephes_ndtrf ( float aa );
extern NT2_EXTERN_CEPHES_DECL float cephes_ndtrif ( float yy0 );
extern NT2_EXTERN_CEPHES_DECL float cephes_onef2f ( float aa, float bb, float cc, float xx, float *err );
extern NT2_EXTERN_CEPHES_DECL float cephes_p1evlf ( float xx, float *coef, int N );
extern NT2_EXTERN_CEPHES_DECL float cephes_pdtrcf ( int k, float mm );
extern NT2_EXTERN_CEPHES_DECL float cephes_pdtrf ( int k, float mm );
extern NT2_EXTERN_CEPHES_DECL float cephes_pdtrif ( int k, float yy );
extern NT2_EXTERN_CEPHES_DECL void cephes_poladdf ( float a[], int na, float b[], int nb, float c[] );
extern NT2_EXTERN_CEPHES_DECL void cephes_polclrf ( float *a, int n );
extern NT2_EXTERN_CEPHES_DECL int cephes_poldivf ( float a[], int na, float b[], int nb, float c[] );
extern NT2_EXTERN_CEPHES_DECL float cephes_polevaf ( float *a, int na, float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_polevlf ( float xx, float *coef, int N );
extern NT2_EXTERN_CEPHES_DECL void cephes_polinif ( int maxdeg );
extern NT2_EXTERN_CEPHES_DECL void cephes_polmovf ( float *a, int na, float *b );
extern NT2_EXTERN_CEPHES_DECL void cephes_polmulf ( float a[], int na, float b[], int nb, float c[] );
extern NT2_EXTERN_CEPHES_DECL void cephes_polprtf ( float *a, int na, int d );
extern NT2_EXTERN_CEPHES_DECL void cephes_polsbt ( float a[], int na, float b[], int nb, float c[] );
extern NT2_EXTERN_CEPHES_DECL void cephes_polsubf ( float a[], int na, float b[], int nb, float c[] );
extern NT2_EXTERN_CEPHES_DECL float cephes_powf ( float x, float y );
extern NT2_EXTERN_CEPHES_DECL float cephes_powif ( float x, int nn );
extern NT2_EXTERN_CEPHES_DECL float cephes_psif ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_redupif ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_rgammaf ( float xx );
extern NT2_EXTERN_CEPHES_DECL int cephes_shichif ( float xx, float *si, float *ci );
extern NT2_EXTERN_CEPHES_DECL int cephes_sicif ( float xx, float *si, float *ci );
extern NT2_EXTERN_CEPHES_DECL float cephes_sindgf ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_sinf ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_sinhf ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_spencef ( float xx );
extern NT2_EXTERN_CEPHES_DECL int cephes_sprec ( void );
extern NT2_EXTERN_CEPHES_DECL float cephes_sqrtf ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_stdtrf ( int k, float tt );
extern NT2_EXTERN_CEPHES_DECL float cephes_struvef ( float vv, float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_tandgf ( float x );
extern NT2_EXTERN_CEPHES_DECL float cephes_tanf ( float x );
extern NT2_EXTERN_CEPHES_DECL float cephes_tanhf ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_threef0f ( float aa, float bb, float cc, float xx, float *err );
extern NT2_EXTERN_CEPHES_DECL float cephes_y0f ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_y1f ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_ynf ( int nn, float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_yvf ( float vv, float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_zetacf ( float xx );
extern NT2_EXTERN_CEPHES_DECL float cephes_zetaf ( float xx, float qq );
#endif
