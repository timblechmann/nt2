//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_DSL_FUNCTIONS_CONTAINER_TERMINAL_HPP_INCLUDED
#define NT2_DSL_FUNCTIONS_CONTAINER_TERMINAL_HPP_INCLUDED

#include <nt2/dsl/functions/terminal.hpp>
#include <nt2/include/functions/splat.hpp>
#include <nt2/include/functions/unaligned_load.hpp>
#include <nt2/include/functions/unaligned_store.hpp>
#include <nt2/include/functions/simd/maximum.hpp>
#include <nt2/core/settings/details/fusion.hpp>
#include <nt2/core/container/table/category.hpp>
#include <nt2/sdk/simd/category.hpp>
#include <nt2/sdk/meta/cardinal_of.hpp>
#include <boost/assert.hpp>

namespace nt2 { namespace ext
{
  template<class T, class A0>
  std::size_t maxpos(A0 const& a0)
  {
    return a0 + meta::cardinal_of<T>::value - 1;
  }

  template<class T, class A0, class X>
  std::size_t maxpos(boost::simd::native<A0, X> const& a0)
  {
    return nt2::maximum(a0);
  }

  //============================================================================
  // table terminal with a position in scalar read mode
  //============================================================================
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::terminal_, tag::cpu_
                            , (A0)(T0)(L0)(S0)(State)(Data)
                            , ((expr_< container_<unspecified_<A0>,S0,L0>
                                     , T0
                                     , boost::mpl::long_<0>
                                     >
                              ))
                              (generic_< integer_<State> >)
                              (target_<scalar_<unspecified_<Data> > >)
                            )
  {

    typedef typename boost::dispatch::meta::
    scalar_of<A0&>::type                               result_type;

    BOOST_FORCEINLINE result_type
    operator()(A0& a0, State const& state, Data const&) const
    {
      return boost::proto::value(a0)[state];
    }
  };

  //============================================================================
  // table terminal with a position in scalar write mode
  //============================================================================
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::terminal_, tag::cpu_
                            , (A0)(T0)(S0)(L0)(State)(Data)
                            , ((expr_< container_<unspecified_<A0>,S0,L0>
                                     , T0
                                     , boost::mpl::long_<0>
                                     >
                              ))
                              (generic_< integer_<State> >)
                              (scalar_<unspecified_<Data> >)
                            )
  {
    typedef typename boost::dispatch::meta::
    scalar_of<A0&>::type                                result_type;

    BOOST_FORCEINLINE result_type
    operator()(A0& a0, State const& state, Data const& data) const
    {
      return boost::proto::value(a0)[state] = data;
    }
  };

  //============================================================================
  // table terminal with a position in SIMD read mode
  //============================================================================
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::terminal_, tag::cpu_
                            , (A0)(T0)(S0)(L0)(State)(Data)(X)
                            , ((expr_< container_<unspecified_<A0>,S0,L0>
                                     , T0
                                     , boost::mpl::long_<0>
                                     >
                              ))
                              (generic_< integer_<State> >)
                              ((target_< simd_<unspecified_<Data>, X> >))
                            )
  {
    typedef typename Data::type result_type;

    BOOST_FORCEINLINE
    result_type operator()(A0 const& a0, State const& state, Data const&) const
    {
      BOOST_ASSERT_MSG
      ( boost::proto::value(a0).is_safe(maxpos<result_type>(state))
      , "Out of range SIMD read"
      );

      return unaligned_load<result_type>(a0.raw(), state);
    }
  };

  //============================================================================
  // table terminal with a position in SIMD write mode
  //============================================================================
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::terminal_, tag::cpu_
                            , (A0)(T0)(S0)(L0)(State)(Data)(X)
                            , ((expr_< container_<unspecified_<A0>,S0,L0>
                                     , T0
                                     , boost::mpl::long_<0>
                                     >
                              ))
                              (generic_< integer_<State> >)
                              ((simd_<unspecified_<Data>, X>))
                            )
  {
    typedef Data                                            result_type;

    BOOST_FORCEINLINE
    result_type operator()(A0& a0, State const& state, Data const& data) const
    {
      BOOST_ASSERT_MSG
      ( boost::proto::value(a0).is_safe(maxpos<result_type>(state))
      , "Out of range SIMD read"
      );

      return unaligned_store<result_type>(data, a0.raw(), state);
    }
  };

  //============================================================================
  // scalar terminal, return value in read mode
  //============================================================================
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::terminal_, tag::cpu_
                            , (A0)(T0)(State)(Data)
                            , ((expr_< scalar_< unspecified_<A0> >
                                     , T0
                                     , boost::mpl::long_<0>
                                     >
                              ))
                              (generic_< integer_<State> >)
                              (target_< scalar_< unspecified_<Data> > >)
                            )
  {
    typedef typename nt2::meta::call<T0(A0&)>::type result_type;

    BOOST_FORCEINLINE result_type
    operator()(A0& a0, State const&, Data const&) const
    {
      return boost::proto::value(a0);
    }
  };

  //============================================================================
  // scalar terminal, assign value in write mode
  //============================================================================
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::terminal_, tag::cpu_
                            , (A0)(T0)(State)(Data)
                            , ((expr_< scalar_< unspecified_<A0> >
                                     , T0
                                     , boost::mpl::long_<0>
                                     >
                              ))
                              (generic_< integer_<State> >)
                              (scalar_< unspecified_<Data> >)
                            )
  {
    typedef typename nt2::meta::call<T0(A0&)>::type result_type;

    BOOST_FORCEINLINE result_type
    operator()(A0& a0, State const&, Data const& data) const
    {
      return boost::proto::value(a0) = data;
    }
  };

  //============================================================================
  // scalar terminal, splat value in SIMD read mode
  //============================================================================
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::terminal_, tag::cpu_
                            , (A0)(T0)(State)(Data)(X)
                            , ((expr_< scalar_< unspecified_<A0> >
                                     , T0
                                     , boost::mpl::long_<0>
                                     >
                              ))
                              (generic_< integer_<State> >)
                              ((target_< simd_< unspecified_<Data>,X > >))
                            )
  {
    typedef typename Data::type result_type;

    BOOST_FORCEINLINE
    result_type operator()(A0& a0, State const&, Data const&) const
    {
      return nt2::splat<result_type>(boost::proto::value(a0));
    }
  };

  //============================================================================
  // scalar terminal, error in SIMD write mode
  //============================================================================
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::terminal_, tag::cpu_
                            , (A0)(T0)(State)(Data)(X)
                            , ((expr_< scalar_< unspecified_<A0> >
                                     , T0
                                     , boost::mpl::long_<0>
                                     >
                              ))
                              (generic_< integer_<State> >)
                              ((simd_< unspecified_<Data>,X >))
                            )
  {
    typedef Data const&      result_type;

    BOOST_FORCEINLINE
    result_type operator()(A0&, State const&, Data const& data) const
    {
      BOOST_ASSERT_MSG(0, "Writing SIMD value to scalar not allowed");
      return data;
    }
  };
} }

#endif
