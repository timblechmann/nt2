//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_CORE_FUNCTIONS_EXPR_LENGTH_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_EXPR_LENGTH_HPP_INCLUDED

#include <nt2/core/container/dsl.hpp>
#include <nt2/core/functions/length.hpp>
#include <nt2/core/container/category.hpp>
#include <nt2/include/functions/extent.hpp>

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( length_, tag::cpu_
                            , (A0)
                            , (ast_<A0>)
                            )
  {
    typedef typename meta::
            call<tag::length_(typename A0::extent_type)>::type result_type;

    BOOST_DISPATCH_FORCE_INLINE result_type operator()(const A0& a0) const
    {
      return nt2::length( a0.extent() );
    }
  };
} }

#endif
