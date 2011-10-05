//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_LRB_LRB_MAKE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_LRB_LRB_MAKE_HPP_INCLUDED
#include <boost/simd/toolbox/operator/functions/make.hpp>
#include <boost/simd/toolbox/operator/functions/simd/details/make_helper.hpp>

//==============================================================================
// make for double
//==============================================================================
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::make_, boost::simd::tag::lrb_, (A0)
                            , ((target_< simd_< double_<A0>, boost::simd::tag::lrb_ > >))
                            )
  {
    BOOST_SIMD_MAKE_BODY(8)
    {
      result_type that = { _mm512_set_8to8_pd(a7, a6, a5, a4, a3, a2, a1, a0) };
      return that;
    }
  };
} } }

//==============================================================================
// make for 64bits integers
//==============================================================================
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::make_, boost::simd::tag::lrb_, (A0)
                            , ((target_< simd_< ints64_<A0>, boost::simd::tag::lrb_ > >))
                            )
  {
    BOOST_SIMD_MAKE_BODY(8)
    {
      result_type that = { _mm512_set_8to8_pq(a7, a6, a5, a4, a3, a2, a1, a0) };
      return that;
    }
  };
} } }

//==============================================================================
// make for float
//==============================================================================
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::make_, boost::simd::tag::lrb_, (A0)
                            , ((target_< simd_< single_<A0>, boost::simd::tag::lrb_ > >))
                            )
  {
    BOOST_SIMD_MAKE_BODY(16)
    {
      result_type that = { _mm512_set_16to16_ps(a15, a14, a13, a12, a11, a10, a9, a8,
                                                a7,  a6,  a5,  a4,  a3,  a2,  a1, a0) };
      return that;
    }
  };
} } }

//==============================================================================
// make for 32 bits integer
//==============================================================================
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::make_, boost::simd::tag::lrb_, (A0)
                            , ((target_< simd_< ints32_<A0>, boost::simd::tag::lrb_ > >))
                            )
  {
    BOOST_SIMD_MAKE_BODY(16)
    {
      result_type that = { _mm512_set_16to16_pi(a15, a14, a13, a12, a11, a10, a9, a8,
                  a7,  a6,  a5,  a4,  a3,  a2,  a1, a0) };
    }
  };
} } }

#endif

