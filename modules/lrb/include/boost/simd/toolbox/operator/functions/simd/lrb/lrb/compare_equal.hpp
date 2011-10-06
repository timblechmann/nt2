//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_LRB_LRB_COMPARE_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_LRB_LRB_COMPARE_EQUAL_HPP_INCLUDED
#include <boost/simd/include/functions/is_equal.hpp>

////////////////////////////////////////////////////////////////////////////////
// operator binary compare_equal
////////////////////////////////////////////////////////////////////////////////

/////////TODO
// namespace boost { namespace simd { namespace ext
// {
//   BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::compare_equal_, boost::simd::tag::lrb_
//                             , (A0)
//                             , ((simd_<type64_<A0>,boost::simd::tag::lrb_>))
//                               ((simd_<type64_<A0>,boost::simd::tag::lrb_>))
//                             )
//   {
//     typedef bool result_type;
//     BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
//     {
//       return is_equal(a0,a1) == 0xFF;
//     }
//   };
// } } }

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::compare_equal_, boost::simd::tag::lrb_
                            , (A0)
                            , ((simd_<type32_<A0>,boost::simd::tag::lrb_>))
                              ((simd_<type32_<A0>,boost::simd::tag::lrb_>))
                            )
  {
    typedef bool result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return is_equal(a0,a1) == 0xFFFF;
    }
  };
} } }


#endif
