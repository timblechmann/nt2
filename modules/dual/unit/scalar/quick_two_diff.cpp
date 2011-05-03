//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 dual toolbox - quick_two_diff/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of dual components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 05/03/2011
/// modified by jt the 03/05/2011
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/toolbox/dual/include/quick_two_diff.hpp>

NT2_TEST_CASE_TPL ( quick_two_diff_real__2_0,  NT2_REAL_TYPES)
{
  
  using nt2::quick_two_diff;
  using nt2::tag::quick_two_diff_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<quick_two_diff_(T,T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef boost::fusion::tuple<T,T> wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;

} // end of test for real_
