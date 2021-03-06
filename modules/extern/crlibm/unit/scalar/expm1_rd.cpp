//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 crlibm toolbox - expm1_rd/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of crlibm components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 02/03/2011
///
#include <nt2/toolbox/crlibm/include/functions/expm1_rd.hpp>
#include <nt2/include/functions/expm1.hpp>

#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/include/constants/real.hpp>
#include <nt2/include/constants/infinites.hpp>


NT2_TEST_CASE_TPL ( expm1_rd_real__1_0,  NT2_REAL_TYPES)
{
  using nt2::rn;
  using nt2::crlibm::expm1_rd;
  using nt2::crlibm::tag::expm1_rd_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<expm1_rd_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef T wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;

} // end of test for floating_
