//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_DUAL_FUNCTION_SCALAR_PLUS_HPP_INCLUDED
#define NT2_TOOLBOX_DUAL_FUNCTION_SCALAR_PLUS_HPP_INCLUDED
#include <nt2/toolbox/dual/specific/interface.hpp>
#include <nt2/toolbox/dual/specific/dual_types.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 and A1 are dual
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::plus_, tag::cpu_,
                      (A0),
                      ((dual_<real_<A0> > ))
                      ((dual_<real_<A0> > )) 
                     ); 

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::plus_(tag::dual_ <tag::real_> ,
			tag::dual_ <tag::real_> ),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0, A0)> : meta::strip<A0>{};

    NT2_FUNCTOR_CALL(2)
    {
      typedef typename NT2_RETURN_TYPE(2)::type type;
      type res =  a0;
      res += a1;
      return res; 
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is dual
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::plus_, tag::cpu_,
                      (A0),
                      ((dual_<real_<A0> > ))
                      ((real_<A0> )) 
                     ); 

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::plus_(tag::dual_ <tag::real_> ,
			 tag::real_ ),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0, class A1>
    struct result<This(A0, A1)> : meta::strip<A0>{};

    NT2_FUNCTOR_CALL(2)
    {
      typedef typename NT2_RETURN_TYPE(2)::type type;
      type res =  a0;
      res += a1;
      return res; 
    }
  };
} }
/////////////////////////////////////////////////////////////////////////////
// Implementation when type A1 is dual
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::plus_, tag::cpu_,
                      (A0),
                      ((real_<A0> )) 
                      ((dual_<real_<A0> > ))
                     ); 

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::plus_(tag::real_,
			 tag::dual_ <tag::real_> 
			 ),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0, class A1>
    struct result<This(A0, A1)> : meta::strip<A1>{};

    NT2_FUNCTOR_CALL(2)
    {
      typedef typename NT2_RETURN_TYPE(2)::type type;
      type res =  a1;
      res += a0;
      return res; 
    }
  };
} }

#endif

