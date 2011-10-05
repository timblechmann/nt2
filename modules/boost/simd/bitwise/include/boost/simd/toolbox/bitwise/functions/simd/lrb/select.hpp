//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_BITWISE_FUNCTIONS_SIMD_LRB_LRB_SELECT_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_BITWISE_FUNCTIONS_SIMD_LRB_LRB_SELECT_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_LRB_SUPPORT

#include <boost/simd/toolbox/bitwise/functions/select.hpp>
#include <boost/simd/sdk/simd/native_cast.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::select_, boost::simd::tag::lrb_
                            , (A0)(A1)
                            , ((scalar_<arithmetic_<A0> >))
                              ((simd_<integer_<A1>, boost::simd::tag::lrb_>))
                              ((simd_<integer_<A1>, boost::simd::tag::lrb_>))
                            )
  {
    typedef A1 result_type;

    inline result_type operator()(A0 const& a0,A1 const& a1,A1 const& a2) const
    {
      A1 that = { _mm512_mask_or_pi(a2,a0,a1,Zero<A1>())};
      return that; 
    }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::select_, boost::simd::tag::lrb_
                            , (A0)(A1)
                            , ((scalar_<arithmetic_<A0> >))
                              ((simd_<single_<A1>, boost::simd::tag::lrb_>))
                              ((simd_<single_<A1>, boost::simd::tag::lrb_>))
                            )
  {
    typedef A1 result_type;

    inline result_type operator()(A0 const& a0,A1 const& a1,A1 const& a2) const
    {
      A1 that = { _mm512_mask_sub_ps(a2,a0,a1,Zero<A1>())};
      return that; 
    }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::select_, boost::simd::tag::lrb_
                            , (A0)(A1)
                            , ((scalar_<arithmetic_<A0> >))
                              ((simd_<double_<A1>, boost::simd::tag::lrb_>))
                              ((simd_<double_<A1>, boost::simd::tag::lrb_>))
                            )
  {
    typedef A1 result_type;

    inline result_type operator()(A0 const& a0,A1 const& a1,A1 const& a2) const
    {
      A1 that = { _mm512_mask_sub_pd(a2,a0,a1,Zero<A1>())};
      return that; 
    }
  };  
} } }



#endif
#endif
