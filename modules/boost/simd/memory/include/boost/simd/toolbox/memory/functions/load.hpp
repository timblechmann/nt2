//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2011 - 2012   MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================

/*!
  @file
  @brief Defines and implements the load function
**/

#ifndef BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_LOAD_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_LOAD_HPP_INCLUDED

#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>
#include <boost/dispatch/meta/as.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    /*!
      @brief Define the load function tag

      Define a hierarchizable Tag representing the load function in generic
      contexts.
    **/
    struct load_ : ext::elementwise_<load_>
    {
      typedef ext::elementwise_<load_> parent;
    };
  }

  /*!
    @brief Load data from memory

    load retrieves data from a given memory block using the most efficient
    operations and register types for the chosen destination type.

    The memory block is referenced either through a direct address or from an
    address/offset pair. In this case, the offset can either be dynamic or a
    compile-time integral constant. Beware that dynamic offset are expressed in
    number of elements of the type requested while compile-time offset are
    expressed in number of elements of the type pointed to by ptr. This difference
    is meaningless while loading scalar values but allow to load statically
    unaligned data into SIMD registers.

    When used to load SIMD register (either native or pack), load enforces that
    the memory block is aligned to satisfy current SIMD extension alignment
    constraints and may trigger a runtime assertion.

    @par Semantic

    For any given type @c T and @c U so that @c T and @c U are bitwise
    compatible, any pointer to @c U @c ptr and any integral type value @c offset:

    @code
    T x = load<T>(ptr, o);
    @endcode

    is equivalent to:

    @code
    T x = *(reinterpret_cast<T*>(ptr)+o);
    @endcode

    @tparam T     Type of data to load from memory
    @param ptr    Memory block to load from.
    @param offset Offset to apply to ptr

    @return A value of type @c T loaded from target memory block
  **/
  template<class T,class A0,class A1>
  BOOST_FORCEINLINE T load(A0 const& ptr,A1 const& offset)
  {
    typename boost::dispatch::make_functor<tag::load_, A0>::type callee;
    return callee(ptr,offset,boost::dispatch::meta::as_<T>());
  }

  /*!
    @overload
    @brief Load data from memory

    @par Semantic

    For any given type @c T and @c U so that @c T and @c U are bitwise
    compatible, any pointer to @c U @c ptr:

    @code
    T x = load<T>(ptr);
    @endcode

    is equivalent to:

    @code
    T x = *reinterpret_cast<T*>(ptr);
    @endcode

    @par Usage

    @include load_ptr.cpp

    @tparam T     Type of data to load from memory
    @param ptr    Memory block to load from.
    @return A value of type @c T loaded from target memory block
  **/
  template<class T,class A0> BOOST_FORCEINLINE T load(A0 const& ptr)
  {
    return load<T>(ptr,int(0));
  }

  /*!
    @overload
    @brief Load data from memory

    @par Semantic

    For any given type @c T and @c U so that @c T and @c U are bitwise
    compatible, any compile time Integral Constant @c N, any pointer to @c U
    @c ptr and any integral type value @c offset:

    @code
    T x = load<T,N>(ptr, o);
    @endcode

    is equivalent to:

    @code
    T x = *(reinterpret_cast<T*>(ptr+N)+o);
    @endcode

    @tparam T      Type of data to load from memory
    @tparam Offset Compile-time offset to apply to ptr
    @param  ptr    Memory block to load from.
    @param  offset Offset to apply to ptr
    @return A value of type @c T loaded from target memory block
  **/
  template<class T,int Offset,class A0,class A1>
  BOOST_FORCEINLINE T load(A0 const& ptr, A1 const& offset)
  {
    typename boost::dispatch::make_functor<tag::load_, A0>::type callee;
    return callee ( ptr , offset
                  , boost::dispatch::meta::as_<T>()
                  , boost::mpl::int_<Offset>()
                  );
  }

  /*!
    @overload
    @brief Load data from memory

    @par Semantic

    For any given type @c T and @c U so that @c T and @c U are bitwise
    compatible, any compile time Integral Constant @c N and any pointer to @c U
    @c ptr:

    @code
    T x = load<T,N>(ptr);
    @endcode

    is equivalent to:

    @code
    T x = *(reinterpret_cast<T*>(ptr+N));
    @endcode

    @tparam T      Type of data to load from memory
    @tparam Offset Compile-time offset to apply to ptr
    @param  ptr    Memory block to load from.
    @return A value of type @c T loaded from target memory block
  **/
  template<class T,int Offset,class A0> BOOST_FORCEINLINE T load(A0 const& ptr)
  {
    return load<T,Offset>(ptr,int(0));
  }
} }

#endif
