//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_LRB_LRB_STORE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_FUNCTIONS_SIMD_LRB_LRB_STORE_HPP_INCLUDED

//==============================================================================
// TODO : Documentation for simd store
// TODO : Make them work properly with ContiguousRandomAccessIterator
//==============================================================================
#include <boost/simd/sdk/memory/details/category.hpp>
#include <boost/dispatch/functor/preprocessor/call.hpp>
#include <boost/simd/sdk/simd/native_cast.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::store_ , boost::simd::tag::lrb_
                            , (A0)(A1)(A2)
                            , ((simd_< double_<A0>, boost::simd::tag::lrb_ >))
                              (iterator_< scalar_< double_<A1> > >)
                              (scalar_< integer_<A2> >)
                            )
  {
    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL(3)
    {
      typedef native <float, boost::simd::tag::lrb_ >  vf; 
      _mm512_storeq(a1+8*a2,native_cast<vf>(a0), _MM_DOWNC64_NONE, _MM_SUBSET64_8, _MM_HINT_NONE);
// void      _mm512_stored(void *m, _M512 v1, _MM_DOWNCONV32_ENUM d, _MM_STORE_SUBSET32_ENUM s,
// _MM_MEM_HINT_ENUM nt)
// void      _mm512_storeq(void *m, _M512 v1, _MM_DOWNCONV64_ENUM d, _MM_STORE_SUBSET64_ENUM subset,
// _MM_MEM_HINT_ENUM nt)
  return a0;
    }
  };
} } }

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::store_ , boost::simd::tag::lrb_
                            , (A0)(A1)(A2)
                            , ((simd_< single_<A0>, boost::simd::tag::lrb_ >))
                              (iterator_< scalar_< single_<A1> > >)
                              (scalar_< integer_<A2> >)
                            )
  {
    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL(3)
    {
      typedef native <float, boost::simd::tag::lrb_ >  vf; 
      _mm512_stored(a1+16*a2,native_cast<vf>(a0), _MM_DOWNC_NONE, _MM_SUBSET32_16, _MM_HINT_NONE);
      return a0;
    }
  };
} } }

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::store_ , boost::simd::tag::lrb_
                            , (A0)(A1)(A2)
                            , ((simd_< ints32_<A0>, boost::simd::tag::lrb_ >))
                              (iterator_< scalar_< integer_<A1> > >)
                              (scalar_< ints32_<A2> >)
                            )
  {
    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL(3)
    {
      typedef native <float, boost::simd::tag::lrb_ >  vf; 
       _mm512_stored(a1+16*a2,native_cast<vf>(a0), _MM_DOWNC_NONE, _MM_SUBSET32_16, _MM_HINT_NONE);
      return a0;
    }
  };
} } }

#endif
