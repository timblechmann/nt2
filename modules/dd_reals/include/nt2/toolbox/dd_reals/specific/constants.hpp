/*******************************************************************************
 *         Copyright 2003-2011 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_TOOLBOX_DD_REALS_SPECIFIC_CONSTANTS_HPP_INCLUDED
#define NT2_TOOLBOX_DD_REALS_SPECIFIC_CONSTANTS_HPP_INCLUDED

//#include <nt2/constant/constant.hpp>
#include <nt2/include/constants/real.hpp>

namespace nt2 { namespace tag
{
  struct dd_reals_thresh_   {};
  struct dd_reals_fac_      {};
  struct dd_reals_shift_    {};  
  struct dd_reals_mshift_   {};  
}  }

namespace nt2
{
  NT2_CONSTANT_IMPLEMENTATION(tag::dd_reals_thresh_       , Dd_Realsthresh   )
  NT2_CONSTANT_IMPLEMENTATION(tag::dd_reals_fac_          , Dd_Realsfac      )
  NT2_CONSTANT_IMPLEMENTATION(tag::dd_reals_shift_        , Dd_Realsshift    )   
  NT2_CONSTANT_IMPLEMENTATION(tag::dd_reals_mshift_       , Dd_Realsmshift    )   
}

NT2_CONSTANT_MAKE_REAL(tag::dd_reals_thresh_      , 0x7e2fffffffffffffll, 0x78800000)
// 6.69692879491417e+299 = 2^(1023-27),  2.076918743413931e+34f = 2^(127-13)
NT2_CONSTANT_MAKE_REAL(tag::dd_reals_fac_   , 0x41a0000002000000ll, 0x46000400)
// 134217729.0 = 2^27 + 1, 8193.0f = 2^13+1

#define LOCAL_CALL(TAG, SEL, VAL)					\
template<class Dummy>                                                       \
struct call< TAG(tag::target_<SEL>), tag::cpu_, Dummy>  : callable          \
{                                                                           \
  template<class Sig> struct result;                                        \
  template<class This, class A0>                                            \
  struct  result<This(A0)>                                                  \
        : meta::as_integer<typename meta::strip<A0>::type::type,signed> {}; \
  NT2_FUNCTOR_CALL(1)                                                       \
  {                                                                         \
    typedef typename  NT2_RETURN_TYPE(1)::type type;                        \
    return splat<type>(VAL);                                                \
  }                                                                         \
}                                                                           \
/**/
#define LOCAL_CONST(TAG, VD, VF)					\
  NT2_REGISTER_DISPATCH(TAG,tag::cpu_,(A0), (target_< double_<A0> > ) )	\
  NT2_REGISTER_DISPATCH(TAG,tag::cpu_,(A0), (target_< float_<A0>  > ) ) \
  namespace nt2 { namespace ext				  	        \
		    {							\
  LOCAL_CALL(TAG, tag::double_, VD);  LOCAL_CALL(TAG, tag::float_, VF); \
} }                                                                     \
/**/

LOCAL_CONST(tag::dd_reals_shift_,                  28,         14);
LOCAL_CONST(tag::dd_reals_mshift_,                -28,        -14);

#undef LOCAL_CONST
#undef LOCAL_CALL


#endif

// /////////////////////////////////////////////////////////////////////////////
// End of constants.hpp
// /////////////////////////////////////////////////////////////////////////////
