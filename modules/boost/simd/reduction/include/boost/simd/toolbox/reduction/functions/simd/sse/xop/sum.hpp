//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_REDUCTION_FUNCTIONS_SIMD_SSE_XOP_SUM_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_REDUCTION_FUNCTIONS_SIMD_SSE_XOP_SUM_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_XOP_SUPPORT

#include <boost/simd/toolbox/reduction/functions/sum.hpp>
#include <boost/simd/toolbox/reduction/functions/first.hpp>
#include <boost/simd/toolbox/reduction/functions/second.hpp>

namespace boost { namespace simd { namespace ext
{

#define BOOST_SIMD_XOP_SUM(TYPE, INTRIN)                        \
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::sum_,     \
                                    boost::simd::tag::xop_,     \
                                    (A0),                       \
    ((simd_<BOOST_PP_CAT(TYPE, _)<A0>,boost::simd::tag::sse_>)) \
                                    )                           \
  {                                                             \
    typedef int64_t                 result_type;                \
    inline result_type operator()(__m128i a0) const             \
      {                                                         \
        typedef native<result_type, tag::sse_> type64;          \
        type64 tmp = INTRIN(a0);                                \
        return sum(tmp);                                        \
      }                                                         \
  }                                                             \
    /**/

  BOOST_SIMD_XOP_SUM(int8, _mm_haddq_epi8); 
  BOOST_SIMD_XOP_SUM(int16, _mm_haddq_epi16);   
  BOOST_SIMD_XOP_SUM(int32, _mm_haddq_epi32);
#undef BOOST_SIMD_XOP_SUM

#define BOOST_SIMD_XOP_SUM(TYPE, INTRIN)                        \
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::sum_,     \
                                    boost::simd::tag::xop_,     \
                                    (A0),                       \
    ((simd_<BOOST_PP_CAT(TYPE, _)<A0>,boost::simd::tag::sse_>)) \
                                    )                           \
  {                                                             \
    typedef uint64_t                 result_type;                \
    inline result_type operator()(__m128i a0) const             \
      {                                                         \
        typedef native<result_type, tag::sse_> type64;          \
        type64 tmp = INTRIN(a0);                                \
        return sum(tmp);                                        \
      }                                                         \
  }                                                             \
  
  BOOST_SIMD_XOP_SUM(uint8, _mm_haddq_epu8); 
  BOOST_SIMD_XOP_SUM(uint16, _mm_haddq_epu16);   
  BOOST_SIMD_XOP_SUM(uint32, _mm_haddq_epu32);

#undef BOOST_SIMD_XOP_SUM
  
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::sum_,     
                                    boost::simd::tag::xop_,     
                                    (A0),                       
                ((simd_<ints64_<A0>,boost::simd::tag::sse_>)) 
                                    )                           
  {                                                             
    typedef A0                 result_type;                
                                                                
    inline result_type operator()(const A0 & a0) const             
      {                                                         
        return first(a0)+second(a0);                                        
      }                                                         
  };                                                             

} } }
#endif
#endif
