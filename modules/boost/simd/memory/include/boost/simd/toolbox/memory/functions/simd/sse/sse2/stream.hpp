//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SIMD_SSE_SSE2_STREAM_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SIMD_SSE_SSE2_STREAM_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_SSE2_SUPPORT

#include <boost/simd/memory/iterator_category.hpp>
#include <boost/dispatch/functor/preprocessor/call.hpp>
#include <boost/simd/memory/is_aligned.hpp>
#include <boost/assert.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::stream_ , boost::simd::tag::sse2_
                            , (A0)(A1)(A2)
                            , ((simd_< double_<A0>, boost::simd::tag::sse_ >))
                              (iterator_< scalar_< double_<A1> > >)
                              (scalar_< integer_<A2> >)
                            )
  {
    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL(3)
    {
      BOOST_ASSERT_MSG
      ( boost::simd::is_aligned(a1+a2,sizeof(result_type))
      , "stream has been called on a pointer which alignment is not "
        "compatible with current SIMD extension."
      );

      _mm_stream_pd(a1+a2,a0);
      return a0;
    }
  };
} } }

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::stream_ , boost::simd::tag::sse2_
                            , (A0)(A1)(A2)
                            , ((simd_< single_<A0>, boost::simd::tag::sse_ >))
                              (iterator_< scalar_< single_<A1> > >)
                              (scalar_< integer_<A2> >)
                            )
  {
    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL(3)
    {
      BOOST_ASSERT_MSG
      ( boost::simd::is_aligned(a1+a2,sizeof(result_type))
      , "stream has been called on a pointer which alignment is not "
        "compatible with current SIMD extension."
      );

      _mm_stream_ps(a1+a2,a0);
      return a0;
    }
  };
} } }

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::stream_ , boost::simd::tag::sse2_
                            , (A0)(A1)(A2)
                            , ((simd_< integer_<A0>, boost::simd::tag::sse_ >))
                              (iterator_< scalar_< integer_<A1> > >)
                              (scalar_< integer_<A2> >)
                            )
  {
    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL(3)
    {
      BOOST_ASSERT_MSG
      ( boost::simd::is_aligned(a1+a2,sizeof(result_type))
      , "stream has been called on a pointer which alignment is not "
        "compatible with current SIMD extension."
      );

      _mm_stream_si128(reinterpret_cast<__m128i*>(a1 + a2), a0);
      return a0;
    }
  };
} } }

#endif
#endif
