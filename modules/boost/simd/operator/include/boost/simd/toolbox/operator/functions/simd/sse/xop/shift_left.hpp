//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_SSE_XOP_SHIFT_LEFT_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_SSE_XOP_SHIFT_LEFT_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_XOP_SUPPORT

#include <boost/simd/toolbox/operator/functions/shift_left.hpp>
#include <boost/simd/include/functions/simd/bitwise_cast.hpp>
#include <boost/simd/include/functions/simd/genmask.hpp>

namespace boost { namespace simd { namespace ext
{
#define BOOST_SIMD_XOP_SHIFT_LEFT(TYPE_TAG, TYPE_WIDTH)                 \
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::shift_left_,     \
    boost::simd::tag::xop_                                              \
 , (A0)(A1)                                                             \
 , ((simd_<TYPE_TAG<A0>,boost::simd::tag::sse_>))                       \
   ((simd_<integer_<A1>,boost::simd::tag::sse_>))                       \
   )                                                                    \
  {                                                                     \
    typedef A0 result_type;                                             \
    inline result_type operator()(A0 const& a0,A1 const& a1) const      \
      {                                                                 \
        return _mm_shl_epi##TYPE_WIDTH(a0, a1);                         \
      }                                                                 \
  }                                                                     \
    /**/
  
  BOOST_SIMD_XOP_SHIFT_LEFT(ints8_ , 8); 
  BOOST_SIMD_XOP_SHIFT_LEFT(ints16_ , 16); 
  BOOST_SIMD_XOP_SHIFT_LEFT(ints32_ , 32); 
  BOOST_SIMD_XOP_SHIFT_LEFT(ints64_ , 64); 
  

#undef BOOST_SIMD_XOP_SHIFT_LEFT

    BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::shift_left_, boost::simd::tag::xop_    
                                      , (A0)                                           
                                      , ((simd_<integer_<A0>,boost::simd::tag::xop_>)) 
                                      ((simd_<integer_<A0>,boost::simd::tag::xop_>))   
                                      )                                                
  {                                                                     
    typedef typename meta::as_logical<A0>::type result_type;            
    typedef typename meta::retarget<A0,simd::tag::sse_>::type          htype;
    typedef typename meta::retarget<result_type,simd::tag::sse_>::type btype;
    result_type operator()(__m256i const a0, __m256i const a1) const    
    {
      htype a00 = _mm256_extractf128_si256(a0, 0);
      htype a01 = _mm256_extractf128_si256(a0, 1);
      htype a10 = _mm256_extractf128_si256(a1, 0);
      htype a11 = _mm256_extractf128_si256(a1, 1);
      btype r0 = shift_left(a00, a10); 
      btype r1 = shift_left(a01, a11); 
      __m256i r = _mm256_castsi128_si256(r0);
      return _mm256_insertf128_si256(r, r1, 1);      
    }                                                                 
  }; 
  
} } }

#endif
#endif
