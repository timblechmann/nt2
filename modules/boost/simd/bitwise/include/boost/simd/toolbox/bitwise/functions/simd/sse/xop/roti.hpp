//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_SSE_XOP_ROTI_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_SSE_XOP_ROTI_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_XOP_SUPPORT

#include <boost/simd/include/functions/roti.hpp>
#include <boost/simd/include/functions/simd/bitwise_cast.hpp>
#include <boost/simd/include/functions/simd/unary_minus.hpp>
#include <boost/simd/include/functions/simd/genmask.hpp>

namespace boost { namespace simd { namespace ext
{
#define BOOST_SIMD_XOP_ROTI(TYPE_TAG, SUFFIX)                           \
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::roti_,           \
    boost::simd::tag::xop_                                              \
 , (A0)(A1)                                                             \
 , ((simd_<TYPE_TAG<A0>,boost::simd::tag::sse_>))                       \
   ((scalar_<integer_<A1> >))                                           \
   )                                                                    \
  {                                                                     \
    typedef A0 result_type;                                             \
    inline result_type operator()(A0 const& a0,A1 const& a1) const      \
      {                                                                 \
        return BOOST_PP_CAT(_mm_rot_ep, SUFFIX)(a0, a1);                \
      }                                                                 \
  }                                                                     \
    /**/
  
  BOOST_SIMD_XOP_ROTI(ints8_  , i8); 
  BOOST_SIMD_XOP_ROTI(ints16_ , i16); 
  BOOST_SIMD_XOP_ROTI(ints32_ , i32); 
  BOOST_SIMD_XOP_ROTI(ints64_ , i64); 
  

#undef BOOST_SIMD_XOP_ROTI


    BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::roti_, boost::simd::tag::xop_    
                                      , (A0)                                           
                                      , ((simd_<integer_<A0>,boost::simd::tag::xop_>)) 
                                        ((scalar_<integer_<A1> >))      
                                      )                                                
  {                                                                     
    typedef typename meta::as_logical<A0>::type result_type;            
    typedef typename meta::retarget<A0,simd::tag::sse_>::type          htype;
    typedef typename meta::retarget<result_type,simd::tag::sse_>::type btype;
    result_type operator()(__m256i const a0, __m256i const a1) const    
    {
      htype a00 = _mm256_extractf128_si256(a0, 0);
      htype a10 = _mm256_extractf128_si256(a1, 0);  
      btype r0 = roti(a00, a1); 
      btype r1 = roti(a10, a1); 
      __m256i r = _mm256_castsi128_si256(r0);
      return _mm256_insertf128_si256(r, r1, 1);      
    }                                                                 
  };                                                                    


  
} } }

#endif
#endif
