//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_DD_REALS_FUNCTION_SIMD_COMMON_SPLAT_HPP_INCLUDED
#define NT2_TOOLBOX_DD_REALS_FUNCTION_SIMD_COMMON_SPLAT_HPP_INCLUDED
#include <nt2/toolbox/dd_reals/specific/interface.hpp>
#include <nt2/include/functions/splat.hpp>
#include <nt2/toolbox/dd_reals/include/splat.hpp>
/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
NT2_REGISTER_DISPATCH(tag::splat_, tag::cpu_,
		      (A0)(A1)(X),
		      (dd_reals_<real_<A0> >)
		      ((target_<simd_< dd_reals_<real_<A1> >, X > >))
                      );

namespace nt2 { namespace ext
{
  template<class X, class Dummy>
  struct call<tag::splat_(tag::dd_reals_<tag::real_>,
			  tag::target_<tag::simd_<tag::dd_reals_<tag::real_>, X > >
			  ),
              tag::cpu_,
	      Dummy
	      >
  : callable
  {
    template<class Sig> struct result;
    template<class This,class A0, class A1>
      struct result<This(A0, A1)>: meta::strip<A1>::type{}; 

    NT2_FUNCTOR_CALL(2)
    {
//       typedef typename A1::type ntype;
//       typedef typename meta::scalar_of<ntype>::type sA1;

      typedef typename NT2_RETURN_TYPE(2)::type type;
      typedef nt2::simd::native<typename A0::type, X> v_type;
//        outer_type i0 = nt2::splat<v_type>(get<0>(a0));
//        outer_type i1 = nt2::splat<v_type>(get<1>(a0));
//       type res(i0, i1); 
//        std::cout << i0 << "  " << i1 << std::endl; //(splat<inner_type>(get<0>(a0)),splat<inner_type>(get<1>(a0)));
//      ntype res;
      return type(nt2::splat<v_type>(get<0>(a0)),nt2::splat<v_type>(get<1>(a0))); 
    }
  };
} }

//       {
// 	typedef typename meta::strip<A0>::type          sA0;
// 	typedef dd_reals<sA0>                        inner_type; 
// 	typedef nt2::simd::native<inner_type, X>       type; 
//       }; 

//       {
// 	typedef typename meta::strip<A0>::type sA0; 
// 	typedef nt2::simd::native<typename sA0::type, X> outer_type;
// 	typedef nt2::dd_reals < outer_type >  type;
//      }; 

#endif
