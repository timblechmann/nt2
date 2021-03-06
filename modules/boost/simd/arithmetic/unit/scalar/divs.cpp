//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.arithmetic toolbox - divs/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.arithmetic components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 28/11/2010
///
#include <boost/simd/toolbox/arithmetic/include/functions/divs.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/toolbox/constant/constant.hpp>


NT2_TEST_CASE_TPL ( divs_signed_int__2_0,  BOOST_SIMD_INTEGRAL_SIGNED_TYPES)
{

  using boost::simd::divs;
  using boost::simd::tag::divs_;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef typename boost::dispatch::meta::call<divs_(T,T)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  typedef T wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;

  // specific values tests
  NT2_TEST_EQUAL(divs(boost::simd::Mone<T>(), boost::simd::Mone<T>()), boost::simd::One<T>());
  NT2_TEST_EQUAL(divs(boost::simd::One<T>(), boost::simd::One<T>()), boost::simd::One<T>());
  NT2_TEST_EQUAL(divs(boost::simd::Valmax<T>(),boost::simd::Mone<T>()), boost::simd::Valmin<T>()+boost::simd::One<T>());
  NT2_TEST_EQUAL(divs(boost::simd::Valmax<T>(),boost::simd::One<T>()), boost::simd::Valmax<T>());
  NT2_TEST_EQUAL(divs(boost::simd::Valmin<T>(),boost::simd::Mone<T>()), boost::simd::Valmax<T>());
  NT2_TEST_EQUAL(divs(boost::simd::Zero<T>(), boost::simd::Zero<T>()), boost::simd::Zero<T>());
} // end of test for signed_int_

NT2_TEST_CASE_TPL ( divs_unsigned_int__2_0,  BOOST_SIMD_UNSIGNED_TYPES)
{

  using boost::simd::divs;
  using boost::simd::tag::divs_;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef typename boost::dispatch::meta::call<divs_(T,T)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  typedef T wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;

  // specific values tests
  NT2_TEST_EQUAL(divs(boost::simd::One<T>(), boost::simd::One<T>()), boost::simd::One<T>());
  NT2_TEST_EQUAL(divs(boost::simd::Valmax<T>(),boost::simd::One<T>()), boost::simd::Valmax<T>());
  NT2_TEST_EQUAL(divs(boost::simd::Zero<T>(), boost::simd::Zero<T>()), boost::simd::Zero<T>());
} // end of test for unsigned_int_
