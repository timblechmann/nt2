//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_SSE_XOP_SHIFT_RIGHT_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_SSE_XOP_SHIFT_RIGHT_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_XOP_SUPPORT

#include <boost/simd/toolbox/operator/functions/shift_right.hpp>
#include <boost/simd/include/functions/simd/bitwise_cast.hpp>
#include <boost/simd/include/functions/simd/unary_minus.hpp>
#include <boost/simd/include/functions/simd/genmask.hpp>
#include <boost/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd { namespace ext
{
#define BOOST_SIMD_XOP_SHIFT_RIGHT(TYPE_TAG, INTRIN)                    \
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::shift_right_,    \
    boost::simd::tag::xop_                                              \
 , (A0)(A1)                                                             \
 , ((simd_<TYPE_TAG<A0>,boost::simd::tag::sse_>))                       \
   ((simd_<integer_<A1>,boost::simd::tag::sse_>))                       \
   )                                                                    \
  {                                                                     \
    typedef A0 result_type;                                             \
    inline result_type operator()(A0 const& a0,A1 const& a1) const      \
      {                                                                 \
        typedef typename dispatch::meta::as_integer<A0>::type sitype;   \
        return INTRIN(a0, unary_minus(bitwise_cast<sitype>(a1)));        \
      }                                                                 \
  }                                                                     \
    /**/
  
  BOOST_SIMD_XOP_SHIFT_RIGHT(ints8_  , _mm_shl_epi8); 
  BOOST_SIMD_XOP_SHIFT_RIGHT(ints16_ , _mm_shl_epi16); 
  BOOST_SIMD_XOP_SHIFT_RIGHT(ints32_ , _mm_shl_epi32); 
  BOOST_SIMD_XOP_SHIFT_RIGHT(ints64_ , _mm_shl_epi64); 
  

#undef BOOST_SIMD_XOP_SHIFT_RIGHT

     BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::shift_right_, boost::simd::tag::xop_    
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
      btype r0 = shift_right(a00, a10); 
      btype r1 = shift_right(a01, a11); 
      __m256i r = _mm256_castsi128_si256(r0);
      return _mm256_insertf128_si256(r, r1, 1);      
    }                                                                 
  };
  
} } }

#endif
#endif
