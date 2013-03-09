//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 bitwise toolbox - shri/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of bitwise components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 18/02/2011
///
#include <nt2/toolbox/bitwise/include/functions/shri.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <nt2/include/functions/twopower.hpp>

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

#include <nt2/toolbox/constant/constant.hpp>
#include <nt2/sdk/meta/cardinal_of.hpp>
#include <nt2/include/functions/splat.hpp>



NT2_TEST_CASE_TPL ( shri_unsigned_int__2_0,  NT2_SIMD_UNSIGNED_TYPES)
{
  using nt2::shri;
  using nt2::tag::shri_;
  using boost::simd::native;
  using nt2::meta::cardinal_of;
  typedef T r_type;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<shri_(vT,iT)>::type r_t;
  typedef typename nt2::meta::call<shri_(T,iT)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(shri(nt2::splat<vT>(2),1)[0], nt2::One<T>());
  NT2_TEST_EQUAL(shri(nt2::Mone<vT>(),(sizeof(r_type)*8-1))[0], nt2::One<sr_t>());
  NT2_TEST_EQUAL(shri(nt2::Mone<vT>(),(sizeof(r_type)*8-2))[0], nt2::Three<sr_t>());
  NT2_TEST_EQUAL(shri(nt2::One<vT>(),1)[0], nt2::Zero<sr_t>());
  NT2_TEST_EQUAL(shri(nt2::Zero<vT>(),1)[0], nt2::Zero<sr_t>());
} // end of test for unsigned_int_
