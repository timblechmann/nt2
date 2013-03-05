//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_MEMORY_FORWARD_CONTAINER_HPP_INCLUDED
#define NT2_SDK_MEMORY_FORWARD_CONTAINER_HPP_INCLUDED

//==============================================================================
// Forward declaration
//==============================================================================
namespace nt2 { namespace memory
{
  struct container_base
  {
  };

  template<class T, class S>                   class   container;
  template<class T, class S>                   struct  container_ref;
  template<class T, class S, bool Own = false> struct  container_shared_ref;
} }


#endif
