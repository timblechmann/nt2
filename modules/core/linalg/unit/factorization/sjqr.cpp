//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 linalg toolbox - sjqr factorization"

#include <nt2/table.hpp>
#include <nt2/include/functions/zeros.hpp>
#include <nt2/include/functions/ones.hpp>
#include <nt2/include/functions/eye.hpp>
#include <nt2/include/functions/sjqr.hpp>
#include <nt2/include/functions/isulpequal.hpp>
#include <nt2/include/functions/mtimes.hpp>
#include <nt2/include/functions/globalmax.hpp>
#include <nt2/include/functions/cif.hpp>
#include <nt2/include/functions/rif.hpp>
#include <nt2/include/functions/ulpdist.hpp>

#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/exceptions.hpp>
#include <nt2/sdk/unit/tests/basic.hpp>

NT2_TEST_CASE_TPL(sjqr_factorization, NT2_REAL_TYPES)
{
  using nt2::tag::factorization::sjqr_;
  
  typedef nt2::table<T> t_t;
  t_t b =       nt2::ones (4, 4, nt2::meta::as_<T>())
    + T(15)*nt2::eye  (4, 4, nt2::meta::as_<T>());
  
  nt2::details::sjqr<t_t,'A'> res(b); 
  NT2_DISPLAY(b);
  NT2_DISPLAY(res.p()); 
  NT2_DISPLAY(res.q());
  NT2_DISPLAY(res.r());
  NT2_TEST_EQUAL(res.status(), 0);
  NT2_DISPLAY(nt2::mtimes(res.q(), res.r()));
  NT2_DISPLAY(nt2::mtimes(b, res.p()));
  std::cout << nt2::globalmax(ulpdist(nt2::mtimes(res.q(), res.r()), nt2::mtimes(b, res.p()))) << std::endl; 
  NT2_TEST(nt2::isulpequal(nt2::mtimes(res.q(), res.r()), nt2::mtimes(b, res.p()), 6.0)); 
  t_t c =  nt2::rif (4, 1, nt2::meta::as_<T>());
  NT2_DISPLAY(c);
  t_t x = res.solve(c);
  NT2_DISPLAY(c);
  NT2_DISPLAY(x); 
  std::cout << nt2::globalmax(ulpdist(nt2::mtimes(b, x), c)) << std::endl; 
  NT2_TEST(nt2::isulpequal(nt2::mtimes(b, x), c, 6.0)); 
}
// NT2_TEST_CASE_TPL(sjqr_factorization2, NT2_REAL_TYPES)
// {
//   using nt2::tag::factorization::sjqr_;
  
//   typedef nt2::table<T> t_t;
//   t_t b =       nt2::ones (4, 4, nt2::meta::as_<T>())
//     + T(15)*nt2::eye  (4, 4, nt2::meta::as_<T>());
  
//   nt2::details::sjqr<t_t,'A'> res(b); 
//   NT2_DISPLAY(b);
//   NT2_DISPLAY(res.p());
//   NT2_DISPLAY(res.q());
//   NT2_DISPLAY(res.r());
//   NT2_TEST_EQUAL(res.status(), 0);
//   NT2_DISPLAY(nt2::mtimes(res.q(), res.r()));
//   NT2_DISPLAY(nt2::mtimes(b, res.p()));
//   std::cout << nt2::globalmax(ulpdist(nt2::mtimes(res.q(), res.r()), nt2::mtimes(b, res.p()))) << std::endl; 
//   NT2_TEST(nt2::isulpequal(nt2::mtimes(res.q(), res.r()), nt2::mtimes(b, res.p()), 6.0)); 
// //  t_t c =  nt2::ones (4, 1, nt2::meta::as_<T>());
// //   NT2_DISPLAY(c);
// //   t_t x = res.solve(c);
// //   NT2_DISPLAY(c);
// //   NT2_DISPLAY(x); 
// //   std::cout << nt2::globalmax(ulpdist(nt2::mtimes(b, x), c)) << std::endl; 
// //   NT2_TEST(nt2::isulpequal(nt2::mtimes(b, x), c, 6.0)); 
// }

// NT2_TEST_CASE_TPL(sjqr_factorization3, NT2_REAL_TYPES)
// {
//   using nt2::tag::factorization::sjqr_;
  
//   typedef nt2::table<T> t_t;
//   t_t b =       nt2::ones (4, 4, nt2::meta::as_<T>())
//     + T(15)*nt2::eye  (4, 4, nt2::meta::as_<T>());
  
//   nt2::details::sjqr<t_t,'A'> res(b); 
//   NT2_DISPLAY(b);
//   NT2_DISPLAY(res.p());
//   NT2_DISPLAY(res.q());
//   NT2_DISPLAY(res.r());
//   NT2_TEST_EQUAL(res.status(), 0);
//   NT2_DISPLAY(nt2::mtimes(res.q(), res.r()));
//   NT2_DISPLAY(nt2::mtimes(b, res.p()));
//   std::cout << nt2::globalmax(ulpdist(nt2::mtimes(res.q(), res.r()), nt2::mtimes(b, res.p()))) << std::endl; 
//   NT2_TEST(nt2::isulpequal(nt2::mtimes(res.q(), res.r()), nt2::mtimes(b, res.p()), 6.0)); 
// //  t_t c =  nt2::ones (4, 1, nt2::meta::as_<T>());
// //   NT2_DISPLAY(c);
// //   t_t x = res.solve(c);
// //   NT2_DISPLAY(c);
// //   NT2_DISPLAY(x); 
// //   std::cout << nt2::globalmax(ulpdist(nt2::mtimes(b, x), c)) << std::endl; 
// //   NT2_TEST(nt2::isulpequal(nt2::mtimes(b, x), c, 6.0)); 
// }
NT2_TEST_CASE_TPL(sjqr_factorization4, NT2_REAL_TYPES)
{

  size_t m = 4;
  nt2::table<long int> jpvt = nt2::_(4l, -1l, 1l); 
  nt2::table<float> z(nt2::of_size(4, 3));
  nt2::table<float> b = nt2::cif(4, 3, nt2::meta::as_<float>());
  z(jpvt, nt2::_) = b;
  z(jpvt(nt2::_(1, 4)), nt2::_) = b;
  nt2::table<int> jpvt1 = nt2::_(4, -1, 1); 
  z(jpvt1, nt2::_) = b;
  z(jpvt1(nt2::_(1, 4)), nt2::_) = b;
  
}
