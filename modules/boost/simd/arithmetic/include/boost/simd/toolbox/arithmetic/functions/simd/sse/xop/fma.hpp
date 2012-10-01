//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_SIMD_SSE_XOP_FMA_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_SIMD_SSE_XOP_FMA_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_XOP_SUPPORT

#include <boost/simd/toolbox/arithmetic/functions/fma.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::fma_, boost::simd::tag::xop_,
                      (A0),
                      ((simd_<int16_<A0>,boost::simd::tag::sse_>))
                      ((simd_<int16_<A0>,boost::simd::tag::sse_>))
                      ((simd_<int16_<A0>,boost::simd::tag::sse_>))
                     )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(3)
    {
      return _mm_macc_epi16(a0, a1, a2);
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::fma_, boost::simd::tag::xop_,
                      (A0),
                      ((simd_<int32_<A0>,boost::simd::tag::sse_>))
                      ((simd_<int32_<A0>,boost::simd::tag::sse_>))
                      ((simd_<int32_<A0>,boost::simd::tag::sse_>))
                     )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(3)
    {
      return _mm_macc_epi32(a0, a1, a2);
    }
  };

} } }

#endif
#endif
