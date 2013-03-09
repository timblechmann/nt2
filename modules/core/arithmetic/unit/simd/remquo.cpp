//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 arithmetic toolbox - remquo/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of arithmetic components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 01/12/2010
///
#include <nt2/toolbox/arithmetic/include/functions/remquo.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/fusion/tuple.hpp>
#include <boost/fusion/tuple.hpp>
#include <nt2/include/functions/remainder.hpp>
#include <nt2/include/functions/idivround.hpp>

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



NT2_TEST_CASE_TPL ( remquo_real__2_0,  NT2_SIMD_REAL_TYPES)
{
  using nt2::remquo;
  using nt2::tag::remquo_;
  using boost::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<remquo_(vT,vT)>::type r_t;
  typedef typename nt2::meta::call<remquo_(T,T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;

  T a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  T b[10] = {1, 3, 4, 5, 6, 7, 8, 9, 10};
  vT r;
  ivT n;
  T sr = 0;
  iT sn = 0;

  for(int i=0; i < 10; ++i)
    {
      for(int j=0; j < 10; ++j)
        {
          remquo(nt2::splat<vT>(a[i]), nt2::splat<vT>(b[j]), r, n);
          remquo(a[i], b[j], sr, sn);
          NT2_TEST_EQUAL(r[0], sr);
          NT2_TEST_EQUAL(n[0], sn);
       }
   }
} // end of test for floating_
