//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_DUAL_FUNCTION_SCALAR_TWO_SQR_HPP_INCLUDED
#define NT2_TOOLBOX_DUAL_FUNCTION_SCALAR_TWO_SQR_HPP_INCLUDED

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::two_sqr_, tag::cpu_,
                      (A0),
                      (arithmetic_<A0>)
                     )

namespace nt2 { namespace ext
{
  template<class Dummy>
  struct call<tag::two_sqr_(tag::arithmetic_),
              tag::cpu_, Dummy> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> 
    {
      typedef typename meta::strip<A0>::type              rtype;
      typedef typename boost::fusion::tuple<rtype,rtype>   type;
    };


    NT2_FUNCTOR_CALL(1)
    {
      typename NT2_RETURN_TYPE(1)::type res;
      eval(a0, boost::fusion::at_c<0>(res),boost::fusion::at_c<1>(res));
      return res;
    }
  private:
    template<class A0,class A1,class R0,class R1> inline void
      eval(A0 const& a,R0& r0, R1& r1)const
      {
	typename NT2_RETURN_TYPE(1)::type res;
	res = two_split(a);
	const A0 hi = boost::fusion::at_c<0>(res); 
	const A0 lo = boost::fusion::at_c<1>(res);   
	r0 = sqr(a);
	r1 = ((sqr(hi) - r0) + 2.0 * hi * lo) + sqr(lo);
      }
  };
} }

#endif
