//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
/*!
 * \file
**/
#ifndef NT2_TOOLBOX_BOOST_MATH_FUNCTIONS_ELLINT_2_HPP_INCLUDED
#define NT2_TOOLBOX_BOOST_MATH_FUNCTIONS_ELLINT_2_HPP_INCLUDED
#include <nt2/include/functor.hpp>
#include <boost/math/special_functions/ellint_2.hpp>

/*!
 * \ingroup boost_math
 * \defgroup boost_math_ellint_2 ellint_2
 *
 * \par Description
 * Please for details consult the proper documentation of the external
 * library boost_math.
 *
 * \par Header file
 *
 * \code
 * #include <nt2/toolbox/boost_math/include/functions/ellint_2.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace nt2
 * {
 *   namespace boost_math
 *   {
 *     template <class A0>
 *       meta::call<tag::ellint_2_(A0)>::type
 *       ellint_2(const A0 & a0);
 *   }
 * }
 * \endcode
 *
 * \param a0 the unique parameter of ellint_2
 *
 * \return a value of the same type as the parameter
 *
 * \par Notes
 * In SIMD mode, this function acts elementwise on the inputs vectors elements
 * \par
 * When calling external library, nt2 simply encapsulates the
 * original proper call to provide easy use.
 * \par
 * Remenber that SIMD implementation is therefore merely
 * mapping the scalar function to each SIMD vectors elements
 * and will not provide acceleration, but ease.
 *
**/

namespace nt2 { namespace boost_math { namespace tag
  {
    /*!
     * \brief Define the tag ellint_2_ of functor ellint_2
     *        in namespace nt2::boost_math::tag for toolbox boost_math
    **/
    struct ellint_2_ : ext::elementwise_<ellint_2_> { typedef ext::elementwise_<ellint_2_> parent; };
  }
  NT2_FUNCTION_IMPLEMENTATION(boost_math::tag::ellint_2_, ellint_2, 1)
  NT2_FUNCTION_IMPLEMENTATION(boost_math::tag::ellint_2_, ellint_2, 2)
  } }

#include <nt2/toolbox/boost_math/functions/scalar/ellint_2.hpp>
// #include <nt2/toolbox/boost_math/functions/simd/all/ellint_2.hpp>

#endif

// modified by jt the 29/12/2010
