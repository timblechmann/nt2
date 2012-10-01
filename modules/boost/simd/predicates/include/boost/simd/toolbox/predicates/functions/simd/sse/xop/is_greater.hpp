//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTIONS_SIMD_SSE_XOP_IS_GREATER_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTIONS_SIMD_SSE_XOP_IS_GREATER_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_XOP_SUPPORT

#include <boost/simd/toolbox/predicates/functions/is_greater.hpp>
#include <boost/simd/sdk/simd/logical.hpp>

namespace boost { namespace simd { namespace ext
{
#define NT2_XOP_COMP(TAG, TYPE_TAG, INTRIN)                             \
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(                                    \
                       boost::simd::tag::TAG, boost::simd::tag::xop_    \
                       , (A0)                                           \
                       , ((simd_<TYPE_TAG<A0>,boost::simd::tag::xop_>)) \
                       ((simd_<TYPE_TAG<A0>,boost::simd::tag::xop_>))   \
                       )                                                \
  {                                                                     \
    result_type operator()(__m256i const a0, __m256i const a1) const    \
      {                                                                 \
        return  INTRIN(a0,a1);                                          \
      }                                                                 \
  };                                                                    \
    /**/
  
  NT2_XOP_COMP(is_greater_, int8_, _mmcmpgt_epi8)
  NT2_XOP_COMP(is_greater_, int16_, _mmcmpgt_epi16)
  NT2_XOP_COMP(is_greater_, int32_, _mmcmpgt_epi32)
  NT2_XOP_COMP(is_greater_, int64_, _mmcmpgt_epi64)
  NT2_XOP_COMP(is_greater_, uint8_, _mmcmpgt_epu8)
  NT2_XOP_COMP(is_greater_, uint16_, _mmcmpgt_epu16)
  NT2_XOP_COMP(is_greater_, uint32_, _mmcmpgt_epu32)
  NT2_XOP_COMP(is_greater_, uint64_, _mmcmpgt_epu64)

#undef NT2_XOP_COMP
} } }

#endif
#endif
