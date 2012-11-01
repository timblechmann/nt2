//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_SETTINGS_SEMANTIC_HPP_INCLUDED
#define NT2_CORE_SETTINGS_SEMANTIC_HPP_INCLUDED

#include <nt2/core/settings/forward/semantic.hpp>
#include <nt2/core/settings/option.hpp>
#include <nt2/core/settings/index.hpp>
#include <nt2/core/settings/alignment.hpp>
#include <nt2/core/settings/storage_order.hpp>

namespace nt2
{
  namespace tag
  {
    struct table_;

    struct no_semantic_
    {
      typedef matlab_index_ index_t;
      typedef _0D           of_size_t;
      typedef matlab_order_ storage_order_t;
      typedef unaligned_    alignment_t;
    };
  }

  namespace meta
  {
    template<class Default> struct option<tag::table_, tag::semantic_, Default>
    {
      typedef tag::table_ type;
    };

    template<class Default> struct option<tag::no_semantic_, tag::semantic_, Default>
    {
      typedef tag::no_semantic_ type;
    };
  }
}

#endif
