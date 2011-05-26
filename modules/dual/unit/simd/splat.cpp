//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 dual toolbox - splat/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of dual components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 05/03/2011
/// modified by jt the 10/05/2011
#include <nt2/sdk/memory/is_aligned.hpp>
#include <nt2/sdk/memory/aligned_type.hpp>
//#include <nt2/sdk/memory/load.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
//#include <nt2/sdk/constant/real.hpp>
//#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/include/functions/max.hpp>
#include <nt2/include/functions/splat.hpp>
#include <nt2/toolbox/dual/include/splat.hpp>  

NT2_TEST_CASE_TPL ( splat_dual__1_0,  (nt2::dual<float>))//(nt2::dual<double>))
{
  using nt2::splat;
  using nt2::tag::splat_;
  using nt2::load; 
  using nt2::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename T::part stype; 
 
  typedef native<nt2::dual<stype>,ext_t>   type;
  //  typedef nt2::dual<native<stype,ext_t> >   rtype;
  nt2::dual<stype> o(nt2::One<stype>());
  o.print();
  std::cout << nt2::type_id < type > () << std::endl;
  std::cout << nt2::type_id <stype > () << std::endl;

  typedef typename type::vtype   vtype;
  vtype oo =  nt2::One<vtype>(); 
  vtype zz =  nt2::Zero<vtype>();
  type a = type(oo, zz);
  a.print();
  type b = a+a;
  b.print();
  std::cout << nt2::type_id < type > () << std::endl;
  std::cout << nt2::type_id < typename type::type > () << std::endl;
  std::cout << nt2::type_id < typename type::vtype > () << std::endl;
  
//   type c =
  nt2::splat<type>(o);
//   c.print();
  
    //  std::cout << o << " --> " << a << std::endl; 
} // end of test for dual_
  
