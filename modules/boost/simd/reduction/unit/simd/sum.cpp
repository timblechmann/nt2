//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.reduction toolbox - sum/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.reduction components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 24/02/2011
///
#include <boost/simd/toolbox/reduction/include/functions/sum.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/simd/include/functions/enumerate.hpp>
#include <boost/simd/sdk/simd/logical.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/toolbox/constant/constant.hpp>


NT2_TEST_CASE_TPL ( sum_real__1_0,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::sum;
  using boost::simd::tag::sum_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef typename boost::dispatch::meta::scalar_of<T>::type sT;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<sum_(vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;

  // specific values tests
  T c = cardinal_of<n_t>();
  NT2_TEST_ULP_EQUAL(sum(boost::simd::Inf<vT>()), boost::simd::Inf<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(sum(boost::simd::Minf<vT>()), boost::simd::Minf<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(sum(boost::simd::Mone<vT>()), -c, 0);
  NT2_TEST_ULP_EQUAL(sum(boost::simd::Nan<vT>()), boost::simd::Nan<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(sum(boost::simd::One<vT>()), c, 0);
  NT2_TEST_ULP_EQUAL(sum(boost::simd::Two<vT>()), 2*c, 0);
  NT2_TEST_ULP_EQUAL(sum(boost::simd::Zero<vT>()), boost::simd::Zero<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(sum(boost::simd::enumerate<vT>(1)), c*(c+1)/2, 0);
} // end of test for floating_

NT2_TEST_CASE_TPL ( sum_int__1_0,  BOOST_SIMD_SIMD_INTEGRAL_TYPES)
{
  using boost::simd::sum;
  using boost::simd::tag::sum_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef typename boost::dispatch::meta::scalar_of<T>::type sT;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<sum_(vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;

  // specific values tests
  std::size_t c = cardinal_of<n_t>::value;
  NT2_TEST_ULP_EQUAL(sum(boost::simd::One<vT>()), T(c), 0);
  NT2_TEST_ULP_EQUAL(sum(boost::simd::Two<vT>()), T(2*c), 0);
  NT2_TEST_ULP_EQUAL(sum(boost::simd::Zero<vT>()), boost::simd::Zero<sr_t>(), 0);
  NT2_TEST_ULP_EQUAL(sum(boost::simd::enumerate<vT>(1)), c*(c+1)/2, 0);
} //
