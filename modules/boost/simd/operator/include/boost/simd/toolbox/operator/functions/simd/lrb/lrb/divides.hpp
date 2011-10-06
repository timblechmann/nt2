//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_LRB_LRB_DIVIDES_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_LRB_LRB_DIVIDES_HPP_INCLUDED

#include <boost/simd/include/functions/map.hpp>
#include <boost/simd/include/functions/bitwise_and.hpp>
#include <boost/simd/include/functions/bitwise_or.hpp>
#include <boost/simd/include/functions/plus.hpp>
#include <boost/simd/include/functions/minus.hpp>
#include <boost/simd/include/functions/is_equal.hpp>
#include <boost/simd/include/constants/digits.hpp>
#include <boost/simd/include/functions/select.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::divides_, boost::simd::tag::lrb_
                            , (A0)
                            , ((simd_<double_<A0>,boost::simd::tag::lrb_>))
                              ((simd_<double_<A0>,boost::simd::tag::lrb_>))
                            )
  {
    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      A0  that = { _mm512_div_pd(a0,a1) };
      return that; 
      //      return select(b_and(eq(a0, Zero<A0>()), eq(a1, Zero<A0>())),Nan<A0>(),that);
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::divides_, boost::simd::tag::lrb_
                            , (A0)
                            , ((simd_<single_<A0>,boost::simd::tag::lrb_>))
                              ((simd_<single_<A0>,boost::simd::tag::lrb_>))
                            )
  {
    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      A0  that = { _mm512_div_ps(a0,a1) };
      //      return select(b_and(eq(a0, Zero<A0>()), eq(a1, Zero<A0>())),Nan<A0>(),that);
      return that; 
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::divides_, boost::simd::tag::lrb_
                            , (A0)
                            , ((simd_<ints32_<A0>,boost::simd::tag::lrb_>))
                              ((simd_<ints32_<A0>,boost::simd::tag::lrb_>))
                            )
  {
    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      const typename meta::boolean<A0>::type iseqza1 = eq(a1, Zero<A0>());
      A0 tmp0 =  a0-select(iseqza1, a0, Zero<A0>());
      A0 tmp1 =  a1+select(iseqza1, One<A0>(), Zero<A0>());
      A0 r; 
//       for(int i = 0;  i < 8;  ++i)
//            r[i] = tmp0[i]/tmp1[i];
//       return r; 
       return map( typename dispatch::make_functor<boost::simd::tag::divides_,A0>::type(), 
                   tmp0,
                   tmp1)
                 );
    }
  };
} } }

#endif
