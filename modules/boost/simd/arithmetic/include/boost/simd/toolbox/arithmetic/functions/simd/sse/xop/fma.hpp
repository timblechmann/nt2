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

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::fma_, boost::simd::tag::xop_    
                                    , (A0)                                           
                                    , ((simd_<integer_<A0>,boost::simd::tag::xop_>)) 
                                    ((simd_<integer_<A0>,boost::simd::tag::xop_>))   
                                    ((simd_<integer_<A0>,boost::simd::tag::xop_>))   
                                    )                                                
  {                                                                     
    typedef A0 result_type;            
    typedef typename meta::retarget<A0,simd::tag::sse_>::type          htype;
    typedef typename meta::retarget<result_type,simd::tag::sse_>::type btype;
    result_type operator()(__m256i const a0, __m256i const a1, __m256i const a2) const    
    {
      htype a00 = _mm256_extractf128_si256(a0, 0);
      htype a01 = _mm256_extractf128_si256(a0, 1);
      htype a10 = _mm256_extractf128_si256(a1, 0);
      htype a11 = _mm256_extractf128_si256(a1, 1);
      htype a20 = _mm256_extractf128_si256(a2, 0);
      htype a21 = _mm256_extractf128_si256(a2, 1);
      btype r0 = fma(a00, a10, a20); 
      btype r1 = fma(a01, a11, a21); 
      __m256i r = _mm256_castsi128_si256(r0);
      return _mm256_insertf128_si256(r, r1, 1);      
    }                                                                 
  };
  
} } }

#endif
#endif
