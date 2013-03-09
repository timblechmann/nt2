//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.operator toolbox - is_greater/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.operator components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 18/02/2011
///
#include <boost/simd/toolbox/operator/include/functions/is_greater.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/simd/sdk/simd/logical.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/toolbox/constant/constant.hpp>


NT2_TEST_CASE_TPL ( is_greater_integer__2_0,  BOOST_SIMD_SIMD_INTEGRAL_TYPES)
{
  using boost::simd::is_greater;
  using boost::simd::tag::is_greater_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<is_greater_(vT,vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;

  // specific values tests
  NT2_TEST_EQUAL(is_greater(boost::simd::One<vT>(), boost::simd::One<vT>())[0], ssr_t(false));
  NT2_TEST_EQUAL(is_greater(boost::simd::One<vT>(),boost::simd::Zero<vT>())[0], ssr_t(true));
  NT2_TEST_EQUAL(is_greater(boost::simd::Zero<vT>(), boost::simd::Zero<vT>())[0], ssr_t(false));
} // end of test for integer_

NT2_TEST_CASE_TPL ( is_greater_signed_integer,  BOOST_SIMD_SIMD_INTEGRAL_SIGNED_TYPES)
{
  typedef boost::simd::native<T, BOOST_SIMD_DEFAULT_EXTENSION> vT;
  using boost::simd::splat;
  using boost::simd::is_greater;
  using boost::simd::logical;

  T hvalmin = T(1) << (sizeof(T)*CHAR_BIT/2-1);
  NT2_TEST_EQUAL( is_greater(splat<vT>(hvalmin), splat<vT>(hvalmin-1))[0], logical<T>(true) );
}

NT2_TEST_CASE_TPL ( is_greater_real__2_0,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::is_greater;
  using boost::simd::tag::is_greater_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<is_greater_(vT,vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;

  // specific values tests
  NT2_TEST_EQUAL(is_greater(boost::simd::Inf<vT>(), boost::simd::Inf<vT>())[0], ssr_t(false));
  NT2_TEST_EQUAL(is_greater(boost::simd::Minf<vT>(), boost::simd::Minf<vT>())[0], ssr_t(false));
  NT2_TEST_EQUAL(is_greater(boost::simd::Nan<vT>(), boost::simd::Nan<vT>())[0], ssr_t(false));
  NT2_TEST_EQUAL(is_greater(boost::simd::One<vT>(),boost::simd::Zero<vT>())[0], ssr_t(true));
  NT2_TEST_EQUAL(is_greater(boost::simd::Zero<vT>(), boost::simd::Zero<vT>())[0], ssr_t(false));
} // end of test for floating_
