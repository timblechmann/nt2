//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TOOLBOX_OPERATOR_FUNCTION_COMPARE_GREATER_EQUAL_HPP_INCLUDED
#define NT2_TOOLBOX_OPERATOR_FUNCTION_COMPARE_GREATER_EQUAL_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/toolbox/operator/include.hpp>
#include <nt2/toolbox/operator/specific/common.hpp>

#include <nt2/toolbox/operator/specific/compare_tags.hpp>

namespace nt2
{
  NT2_FUNCTION_IMPLEMENTATION(tag::compare_greater_equal_, compare_greater_equal , 2 )
  NT2_FUNCTION_IMPLEMENTATION(tag::compare_greater_equal_, compare_ge            , 2 )
}

#include <nt2/toolbox/operator/function/scalar/compare_greater_equal.hpp>
#include NT2_OPERATOR_INCLUDE(compare_greater_equal.hpp)

#endif
