//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_LRB_LRB_LOAD_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_LRB_LRB_LOAD_HPP_INCLUDED
#include <iostream>

////////////////////////////////////////////////////////////////////////////////
// load for larrabee SIMD types
////////////////////////////////////////////////////////////////////////////////
#include <boost/dispatch/meta/mpl.hpp>
#include <boost/simd/sdk/simd/category.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>
#include <boost/simd/sdk/meta/cardinal_of.hpp>
#include <boost/dispatch/functor/preprocessor/call.hpp>
#include <boost/simd/sdk/simd/native_cast.hpp>

//==============================================================================
// load vector of double
//==============================================================================
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::load_ , boost::simd::tag::lrb_
                            , (A0)(A1)(A2)
                            , (iterator_< scalar_< fundamental_<A0> > >)
                              (scalar_< fundamental_<A1> >)
                              ((target_< simd_< double_<A2>, boost::simd::tag::lrb_ > >))
                            )
  {
    typedef typename A2::type result_type;
    inline result_type operator()(const A0& a0, const A1& a1, const A2&)const
    {
      std::cout << "icitte" << std::endl; 
      result_type
  that = native_cast<result_type>(_mm512_loadd(a0+a1*boost::simd::meta::cardinal_of<result_type>::value,
                 _MM_FULLUPC_NONE,
                 _MM_BROADCAST_16X16,
                 _MM_HINT_NONE));
      std::cout << that << std::endl; 
      return that;
    }
  };
} } }

//==============================================================================
// load vector of float
//==============================================================================
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::load_ , boost::simd::tag::lrb_
                            , (A0)(A1)(A2)
                            , (iterator_< scalar_< fundamental_<A0> > >)
                              (scalar_< fundamental_<A1> >)
                              ((target_< simd_< single_<A2>, boost::simd::tag::lrb_ > >))
                            )
  {
    typedef typename A2::type result_type;
    inline result_type operator()(const A0& a0, const A1& a1, const A2&)const
    {
      result_type
  that = native_cast<result_type>(_mm512_loadd(a0+a1*boost::simd::meta::cardinal_of<result_type>::value,
                 _MM_FULLUPC_NONE,
                 _MM_BROADCAST_16X16,
                 _MM_HINT_NONE)); 
      return that;
    }
  };
} } }

//==============================================================================
// load vector of integer
//==============================================================================
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::load_ , boost::simd::tag::lrb_
                            , (A0)(A1)(A2)
                            , (iterator_< scalar_< fundamental_<A0> > >)
                              (scalar_< fundamental_<A1> >)
                              ((target_< simd_< integer_<A2>, boost::simd::tag::lrb_ > >))
                            )
  {
    typedef typename A2::type result_type;
    inline result_type operator()(const A0& a0, const A1& a1, const A2&)const
    {
      result_type
  that =  native_cast<result_type>(_mm512_loadd(a0+a1*boost::simd::meta::cardinal_of<result_type>::value,
                  _MM_FULLUPC_NONE,
                  _MM_BROADCAST_16X16,
                  _MM_HINT_NONE)); /*};*/
      return that;
    }
  };
} } }


//#include <boost/simd/toolbox/operator/functions/simd/lrb/lrb/details/load_offset.hpp>

#endif

