//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.ieee toolbox - modf/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.ieee components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 04/12/2010
///
#include <boost/simd/toolbox/ieee/include/functions/modf.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/fusion/tuple.hpp>
#include <boost/simd/include/functions/trunc.hpp>
#include <boost/simd/include/functions/frac.hpp>

#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/toolbox/constant/constant.hpp>
#include <boost/simd/include/functions/splat.hpp>
#include <boost/simd/toolbox/constant/constant.hpp>


NT2_TEST_CASE_TPL ( modf_real__1_0,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::modf;
  using boost::simd::tag::modf_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef typename boost::dispatch::meta::as_floating<T>::type ftype;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<modf_(vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  vT vn, vf;
  T n, f;
  T a[6] = {T(0), T(1), T(1.5), boost::simd::Inf<T>(), boost::simd::Minf<T>(), boost::simd::Nan<T>()};
  for(int i=0; i < 6; i++)
    {
      modf(a[i], n, f);
      modf(boost::simd::splat<vT>(a[i]), vn, vf);
      NT2_TEST_EQUAL(vn[0], n);
      NT2_TEST_EQUAL(vf[0], f);
    }
} // end of test for floating_
