//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_DUAL_FUNCTION_SIMD_COMMON_STORE_HPP_INCLUDED
#define NT2_TOOLBOX_DUAL_FUNCTION_SIMD_COMMON_STORE_HPP_INCLUDED
#include <nt2/sdk/meta/as_real.hpp>
#include <nt2/toolbox/dual/specific/interface.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH ( tag::store_
			, tag::cpu_
			, (A0)(A1)(A2)(X)
			, ((simd_< dual_<A0>, X >))
                        (iterator_< dual_<A1> >)
                        (integer_<A2>)
                      )

namespace nt2 { namespace ext
{
  template<class X, class Dummy>
  struct  call< tag::store_ ( tag::simd_<tag::dual_ <tag::real_> ,X>
			      , tag::iterator_<tag::dual_ <tag::real_> >
			      , tag::integer_
			      )
                , tag::cpu_
		, Dummy
              >
  : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1,class A2>
    struct result<This(A0,A1,A2)> : meta::as_real<A0>{};

    NT2_FUNCTOR_CALL(3)
    {
      typedef typename NT2_RETURN_TYPE(3)::type type;
      type res(store(nt2::get<0>(a0), nt2::get<0>(a1), a2),
	       store(nt2::get<1>(a0), nt2::get<1>(a1), a2)
	       ); 
	}
  };
} }

#endif
