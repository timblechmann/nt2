//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.operator toolbox - logical_or/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.operator components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 18/02/2011
///
#include <boost/simd/toolbox/operator/include/functions/logical_or.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/simd/sdk/simd/logical.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/toolbox/constant/constant.hpp>

// static void pb(unsigned short a,  int n = 16)
// {
//   unsigned short j = 1;
//   for(int i =  0;  i < n;  i++){
//     std::cout << ((a&j)!= 0);
//     j <<= 1;
//   }
//   std::cout << std::endl;
// }

NT2_TEST_CASE_TPL ( logical_or_integer__2_0,  BOOST_SIMD_SIMD_INTEGRAL_TYPES)
{
  using boost::simd::logical_or;
  using boost::simd::tag::logical_or_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef native< boost::simd::logical<T>, ext_t> vlT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<logical_or_(vT,vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;

  // specific values tests
  NT2_TEST_EQUAL(logical_or(boost::simd::True<vlT>(), boost::simd::True<vlT>())[0], boost::simd::True<sr_t>());
  NT2_TEST_EQUAL(logical_or(boost::simd::True<vlT>(),boost::simd::False<vlT>())[0], boost::simd::True<sr_t>());
  NT2_TEST_EQUAL(logical_or(boost::simd::False<vlT>(), boost::simd::False<vlT>())[0], boost::simd::False<sr_t>());
} // end of test for integer_

NT2_TEST_CASE_TPL ( logical_or_real__2_0,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::logical_or;
  using boost::simd::tag::logical_or_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef native< boost::simd::logical<T>, ext_t> vlT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<logical_or_(vT,vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  // specific values tests
  NT2_TEST_EQUAL(logical_or(boost::simd::Inf<vT>(), boost::simd::Inf<vT>())[0], boost::simd::True<sr_t>());
  NT2_TEST_EQUAL(logical_or(boost::simd::Minf<vT>(), boost::simd::Minf<vT>())[0], boost::simd::True<sr_t>());
  NT2_TEST_EQUAL(logical_or(boost::simd::Nan<vT>(), boost::simd::Nan<vT>())[0], boost::simd::True<sr_t>());
  NT2_TEST_EQUAL(logical_or(boost::simd::One<vT>(),boost::simd::Zero<vT>())[0], boost::simd::True<sr_t>());
  NT2_TEST_EQUAL(logical_or(boost::simd::Zero<vT>(), boost::simd::Zero<vT>())[0], boost::simd::False<sr_t>());
} // end of test for floating_
