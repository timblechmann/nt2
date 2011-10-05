//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_LRB_LRB_SPLAT_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_LRB_LRB_SPLAT_HPP_INCLUDED
#include <boost/simd/toolbox/operator/functions/splat.hpp>
#include <boost/simd/include/functions/make.hpp>
#include <iostream>

//==============================================================================
// Implementation when type A0 is double
//==============================================================================
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::splat_, boost::simd::tag::lrb_, (A0)(A1)
                            , (scalar_< fundamental_<A0> >)
                              ((target_< simd_< double_<A1>, boost::simd::tag::lrb_ > >))
                      )
  {
    typedef typename A1::type result_type;
    BOOST_DISPATCH_FORCE_INLINE result_type operator()(A0 const& a0, A1 const&) const
    {
      result_type that = { _mm512_set_1to8_pd(double(a0)) };
      return that;
    }
  };
} } }

//==============================================================================
// Implementation when type A0 is float
//==============================================================================
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::splat_, boost::simd::tag::lrb_, (A0)(A1)
                            , (scalar_< fundamental_<A0> >)
                              ((target_< simd_< single_<A1>, boost::simd::tag::lrb_ > >))
                      )
  {
    typedef typename A1::type result_type;
    BOOST_DISPATCH_FORCE_INLINE result_type operator()(A0 const& a0, A1 const&) const
    {
      std::cout << "a0 = " << a0 << std::endl; 
      result_type that = { _mm512_set_1to16_ps(float(a0)) };
      std::cout << "that = " << that << std::endl;       
      return that;
    }
  };
} } }


//==============================================================================
// Implementation when type A0 is ints32
//==============================================================================
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::splat_, boost::simd::tag::lrb_, (A0)(A1)
                            , (scalar_< fundamental_<A0> >)
                              ((target_< simd_< ints32_<A1>, boost::simd::tag::lrb_ > >))
                      )
  {
    typedef typename A1::type result_type;
    BOOST_DISPATCH_FORCE_INLINE result_type operator()(A0 const& a0, A1 const&) const
    {
      result_type that = { _mm512_set_1to16_pi(a0) };
      return that;
    }
  };
} } }

//==============================================================================
// Implementation when type A0 is ints64
//==============================================================================
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::splat_, boost::simd::tag::lrb_, (A0)(A1)
                            , (scalar_< fundamental_<A0> >)
                              ((target_< simd_< ints64_<A1>, boost::simd::tag::lrb_ > >))
                      )
  {
    typedef typename A1::type result_type;
    BOOST_DISPATCH_FORCE_INLINE result_type operator()(A0 const& a0, A1 const&) const
    {
      result_type that = { _mm512_set_1to8_pq(a0) };
      return that;
    }
  };
} } }


#endif
