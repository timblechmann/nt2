//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_SDK_SIMD_DETAILS_NATIVE_META_MODEL_OF_HPP_INCLUDED
#define BOOST_SIMD_SDK_SIMD_DETAILS_NATIVE_META_MODEL_OF_HPP_INCLUDED

#include <boost/simd/sdk/simd/native_fwd.hpp>
#include <boost/dispatch/meta/model_of.hpp>

namespace boost { namespace dispatch { namespace meta
{
  template<class Type,class Extension>
  struct model_of< simd::native<Type,Extension> >
  {
    struct type
    {
      template<class T>
      struct apply
      {
          typedef simd::native<T, Extension> type;
      };
    };
  };
} } }

#endif
