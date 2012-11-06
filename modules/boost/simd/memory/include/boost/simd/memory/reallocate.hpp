//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_MEMORY_REALLOCATE_HPP_INCLUDED
#define BOOST_SIMD_MEMORY_REALLOCATE_HPP_INCLUDED

#include <boost/simd/memory/allocate.hpp>
#include <boost/simd/memory/deallocate.hpp>
#include <boost/simd/memory/is_aligned.hpp>
#include <boost/simd/memory/parameters.hpp>
#include <boost/simd/memory/aligned_realloc.hpp>

#include <boost/dispatch/attributes.hpp>
#include <algorithm>
#include <cstring>
#include <cstddef>

namespace boost { namespace simd {  namespace memory
{
  /*!
    @brief Aligned memory reallocation

    Reallocated a raw buffer of aligned bytes on an arbitrary alignment boundary.

    @param ptr     Pointer to the memory to reallocate.
    @param nbytes  New number of bytes to allocate
    @param align   Hint on the alignment boundary used at allocation.

    @return A pointer to a reallocated memory block
  **/
  BOOST_FORCEINLINE byte*
  reallocate(byte* ptr, std::size_t nbytes, std::size_t align)
  {
    return reinterpret_cast<byte*>(aligned_realloc(ptr,nbytes,align));
  }

  /*!
    @brief Aligned memory reallocation

    Reallocated a raw buffer of aligned bytes on current architecture preferred
    SIMD comaptible alignment.

    @param ptr     Pointer to the memory to reallocate.
    @param nbytes  New number of bytes to allocate

    @return A pointer to a reallocated memory block
  **/
  inline byte* reallocate( byte* ptr, std::size_t nbytes )
  {
    return reinterpret_cast<byte*>(aligned_realloc( ptr , nbytes
                                                  , BOOST_SIMD_CONFIG_ALIGNMENT
                                                  )
                                  );
  }

  /*!
     Reallocated a raw buffer of aligned bytes using an Allocator.

     @param alloc   Allocator performing the (de)allocation
     @param ptr     Pointer to the memory to reallocate.
     @param nbytes  New number of bytes to allocate
     @param align   Hint on the alignment boundary used at allocation. By
     default, this parameter is equals to the current system SIMD alignment
     requirement.

     @return A pointer to a reallocated memory block containing \c nbytes bytes.
  **/
  template<class Allocator>
  typename  boost::dispatch::meta::
            enable_if_type< typename Allocator::pointer, byte* >::type
  reallocate( Allocator& a, byte* ptr, std::size_t nbytes, std::size_t align )
  {
    /// Resizing to 0 free the pointer data and return
    if(nbytes == 0)
    {
      deallocate(a, ptr );
      return 0;
    }

    /// Reallocating empty pointer performs allocation
    if(ptr == 0) return allocate(a, nbytes, align );

    details::aligned_block_header const old( details::get_block_header( ptr ) );
    std::size_t const oldSize( old.userBlockSize );

    /// Return if idempotent reallocation is performed with constant alignment
    /// TODO Try to just reajust if possible (aka align is lower than before ?)
    if( oldSize == nbytes && is_aligned(ptr,align) ) return ptr;

    /// Else reallocate manually/copy/deallocate old data
    byte* fresh_ptr = allocate(a, nbytes, align );
    if( !fresh_ptr ) return 0;

    std::memcpy( fresh_ptr, ptr, std::min( nbytes, oldSize ) );
    deallocate(a, ptr );

    return fresh_ptr;
  }
} } }

#endif
