//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
/*!
 * \file
**/
#ifndef BOOST_SIMD_TOOLBOX_BITWISE_FUNCTIONS_ROTI_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_BITWISE_FUNCTIONS_ROTI_HPP_INCLUDED
#include <boost/simd/include/simd.hpp>
#include <boost/dispatch/include/functor.hpp>

/*!
 * \ingroup boost_simd_bitwise
 * \defgroup boost_simd_bitwise_roti roti
 *
 * \par Description
 * The function returns the first entry logically rotated
 * by the second entry. Positive means left,  negative right.
 *
 * \par Header file
 * 
 * \code
 * #include <nt2/include/functions/roti.hpp>
 * \endcode
 * 
 * 
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class A0>
 *     meta::call<tag::roti_(A0,A0)>::type
 *     roti(const A0 & a0,const int & a1);
 * }
 * \endcode
 *
 * \param a0 the first parameter of roti
 * \param a1 the second parameter of roti, must be a scalar integer value
 * 
 * \return returns a value of the type of the first parameter
 *  
 * \par Notes
 * In SIMD mode, this function acts elementwise on the inputs vectors elements
 * \par
 *  
**/

namespace boost { namespace simd { namespace tag
  {         
    /*!
     * \brief Define the tag roti_ of functor roti 
     *        in namespace boost::simd::tag for toolbox boost.simd.bitwise
    **/
    struct roti_ : ext::elementwise_<roti_> { typedef ext::elementwise_<roti_> parent; };
  }
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::roti_, roti, 2)
} }

#endif

// modified by jt the 25/12/2010
