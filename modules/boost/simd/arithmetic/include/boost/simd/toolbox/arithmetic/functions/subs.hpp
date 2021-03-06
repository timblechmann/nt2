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
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_SUBS_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_SUBS_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>

/*!
 * \ingroup boost_simd_arithmetic
 * \defgroup boost_simd_arithmetic_subs subs
 *
 * \par Description
 * The result is the mathetical subtraction of the arguments
 * saturated in the interval defined by the common arguments type bounds
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/subs.hpp>
 * \endcode
 *
 * \par Alias
 * \arg satrated_sub
 *
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class A0>
 *     meta::call<tag::subs_(A0,A0)>::type
 *     subs(const A0 & a0,const A0 & a1);
 * }
 * \endcode
 *
 * \param a0 the first parameter of subs
 * \param a1 the second parameter of subs
 *
 * \return a value of the common type of the parameters
 *
 * \par Notes
 * In SIMD mode, this function acts elementwise on the inputs vectors elements
 * \par
 *
**/

namespace boost { namespace simd {
  namespace tag
  {
    /*!
     * \brief Define the tag subs_ of functor subs
     *        in namespace boost::simd::tag for toolbox boost.simd.arithmetic
    **/
    struct subs_ : ext::elementwise_<subs_> { typedef ext::elementwise_<subs_> parent; };
  }
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::subs_, subs, 2)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::subs_, satrated_sub, 2)
} }

#endif
