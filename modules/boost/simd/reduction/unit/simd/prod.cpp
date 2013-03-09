//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.reduction toolbox - prod/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.reduction components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 24/02/2011
///
#include <boost/simd/toolbox/reduction/include/functions/prod.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/toolbox/constant/constant.hpp>
#include <boost/dispatch/details/ignore_unused.hpp>
#include <boost/simd/toolbox/constant/constant.hpp>
#include <boost/dispatch/details/ignore_unused.hpp>


NT2_TEST_CASE_TPL ( prod_real__1_0,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::prod;
  using boost::simd::tag::prod_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef typename boost::dispatch::meta::scalar_of<T>::type sT;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<prod_(vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;

  // specific values tests
  NT2_TEST_EQUAL(prod(boost::simd::Inf<vT>()), boost::simd::Inf<sr_t>());
  NT2_TEST_EQUAL(prod(boost::simd::Minf<vT>()), (boost::simd::meta::cardinal_of<vT>::value == 1) ? boost::simd::Minf<sr_t>() : boost::simd::Inf<sr_t>());
  NT2_TEST_EQUAL(prod(boost::simd::Mone<vT>()), (boost::simd::meta::cardinal_of<vT>::value == 1) ? boost::simd::Mone<sr_t>() : boost::simd::One<sr_t>());
  NT2_TEST_EQUAL(prod(boost::simd::Nan<vT>()), boost::simd::Nan<sr_t>());
  NT2_TEST_EQUAL(prod(boost::simd::One<vT>()), boost::simd::One<sr_t>());
  NT2_TEST_EQUAL(prod(boost::simd::Zero<vT>()), boost::simd::Zero<sr_t>());
} // end of test for floating_
