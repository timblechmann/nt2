//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.bitwise toolbox - shri/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.bitwise components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 18/02/2011
///
#include <boost/simd/toolbox/bitwise/include/functions/shri.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/simd/include/functions/twopower.hpp>

#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/toolbox/constant/constant.hpp>


NT2_TEST_CASE_TPL ( shri_unsigned_int__2_0,  BOOST_SIMD_SIMD_UNSIGNED_TYPES)
{
  using boost::simd::shri;
  using boost::simd::tag::shri_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef T r_type;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<shri_(vT,iT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;

  // specific values tests
  NT2_TEST_EQUAL(shri(boost::simd::splat<vT>(2),1)[0], boost::simd::One<T>());
  NT2_TEST_EQUAL(shri(boost::simd::Mone<vT>(),(sizeof(r_type)*8-1))[0], boost::simd::One<sr_t>());
  NT2_TEST_EQUAL(shri(boost::simd::Mone<vT>(),(sizeof(r_type)*8-2))[0], boost::simd::Three<sr_t>());
  NT2_TEST_EQUAL(shri(boost::simd::One<vT>(),1)[0], boost::simd::Zero<sr_t>());
  NT2_TEST_EQUAL(shri(boost::simd::Zero<vT>(),1)[0], boost::simd::Zero<sr_t>());
} // end of test for unsigned_int_
