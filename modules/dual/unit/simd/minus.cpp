//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 dual toolbox - minus/simd Mode"

// //////////////////////////////////////////////////////////////////////////////
// // Test behavior of dual components in simd mode
// //////////////////////////////////////////////////////////////////////////////
// /// created by jt the 05/03/2011
// /// modified by jt the 05/05/2011
#include <nt2/sdk/memory/is_aligned.hpp>
#include <nt2/sdk/memory/aligned_type.hpp>
#include <nt2/sdk/memory/load.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/include/functions/max.hpp>
#include <nt2/toolbox/dual/include/minus.hpp>

NT2_TEST_CASE_TPL ( minus_dual__2_0,  (nt2::dual<float>)(nt2::dual<double>))
{
  using nt2::minus;
  using nt2::tag::minus_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef typename T::part sT; 
  typedef native<sT,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef nt2::dual < vT >                           type;    

  std::cout << std::endl; 
  type a(nt2::One<vT>(), -nt2::Eps<vT>());
  type b(nt2::One<vT>(), nt2::Eps<vT>()/nt2::Four<vT>());
  a.print("a"); 
  b.print("b");
  std::cout << nt2::get<0>(a) << " --- " << nt2::get<1>(a) <<  std::endl; 
  //  type c = minus(a, b);
//   c.print("c"); 

} // end of test for dual_
