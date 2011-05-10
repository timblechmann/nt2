//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 dual toolbox - plus/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of dual components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 05/03/2011
/// modified by jt the 04/05/2011
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
#include <nt2/toolbox/dual/include/plus.hpp>

NT2_TEST_CASE_TPL ( plus_dual__2_0,  (nt2::dual < float>))
{
  using nt2::plus;
  using nt2::tag::plus_;
  using nt2::load;  
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename T::part stype; 

  typedef native<stype,ext_t>                          n_t;
  typedef n_t vT; 
  typedef nt2::dual<n_t>                              type;
  typedef typename nt2::meta::call<plus_(vT,vT)>::type r_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;
  type a(nt2::One<vT>(), nt2::Zero<vT>());
  type b(nt2::One<vT>(), nt2::Zero<vT>());
  type c =  nt2::plus(a, b); 
} // end of test for dual_
