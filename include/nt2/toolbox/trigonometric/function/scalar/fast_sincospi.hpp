//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_TRIGONOMETRIC_FUNCTION_SCALAR_FAST_SINCOSPI_HPP_INCLUDED
#define NT2_TOOLBOX_TRIGONOMETRIC_FUNCTION_SCALAR_FAST_SINCOSPI_HPP_INCLUDED
#include <boost/fusion/tuple.hpp>

#include <nt2/toolbox/trigonometric/function/scalar/impl/trigo.hpp>
//  MIGRATION WARNING you have to provide the file for the previous include from
//  nt2/core/numeric/function/details/scalar/impl/trigo.hpp
//  of the old nt2

namespace nt2 { namespace functors
{

  //  no special validate for fast_sincospi

  /////////////////////////////////////////////////////////////////////////////
  // Compute fast_sincospi(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<fast_sincospi_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>
    {
      typedef typename boost::result_of<meta::floating(A0)>::type etype;
      typedef boost::fusion::tuple<etype, etype>                   type;
    };

    NT2_FUNCTOR_CALL(1)
    {
      typename NT2_CALL_RETURN_TYPE(1)::type res;
      typedef typename boost::result_of<meta::floating(A0)>::type etype;
      impl::trig_base < A0,pi_tag
                      , fast_tag, tag::not_simd_type
                      >::sincosa( etype(a0)
                                , boost::fusion::at_c<0>(res)
                                , boost::fusion::at_c<1>(res)
                                );
      return res;
    }
  };
} }


      
#endif
