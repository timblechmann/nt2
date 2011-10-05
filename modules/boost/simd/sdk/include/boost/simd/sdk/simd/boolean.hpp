//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_SDK_SIMD_BOOLEAN_HPP_INCLUDED
#define BOOST_SIMD_SDK_SIMD_BOOLEAN_HPP_INCLUDED
#include <boost/simd/sdk/meta/cardinal_of.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/dispatch/meta/make_integer.hpp>

/*!
 * \file
 * \brief Defines and implements the \ref boost::simd::meta::boolean \metafunction
 */

namespace boost { namespace simd { namespace meta
{
  template<class T >
  struct  boolean { typedef bool type; }; 
  template < class S,  class E >
  struct  boolean<native<S,E>  >{ typedef native<S,E> type; };
  template < class S >
  struct  boolean < boost::simd::native<S, boost::simd::tag::lrb_> > {
    typedef boost::simd::uint16_t type;
  };
  
} } }

#endif
