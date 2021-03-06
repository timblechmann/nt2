//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.bitwise toolbox - shli/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.bitwise components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 18/02/2011
///
#include <boost/simd/toolbox/bitwise/include/functions/shli.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/simd/include/functions/twopower.hpp>

#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/toolbox/constant/constant.hpp>


NT2_TEST_CASE_TPL ( shli_integer__2_0,  BOOST_SIMD_INTEGRAL_TYPES)
{

  using boost::simd::shli;
  using boost::simd::tag::shli_;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef typename boost::dispatch::meta::call<shli_(T,iT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  typedef T wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;

  // specific values tests
  NT2_TEST_EQUAL(shli(T(2),2), boost::simd::Eight<r_t>());
  NT2_TEST_EQUAL(shli(boost::simd::Mone<T>(),1), r_t(-2));
  NT2_TEST_EQUAL(shli(boost::simd::Mone<T>(),2), r_t(-4));
  NT2_TEST_EQUAL(shli(boost::simd::One<T>(),1), boost::simd::Two<r_t>());
  NT2_TEST_EQUAL(shli(boost::simd::Zero<T>(),1), boost::simd::Zero<r_t>());
} // end of test for integer_
