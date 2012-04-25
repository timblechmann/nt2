//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_EXPONENTIAL_FUNCTIONS_SCALAR_EXP2_HPP_INCLUDED
#define NT2_TOOLBOX_EXPONENTIAL_FUNCTIONS_SCALAR_EXP2_HPP_INCLUDED

#include <nt2/toolbox/exponential/functions/exp2.hpp>
#include <nt2/toolbox/exponential/functions/scalar/impl/expo.hpp>
#include <nt2/include/functions/ldexp.hpp>
#include <nt2/include/constants/one.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( exp2_, tag::cpu_
                            , (A0)
                            , (scalar_< arithmetic_<A0> >)
                            )
  {

    typedef typename boost::dispatch::meta::as_floating<A0>::type result_type;

    NT2_FUNCTOR_CALL(1)
    {
//       typedef int itype;
//       if (itype(a0) > itype(Maxexponent<type>())) return Inf<type>();
//       if (itype(a0) <= itype(Minexponent<type>())) return Zero<type>();
      return ldexp(One<result_type>(), a0);
    }
  };
} }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is floating_
/////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( exp2_, tag::cpu_
                            , (A0)
                            , (scalar_< floating_<A0> >)
                            )
  {

    typedef typename boost::dispatch::meta::as_floating<A0>::type result_type;

    NT2_FUNCTOR_CALL(1)
    {
      return impl::exponential<A0,two_tag, tag::not_simd_type, accu_tag>::expa(a0);
    }
  };
} }


#endif
