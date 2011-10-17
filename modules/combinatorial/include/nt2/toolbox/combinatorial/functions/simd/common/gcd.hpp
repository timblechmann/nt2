//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_COMBINATORIAL_FUNCTIONS_SIMD_COMMON_GCD_HPP_INCLUDED
#define NT2_TOOLBOX_COMBINATORIAL_FUNCTIONS_SIMD_COMMON_GCD_HPP_INCLUDED
#include <nt2/include/constants/digits.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/seladd.hpp>
#include <nt2/include/functions/is_nez.hpp>
#include <nt2/include/functions/select.hpp>
#include <nt2/include/functions/round2even.hpp>
#include <nt2/include/functions/rem.hpp>
#include <nt2/include/functions/bitwise_any.hpp>
#include <nt2/include/functions/bitwise_ornot.hpp>
#include <nt2/include/functions/bitwise_and.hpp>
#include <nt2/include/functions/is_flint.hpp>
#include <nt2/include/functions/ifelsezero.hpp>
#include <nt2/include/functions/ifnotnanelse.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::gcd_, tag::cpu_
                            , (A0)(X)
                            , ((simd_<arithmetic_<A0>,X>))((simd_<arithmetic_<A0>,X>))
                            )
  {
    typedef A0 result_type;
    NT2_FUNCTOR_CALL_REPEAT(2)
    {
      typedef typename meta::boolean<A0>::type bA0; 
      A0 a = a0, b = a1;
      bA0 t= is_nez(b);
      while (nt2::bitwise_any(t))
      {
        A0 r = ifelsezero(t, rem(a, b));
        a = sel(t, b, a);
        b = r;
        t = is_nez(b);
      }
      return a;
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is floating_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::gcd_, tag::cpu_
                            , (A0)(X)
                            , ((simd_<floating_<A0>,X>))((simd_<floating_<A0>,X>))
                            )
  {

    typedef A0 result_type;

    NT2_FUNCTOR_CALL_REPEAT(2)
    {
      typedef typename meta::boolean<A0>::type bA0; 
      bA0 ints = b_and(is_flint(a1), is_flint(a0)); 
      A0 a = a0; //b_and(round2even(a0),ints); 
      A0 b = a1; //b_and(round2even(a1),ints);
      bA0 t= is_nez(b);
      while (nt2::bitwise_any(t))
      {
        A0 r = ifelsezero(t, rem(a, b));
        a = sel(t, b, a);
        b = r;
        t = is_nez(b);
      }
      return ifnotnanelse(ints, round2even(a));
    }
  };
} }

#endif
