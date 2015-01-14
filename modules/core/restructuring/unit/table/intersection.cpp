//==============================================================================
//         Copyright 2015 J.T. Lapreste
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//=============================================================================
#include <nt2/table.hpp>
#include <nt2/include/functions/intersection.hpp>
#include <nt2/include/functions/cons.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/exceptions.hpp>
#include <nt2/sdk/unit/tests/basic.hpp>
#include <nt2/sdk/meta/as.hpp>

#include <nt2/include/functions/reshape.hpp>
#include <nt2/include/functions/find.hpp>
#include <nt2/include/functions/is_nez.hpp>
#include <nt2/include/constants/true.hpp>
#include <nt2/include/constants/false.hpp>

NT2_TEST_CASE_TPL(intersection, NT2_REAL_TYPES)
{
  using nt2::intersection;
  using nt2::tag::intersection_;

  nt2::table<T> n = nt2::reshape(nt2::cons<T>(3, 1, 2, 2, 3, 5, 2, 3), 2, 4);
  nt2::table<T> n1 = n+nt2::One<T>();
  nt2::table<T> r = nt2::cons<T>(2, 3); ;
  NT2_DISPLAY(n);
  NT2_DISPLAY(n1);
  NT2_DISPLAY(intersection(n, n1));
  nt2::table<T> b = intersection(n, n1);
  NT2_TEST_EQUAL(b, r);
}

