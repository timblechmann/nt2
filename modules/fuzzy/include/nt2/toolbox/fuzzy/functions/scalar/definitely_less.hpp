//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_FUZZY_FUNCTIONS_SCALAR_DEFINITELY_LESS_HPP_INCLUDED
#define NT2_TOOLBOX_FUZZY_FUNCTIONS_SCALAR_DEFINITELY_LESS_HPP_INCLUDED
#include <nt2/include/constants/infinites.hpp>
#include <nt2/include/functions/is_nan.hpp>
#include <nt2/include/functions/is_finite.hpp>
#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/successor.hpp>
#include <nt2/include/functions/predecessor.hpp>
#include <nt2/include/functions/subs.hpp>
#include <nt2/sdk/simd/logical.hpp>
#include <nt2/include/functions/logical_and.hpp>
#include <nt2/include/functions/logical_or.hpp>
#include <nt2/include/constants/true.hpp>
#include <nt2/include/constants/false.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( definitely_less_, tag::cpu_
                            , (A0)(A2)
                            , (scalar_< integer_<A0> >)(scalar_< integer_<A0> >)(scalar_< integer_<A2> >)
                            )
  {
    typedef typename meta::as_logical<A0>::type result_type;
    inline result_type operator()(const A0 & a0,const A0 & a1, const A2 & a2) 
    {
      return result_type(a0 < nt2::subs(a1, nt2::abs(a2)));
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is floating_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( definitely_less_, tag::cpu_
                            , (A0)(A2)
                            , (scalar_< floating_<A0> >)(scalar_< floating_<A0> >)(scalar_< integer_<A2> >)
                            )
  {
    typedef typename meta::as_logical<A0>::type result_type;
    inline result_type operator()(const A0 & a0,const A0 & a1, const A2 & a2) 
    {
      if (logical_and(is_finite(a0), result_type(a1 == Inf<A0>()))) return True<result_type>();
      if (logical_and(is_finite(a1), result_type(a0 == Minf<A0>()))) return True<result_type>();
      if (logical_or(is_nan(a0), is_nan(a1))) return False<result_type>();
      return  result_type(a0 < predecessor(a1,nt2::abs(a2)));
    }
  };
} }


#endif
