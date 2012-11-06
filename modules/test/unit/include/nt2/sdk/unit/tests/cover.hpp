//==============================================================================
//         Copyright 2003 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2012        MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_UNIT_TESTS_COVER_HPP_INCLUDED
#define NT2_SDK_UNIT_TESTS_COVER_HPP_INCLUDED

// TODO cover tests should disappear and so will this file
#define NT2_NB_RANDOM_TEST 128

#include <vector>
#include <boost/simd/memory/allocator.hpp>

#define NT2_CREATE_BUF(NAME, TYPE, SIZE, MIN, MAX)                        \
std::vector<TYPE, boost::simd::memory::allocator<TYPE> > NAME(SIZE);      \
for(std::size_t k = 0; k < NAME.size(); ++k)                              \
{                                                                         \
  NAME[k] = static_cast<TYPE> (  static_cast<double>(MAX-MIN)             \
                              * (static_cast<double>(::rand())/RAND_MAX)  \
                              + MIN                                       \
                              );                                          \
}                                                                         \
/**/

#endif



