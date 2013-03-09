//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.operator toolbox - is_equal/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.operator components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 18/02/2011
///
#include <boost/simd/toolbox/operator/include/functions/is_equal.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/simd/sdk/simd/logical.hpp>

#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/toolbox/constant/constant.hpp>


NT2_TEST_CASE_TPL ( is_equal_integer__2_0, BOOST_SIMD_SIMD_INTEGRAL_TYPES)
{
  using boost::simd::is_equal;
  using boost::simd::tag::is_equal_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef native< boost::simd::logical<T>, ext_t> vlT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<is_equal_(vT,vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  typedef typename r_t::value_type vsr_t;

  // specific values tests
   NT2_TEST_EQUAL(is_equal(boost::simd::One<vT>(), boost::simd::One<vT>())[0], vsr_t(true));
   NT2_TEST_EQUAL(is_equal(boost::simd::One<vT>(),boost::simd::Zero<vT>())[0], vsr_t(false));
   NT2_TEST_EQUAL(is_equal(boost::simd::Zero<vT>(), boost::simd::Zero<vT>())[0], vsr_t(true));
} // end of test for integer_

NT2_TEST_CASE_TPL ( is_equal_real__2_0,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::is_equal;
  using boost::simd::tag::is_equal_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef native< boost::simd::logical<T>, ext_t> vlT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<is_equal_(vT,vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  typedef typename r_t::value_type vsr_t;

  // specific values tests
  NT2_TEST_EQUAL(is_equal(boost::simd::Inf<vT>(), boost::simd::Inf<vT>())[0], vsr_t(true));
  NT2_TEST_EQUAL(is_equal(boost::simd::Minf<vT>(), boost::simd::Minf<vT>())[0], vsr_t(true));
  NT2_TEST_EQUAL(is_equal(boost::simd::Nan<vT>(), boost::simd::Nan<vT>())[0], vsr_t(false));
  NT2_TEST_EQUAL(is_equal(boost::simd::One<vT>(),boost::simd::Zero<vT>())[0], vsr_t(false));
  NT2_TEST_EQUAL(is_equal(boost::simd::Zero<vT>(), boost::simd::Zero<vT>())[0], vsr_t(true));
} // end of test for floating_
NT2_TEST_CASE_TPL ( is_equall,  BOOST_SIMD_SIMD_TYPES)
{
  using boost::simd::is_equal;
  using boost::simd::tag::is_equal_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef native< boost::simd::logical<T>, ext_t> vlT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<is_equal_(vT,vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  typedef typename r_t::value_type vsr_t;

  // specific values tests
  NT2_TEST_EQUAL(is_equal(boost::simd::True<vlT>(),boost::simd::False<vlT>())[0], vsr_t(false));
  NT2_TEST_EQUAL(is_equal(boost::simd::True<vlT>(), boost::simd::True<vlT>())[0], vsr_t(true));
  NT2_TEST_EQUAL(is_equal(boost::simd::False<vlT>(),boost::simd::False<vlT>())[0], vsr_t(true));
  NT2_TEST_EQUAL(is_equal(boost::simd::False<vlT>(), boost::simd::True<vlT>())[0], vsr_t(false));
} // end of test for floating_
