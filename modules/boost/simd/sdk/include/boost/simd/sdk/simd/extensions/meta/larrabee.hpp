/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BOOST_SIMD_SDK_SIMD_EXTENSIONS_META_LRBI_HPP_INCLUDED
#define BOOST_SIMD_SDK_SIMD_EXTENSIONS_META_LRBI_HPP_INCLUDED

#include <boost/simd/sdk/config/types.hpp>
#include <boost/simd/sdk/simd/meta/as_simd.hpp>
#include <boost/simd/sdk/simd/meta/extension_of.hpp>
#include <boost/simd/sdk/simd/meta/is_simd_specific.hpp>
#include <boost/simd/sdk/simd/extensions/meta/tags.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/is_integral.hpp>

////////////////////////////////////////////////////////////////////////////////
// LRBI extensions overload
////////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace meta
{
  //////////////////////////////////////////////////////////////////////////////
  // For a given type and extension, check if it's a SIMD register type
  //////////////////////////////////////////////////////////////////////////////
  template<> struct is_simd_specific<__m256 , tag::lrbi_> : boost::mpl::true_ {};
  template<> struct is_simd_specific<__m256d, tag::lrbi_> : boost::mpl::true_ {};
  template<> struct is_simd_specific<__m256i, tag::lrbi_> : boost::mpl::true_ {};

  //////////////////////////////////////////////////////////////////////////////
  // For a given type and extension, return the associated SIMD register type
  //////////////////////////////////////////////////////////////////////////////
  template<class T>
  struct  as_simd<T,tag::lrbi_>
        : boost::mpl::if_ < boost::is_integral<T>
                          , __m512i
                          , typename  boost::mpl
                            ::if_ < boost::is_same<T,float>
                                  , __m512
                                  , typename  boost::mpl
                                    ::if_ < boost::is_same<T,double>
                                        , __m512d
                                        , dispatch::meta::na_
                                        >::type
                                  >::type
                          >
  {};

  //////////////////////////////////////////////////////////////////////////////
  // For a given SIMD register type, return the associated SIMD extension tag
  //////////////////////////////////////////////////////////////////////////////
  template<class X> struct extension_of<__m512 ,X>  { typedef tag::lrbi_ type; };
  template<class X> struct extension_of<__m512d,X>  { typedef tag::lrbi_ type; };
  template<class X> struct extension_of<__m512i,X>  { typedef tag::lrbi_ type; };
} } }

#endif
