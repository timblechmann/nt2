//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_STREFLOP_FUNCTION_COS_HPP_INCLUDED
#define NT2_TOOLBOX_STREFLOP_FUNCTION_COS_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/toolbox/streflop/include.hpp>

namespace nt2 { namespace streflop { namespace tag
  {         
    struct cos_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION(streflop::tag::cos_, cos, 1)
  } }
 
#include <nt2/toolbox/streflop/function/scalar/cos.hpp>
// #include <nt2/toolbox/streflop/function/simd/all/cos.hpp> 

 
#endif

// modified by jt the 29/12/201
