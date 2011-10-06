//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_LRB_LRB_BITWISE_OR_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_LRB_LRB_BITWISE_OR_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// operator binary bitwise_or
////////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::bitwise_or_, boost::simd::tag::lrb_
                            , (A0)
                            , ((simd_<arithmetic_<A0>,boost::simd::tag::lrb_>))
                              ((simd_<arithmetic_<A0>,boost::simd::tag::lrb_>))
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      typedef typename dispatch::meta::as_integer< A0 >::type iA0;
      A0 that = { native_cast<A0>(_mm512_or_pi(native_cast<iA0>(a0),native_cast<iA0>(a1))) };
      return that;
    }
  };

//   BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::bitwise_or_, boost::simd::tag::lrb_
//                             , (A0)
//                             , ((simd_<floating_<A0>,boost::simd::tag::lrb_>))
//                               ((simd_<floating_<A0>,boost::simd::tag::lrb_>))
//                             )
//   {
//     typedef A0 result_type;
//     BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
//     {
//       typedef typename dispatch::meta::as_integer< A0 >::type iA0;
//       A0 that = { native_cast<A0>(bitwise_or(native_cast<iA0>(a0),native_cast<iA0>(a1))) };
//       return that;
//     }
//   };

} } }

#endif
