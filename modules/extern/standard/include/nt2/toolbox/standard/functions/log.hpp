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
#ifndef NT2_TOOLBOX_STANDARD_FUNCTIONS_LOG_HPP_INCLUDED
#define NT2_TOOLBOX_STANDARD_FUNCTIONS_LOG_HPP_INCLUDED
#include <nt2/include/functor.hpp>

/*!
 * \ingroup standard
 * \defgroup standard_log log
 *
 * \par Description
 * Please for details consult the proper documentation of the external
 * library standard.
 * \par
 * The call is transfered to the standard C++ library function std::log
 *
 * \par Header file
 *
 * \code
 * #include <nt2/toolbox/standard/include/functions/log.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace nt2
 * {
 *   namespace standard
 *   {
 *     template <class A0>
 *       meta::call<tag::log_(A0)>::type
 *       log(const A0 & a0);
 *   }
 * }
 * \endcode
 *
 * \param a0 the unique parameter of log
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

namespace nt2 { namespace standard { namespace tag
  {
    /*!
     * \brief Define the tag log_ of functor log
     *        in namespace nt2::standard::tag for toolbox standard
    **/
    struct log_ : ext::elementwise_<log_> { typedef ext::elementwise_<log_> parent; };
  }
  NT2_FUNCTION_IMPLEMENTATION(standard::tag::log_, log, 1)
  } }

#include <nt2/toolbox/standard/functions/scalar/log.hpp>
// #include <nt2/toolbox/standard/functions/simd/all/log.hpp>

#endif

// modified by jt the 29/12/2010
