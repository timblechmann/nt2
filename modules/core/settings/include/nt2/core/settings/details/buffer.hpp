//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_SETTINGS_DETAILS_BUFFER_HPP_INCLUDED
#define NT2_CORE_SETTINGS_DETAILS_BUFFER_HPP_INCLUDED

#include <boost/mpl/apply.hpp>
#include <nt2/core/settings/option.hpp>
#include <nt2/core/settings/sharing.hpp>

namespace nt2
{
  //============================================================================
  // If any Buffer type is provided, return it w/e other settings are
  //============================================================================
  template<class Buffer> struct buffer_
  {
    template<class Container> struct apply { typedef Buffer type; };
  };

  //============================================================================
  // If not, build up the buffer manually from the user-defined settings.
  //============================================================================
  template<> struct buffer_<void>
  {
    template<class Container> struct apply
    {
      typedef typename meta::option < typename Container::settings_type
                                    , tag::sharing_
                                    , typename Container::semantic_t::sharing_t
                                    >::type                     sharing_t;
      typedef typename sharing_t::template apply<Container>::type      type;
    };
  };
}

#endif
