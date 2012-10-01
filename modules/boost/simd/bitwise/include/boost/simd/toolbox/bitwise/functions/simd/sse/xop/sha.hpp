//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_SSE_XOP_SHA_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_SSE_XOP_SHA_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_XOP_SUPPORT

#include <boost/simd/include/functions/sha.hpp>
#include <boost/simd/include/functions/simd/bitwise_cast.hpp>
#include <boost/dispatch/meta/as_integer.hpp>

namespace boost { namespace simd { namespace ext
{
#define BOOST_SIMD_XOP_SHA(TYPE_TAG, INTRIN)                            \
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::sha_,            \
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
        return INTRIN(a0, unary_minus(bitwise_cast<sitype>(a1)));       \
      }                                                                 \
  }                                                                     \
    /**/
  
  BOOST_SIMD_XOP_SHA(ints8_  , _mm_sha_epi8); 
  BOOST_SIMD_XOP_SHA(ints16_ , _mm_sha_epi16); 
  BOOST_SIMD_XOP_SHA(ints32_ , _mm_sha_epi32); 
  BOOST_SIMD_XOP_SHA(ints64_ , _mm_sha_epi64); 
  

#undef BOOST_SIMD_XOP_SHA
} } }

#endif
#endif
