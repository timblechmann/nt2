//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 dual toolbox - two_sqr/scalar Mode"

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
#include <nt2/toolbox/dual/include/two_sqr.hpp>
#include <boost/fusion/tuple.hpp>

NT2_TEST_CASE_TPL ( two_sqr_real__1_0,  NT2_REAL_TYPES)
{
  
  using nt2::two_sqr;
  using nt2::tag::two_sqr_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<two_sqr_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef boost::fusion::tuple<T,T> wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;
  r_t res;
  res = two_sqr(nt2::One<T>()+nt2::Eps<T>());
  std::cout << boost::fusion::at_c<0>(res)<< ", " << boost::fusion::at_c<1>(res) << std::endl; 

} // end of test for real_
