//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TOOLBOX_BOOLEAN_FUNCTIONS_COMPLEX_GENERIC_IF_ONE_ELSE_ZERO_HPP_INCLUDED
#define NT2_TOOLBOX_BOOLEAN_FUNCTIONS_COMPLEX_GENERIC_IF_ONE_ELSE_ZERO_HPP_INCLUDED

#include <nt2/toolbox/boolean/functions/if_one_else_zero.hpp>
#include <nt2/include/functions/real.hpp>
#include <nt2/include/functions/imag.hpp>
#include <nt2/include/functions/is_nez.hpp>
#include <nt2/sdk/simd/logical.hpp>

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::if_one_else_zero_, tag::cpu_, (A0)
                            ,  (generic_< complex_<floating_<A0> > >)
                            )
  {
    typedef A0 result_type;
    result_type  operator()(A0 const& a0) const
    {
      return if_one_else_zero(is_nez(a0));
    }
  };
} }

#endif