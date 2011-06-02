//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 dd_reals toolbox - splat/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of dd_reals components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 05/03/2011
/// modified by jt the 02/06/2011
#include <nt2/sdk/memory/is_aligned.hpp>
#include <nt2/sdk/memory/aligned_type.hpp>
#include <nt2/include/functions/load.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/include/constants/real.hpp>
#include <nt2/include/constants/infinites.hpp>
//#include <nt2/include/functions/max.hpp>
#include <nt2/toolbox/dd_reals/include/splat.hpp>

NT2_TEST_CASE_TPL ( splat_dd_reals__1_0,  (nt2::dd_reals<float>)(nt2::dd_reals<double>))
{
  using nt2::splat;
  using nt2::tag::splat_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<splat_(vT)>::type r_t;
  typedef typename nt2::meta::call<splat_(T)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;
  typedef typename T::part stype; 
 
  typedef native<nt2::dd_reals<stype>,ext_t>   type;
  //  typedef nt2::dd_reals<native<stype,ext_t> >   rtype;
  nt2::dd_reals<stype> o(nt2::One<stype>(), nt2::Eps<stype>());
  std::cout << nt2::type_id < typename nt2::meta::hierarchy_of<nt2::dd_reals<stype> >::type > () << std::endl;
  std::cout << nt2::type_id < typename nt2::meta::hierarchy_of<type>::type > () << std::endl;

  typedef typename type::vtype   vtype;
  vtype oo =  nt2::One<vtype>(); 
  vtype zz =  nt2::Zero<vtype>();
  type a = type(oo, zz);
  a.print();
  type b = a+a;
  b.print();
//   std::cout << nt2::type_id < type > () << std::endl;
//   std::cout << nt2::type_id < typename type::type > () << std::endl;
//   std::cout << nt2::type_id < typename type::vtype > () << std::endl;
   
  o.print("o(nt2::One<stype>()) = ");
  type c = nt2::splat<type>(o);
  c.print("nt2::splat<type>(o) =  ");
  
} // end of test for dd_reals_
