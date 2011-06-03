//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 trigonometric toolbox - cos/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of trigonometric components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 11/02/2011
/// modified by jt the 18/04/2011
#include <nt2/sdk/memory/is_aligned.hpp>
#include <nt2/sdk/memory/aligned_type.hpp>
#include <nt2/include/functions/load.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/include/constants/real.hpp>
#include <nt2/include/constants/infinites.hpp>
#include <nt2/include/functions/max.hpp>
#include <nt2/toolbox/trigonometric/include/cos.hpp>

NT2_TEST_CASE_TPL ( cos_real__1_0,  NT2_REAL_TYPES)
{
  using nt2::cos;
  using nt2::tag::cos_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<cos_(vT)>::type r_t;
  typedef typename nt2::meta::call<cos_(T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;
  // random verifications
  static const uint32_t NR = 10000;
  {
    NT2_CREATE_BUF(tab_a0,T, NR, T(-60), T(60));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    for(uint32_t j = 0; j < NR/cardinal_of<n_t>::value; j++)
      {
        vT a0 = load<vT>(&tab_a0[0],j);
        r_t v = cos(a0);
        for(int i = 0; i< cardinal_of<n_t>::value; i++)
        {
          int k = i+j*cardinal_of<n_t>::value;
          NT2_TEST_ULP_EQUAL( v[i],ssr_t(nt2::cos(tab_a0[k])), 0.5);
          ulp0 = nt2::max(ulpd,ulp0);
        }
      }
    std::cout << "max ulp found is: " << ulp0 << std::endl;
  }

  // specific values tests
  NT2_TEST_ULP_EQUAL(cos(-nt2::Pi<vT>())[0], nt2::Mone<sr_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(cos(-nt2::Pi<vT>()/nt2::splat<vT>(2))[0], nt2::Zero<sr_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(cos(-nt2::Pi<vT>()/nt2::splat<vT>(4))[0], nt2::Sqrt_2o_2<sr_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(cos(nt2::Inf<vT>())[0], nt2::Nan<sr_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(cos(nt2::Minf<vT>())[0], nt2::Nan<sr_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(cos(nt2::Nan<vT>())[0], nt2::Nan<sr_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(cos(nt2::Pi<vT>())[0], nt2::Mone<sr_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(cos(nt2::Pi<vT>()/nt2::splat<vT>(2))[0], nt2::Zero<sr_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(cos(nt2::Pi<vT>()/nt2::splat<vT>(4))[0], nt2::Sqrt_2o_2<sr_t>(), 0.5);
  NT2_TEST_ULP_EQUAL(cos(nt2::Zero<vT>())[0], nt2::One<sr_t>(), 0.5);
} // end of test for real_
