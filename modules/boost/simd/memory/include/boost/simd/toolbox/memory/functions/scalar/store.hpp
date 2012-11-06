//==============================================================================
//         Copyright 2003 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2011 - 2012   MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SCALAR_STORE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SCALAR_STORE_HPP_INCLUDED

#include <boost/simd/toolbox/memory/functions/store.hpp>
#include <boost/simd/toolbox/memory/functions/details/store.hpp>
#include <boost/simd/sdk/meta/iterate.hpp>
#include <boost/simd/memory/iterator_category.hpp>
#include <boost/dispatch/functor/preprocessor/call.hpp>
#include <boost/dispatch/meta/mpl.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::store_, tag::cpu_
                                    , (A0)(A1)(A2)
                                    , (unspecified_<A0>)
                                      (iterator_< unspecified_<A1> >)
                                      (scalar_< integer_<A2> >)
                                    )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE result_type
    operator()(const A0& a0, A1 const& a1, A2 a2) const
    {
      A1 that = a1;
      std::advance(that,a2);
      return *that = a0;
    }
  };

  // fusion sequence
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::store_, tag::cpu_
                                    , (A0)(A1)(A2)
                                    , (fusion_sequence_<A0>)
                                      (fusion_sequence_<A1>)
                                      (scalar_< integer_<A2> >)
                                    )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE result_type
    operator()(const A0& a0, A1 const& a1, A2 a2) const
    {
      meta::iterate < fusion::result_of::size<A1>::type::value>
                    ( details::storer < boost::simd::tag::store_
                                      , A0, A1, A2
                                      >(a0, a1, a2)
                    );
      return a0;
    }
  };
} } }

#endif
