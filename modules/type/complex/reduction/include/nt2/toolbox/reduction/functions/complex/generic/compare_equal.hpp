//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TOOLBOX_REDUCTION_FUNCTIONS_COMPLEX_GENERIC_COMPARE_EQUAL_HPP_INCLUDED
#define NT2_TOOLBOX_REDUCTION_FUNCTIONS_COMPLEX_GENERIC_COMPARE_EQUAL_HPP_INCLUDED

#include <nt2/toolbox/reduction/functions/compare_equal.hpp>
#include <nt2/include/functions/real.hpp>
#include <nt2/include/functions/imag.hpp>
#include <nt2/include/constants/false.hpp>
#include <nt2/sdk/complex/complex.hpp>
#include <nt2/sdk/complex/imaginary.hpp>
#include <nt2/sdk/meta/scalar_of.hpp>
#include <nt2/sdk/meta/as_logical.hpp>
#include <nt2/sdk/complex/meta/as_real.hpp>

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::compare_equal_, tag::cpu_, (A0),
                                     ((generic_ < complex_< arithmetic_ <A0> > > ))
                                     ((generic_ < complex_< arithmetic_ <A0> > > ))
                      )
  {
    typedef typename meta::as_real<A0>::type    rA0;
    typedef typename meta::scalar_of<rA0>::type  sA0;
    typedef typename meta::as_logical<sA0>::type result_type;
    NT2_FUNCTOR_CALL_REPEAT(2)
    {
      result_type tmp =  compare_equal(nt2::real(a0), nt2::real(a1));
      if (!tmp)
        return False<result_type>();
      else
        return compare_equal(nt2::imag(a0), nt2::imag(a1));
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::compare_equal_, tag::cpu_, (A0),
                                     ((generic_ < imaginary_< arithmetic_ <A0> > > ))
                                     ((generic_ < imaginary_< arithmetic_ <A0> > > ))
                      )
  {
    typedef typename meta::as_real<A0>::type    rA0;
    typedef typename meta::scalar_of<rA0>::type  sA0;
    typedef typename meta::as_logical<sA0>::type result_type;
    NT2_FUNCTOR_CALL_REPEAT(2)
    {
      return compare_equal(nt2::imag(a0), nt2::imag(a1));
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::compare_equal_, tag::cpu_, (A0),
                                     ((generic_ < dry_< arithmetic_ <A0> > > ))
                                     ((generic_ < dry_< arithmetic_ <A0> > > ))
                      )
  {
    typedef typename meta::as_real<A0>::type    rA0;
    typedef typename meta::scalar_of<rA0>::type  sA0;
    typedef typename meta::as_logical<sA0>::type result_type;
    NT2_FUNCTOR_CALL_REPEAT(2)
    {
      return compare_equal(nt2::real(a0), nt2::real(a1));
    }
  };
} }

#endif
