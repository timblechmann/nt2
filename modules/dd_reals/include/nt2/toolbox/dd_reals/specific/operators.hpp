/*******************************************************************************
 *         Copyright 2003-2011 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_TOOLBOX_DD_REALS_SPECIFIC_OPERATORS_HPP_INCLUDED
#define NT2_TOOLBOX_DD_REALS_SPECIFIC_OPERATORS_HPP_INCLUDED

#define NT2_MAKE_DD_REALS_OP(TAG,OP)					\
  template<class T> inline						\
  typename nt2::meta::enable_call<TAG(dd_reals<T>,dd_reals<T>)>::type	\
  OP(dd_reals<T> const& a0, dd_reals<T> const& a1)			\
  {                                                                     \
    nt2::functor<TAG> callee;                                           \
    return callee(a0,a1);                                               \
  }                                                                     \
  template<class T> inline						\
  typename nt2::meta::enable_call<TAG(T,dd_reals<T>)>::type		\
  OP(T const& a0, dd_reals<T> const& a1)				\
  {                                                                     \
    nt2::functor<TAG> callee;                                           \
    return callee(a0,a1);                                               \
  }                                                                     \
  template<class T> inline						\
  typename nt2::meta::enable_call<TAG(dd_reals<T>,T)>::type		\
  OP(dd_reals<T> const& a0, T const& a1)				\
  {                                                                     \
    nt2::functor<TAG> callee;                                           \
    return callee(a0,a1);                                               \
  }                                                                     \
/**/

namespace nt2 { 
  NT2_MAKE_DD_REALS_OP( tag::bitwise_and_     , operator&  )
  NT2_MAKE_DD_REALS_OP( tag::bitwise_or_      , operator|  )
  NT2_MAKE_DD_REALS_OP( tag::bitwise_xor_     , operator^  )
  NT2_MAKE_DD_REALS_OP( tag::logical_and_     , operator&& )
  NT2_MAKE_DD_REALS_OP( tag::logical_or_      , operator|| )
  NT2_MAKE_DD_REALS_OP( tag::plus_            , operator+  )
  NT2_MAKE_DD_REALS_OP( tag::minus_           , operator-  )
  NT2_MAKE_DD_REALS_OP( tag::divides_         , operator/  )
  NT2_MAKE_DD_REALS_OP( tag::multiplies_      , operator*  )
//   NT2_MAKE_DD_REALS_OP( tag::modulo_          , operator%  )
//   NT2_MAKE_DD_REALS_OP( tag::shift_left_      , operator<< )
//   NT2_MAKE_DD_REALS_OP( tag::shift_right_     , operator>> )
} 

#undef NT2_MAKE_DD_REALS_OP


#endif

// /////////////////////////////////////////////////////////////////////////////
// End of operators.hpp<2>
// /////////////////////////////////////////////////////////////////////////////
