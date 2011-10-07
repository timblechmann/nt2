// //////////////////////////////////////////////////////////////////////////////
// ///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
// ///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
// ///
// ///          Distributed under the Boost Software License, Version 1.0
// ///                 See accompanying file LICENSE.txt or copy at
// ///                     http://www.boost.org/LICENSE_1_0.txt
// //////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 boost.simd.operator toolbox - plus/simd Mode"

// //////////////////////////////////////////////////////////////////////////////
// // unit test behavior of boost.simd.operator components in simd mode
// //////////////////////////////////////////////////////////////////////////////
// /// created  by jt the 18/02/2011
// /// 
#include <boost/simd/toolbox/operator/include/functions/plus.hpp>
#include <boost/simd/toolbox/operator/include/functions/minus.hpp>
#include <boost/simd/toolbox/predicates/include/functions/is_equal.hpp>
#include <boost/simd/toolbox/predicates/include/functions/is_not_equal.hpp>
#include <boost/simd/toolbox/predicates/include/functions/is_less.hpp>
#include <boost/simd/toolbox/predicates/include/functions/is_less_equal.hpp>
#include <boost/simd/toolbox/predicates/include/functions/is_greater.hpp>  
#include <boost/simd/toolbox/predicates/include/functions/is_greater_equal.hpp>
#include <boost/simd/toolbox/predicates/include/functions/is_nan.hpp>
#include <boost/simd/toolbox/predicates/include/functions/is_finite.hpp>
#include <iostream>
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


NT2_TEST_CASE_TPL ( plus_real__2_0,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::plus;
  using boost::simd::tag::plus_;
  using boost::simd::load; 
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<plus_(vT,vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;


   // specific values tests
  NT2_TEST_EQUAL(plus(boost::simd::Inf<vT>(), boost::simd::Inf<vT>())[0], boost::simd::Inf<sr_t>());
  NT2_TEST_EQUAL(plus(boost::simd::Minf<vT>(), boost::simd::Minf<vT>())[0], boost::simd::Minf<sr_t>());
  NT2_TEST_EQUAL(plus(boost::simd::Nan<vT>(), boost::simd::Nan<vT>())[0], boost::simd::Nan<sr_t>());
  NT2_TEST_EQUAL(plus(boost::simd::One<vT>(),boost::simd::Zero<vT>())[0], boost::simd::One<sr_t>());
  NT2_TEST_EQUAL(plus(boost::simd::Zero<vT>(), boost::simd::Zero<vT>())[0], boost::simd::Zero<sr_t>());
  std::cout << boost::simd::Zero<vT>() << std::endl; 
 } // end of test for floating_

NT2_TEST_CASE_TPL ( plus_integer__2_0,  BOOST_SIMD_SIMD_INTEGRAL_TYPES)
{
  using boost::simd::plus;
  using boost::simd::tag::plus_;
  using boost::simd::load; 
  using boost::simd::native;
  using boost::simd::meta::cardinal_of;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename boost::dispatch::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename boost::dispatch::meta::call<plus_(vT,vT)>::type r_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type sr_t;
  typedef typename boost::simd::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(plus(boost::simd::One<vT>(), boost::simd::One<vT>())[0], boost::simd::Two<sr_t>());
  NT2_TEST_EQUAL(plus(boost::simd::One<vT>(),boost::simd::Zero<vT>())[0], boost::simd::One<sr_t>());
  NT2_TEST_EQUAL(plus(boost::simd::Zero<vT>(), boost::simd::Zero<vT>())[0], boost::simd::Zero<sr_t>());
} // end of test for integer_



// void pb(unsigned short a,  int n)
// {
//   unsigned short j = 1; 
//   for(int i =  0;  i < n;  i++){
//     std::cout << ((a&j)!= 0);
//     j <<= 1;
//   }
//   std::cout << std::endl;
// }

// int main(){
//   typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
//   using boost::simd::native;
//   typedef native<double, ext_t>           n_t;
//   using boost::simd::meta::cardinal_of;
//   using boost::simd::meta::boolean; 
//   n_t a = {1., 2., 3., 4., 5., 6., 7., 8.};
//   n_t b = {1., 3., 4., .5, 5., 7., 8., 8.};
//   n_t c = a-b;
//   typedef typename boolean<n_t>::type b_t;
//   std::cout << is_equal(a, b) << std::endl; 
//   pb(is_equal(a, b), 8);
//   std::cout << a << std::endl;
//   std::cout << b << std::endl;  
//   std::cout << c << std::endl; 
//   c = a+b;
//   std::cout << c << std::endl;
//   //  std::cout << boost::simd::ulpdist(a, b) << std::endl; 
//  return 0; 
// }
