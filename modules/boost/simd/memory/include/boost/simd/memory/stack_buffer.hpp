//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2013          Domagoj Saric, Little Endian Ltd.
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_MEMORY_STACK_BUFFER_HPP_INCLUDED
#define BOOST_SIMD_MEMORY_STACK_BUFFER_HPP_INCLUDED

#include <boost/simd/sdk/config/arch.hpp>
#include <boost/simd/memory/aligned_on.hpp>
#include <boost/simd/memory/parameters.hpp>
#include <boost/dispatch/attributes.hpp>
#include <boost/range/iterator_range_core.hpp>
#include <boost/assert.hpp>

// See http://gcc.gnu.org/bugzilla/show_bug.cgi?id=16660 for some infos

#if defined( _MSC_VER ) && defined( _WIN32 ) && !defined( _WIN64 )
  #define BOOST_SIMD_ALLOCA_ALIGNMENT 16
#else
  #define BOOST_SIMD_ALLOCA_ALIGNMENT BOOST_SIMD_ARCH_ALIGNMENT
#endif

/// INTERNAL ONLY
#define BOOST_SIMD_STACK_BUFFER_AUX_MAKE_RANGE( variableName, type, size )     \
boost::iterator_range<type*> const                                             \
variableName( &__##variableName##helper_pointer__[ 0 ]                         \
            , &__##variableName##helper_pointer__[ size ]                      \
            )                                                                  \
/**/

/// INTERNAL ONLY
#define BOOST_SIMD_STACK_BUFFER_AUX_BUILTIN_ALLOCA( type, size )               \
::alloca( size * sizeof( type ) )                                              \
/**/

#if BOOST_SIMD_ALLOCA_ALIGNMENT >= BOOST_SIMD_CONFIG_ALIGNMENT
/// INTERNAL ONLY
#define BOOST_SIMD_STACK_BUFFER_AUX_ALIGNED_ALLOCA                             \
BOOST_SIMD_STACK_BUFFER_AUX_BUILTIN_ALLOCA                                     \
/**/
#else
/// INTERNAL ONLY
#define BOOST_SIMD_STACK_BUFFER_AUX_ALIGNED_ALLOCA( type, size )               \
reinterpret_cast<void *>                                                       \
(                                                                              \
  (                                                                            \
    reinterpret_cast</*std::*/intptr_t>                                        \
    (                                                                          \
      ::alloca( size * sizeof( type )                                          \
    + BOOST_SIMD_CONFIG_ALIGNMENT - BOOST_SIMD_ALLOCA_ALIGNMENT )              \
    )                                                                          \
    + BOOST_SIMD_CONFIG_ALIGNMENT - BOOST_SIMD_ALLOCA_ALIGNMENT                \
  ) & ~( BOOST_SIMD_CONFIG_ALIGNMENT - 1 )                                     \
)                                                                              \
/**/
#endif


/// INTERNAL ONLY
/// Assignment construction syntax workaround for the most-vexing parse problem
#define BOOST_SIMD_STACK_BUFFER_AUX(variableName, type, size, alignment, impl) \
BOOST_SIMD_ALIGN_ON( alignment ) type * BOOST_DISPATCH_RESTRICT const          \
__##variableName##helper_pointer__  =                                          \
static_cast<type * BOOST_DISPATCH_RESTRICT const>( impl( type, size ) );       \
BOOST_ASSERT_MSG                                                               \
(                                                                              \
  reinterpret_cast<std::size_t>( __##variableName##helper_pointer__ )          \
  % alignment == 0                                                             \
,  "Alignment assumption breached in BOOST_SIMD_STACK_BUFFER"                  \
);                                                                             \
BOOST_SIMD_STACK_BUFFER_AUX_MAKE_RANGE( variableName, type, size )             \
/**/

/*!
  @brief Define a memory buffer allocated on the stack
**/
#define BOOST_SIMD_STACK_BUFFER( variableName, type, size )                    \
BOOST_SIMD_STACK_BUFFER_AUX ( variableName, type, size                         \
                            , BOOST_SIMD_ALLOCA_ALIGNMENT                      \
                            , BOOST_SIMD_STACK_BUFFER_AUX_ALIGNED_ALLOCA       \
                            )                                                  \
/**/

/*!
  @brief Define an aligned memory buffer allocated on the stack
**/
#define BOOST_SIMD_ALIGNED_STACK_BUFFER( variableName, type, size )            \
BOOST_SIMD_STACK_BUFFER_AUX ( variableName, type, size                         \
                            , BOOST_SIMD_CONFIG_ALIGNMENT                      \
                            , BOOST_SIMD_STACK_BUFFER_AUX_ALIGNED_ALLOCA       \
                            )                                                  \
/**/

// BOOST_SIMD_SCOPED_STACK_BUFFER
#if defined( __GNUC__ )
#define BOOST_SIMD_SCOPED_STACK_BUFFER( variableName, type, size )             \
BOOST_SIMD_ALIGN_ON( BOOST_SIMD_ARCH_ALIGNMENT ) type                          \
__##variableName##helper_pointer__[ size ];                                    \
BOOST_ASSERT_MSG                                                               \
(                                                                              \
    reinterpret_cast<std::size_t>( __##variableName##helper_pointer__ )        \
  % BOOST_SIMD_ARCH_ALIGNMENT == 0,                                            \
  "Alignment assumption breached in BOOST_SIMD_SCOPED_STACK_BUFFER"            \
);                                                                             \
BOOST_SIMD_STACK_BUFFER_AUX_MAKE_RANGE( variableName, type, size )             \
/**/
#else
#define BOOST_SIMD_SCOPED_STACK_BUFFER BOOST_SIMD_STACK_BUFFER
#endif

// BOOST_SIMD_ALIGNED_SCOPED_STACK_BUFFER
#if BOOST_SIMD_ARCH_ALIGNMENT >= BOOST_SIMD_CONFIG_ALIGNMENT
#define BOOST_SIMD_ALIGNED_SCOPED_STACK_BUFFER BOOST_SIMD_SCOPED_STACK_BUFFER
#else
#define BOOST_SIMD_ALIGNED_SCOPED_STACK_BUFFER BOOST_SIMD_ALIGNED_STACK_BUFFER
#endif

#endif
