//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_DUAL_FUNCTION_SIMD_COMMON_SPLAT_HPP_INCLUDED
#define NT2_TOOLBOX_DUAL_FUNCTION_SIMD_COMMON_SPLAT_HPP_INCLUDED
#include <nt2/toolbox/dual/specific/interface.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::splat_, tag::cpu_,
                       (A0)(A1)(X),
		       (dual_<real_<A0> >)
                       ((simd_<dual_<real_<A1> >,X >))
                      );

namespace nt2 { namespace ext
{
  template<class X, class Dummy>
  struct call<tag::splat_(tag::dual_ <tag::real_>,
			  tag::target_<tag::simd_<tag::dual_<tag::real_>,X> >
                            ),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0, class A1>
    struct result<This(A0, A1)> : meta::strip<A1>{};

    NT2_FUNCTOR_CALL(2)
    {
      typedef typename NT2_RETURN_TYPE(2)::type type;
      typedef typename A0::type inner_type;
      type res(splat<inner_type>(get<0>(a0)),splat<inner_type>(get<1>(a0)));
      return res; 
    }
  };
} }


#endif
