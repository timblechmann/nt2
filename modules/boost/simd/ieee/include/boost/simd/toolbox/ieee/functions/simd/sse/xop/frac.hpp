//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_IEEE_FUNCTIONS_SIMD_SSE_XOP_FRAC_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_IEEE_FUNCTIONS_SIMD_SSE_XOP_FRAC_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_XOP_SUPPORT

#include <boost/simd/toolbox/ieee/functions/frac.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::frac_, boost::simd::tag::xop_    
                                    , (A0)                                           
                                    , ((simd_<single_<A0>,boost::simd::tag::xop_>)) 
                                    ((simd_<single_<A0>,boost::simd::tag::xop_>))   
                       )                                                
  {                                                                     
    result_type operator()(__m256 const a0, __m256 const a1) const    
      {                                                                 
        return  _mm256_frcz_ps(a0);                                          
      }                                                                 
  };                                                                    
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(boost::simd::tag::frac_, boost::simd::tag::xop_    
                                    , (A0)                                           
                                    , ((simd_<double_<A0>,boost::simd::tag::xop_>)) 
                                    ((simd_<double_<A0>,boost::simd::tag::xop_>))   
                       )                                                
  {                                                                     
    result_type operator()(__m256d const a0, __m256d const a1) const    
      {                                                                 
        return  _mm256_frcz_pd(a0);                                          
      }                                                                 
  };  
} } }

#endif
#endif
