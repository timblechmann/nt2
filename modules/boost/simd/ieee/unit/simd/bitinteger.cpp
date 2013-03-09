//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.ieee toolbox - bitinteger/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.ieee components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 04/12/2010
///
#include <boost/simd/toolbox/ieee/include/functions/bitinteger.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/simd/include/functions/bitfloating.hpp>
#include <boost/dispatch/meta/as_integer.hpp>

#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/toolbox/constant/constant.hpp>


NT2_TEST_CASE_TPL ( bitinteger_real__1_0,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::bitinteger;
  using boost::simd::tag::bitinteger_;
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<bitinteger_(vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  NT2_TEST_EQUAL(bitinteger(boost::simd::Inf<vT>() )[0]   ,bitinteger(boost::simd::Inf<T>())   );
  NT2_TEST_EQUAL(bitinteger(boost::simd::Minf<vT>())[0]  ,bitinteger(boost::simd::Minf<T>())  );
  NT2_TEST_EQUAL(bitinteger(boost::simd::Mone<vT>())[0]  ,bitinteger(boost::simd::Mone<T>())  );
  NT2_TEST_EQUAL(bitinteger(boost::simd::Nan<vT>() )[0]   ,bitinteger(boost::simd::Nan<T>())   );
  NT2_TEST_EQUAL(bitinteger(boost::simd::One<vT>() )[0]   ,bitinteger(boost::simd::One<T>())   );
  NT2_TEST_EQUAL(bitinteger(boost::simd::Valmax<vT>())[0],bitinteger(boost::simd::Valmax<T>()));
  NT2_TEST_EQUAL(bitinteger(boost::simd::Zero<vT>())[0]  ,bitinteger(boost::simd::Zero<T>())  );

} // end of test for floating_
