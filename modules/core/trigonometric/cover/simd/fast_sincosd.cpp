//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 trigonometric toolbox - fast_sincosd/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// cover test behavior of trigonometric components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 11/02/2011
///
#include <nt2/toolbox/trigonometric/include/functions/fast_sincosd.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <nt2/include/functions/max.hpp>
#include <boost/fusion/tuple.hpp>
#include <nt2/toolbox/trigonometric/constants.hpp>
#include <nt2/include/functions/sind.hpp>
#include <nt2/include/functions/cosd.hpp>

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
#include <nt2/include/functions/load.hpp>
#include <nt2/toolbox/constant/constant.hpp>


NT2_TEST_CASE_TPL ( fast_sincosd_real__1_0,  NT2_SIMD_REAL_TYPES)
{
  using nt2::fast_sincosd;
  using nt2::tag::fast_sincosd_;
  using nt2::load;
  using boost::simd::native;
  using nt2::meta::cardinal_of;
  typedef typename boost::dispatch::meta::as_floating<T>::type ftype;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<fast_sincosd_(vT)>::type r_t;
  typedef typename nt2::meta::call<fast_sincosd_(T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;

  // random verifications
  static const nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    typedef typename boost::dispatch::meta::as_floating<T>::type ftype;
    NT2_CREATE_BUF(tab_a0,T, NR, T(-45), T(45));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    for(nt2::uint32_t j = 0; j < NR;j+=cardinal_of<n_t>::value)
      {
        vT a0 = load<vT>(&tab_a0[0],j);
        r_t r = nt2::fast_sincosd(a0);
        for(nt2::uint32_t i = 0; i< cardinal_of<n_t>::value; i++)
        {

          sr_t sr =  nt2::fast_sincosd(a0[i]);
          NT2_TEST_ULP_EQUAL( boost::fusion::get<0>(r)[i],
                                    boost::fusion::get<0>(sr), 1.5);
          ulp0 = nt2::max(ulpd,ulp0);
          NT2_TEST_ULP_EQUAL( boost::fusion::get<1>(r)[i],
                                    boost::fusion::get<1>(sr), 1.5);
          ulp0 = nt2::max(ulpd,ulp0);
        }
      }
    std::cout << "max ulp found is: " << ulp0 << std::endl;
  }
} // end of test for floating_

NT2_TEST_CASE_TPL ( fast_sincosd_int_convert__1_0,  NT2_SIMD_INT_CONVERT_TYPES)
{
  using nt2::fast_sincosd;
  using nt2::tag::fast_sincosd_;
  using nt2::load;
  using boost::simd::native;
  using nt2::meta::cardinal_of;
  typedef typename boost::dispatch::meta::as_floating<T>::type ftype;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<fast_sincosd_(vT)>::type r_t;
  typedef typename nt2::meta::call<fast_sincosd_(T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;

  // random verifications
  static const nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    typedef typename boost::dispatch::meta::as_floating<T>::type ftype;
    NT2_CREATE_BUF(tab_a0,T, NR, T(-45), T(45));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    for(nt2::uint32_t j = 0; j < NR;j+=cardinal_of<n_t>::value)
      {
        vT a0 = load<vT>(&tab_a0[0],j);
        r_t r = nt2::fast_sincosd(a0);
        for(nt2::uint32_t i = 0; i< cardinal_of<n_t>::value; i++)
        {

          sr_t sr =  nt2::fast_sincosd(a0[i]);
          NT2_TEST_ULP_EQUAL( boost::fusion::get<0>(r)[i],
                                    boost::fusion::get<0>(sr), 1.5);
          ulp0 = nt2::max(ulpd,ulp0);
          NT2_TEST_ULP_EQUAL( boost::fusion::get<1>(r)[i],
                                    boost::fusion::get<1>(sr), 1.5);
          ulp0 = nt2::max(ulpd,ulp0);
        }
      }
    std::cout << "max ulp found is: " << ulp0 << std::endl;
  }
} // end of test for int_convert_

NT2_TEST_CASE_TPL ( fast_sincosd_uint_convert__1_0,  NT2_SIMD_UINT_CONVERT_TYPES)
{
  using nt2::fast_sincosd;
  using nt2::tag::fast_sincosd_;
  using nt2::load;
  using boost::simd::native;
  using nt2::meta::cardinal_of;
  typedef typename boost::dispatch::meta::as_floating<T>::type ftype;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<fast_sincosd_(vT)>::type r_t;
  typedef typename nt2::meta::call<fast_sincosd_(T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;

  // random verifications
  static const nt2::uint32_t NR = NT2_NB_RANDOM_TEST;
  {
    typedef typename boost::dispatch::meta::as_floating<T>::type ftype;
    NT2_CREATE_BUF(tab_a0,T, NR, T(-45), T(45));
    double ulp0, ulpd ; ulpd=ulp0=0.0;
    for(nt2::uint32_t j = 0; j < NR;j+=cardinal_of<n_t>::value)
      {
        vT a0 = load<vT>(&tab_a0[0],j);
        r_t r = nt2::fast_sincosd(a0);
        for(nt2::uint32_t i = 0; i< cardinal_of<n_t>::value; i++)
        {

          sr_t sr =  nt2::fast_sincosd(a0[i]);
          NT2_TEST_ULP_EQUAL( boost::fusion::get<0>(r)[i],
                                    boost::fusion::get<0>(sr), 1.5);
          ulp0 = nt2::max(ulpd,ulp0);
          NT2_TEST_ULP_EQUAL( boost::fusion::get<1>(r)[i],
                                    boost::fusion::get<1>(sr), 1.5);
          ulp0 = nt2::max(ulpd,ulp0);
        }
      }
    std::cout << "max ulp found is: " << ulp0 << std::endl;
  }
} // end of test for uint_convert_
