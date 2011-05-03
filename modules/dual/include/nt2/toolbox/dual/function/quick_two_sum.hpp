//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_DUAL_FUNCTION_QUICK_TWO_SUM_HPP_INCLUDED
#define NT2_TOOLBOX_DUAL_FUNCTION_QUICK_TWO_SUM_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/toolbox/dual/include.hpp>

namespace nt2 {
  namespace tag
  {
    struct quick_two_sum_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION(tag::quick_two_sum_, quick_two_sum, 2)
}

#include <nt2/toolbox/dual/function/scalar/quick_two_sum.hpp>
#include NT2_DUAL_INCLUDE(quick_two_sum.hpp) 

#endif
