//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 dual toolbox - splat/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of dual components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 05/03/2011
/// modified by jt the 10/05/2011
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/include/constants/real.hpp>
#include <nt2/include/constants/infinites.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/include/functions/splat.hpp>
#include <nt2/toolbox/dual/include/splat.hpp>
// specific includes for arity 1 tests
#include <nt2/toolbox/dual/specific/dual_types.hpp>
#include <nt2/toolbox/dual/function/scalar/splat.hpp>

#include <nt2/sdk/details/type_id.hpp>

NT2_TEST_CASE_TPL ( splat_dual__1_0,  (nt2::dual<float>)(nt2::dual<double>))
{
  /*
  using nt2::splat;
  using nt2::tag::splat_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<splat_(T,nt2::meta::as_<T>)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef T wished_r_t;


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;
*/
  nt2::display_type<T>();
  nt2::display_type<typename nt2::meta::hierarchy_of<T>::type>();

  T x,y;

  y = nt2::splat<T>(x);

} // end of test for dual_
