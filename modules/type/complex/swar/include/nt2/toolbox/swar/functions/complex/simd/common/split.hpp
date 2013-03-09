//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TOOLBOX_SWAR_FUNCTIONS_COMPLEX_SIMD_COMMON_SPLIT_HPP_INCLUDED
#define NT2_TOOLBOX_SWAR_FUNCTIONS_COMPLEX_SIMD_COMMON_SPLIT_HPP_INCLUDED
#include <nt2/toolbox/swar/functions/split.hpp>
#include <nt2/include/functions/store.hpp>
#include <boost/simd/sdk/meta/cardinal_of.hpp>
#include <boost/simd/sdk/meta/scalar_of.hpp>
#include <boost/fusion/tuple.hpp>
#include <nt2/sdk/complex/complex.hpp>
#include <nt2/sdk/complex/meta/as_complex.hpp>
#include <nt2/sdk/complex/meta/as_real.hpp>
#include <nt2/sdk/complex/meta/as_dry.hpp>
#include <nt2/include/functions/imag.hpp>
#include <nt2/include/functions/real.hpp>
// TODO pb simd_ is not recognized here !?
namespace nt2 { namespace ext
{
//   NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::split_, tag::cpu_,
//                               (A0)(A1)(X),
//                               ((simd_<complex_<arithmetic_<A0> >,X>))
//                               ((simd_<complex_<arithmetic_<A1> >,X>))
//                               ((simd_<complex_<arithmetic_<A1> >,X>))
//                             )
//   {
//     typedef int result_type;
//     inline result_type operator()(A0 const& a0,A1 & a1, A1 & a2) const
//     {
//       typedef typename meta::as_real<A1>::type rA1;
//       rA1 ar0, ar1, ai0, ai1;
//       split(nt2::real(a0), ar0, ar1);
//       split(nt2::imag(a0), ai0, ai1);
//       a1 = A1(ar0, ai0);
//       a2 = A1(ar1, ai1);
//       return 0;
//     }
//   };

//   NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::split_, tag::cpu_,
//                               (A0)(X),
//                               ((simd_<complex_<arithmetic_<A0> >,X>))
//                             )
//   {
//     typedef typename meta::as_real<A0>::type rA0;
//     typedef typename boost::dispatch::meta::upgrade<rA0>::type rU;
//     typedef typename meta::as_complex<rU>::type crU;
//     typedef boost::fusion::tuple<crU, crU> result_type;

//     NT2_FUNCTOR_CALL_REPEAT(1)
//     {
//       result_type res;
//       nt2::split(a0,  boost::fusion::at_c<0>(res),  boost::fusion::at_c<1>(res));
//       return res;
//     }
//   };

//    NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::split_, tag::cpu_,
//                               (A0)(A1)(X),
//                               ((simd_<imaginary_<arithmetic_<A0> >,X>))
//                               ((simd_<imaginary_<arithmetic_<A1> >,X>))
//                               ((simd_<imaginary_<arithmetic_<A1> >,X>))
//                             )
//   {
//     typedef int result_type;
//     inline result_type operator()(A0 const& a0,A1 & a1, A1 & a2) const
//     {
//       typedef typename meta::as_real<A1>::type rA1;
//       rA1 ai0, ai1;
//       split(nt2::imag(a0), ai0, ai1);
//       a1 = A1(ai0);
//       a2 = A1(ai1);
//       return 0;
//     }
//   };

//   NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::split_, tag::cpu_,
//                               (A0)(X),
//                               ((simd_<imaginary_<arithmetic_<A0> >,X>))
//                             )
//   {
//     typedef typename meta::as_real<A0>::type rA0;
//     typedef typename boost::dispatch::meta::upgrade<rA0>::type rU;
//     typedef typename meta::as_imaginary<rU>::type crU;
//     typedef boost::fusion::tuple<crU, crU> result_type;

//     NT2_FUNCTOR_CALL_REPEAT(1)
//     {
//       result_type res;
//       nt2::split(a0,  boost::fusion::at_c<0>(res),  boost::fusion::at_c<1>(res));
//       return res;
//     }
//   };

//   NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::split_, tag::cpu_,
//                               (A0)(A1)(X),
//                               ((simd_<dry_<arithmetic_<A0> >,X>))
//                               ((simd_<dry_<arithmetic_<A1> >,X>))
//                               ((simd_<dry_<arithmetic_<A1> >,X>))
//                             )
//   {
//     typedef int result_type;
//     inline result_type operator()(A0 const& a0,A1 & a1, A1 & a2) const
//     {
//       typedef typename meta::as_real<A1>::type rA1;
//       rA1 ai0, ai1;
//       split(nt2::imag(a0), ai0, ai1);
//       a1 = A1(ai0);
//       a2 = A1(ai1);
//       return 0;
//     }
//   };

//   NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::split_, tag::cpu_,
//                               (A0)(X),
//                               ((simd_<dry_<arithmetic_<A0> >,X>))
//                             )
//   {
//     typedef typename meta::as_real<A0>::type rA0;
//     typedef typename boost::dispatch::meta::upgrade<rA0>::type rU;
//     typedef typename meta::as_dry<rU>::type crU;
//     typedef boost::fusion::tuple<crU, crU> result_type;

//     NT2_FUNCTOR_CALL_REPEAT(1)
//     {
//       result_type res;
//       nt2::split(a0,  boost::fusion::at_c<0>(res),  boost::fusion::at_c<1>(res));
//       return res;
//     }
//   };
} }

#endif
