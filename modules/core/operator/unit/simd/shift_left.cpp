//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 operator toolbox - shift_left/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of operator components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 18/02/2011
///
#include <nt2/toolbox/operator/include/functions/shift_left.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/as_floating.hpp>
#include <nt2/sdk/meta/as_signed.hpp>
#include <nt2/sdk/meta/upgrade.hpp>
#include <nt2/sdk/meta/downgrade.hpp>
#include <nt2/sdk/meta/scalar_of.hpp>
#include <boost/dispatch/meta/as_floating.hpp>
#include <boost/type_traits/common_type.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/toolbox/constant/constant.hpp>
#include <nt2/sdk/meta/cardinal_of.hpp>
#include <nt2/include/functions/splat.hpp>

#ifdef BOOST_MSVC
#pragma warning(disable: 4146) // unary minus operator applied to unsigned type
#endif

NT2_TEST_CASE_TPL ( shift_left_integer__2_0,  NT2_SIMD_INTEGRAL_TYPES)
{
  using nt2::shift_left;
  using nt2::tag::shift_left_;
  using boost::simd::native;
  using nt2::meta::cardinal_of;
  typedef typename nt2::meta::scalar_of<T>::type sT;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<shift_left_(vT,ivT)>::type r_t;
  typedef typename nt2::meta::call<shift_left_(T,iT)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(shift_left(nt2::Mone<vT>(),nt2::One<ivT>())[0], sr_t(-nt2::Two<sr_t>()));
  NT2_TEST_EQUAL(shift_left(nt2::One<vT>(),nt2::One<ivT>())[0], nt2::Two<sr_t>());
  NT2_TEST_EQUAL(shift_left(nt2::One<vT>(),nt2::Zero<ivT>())[0], nt2::One<sr_t>());
  NT2_TEST_EQUAL(shift_left(nt2::Zero<vT>(),nt2::One<ivT>())[0], nt2::Zero<sr_t>());
} // end of test for integer_

NT2_TEST_CASE_TPL ( shift_left_real__2_0,  NT2_SIMD_REAL_TYPES)
{
  using nt2::shift_left;
  using nt2::tag::shift_left_;
  using boost::simd::native;
  using nt2::meta::cardinal_of;
  typedef typename nt2::meta::scalar_of<T>::type sT;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<shift_left_(vT,ivT)>::type r_t;
  typedef typename nt2::meta::call<shift_left_(T,iT)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(shift_left(nt2::One<vT>(),nt2::Zero<ivT>())[0], nt2::One<sr_t>());
  NT2_TEST_EQUAL(shift_left(nt2::Zero<vT>(),nt2::One<ivT>())[0], nt2::Zero<sr_t>());
} // end of test for floating_
