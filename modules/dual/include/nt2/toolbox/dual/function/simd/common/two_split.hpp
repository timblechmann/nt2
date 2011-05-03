//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_DUAL_FUNCTION_SIMD_COMMON_TWO_SPLIT_HPP_INCLUDED
#define NT2_TOOLBOX_DUAL_FUNCTION_SIMD_COMMON_TWO_SPLIT_HPP_INCLUDED
#include <nt2/include/functions/ldexp.hpp>
#include <nt2/include/functions/all.hpp>
#include <nt2/include/functions/select.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::two_split_, tag::cpu_,
                       (A0)(X),
                       ((simd_<real_<A0>,X>))
                      );

namespace nt2 { namespace ext
{
  template<class X, class Dummy>
  struct call<tag::two_split_(tag::simd_<tag::real_, X>),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>
    {
      typedef typename meta::strip<A0>::type                    str_t;
      typedef typename boost::fusion::tuple<str_t, str_t>        type;
    };

    NT2_FUNCTOR_CALL(1)
    {
      typename NT2_RETURN_TYPE(1)::type res;
      eval(a0,boost::fusion::at_c<0>(res),boost::fusion::at_c<1>(res));
      return res;
    }
  private :
    template<class A0,class R0,class R1> inline void
    eval(A0 const& a, R0& r0, R1& r1)const
    {
      typedef typename meta::scalar_of<A0>::type sA0;
      typedef typename meta::as_integer<A0>::type iA0; 
      // TODO: make local constant ?
      static const int N = (Nbmantissabits<A0>()-(Nbmantissabits<A0>()>>1))+1;
      static const A0 fac = splat<A0>((1<<N)+1);
      static const A0 thresh = splat<A0>((1 << Nbexponentbits<A0>())-(1<<N));
      static const iA0 vNp1  = splat<iA0>(N+1); 
      A0 test = le(abs(a), Dualthresh<A0>());
      if (all(test))
	{
	  A0 temp =  Dualfac<A0>()*a; 		    
	  r0 = temp - (temp - a);
	  r1 = a - r0;
	}
      else
	{
	  a = sel(test, a, ldexp(a, Dualmshift<A0>()));
	  A0 temp =   Dualfac<A0>()*a; 		    
	  r0 = temp - (temp - a);
	  r1 = a - r0;
	  r0 = 	sel(test, a, ldexp(r0, Dualshift<A0>()));
	  r1 = 	sel(test, a, ldexp(r1, Dualshift<A0>()));
	}
    }
  };
} }

#endif
