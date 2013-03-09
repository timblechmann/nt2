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
#include <nt2/core/settings/normalize.hpp>
#include <boost/dispatch/meta/property_of.hpp>
#include <boost/simd/memory/allocator.hpp>
#include <nt2/core/settings/storage_order.hpp>
#include <nt2/core/settings/storage_scheme.hpp>
#include <nt2/core/container/table/category.hpp>
#include <nt2/core/settings/storage_duration.hpp>

namespace nt2
{
  namespace tag { struct table_; }

  namespace meta
  {
    //==========================================================================
    // Table settings normalization specify the following default :
    //
    // Layout:
    // + table is _4D
    // + table is rectangular_
    // + table uses conventional storage scheme
    //
    // Access:
    // + table has a base index of 1
    // + table contains aligned data
    // + table use Matlab storage order
    //
    // Memory:
    // + table owns its memory
    // + table allocates its memory dynamically
    // + table uses boost::simd::memory::allocator
    //==========================================================================
    template<typename T, typename S> struct normalize<tag::table_, T, S>
    {
      // Memory layout
      typedef typename option<S,tag::of_size_         , _4D           >::type sz;
      typedef typename option<S,tag::shape_           , rectangular_  >::type sh;
      typedef typename option<S,tag::storage_scheme_  , conventional_ >::type ss;
      typedef settings layout(sz,sh,ss);

      // Access layout
      typedef typename option<S,tag::index_           , matlab_index_ >::type bs;
      typedef typename option<S,tag::alignment_       , aligned_      >::type ag;
      typedef typename option<S,tag::storage_order_   , matlab_order_ >::type so;

      // Memory Management
      typedef typename option<S,tag::interleaving_    , interleaved_  >::type il;
      typedef typename option<S,tag::sharing_         , owned_        >::type sg;
      typedef typename option<S,tag::storage_duration_, dynamic_      >::type sd;
      typedef typename option<S,tag::allocator_
                               ,allocator_< boost::simd::memory::allocator<T> >
                               >::type                                        al;
      typedef typename option<S,tag::buffer_, buffer_<>            >::type    bf;

      // Normalized settings
      typedef settings type(tag::table_,sz,sh,bs,ag,so,il,sg,sd,ss,al,bf);
    };
  }

  namespace tag
  {
    //==========================================================================
    // table_ tag marking a type as usign the table semantic
    //==========================================================================
    struct table_
    {
      template<class T, class S, class Origin> struct apply
      {
        typedef ext::table_
                < typename boost::dispatch::meta::property_of<T,Origin>::type
                , typename meta::normalize<table_,T,S>::layout
                >                                                type;
      };
    };
  }
}

#endif
