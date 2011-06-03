//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 dd_reals toolbox - unary_plus/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of dd_reals components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 05/03/2011
/// modified by jt the 02/06/2011
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/include/constants/real.hpp>
#include <nt2/include/constants/infinites.hpp>
//#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/toolbox/dd_reals/include/unary_plus.hpp>
// specific includes for arity 1 tests
#include <nt2/toolbox/dd_reals/specific/dd_reals_types.hpp>

NT2_TEST_CASE_TPL ( unary_plus_dd_reals__1_0,  (nt2::dd_reals<float>)(nt2::dd_reals<double>))
{
  
  using nt2::unary_plus;
  using nt2::tag::unary_plus_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<unary_plus_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef T wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;

} // end of test for dd_reals_
