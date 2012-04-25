//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTIONS_SIMD_COMMON_IS_NOT_INFINITE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTIONS_SIMD_COMMON_IS_NOT_INFINITE_HPP_INCLUDED
#include <boost/simd/sdk/simd/logical.hpp>
#include <boost/simd/include/constants/infinites.hpp>
#include <boost/simd/include/functions/abs.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(is_not_infinite_, tag::cpu_,
                                  (A0)(X),
                                  ((simd_<arithmetic_<A0>,X>))
                                 )
  {
    typedef typename meta::as_logical<A0>::type result_type;
    inline result_type operator()(const A0&)const
    {
      return boost::simd::True<A0>();
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION(is_not_infinite_, tag::cpu_,
                                  (A0)(X),
                                  ((simd_<floating_<A0>,X>))
                                 )
  {
    typedef typename meta::as_logical<A0>::type result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(1)
    {
      return is_not_equal(abs(a0),boost::simd::Inf<A0>());
    }
  };
} } }
#endif
