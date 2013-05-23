//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 exponential toolbox - pow/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// cover test behavior of exponential components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 08/12/2010
///
#include <nt2/exponential/include/functions/pow.hpp>
#include <nt2/include/functions/max.hpp>
#include <nt2/include/functions/sqr.hpp>
#include <nt2/include/functions/sqrt.hpp>
extern "C" { long double cephes_powl(long double,long double); }
extern "C" { long double cephes_powil(long double,int); }

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
#include <nt2/constant/constant.hpp>

extern "C" { long double cephes_powil(long double,int); }



NT2_TEST_CASE_TPL ( pow_real__2_0,  NT2_REAL_TYPES)
{

  using nt2::pow;
  using nt2::tag::pow_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<pow_(T,T)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::dispatch::meta::as_floating<T>::type wished_r_t;


  // return type conformity test
  NT2_TEST_TYPE_IS( r_t, wished_r_t );

  // random verifications
  static const nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, T(0), T(10));
    NT2_CREATE_BUF(tab_a1,T, NR, T(0), T(10));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    T a0;
    T a1;
    for(nt2::uint32_t j =0; j < NR; ++j )
      {
        std::cout << "for params "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << ", a1 = "<< u_t(a1 = tab_a1[j])
                  << std::endl;
        NT2_TEST_ULP_EQUAL( nt2::pow(a0,a1),::cephes_powl(a0,a1),12.5);
        NT2_TEST_ULP_EQUAL( nt2::pow(a0,nt2::Two<T>()),nt2::sqr(a0),1);
        NT2_TEST_ULP_EQUAL( nt2::pow(a0,nt2::Half<T>()),nt2::sqrt(a0),1);
        ulp0=nt2::max(ulpd,ulp0);
     }
     std::cout << "max ulp found is: " << ulp0 << std::endl;
   }
} // end of test for floating_

NT2_TEST_CASE_TPL ( pow_unsigned_int__2_0,  NT2_UNSIGNED_TYPES)
{

  using nt2::pow;
  using nt2::tag::pow_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<pow_(T,T)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::dispatch::meta::as_floating<T>::type wished_r_t;


  // return type conformity test
  NT2_TEST_TYPE_IS( r_t, wished_r_t );

} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( pow_signed_int__2_0,  NT2_INTEGRAL_SIGNED_TYPES)
{

  using nt2::pow;
  using nt2::tag::pow_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<pow_(T,T)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::dispatch::meta::as_floating<T>::type wished_r_t;


  // return type conformity test
  NT2_TEST_TYPE_IS( r_t, wished_r_t );

} // end of test for signed_int_

NT2_TEST_CASE_TPL ( pow_real__2_1,  NT2_REAL_TYPES)
{

  using nt2::pow;
  using nt2::tag::pow_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<pow_(T,iT)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::dispatch::meta::as_floating<T>::type wished_r_t;


  // return type conformity test
  NT2_TEST_TYPE_IS( r_t, wished_r_t );

  // random verifications
  static const nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, T(-10), T(10));
    NT2_CREATE_BUF(tab_a1,iT, NR, T(-10), T(10));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    T a0;
    iT a1;
    for(nt2::uint32_t j =0; j < NR; ++j )
      {
        std::cout << "for params "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << ", a1 = "<< u_t(a1 = tab_a1[j])
                  << std::endl;
        NT2_TEST_ULP_EQUAL( nt2::pow(a0,a1),cephes_powil(a0,a1),2.5);
        NT2_TEST_ULP_EQUAL( nt2::pow(a0,nt2::Two<iT>()),nt2::sqr(a0),2);
        NT2_TEST_ULP_EQUAL( nt2::pow(a0,nt2::Three<iT>()),a0*nt2::sqr(a0),2);
        ulp0=nt2::max(ulpd,ulp0);
     }
     std::cout << "max ulp found is: " << ulp0 << std::endl;
   }
} // end of test for floating_

NT2_TEST_CASE_TPL ( powi_real__2_0,  NT2_REAL_TYPES)
{

  using nt2::pow;
  using nt2::tag::pow_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<pow_(T,iT)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef typename boost::dispatch::meta::as_floating<T>::type wished_r_t;


  // return type conformity test
  NT2_TEST_TYPE_IS( r_t, wished_r_t );

  // random verifications
  static const nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, T(-10), T(10));
    NT2_CREATE_BUF(tab_a1,iT, NR, T(-10), T(10));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    T a0;
    iT a1;
    for(nt2::uint32_t j =0; j < NR; ++j )
      {
        std::cout << "for params "
                  << "  a0 = "<< u_t(a0 = tab_a0[j])
                  << ", a1 = "<< u_t(a1 = tab_a1[j])
                  << std::endl;
        NT2_TEST_ULP_EQUAL( nt2::pow(a0,a1),cephes_powil(a0,a1),2.5);
        NT2_TEST_ULP_EQUAL( nt2::pow(a0,nt2::Two<iT>()),nt2::sqr(a0),2);
        NT2_TEST_ULP_EQUAL( nt2::pow(a0,nt2::Three<iT>()),a0*nt2::sqr(a0),2);
        ulp0=nt2::max(ulpd,ulp0);
     }
     std::cout << "max ulp found is: " << ulp0 << std::endl;
   }
} // end of test for floating_
