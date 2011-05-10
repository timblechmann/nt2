//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_DUAL_FUNCTION_SIMD_COMMON_LOAD_HPP_INCLUDED
#define NT2_TOOLBOX_DUAL_FUNCTION_SIMD_COMMON_LOAD_HPP_INCLUDED

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH ( tag::load_
                      , tag::cpu_
                      , (A0)(A1)(T)
                      , (iterator_<fundamental_<A0> >)
                        (fundamental_<A1>)
                        ((target_< simd_< dual_<T>, tag::sse_ > >))
                      )

namespace nt2 { namespace ext
{
  template<class Dummy, class X>
  struct  call< tag::load_( tag::iterator_<tag::fundamental_>
			    , tag::fundamental_
			    , tag::target_< tag::simd_<tag::dual_ <tag::real_,X> >
                          )
              , tag::cpu_
              , Dummy
              >
        : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1,class A2>
    struct result<This(A0,A1,A2)> : meta::strip<A2>{};

    NT2_FUNCTOR_CALL(3)
    {
      typedef typename NT2_RETURN_TYPE(3)::type type;
      type that(load(nt2::get<0>(a0), a1, a2), load(nt2::get<1>(a0), a1, a2));
      return that;

    }
  };
} }

#endif
