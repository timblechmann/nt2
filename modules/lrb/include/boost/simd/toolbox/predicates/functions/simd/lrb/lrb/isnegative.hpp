//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTIONS_SIMD_LRB_LRB_IS_NEGATIVE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTIONS_SIMD_LRB_LRB_IS_NEGATIVE_HPP_INCLUDED
#include <boost/simd/include/functions/is_gez.hpp>
#include <boost/simd/include/constants/one.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::is_negative_, boost::simd::tag::lrb_,
                              (A0),
                              ((simd_<arithmetic_<A0>,boost::simd::tag::lrb_ >))
                             )
  {
    typedef typename meta::boolean<A0>::type result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(1)
    {
      return is_ltz(a0);
    }
  };

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is floating_
/////////////////////////////////////////////////////////////////////////////


  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::is_negative_, boost::simd::tag::lrb_,
                              (A0),
                              ((simd_<floating_<A0>,boost::simd::tag::lrb_>))
                             )
  {
    typedef typename meta::boolean<A0>::type result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(1)
    {
      typedef typename dispatch::meta::as_integer<A0, signed>::type type;
      return is_ltz(b_or(bitofsign(a0), One<A0>());
    }
  };
} } }
#endif
