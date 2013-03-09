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
 * \file
**/
#ifndef BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_UNALIGNED_STORE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_UNALIGNED_STORE_HPP_INCLUDED

#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>

namespace boost { namespace simd
{
  namespace tag { struct unaligned_store_ : ext::elementwise_<unaligned_store_> { typedef ext::elementwise_<unaligned_store_> parent; }; }

  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::unaligned_store_, unaligned_store,2)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::unaligned_store_, unaligned_store,3)
} }

#endif
