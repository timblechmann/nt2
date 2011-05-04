//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_DUAL_FUNCTION_SCALAR_TWO_PROD_HPP_INCLUDED
#define NT2_TOOLBOX_DUAL_FUNCTION_SCALAR_TWO_PROD_HPP_INCLUDED
#include <nt2/include/functions/two_split.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is real_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::two_prod_, tag::cpu_,
                      (A0)(A1),
                      (real_<A0>)(real_<A1>)
                     )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::two_prod_(tag::real_,tag::real_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)>
    {
      typedef typename std::tr1::result_of<meta::floating(A0, A1)>::type rtype;
      typedef typename boost::fusion::tuple<rtype,rtype>                  type;
    };

    NT2_FUNCTOR_CALL(2)
    {
      typename NT2_RETURN_TYPE(2)::type res;
      eval(a0,a1, boost::fusion::at_c<0>(res),boost::fusion::at_c<1>(res));
      return res;
    }
  private:
    template<class A0,class A1,class R0,class R1> inline void
    eval(A0 const& a, A1 const& b,R0& r0, R1& r1)const
    {
      typedef typename NT2_RETURN_TYPE(2)::type res_type;
      const res_type resa =  two_split(a);
      const res_type resb =  two_split(b);
      const A0 a_hi= boost::fusion::at_c<0>(resa);
      const A0 a_lo= boost::fusion::at_c<1>(resa); 
      const A0 b_hi= boost::fusion::at_c<0>(resb);
      const A0 b_lo= boost::fusion::at_c<1>(resb);
      r0 = a * b;
      r1 = ((a_hi * b_hi - r0) + a_hi * b_lo + a_lo * b_hi) + a_lo * b_lo;
    }

  };
} }

#endif
