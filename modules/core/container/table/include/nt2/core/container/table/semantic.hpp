//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_TABLE_SEMANTIC_HPP_INCLUDED
#define NT2_CORE_CONTAINER_TABLE_SEMANTIC_HPP_INCLUDED

#include <nt2/core/settings/size.hpp>
#include <nt2/core/settings/index.hpp>
#include <nt2/core/settings/shape.hpp>
#include <nt2/core/settings/buffer.hpp>
#include <nt2/core/settings/sharing.hpp>
#include <nt2/core/settings/settings.hpp>
#include <nt2/core/settings/allocator.hpp>
#include <nt2/core/settings/alignment.hpp>
#include <nt2/core/settings/interleaving.hpp>
#include <boost/simd/sdk/memory/allocator.hpp>
#include <nt2/core/settings/storage_order.hpp>
#include <nt2/core/settings/storage_scheme.hpp>
#include <nt2/core/container/table/category.hpp>
#include <nt2/core/settings/storage_duration.hpp>

namespace nt2
{
  namespace tag
  {
    //==========================================================================
    // table_ tag marking a type as using the table semantic and defines
    // table default settings
    //==========================================================================
    struct table_
    {
      typedef _4D                                             of_size_t;
      typedef rectangular_                                    shape_t;
      typedef conventional_                                   storage_scheme_t;
      typedef matlab_index_                                   index_t;
      typedef aligned_                                        alignment_t;
      typedef matlab_order_                                   storage_order_t;
      typedef interleaved_                                    interleaving_t;
      typedef owned_                                          sharing_t;
      typedef dynamic_                                        storage_duration_t;
      typedef nt2::allocator_< boost::simd::memory::allocator<void*> > allocator_t;
      typedef nt2::buffer_<>                                       buffer_t;
    };
  }
}

#endif
