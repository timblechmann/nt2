//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTIONS_SIMD_LRB_LRB_IS_EQZ_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTIONS_SIMD_LRB_LRB_IS_EQZ_HPP_INCLUDED
#include <boost/simd/include/constants/digits.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::is_eqz_, boost::simd::tag::lrb_,
                             (A0),
                             ((simd_<arithmetic_<A0>,boost::simd::tag::lrb_>))
                            )
  {
    typedef typename meta::boolean<A0>::type result_type;

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      return eq(a0,Zero<A0>());
    }

  };
    BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::is_eqz_, boost::simd::tag::lrb_,
                             (A0),
                             ((simd_<ints64_<A0>,boost::simd::tag::lrb_>))
                            )
  {
    typedef typename meta::boolean<A0>::type result_type;

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      typedef native<double,               boost::simd::tag::lrb_ >  vd;
      typedef native<boost::simd::int32_t, boost::simd::tag::lrb_ >  vi;
      vd tmp = {native_cast<vd>(_mm512_srl_pi(a0, One<vi>()))}; 
      return _mm512_vkand(_mm512_cmpeq_pd(native_cast<vd>(a0), Zero<vd>()),
              _mm512_cmpeq_pd(tmp, Zero<vd>()));
    }

  };
} } }

#endif
