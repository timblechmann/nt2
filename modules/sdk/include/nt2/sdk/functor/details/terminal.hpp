/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_FUNCTOR_DETAILS_TERMINAL_HPP_INCLUDED
#define NT2_SDK_FUNCTOR_DETAILS_TERMINAL_HPP_INCLUDED

namespace nt2
{
  //////////////////////////////////////////////////////////////////////////////
  // Special functor for handling terminal in expression AST evaluation
  //////////////////////////////////////////////////////////////////////////////
  template<class Site> struct functor<tag::terminal_,Site>
  {
    template<class Sig> struct result;

    #define M0(z,n,t)                                                             \
    template<class This, BOOST_PP_ENUM_PARAMS(n,class A) >                        \
    struct result<This(BOOST_PP_ENUM_PARAMS(n,A))>                                \
    {                                                                             \
      typedef typename meta::                                                     \
      dispatch_call<tag::terminal_(BOOST_PP_ENUM_PARAMS(n,A)),Site>::type callee; \
      typedef typename                                                            \
      std::tr1::result_of<callee(BOOST_PP_ENUM_PARAMS(n,A))>::type  type;         \
    };                                                                            \
                                                                                  \
    template<BOOST_PP_ENUM_PARAMS(n,class A)> inline                              \
    typename meta::                                                               \
    enable_call<tag::terminal_(BOOST_PP_ENUM_PARAMS(n,A)),Site>::type             \
    operator()( BOOST_PP_ENUM_BINARY_PARAMS(n,A,& a)  ) const                     \
    {                                                                             \
      typename meta::                                                             \
      dispatch_call<tag::terminal_(BOOST_PP_ENUM_PARAMS(n,A)),Site>::type callee; \
      return callee( BOOST_PP_ENUM_PARAMS(n,a) );                                 \
    }                                                                             \
    /**/

    BOOST_PP_REPEAT_FROM_TO(1,4,M0,~)

    #undef M0
	};
}

#endif
