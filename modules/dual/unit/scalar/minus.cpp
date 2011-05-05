//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 dual toolbox - minus/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of dual components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 05/03/2011
/// modified by jt the 05/05/2011
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/toolbox/dual/include/minus.hpp>
// specific includes for arity 2 tests
#include <nt2/toolbox/dual/specific/dual_types.hpp>

NT2_TEST_CASE_TPL ( minus_dual__2_0,  (nt2::dual<float>)(nt2::dual<double>))
{
  
  using nt2::minus;
  using nt2::tag::minus_;
  typedef typename nt2::meta::call<minus_(T,T)>::type r_t;
  typedef T wished_r_t;
  typedef typename T::type type; 


  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 
  double ulpd;
  ulpd=0.0;
  T a(nt2::One<type>(), -nt2::Eps<type>());
  T b(nt2::One<type>(), nt2::Eps<type>()/16);
  a.print("a"); 
  b.print("b"); 
  T c = minus(a, b);
  c.print("a-b"); 
  T d = (a-b);
  d.print("a-b");
  T e = b- nt2::One<type>();
  e.print("b-1");
  T f = minus(nt2::One<type>(), b);
  f.print("1-b");
  T g = nt2::One<type>()-b;
  g.print("1-b");
  T h(nt2::Inf<type>(), nt2::Zero<type>());
  h.print("h");
  T i = h-h;
  i.print("h-h");
} // end of test for dual_
