//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_DUAL_FUNCTION_SIMD_COMMON_TWO_SUM_HPP_INCLUDED
#define NT2_TOOLBOX_DUAL_FUNCTION_SIMD_COMMON_TWO_SUM_HPP_INCLUDED
#include <nt2/sdk/meta/adapted_traits.hpp>
#include <boost/fusion/tuple.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/is_finite.hpp>
#include <nt2/include/functions/select.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::two_sum_, tag::cpu_,
                       (A0)(X),
                       ((simd_<real_<A0>,X>))((simd_<real_<A0>,X>))
                      );

namespace nt2 { namespace ext
{
  template<class X, class Dummy>
  struct call<tag::two_sum_(tag::simd_<tag::real_, X>,tag::simd_<tag::real_, X>),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0,A0)>
    {
      typedef typename meta::strip<A0>::type                    str_t;
      typedef typename boost::fusion::tuple<str_t, str_t>        type;
    };

    NT2_FUNCTOR_CALL(2)
    {
      typename NT2_RETURN_TYPE(2)::type res;
      eval(a0,a1, boost::fusion::at_c<0>(res),boost::fusion::at_c<1>(res));
      return res;
    }
  private:
    template<class A0,class A1,class R0,class R1> inline void
    eval(A0 const& a, A1 const& b,R0& s, R1& err)const
    {
      s = a + b;
      const A0 bb = s - a;
      err = (a - (s - bb)) + (b - bb);
      err =  b_and(is_finite(s), err);
    }
  };
} }

#endif
