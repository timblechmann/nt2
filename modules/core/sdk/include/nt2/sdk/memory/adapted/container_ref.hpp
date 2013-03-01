//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_MEMORY_ADAPTED_CONTAINER_REF_HPP_INCLUDED
#define NT2_SDK_MEMORY_ADAPTED_CONTAINER_REF_HPP_INCLUDED

#include <nt2/core/container/dsl/forward.hpp>
#include <nt2/sdk/memory/forward/container.hpp>
#include <nt2/sdk/meta/is_container.hpp>
#include <boost/dispatch/meta/model_of.hpp>
#include <boost/dispatch/meta/value_of.hpp>
#include <boost/dispatch/meta/hierarchy_of.hpp>

#include <nt2/core/settings/option.hpp>
#include <nt2/core/settings/forward/semantic.hpp>
#include <nt2/core/container/table/semantic.hpp>

namespace nt2 { namespace meta
{
  //============================================================================
  // Register container as a proper container
  //============================================================================
  template<class T, class S>
  struct  is_container< memory::container_ref<T, S> >
        : boost::mpl::true_
  {};

  template<class T, class S>
  struct  is_container_ref< memory::container_ref<T, S> >
        : boost::mpl::true_
  {};
} }

namespace boost { namespace dispatch { namespace meta
{
  //============================================================================
  // value_of specializations
  //============================================================================
  template<class T, class S>
  struct value_of< nt2::memory::container_ref<T, S> >
  {
    typedef T& type;
  };

  //============================================================================
  // model_of specialization
  //============================================================================
  template<class T, class S>
  struct model_of< nt2::memory::container_ref<T, S> >
  {
    struct type
    {
      template<class X>
      struct apply
      {
        typedef nt2::memory::container_ref<X, S> type;
      };
    };
  };

  //============================================================================
  // container hierarchy
  //============================================================================
  template<class T, class S, class Origin>
  struct hierarchy_of< nt2::memory::container_ref<T, S>, Origin >
  {
    typedef typename nt2::meta::option < S
                                      , nt2::tag::semantic_
                                      , nt2::tag::table_
                                      >::type                   semantic_t;
    typedef typename semantic_t::template apply<T,S,Origin>::type type;
  };
} } }

#endif
