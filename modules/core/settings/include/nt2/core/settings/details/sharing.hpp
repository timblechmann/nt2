//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_SETTINGS_DETAILS_SHARING_HPP_INCLUDED
#define NT2_CORE_SETTINGS_DETAILS_SHARING_HPP_INCLUDED

#include <nt2/core/settings/option.hpp>
#include <nt2/sdk/memory/fixed_allocator.hpp>
#include <nt2/core/settings/storage_duration.hpp>

namespace nt2
{
  //============================================================================
  // When container shares memory, use a dynamic_ buffer with a fixed_allocator
  //============================================================================
  struct shared_
  {
    template<class Container> struct apply
    {
      typedef typename Container::raw_value_type value_type;
      typedef allocator_< memory::fixed_allocator<value_type> >                 alloc_t;
      typedef typename dynamic_::template apply<Container,alloc_t>::type  type;
    };
  };

  //============================================================================
  // When memory is owned by the container, buffer dependd on storage_duration
  //============================================================================
  struct owned_
  {
    template<class Container> struct apply
    {
      typedef typename meta::option < typename Container::settings_type
                                    , tag::storage_duration_
                                    , typename Container::semantic_t::storage_duration_t
                                    >::type                         sd_t;
      typedef typename sd_t::template apply<Container>::type              type;
    };
  };
}

#endif
