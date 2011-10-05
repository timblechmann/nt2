//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_LRB_LRB_COMPARE_LESS_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_LRB_LRB_COMPARE_LESS_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// operator binary compare_less
////////////////////////////////////////////////////////////////////////////////
#include <boost/simd/include/functions/is_less.hpp>
#include <boost/simd/include/functions/is_greater.hpp>
#include <boost/simd/toolbox/operator/functions/simd/common/details/compare_less_helper.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::compare_less_, boost::simd::tag::lrb_
                            , (A0)
                            , ((simd_<arithmetic_<A0>,boost::simd::tag::lrb_>))
                              ((simd_<arithmetic_<A0>,boost::simd::tag::lrb_>))
                            )
  {
    typedef bool result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      __mmask  mask_a_lt_b =  lt(a0,a1);
      __mmask  mask_a_gt_b =  gt(a0,a1);
      return boost::simd::details::compare_less_helper(mask_a_lt_b,mask_a_gt_b);
    }
  };
} } }

#endif
