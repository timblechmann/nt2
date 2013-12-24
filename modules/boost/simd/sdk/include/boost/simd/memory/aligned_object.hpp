//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2013   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2012 - 2013   MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_MEMORY_ALIGNED_OBJECT_HPP_INCLUDED
#define BOOST_SIMD_MEMORY_ALIGNED_OBJECT_HPP_INCLUDED

#include <boost/simd/preprocessor/new.hpp>
#include <boost/simd/preprocessor/parameters.hpp>
#include <cstddef>

#if defined(BOOST_CLANG) && ( (__clang_major__ * 100 + __clang_minor__) >= 302 ) && (__cplusplus >= 201103L)
#define BOOST_SIMD_HAS_ALIGNAS
#endif

#if BOOST_GCC >= 40800 && (__cplusplus >= 201103L)
#define BOOST_SIMD_HAS_ALIGNAS
#endif

// msvc does not implement alignas, yet



namespace boost { namespace simd
{
  /*!
    @brief Imbue a type with aligned new and delete overloads

    When used as a base class, aligned_object adds overloaded new and delete
    operators that use aligned allocation function over an arbitrary alignment
    boundary @c Alignment.

    @usage{memory/aligned_object.cpp}

    @tparam Alignment Alignment boundary in bytes to use for dynamic allocation
            of child type.
  **/
  template<std::size_t Alignment = BOOST_SIMD_CONFIG_ALIGNMENT>
#if defined(BOOST_MSVC)
  __declspec(align(32)) // Note: cannot depend on a template argument, therefore we pessimize
#endif
  struct
#ifdef BOOST_SIMD_HAS_ALIGNAS
  alignas(Alignment)
#endif
  aligned_object
  {
    public:

    /**
      @brief Static integral constant containing current alignment constraints

      alignment_value gives access to the alignment constraint from the
      child type.
     */
    static const std::size_t alignment_value = Alignment;

    #if !defined(DOXYGEN_ONLY)
    BOOST_SIMD_MEMORY_OVERLOAD_NEW_DELETE(Alignment)
    #endif
  }
#if !defined(BOOST_SIMD_HAS_ALIGNAS)
# if defined(BOOST_CLANG) || (BOOST_GCC >= 40800)
  __attribute__ ((aligned (Alignment)))
# elif defined(BOOST_GCC)
  __attribute__ ((aligned (32))) // Note: cannot depend on a template argument, therefore we pessimize
# endif
#endif
  ;
} }

#endif
