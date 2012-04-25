//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_IEEE_FUNCTIONS_COMPLEX_GENERIC_ULPDIST_HPP_INCLUDED
#define NT2_TOOLBOX_IEEE_FUNCTIONS_COMPLEX_GENERIC_ULPDIST_HPP_INCLUDED

#include <nt2/toolbox/ieee/functions/ulpdist.hpp>
#include <nt2/include/functions/max.hpp>
#include <nt2/include/functions/real.hpp>
#include <nt2/include/functions/imag.hpp>
#include <nt2/sdk/complex/meta/as_real.hpp>
#include <nt2/sdk/complex/meta/as_dry.hpp>

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( ulpdist_, tag::cpu_, (A0)
                            , (generic_< complex_< arithmetic_<A0> > >)
                              (generic_< complex_< arithmetic_<A0> > >)
                            )
  {
    typedef typename meta::as_real<A0>::type result_type;
    NT2_FUNCTOR_CALL_REPEAT(2)
    {
      return nt2::max(ulpdist(real(a0), real(a1)),ulpdist(imag(a0), imag(a1))); 
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( ulpdist_, tag::cpu_, (A0)
                            , (generic_< dry_< arithmetic_<A0> > >)
                              (generic_< dry_< arithmetic_<A0> > >)
                            )
  {
    typedef typename meta::as_real<A0>::type result_type;
    NT2_FUNCTOR_CALL_REPEAT(2)
    {
      return ulpdist(real(a0), real(a1)); 
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( ulpdist_, tag::cpu_, (A0)
                            , (generic_< imaginary_< arithmetic_<A0> > >)
                              (generic_< imaginary_< arithmetic_<A0> > >)
                            )
  {
    typedef typename meta::as_real<A0>::type result_type;
    NT2_FUNCTOR_CALL_REPEAT(2)
    {
      return nt2::ulpdist(imag(a0), imag(a1)); 
    }
  };
  
} }

#endif
