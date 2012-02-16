/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define NT2_UNIT_MODULE "nt2::table iterator"

#include <nt2/table.hpp>
#include <nt2/core/container/dsl/iterator.hpp>
#include <boost/foreach.hpp>

#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/basic.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>

NT2_TEST_CASE( _1D )
{
  nt2::table<float> a0(nt2::of_size(4));

  int u = 0;
  for(int j=1; j!=1+4; ++j)
    a0(j) = float(++u);

  u = 0;
  typedef nt2::container::iterator< nt2::table<float>::parent > It;
  for(It it = a0.begin(); it != a0.end(); ++it)
  {
    float& f = *it;
    NT2_TEST_EQUAL( f, ++u );
  }

  u = 0;
  typedef nt2::container::iterator< nt2::table<float>::parent > It;
  BOOST_FOREACH(float& f, a0)
    NT2_TEST_EQUAL( f, ++u );
}
