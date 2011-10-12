//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 boost.simd.arithmetic toolbox - logical_xor/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.arithmetic components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 01/12/2010
/// 
#include <boost/simd/toolbox/arithmetic/include/functions/logical_xor.hpp>
#include <boost/simd/include/functions/ulpdist.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/sdk/memory/buffer.hpp>
#include <boost/simd/toolbox/constant/constant.hpp>
#include <boost/simd/sdk/memory/is_aligned.hpp>
#include <boost/simd/sdk/memory/aligned_type.hpp>
#include <boost/simd/include/functions/load.hpp>

#ifdef __LRB__
#define REF &1
#else
#define REF [0]
#endif
NT2_TEST_CASE_TPL ( logical_xor_real__2_0,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::logical_xor;
  using boost::simd::tag::logical_xor_;
  using boost::simd::load; 
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<logical_xor_(vT,vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_ULP_EQUAL(logical_xor(boost::simd::splat<vT>(0),boost::simd::splat<vT>(1))REF!=0, true, 0);
  NT2_TEST_ULP_EQUAL(logical_xor(boost::simd::splat<vT>(3),boost::simd::splat<vT>(0))REF!=0, true, 0);
  NT2_TEST_ULP_EQUAL(logical_xor(boost::simd::Inf<vT>(), boost::simd::Inf<vT>())REF!=0, false, 0);
  NT2_TEST_ULP_EQUAL(logical_xor(boost::simd::Minf<vT>(), boost::simd::Minf<vT>())REF!=0, false, 0);
  NT2_TEST_ULP_EQUAL(logical_xor(boost::simd::Mone<vT>(), boost::simd::Mone<vT>())REF!=0, false, 0);
  NT2_TEST_ULP_EQUAL(logical_xor(boost::simd::Nan<vT>(), boost::simd::Nan<vT>())REF!=0, false, 0);
  NT2_TEST_ULP_EQUAL(logical_xor(boost::simd::One<vT>(), boost::simd::One<vT>())REF!=0, false, 0);
  NT2_TEST_ULP_EQUAL(logical_xor(boost::simd::Zero<vT>(), boost::simd::Zero<vT>())REF!=0, false, 0);
} // end of test for floating_
