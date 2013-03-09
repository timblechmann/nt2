//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.swar toolbox - cumprod/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.swar components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 24/02/2011
///
#include <boost/simd/toolbox/swar/include/functions/cumprod.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/simd/include/functions/all.hpp>

#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/toolbox/constant/constant.hpp>


NT2_TEST_CASE_TPL ( cumprod_real__1_0,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::cumprod;
  using boost::simd::tag::cumprod_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<cumprod_(vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  // specific values tests
  NT2_TEST_EQUAL(cumprod(boost::simd::Inf<vT>())[0], boost::simd::Inf<sr_t>());
  NT2_TEST_EQUAL(cumprod(boost::simd::Minf<vT>())[0], boost::simd::Minf<sr_t>());
  NT2_TEST_EQUAL(cumprod(boost::simd::Mone<vT>())[0], boost::simd::Mone<sr_t>());
  NT2_TEST_EQUAL(cumprod(boost::simd::Nan<vT>())[0], boost::simd::Nan<sr_t>());
  NT2_TEST_EQUAL(cumprod(boost::simd::One<vT>())[0], boost::simd::One<sr_t>());
  NT2_TEST_EQUAL(cumprod(boost::simd::Zero<vT>())[0], boost::simd::Zero<sr_t>());
  NT2_TEST_EQUAL(cumprod(boost::simd::Inf<vT>())[1], boost::simd::Inf<sr_t>());
  NT2_TEST_EQUAL(cumprod(boost::simd::Minf<vT>())[1], boost::simd::Inf<sr_t>());
  NT2_TEST_EQUAL(cumprod(boost::simd::Mone<vT>())[1], boost::simd::One<sr_t>());
  NT2_TEST_EQUAL(cumprod(boost::simd::Nan<vT>())[1], boost::simd::Nan<sr_t>());
  NT2_TEST_EQUAL(cumprod(boost::simd::One<vT>())[1], boost::simd::One<sr_t>());
  NT2_TEST_EQUAL(cumprod(boost::simd::Zero<vT>())[1], boost::simd::Zero<sr_t>());
} // end of test for floating_

NT2_TEST_CASE_TPL ( cumprod_signed_int__1_0,  BOOST_SIMD_SIMD_INTEGRAL_SIGNED_TYPES)
{
  using boost::simd::cumprod;
  using boost::simd::tag::cumprod_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<cumprod_(vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;

  // specific values tests
  NT2_TEST_EQUAL(cumprod(boost::simd::Mone<vT>())[0], boost::simd::Mone<sr_t>());
  NT2_TEST_EQUAL(cumprod(boost::simd::One<vT>())[0], boost::simd::One<sr_t>());
  NT2_TEST_EQUAL(cumprod(boost::simd::Zero<vT>())[0], boost::simd::Zero<sr_t>());
  NT2_TEST_EQUAL(cumprod(boost::simd::Mone<vT>())[1], boost::simd::One<sr_t>());
  NT2_TEST_EQUAL(cumprod(boost::simd::One<vT>())[1], boost::simd::One<sr_t>());
  NT2_TEST_EQUAL(cumprod(boost::simd::Zero<vT>())[1], boost::simd::Zero<sr_t>());
} // end of test for signed_int_

NT2_TEST_CASE_TPL ( cumprod_unsigned_int__1_0,  BOOST_SIMD_SIMD_UNSIGNED_TYPES)
{
  using boost::simd::cumprod;
  using boost::simd::tag::cumprod_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<cumprod_(vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;

  // specific values tests
  NT2_TEST_EQUAL(cumprod(boost::simd::One<vT>())[0], boost::simd::One<sr_t>());
  NT2_TEST_EQUAL(cumprod(boost::simd::Zero<vT>())[0], boost::simd::Zero<sr_t>());
  NT2_TEST_EQUAL(cumprod(boost::simd::One<vT>())[1], boost::simd::One<sr_t>());
  NT2_TEST_EQUAL(cumprod(boost::simd::Zero<vT>())[1], boost::simd::Zero<sr_t>());
} // end of test for unsigned_int_
