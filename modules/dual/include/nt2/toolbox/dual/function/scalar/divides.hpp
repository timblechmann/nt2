//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_DUAL_FUNCTION_SCALAR_DIVIDES_HPP_INCLUDED
#define NT2_TOOLBOX_DUAL_FUNCTION_SCALAR_DIVIDES_HPP_INCLUDED

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 and A1 are dual
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::divides_, tag::cpu_,
                      (A0),
                      ((dual_<real_<A0> > ))
                      ((dual_<real_<A0> > )) 
                     ); 

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::divides_(tag::dual_ <tag::real_> ,
			    tag::dual_ <tag::real_> ),
              tag::cpu_, Dummy> : callable
	      {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0, A0)> : meta::strip<A0>{};

    NT2_FUNCTOR_CALL(2)
    {
      return a0.div(a1); 
    }
  };
} }

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is dual
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::divides_, tag::cpu_,
                      (A0),
                      ((dual_<real_<A0> > ))
                      ((real_<A0> )) 
                     ); 

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::divides_(tag::dual_ <tag::real_> ,
			 tag::real_ ),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0, class A1>
    struct result<This(A0, A1)> : meta::strip<A0>{};

    NT2_FUNCTOR_CALL(2)
    {
      return a0.div(a1); 
    }
  };
} }
/////////////////////////////////////////////////////////////////////////////
// Implementation when type A1 is dual
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::divides_, tag::cpu_,
                      (A0),
                      ((real_<A0> )) 
                      ((dual_<real_<A0> > ))
                     ); 

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::divides_(tag::real_,
			 tag::dual_ <tag::real_> 
			 ),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0, class A1>
    struct result<This(A0, A1)> : meta::strip<A1>{};

    NT2_FUNCTOR_CALL(2)
    {
      A1 t(a0); 
      return t/a1; 
    }
  };
} }

#endif
