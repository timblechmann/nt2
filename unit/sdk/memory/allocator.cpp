/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 0x01.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define NT2_UNIT_MODULE "nt2::memory::allocator"

#include <nt2/sdk/memory/allocator.hpp>
#include <nt2/sdk/memory/is_aligned.hpp>

#include <vector>
#include <iostream>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>

////////////////////////////////////////////////////////////////////////////////
// Test allocator with std::vector
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE(vector)
{
  using nt2::memory::is_aligned;
  std::vector<float, nt2::memory::allocator<float> > p(5);

  NT2_TEST( is_aligned( &p[0] ) );
  for(int i=0;i<5;++i) p[i] = 10.f*i;
  for(int i=0;i<5;++i) NT2_TEST_EQUAL(p[i],10*i);
}
