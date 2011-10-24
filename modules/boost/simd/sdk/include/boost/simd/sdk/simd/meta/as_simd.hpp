/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_SDK_SIMD_META_AS_SIMD_HPP_INCLUDED
#define BOOST_SIMD_SDK_SIMD_META_AS_SIMD_HPP_INCLUDED

#include <boost/dispatch/meta/na.hpp>

namespace boost { namespace simd { namespace details
{
  template<class T,class Extension>
  struct as_simd_impl
  {
    typedef dispatch::meta::na_ type;
  };
} } }

namespace boost { namespace simd { namespace meta
{
  template<class T,class Extension>
  struct as_simd;
} } }

#endif
