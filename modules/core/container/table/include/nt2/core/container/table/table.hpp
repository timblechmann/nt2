//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_TABLE_TABLE_HPP_INCLUDED
#define NT2_CORE_CONTAINER_TABLE_TABLE_HPP_INCLUDED

#include <nt2/core/container/dsl.hpp>
#include <nt2/sdk/memory/container.hpp>

#include <nt2/include/functions/construct.hpp>
#include <nt2/core/container/table/category.hpp>
#include <nt2/core/container/table/semantic.hpp>
#include <nt2/core/container/table/adapted/table.hpp>

#if defined(BOOST_MSVC)
#pragma warning( push )
#pragma warning( disable : 4522 )
#endif

namespace nt2 { namespace container
{
  template<class T, class S>
  struct  table
        : expression< boost::proto::basic_expr< boost::proto::tag::terminal
                                              , boost::proto::term< nt2::memory::container<T,S> >
                                              >
                    , nt2::memory::container<T,S>
                    >
  {
    typedef memory::container<T,S>                                container_type;
    typedef expression< boost::proto::basic_expr< boost::proto::tag::terminal
                                                , boost::proto::term<container_type>
                                                 >
                      , container_type
                      >                                           nt2_expression;

    typedef typename container_type::pointer                      pointer;
    typedef typename container_type::const_pointer                const_pointer;
    typedef typename container_type::iterator                     iterator;
    typedef typename container_type::const_iterator               const_iterator;
    typedef typename container_type::allocator_type               allocator_type;

    //==========================================================================
    //  table default constructor
    //==========================================================================
    table() {}

    //==========================================================================
    //  table constructor from its allocator
    //==========================================================================
    table( allocator_type const& a ) : nt2_expression(container_type(a)) {}

    //==========================================================================
    // table copy constructor
    //==========================================================================
    table( table const& a0 ) : nt2_expression(a0)
    {
    }

    //==========================================================================
    // table constructor from a single initializer.
    // This version handles initializing from of_size or expression.
    //==========================================================================
    template<class A0>
    table( A0 const& a0 )
    {
      nt2::construct(*this,a0);
    }

    //==========================================================================
    // table constructor from a pair of initializer.
    //==========================================================================
    template<class A0, class A1>
    table( A0 const& a0, A1 const& a1 )
    {
      nt2::construct(*this,a0,a1);
    }

    //==========================================================================
    // table constructor from a triplet of initializer.
    // This version handles initializing from : { size, Iterator, Iterator }
    //==========================================================================
    template<class A0, class A1, class A2>
    table( A0 const& a0, A1 const& a1, A2 const& a2 )
    {
      nt2::construct(*this,a0,a1,a2);
    }

    //==========================================================================
    // Enable base expression handling of assignment
    //==========================================================================
    using nt2_expression::operator=;

    iterator        begin()       { return nt2_expression::raw(); }
    const_iterator  begin() const { return nt2_expression::raw(); }

    iterator        end()       { return begin() + nt2_expression::size(); }
    const_iterator  end() const { return begin() + nt2_expression::size(); }
  };
} }

#if defined(BOOST_MSVC)
#pragma warning( pop )
#endif

#endif
