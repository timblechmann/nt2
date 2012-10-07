//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTIONS_SIMD_SSE_XOP_IS_LESS_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTIONS_SIMD_SSE_XOP_IS_LESS_EQUAL_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_XOP_SUPPORT

#include <boost/simd/toolbox/predicates/functions/is_less_equal.hpp>
#include <boost/simd/sdk/simd/logical.hpp>
#include <boost/simd/sdk/meta/make_dependent.hpp>
#include <boost/simd/sdk/simd/meta/retarget.hpp>

namespace boost { namespace simd { namespace ext
{
#define NT2_XOP_COMP(TYPE_TAG, SUFFIX)                                  \
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(                                    \
            boost::simd::tag::is_less_equal_, boost::simd::tag::xop_    \
                       , (A0)                                           \
                       , ((simd_<TYPE_TAG<A0>,boost::simd::tag::sse_>)) \
                       ((simd_<TYPE_TAG<A0>,boost::simd::tag::sse_>))   \
                       )                                                \
  {                                                                     \
    typedef typename meta::as_logical<A0>::type result_type;            \
    result_type operator()(__m128i const a0, __m128i const a1) const    \
      {                                                                 \
        return  BOOST_PP_CAT(_mm_comle_ep, SUFFIX)(a0,a1);              \
      }                                                                 \
  };                                                                    \
    /**/
  
  NT2_XOP_COMP(int8_,   i8)
  NT2_XOP_COMP(int16_,  i16)
  NT2_XOP_COMP(int32_,  i32)
  NT2_XOP_COMP(int64_,  i64)
  NT2_XOP_COMP(uint8_,  u8)
  NT2_XOP_COMP(uint16_, u16)
  NT2_XOP_COMP(uint32_, u32)
  NT2_XOP_COMP(uint64_, u64)

#undef NT2_XOP_COMP

    BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::is_less_equal_, boost::simd::tag::xop_    
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
      btype r0 = is_less_equal(a00, a10); 
      btype r1 = is_less_equal(a01, a11); 
      __m256i r = _mm256_castsi128_si256(r0);
      return _mm256_insertf128_si256(r, r1, 1);      
    }                                                                 
  };                                                                    

} } }

#endif
#endif
