//==============================================================================
//         Copyright 2003 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2011 - 2012   MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SCALAR_UNALIGNED_STORE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SCALAR_UNALIGNED_STORE_HPP_INCLUDED

#include <boost/simd/toolbox/memory/functions/unaligned_store.hpp>
#include <boost/simd/toolbox/memory/functions/scalar/store.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::unaligned_store_
                                    , tag::cpu_, (A0)(A1)(A2)
                                    , (unspecified_<A0>)
                                      (iterator_< unspecified_<A1> >)
                                      (scalar_< integer_<A2> >)
                                    )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE result_type
    operator()(const A0& a0, A1 const& a1, A2 a2) const
    {
      return store(a0,a1,a2);
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::unaligned_store_
                                    , tag::cpu_, (A0)(A1)(A2)(A3)
                                    , (unspecified_<A0>)
                                      (iterator_< unspecified_<A1> >)
                                      (scalar_< integer_<A2> >)
                                      (mpl_integral_< scalar_<integer_<A3> > >)
                                    )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE result_type
    operator()(const A0& a0, A1 const& a1, A2 a2) const
    {
      return store<A3::value>(a0,a1,a2);
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::unaligned_store_
                                    , tag::cpu_, (A0)(A1)(A2)
                                    , (fusion_sequence_<A0>)
                                      (fusion_sequence_<A1>)
                                      (scalar_< integer_<A2> >)
                                    )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE result_type
    operator()(const A0& a0, A1 const& a1, A2 a2) const
    {
      return store(a0,a1,a2);
    }
  };
} } }

#endif
