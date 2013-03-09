//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.arithmetic toolbox - muls/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.arithmetic components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 28/11/2010
///
#include <boost/simd/toolbox/arithmetic/include/functions/muls.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/toolbox/constant/constant.hpp>


NT2_TEST_CASE_TPL ( muls_signed_int__2_0,  BOOST_SIMD_SIMD_INTEGRAL_SIGNED_TYPES)
{
  using boost::simd::muls;
  using boost::simd::tag::muls_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<muls_(vT,vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;

  // specific values tests
  NT2_TEST_EQUAL(muls(boost::simd::Mone<vT>(), boost::simd::Mone<vT>())[0], boost::simd::One<T>());
  NT2_TEST_EQUAL(muls(boost::simd::One<vT>(), boost::simd::One<vT>())[0], boost::simd::One<T>());
  NT2_TEST_EQUAL(muls(boost::simd::Valmax<vT>(), boost::simd::Valmax<vT>())[0], boost::simd::Valmax<T>());
  NT2_TEST_EQUAL(muls(boost::simd::Valmax<vT>(),boost::simd::splat<vT>(2))[0], boost::simd::Valmax<T>());
  NT2_TEST_EQUAL(muls(boost::simd::Valmax<vT>(),boost::simd::Mone<vT>())[0], boost::simd::Valmin<T>()+boost::simd::One<T>());
  NT2_TEST_EQUAL(muls(boost::simd::Valmax<vT>(),boost::simd::One<vT>())[0], boost::simd::Valmax<T>());
  NT2_TEST_EQUAL(muls(boost::simd::Valmin<vT>(),boost::simd::Mone<vT>())[0], boost::simd::Valmax<T>());
  NT2_TEST_EQUAL(muls(boost::simd::Zero<vT>(), boost::simd::Zero<vT>())[0], boost::simd::Zero<T>());
} // end of test for signed_int_

NT2_TEST_CASE_TPL ( muls_unsigned_int__2_0,  BOOST_SIMD_SIMD_UNSIGNED_TYPES)
{
  using boost::simd::muls;
  using boost::simd::tag::muls_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<muls_(vT,vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;

  // specific values tests
  NT2_TEST_EQUAL(muls(boost::simd::One<vT>(), boost::simd::One<vT>())[0], boost::simd::One<T>());
  NT2_TEST_EQUAL(muls(boost::simd::Valmax<vT>(),boost::simd::splat<vT>(2))[0], boost::simd::Valmax<T>());
  NT2_TEST_EQUAL(muls(boost::simd::Zero<vT>(), boost::simd::Zero<vT>())[0], boost::simd::Zero<T>());
} // end of test for unsigned_int_
