//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2011 - 2012   MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================

/*!
  @file
  @brief Defines and implements the store function
**/

#ifndef BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_STORE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_STORE_HPP_INCLUDED

#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    /*!
      @brief Define the store function tag

      Define a hierarchizable Tag representing the store function in generic
      contexts.
    **/
    struct store_ : ext::elementwise_<store_>
    {
      typedef ext::elementwise_<store_> parent;
    };
  }

  template<class A0, class A1, class A2>
  BOOST_FORCEINLINE A0 store(A0 const& val, A1 const& ptr, A2 offset)
  {
    typename boost::dispatch::make_functor<tag::store_, A0>::type callee;
    return callee(val, ptr, offset);
  }

  template<class A0, class A1>
  BOOST_FORCEINLINE A0 store(A0 const& a0, A1 const& a1)
  {
    return store(a0, a1, 0u);
  }
} }

#endif
