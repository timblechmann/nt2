//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.ieee toolbox - clz/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.ieee components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 04/12/2010
///
#include <boost/simd/toolbox/bitwise/include/functions/clz.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/simd/include/functions/ilogb.hpp>
#include <boost/simd/include/functions/abs.hpp>

#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/toolbox/constant/constant.hpp>


NT2_TEST_CASE_TPL ( clz_real__1_0,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::clz;
  using boost::simd::tag::clz_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<clz_(vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;

  // specific values tests
  NT2_TEST_EQUAL(clz(boost::simd::Minf<vT>())[0], clz(boost::simd::Minf<T>()));
  NT2_TEST_EQUAL(clz(boost::simd::Mone<vT>())[0], clz(boost::simd::Mone<T>()));
  NT2_TEST_EQUAL(clz(boost::simd::One<vT>())[0],  clz(boost::simd::One<T>()));
  //NT2_TEST_EQUAL(clz(boost::simd::Zero<vT>())[0], clz(boost::simd::Zero<T>()));
} // end of test for floating_

NT2_TEST_CASE_TPL ( clz_ints__1_0,  BOOST_SIMD_SIMD_UNSIGNED_TYPES)
{
  using boost::simd::clz;
  using boost::simd::tag::clz_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<clz_(vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;


  //NT2_TEST_EQUAL(clz(boost::simd::splat<vT>(0))[0], clz(T(0)));
  NT2_TEST_EQUAL(clz(boost::simd::splat<vT>(1))[0], clz(T(1)));


  // specific values tests
  for (T i =  2;  i < boost::simd::Valmax<T>()/2; i*= 2)
    {
      NT2_TEST_EQUAL(clz(boost::simd::splat<vT>(i))[0], clz(i));
      NT2_TEST_EQUAL(clz(boost::simd::splat<vT>(i+1))[0], clz(i));
    }
} // end of test for floating_
