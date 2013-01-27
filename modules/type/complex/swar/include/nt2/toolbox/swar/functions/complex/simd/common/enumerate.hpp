/*******************************************************************************
 *         Copyright 2003-2013 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2011-2013 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_TOOLBOX_SWAR_FUNCTIONS_COMPLEX_SIMD_COMMON_ENUMERATE_HPP_INCLUDED
#define NT2_TOOLBOX_SWAR_FUNCTIONS_COMPLEX_SIMD_COMMON_ENUMERATE_HPP_INCLUDED
#include <nt2/toolbox/swar/functions/enumerate.hpp>
#include <nt2/include/functions/imag.hpp>
#include <nt2/include/functions/real.hpp>

namespace nt2 { namespace ext
{

  NT2_FUNCTOR_IMPLEMENTATION ( nt2::tag::enumerate_, tag::cpu_
                               , (A0)(X)(T)
                               , ((simd_< complex_<arithmetic_<A0> > ,X>))
                               ((target_< simd_< complex_<arithmetic_<T> >,X > >))
    )
{
  typedef typename T::type result_type;

  result_type operator()(A0 const& a0, T const& ) const
  {
    typedef typename meta::as_real<A0>::type            r_t;
    typedef typename meta::scalar_of<r_t>::type         s_t;
    return result_type(enumerate<s_t>(nt2::real(a0), r_t(nt2::imag(a0))));
  }
};

  NT2_FUNCTOR_IMPLEMENTATION (nt2::tag::enumerate_, tag::cpu_
                                      , (A0)(A1)(X)(T)
                                      , ((simd_< complex_<arithmetic_<A0> > ,X>))
                                      ((simd_< complex_<arithmetic_<A1> > ,X>))
                                      ((target_< simd_< complex_<arithmetic_<T> >,X> > ))
    )
  {
    typedef typename T::type result_type;

    result_type operator()(A0 const& a0, A1 const& a1, T const& ) const
    {
      typedef typename meta::as_real<A0>::type            r_t;
      typedef typename meta::scalar_of<r_t>::type         s_t;
      return result_type(enumerate<s_t>(real(a0), real(a1)), enumerate<s_t>(imag(a0), imag(a1)));
    }
  };
} }


#endif