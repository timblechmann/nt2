//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2011 - 2012   MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_UNALIGNED_LOAD_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_UNALIGNED_LOAD_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>
#include <boost/dispatch/meta/as.hpp>

namespace boost { namespace simd
{
  namespace tag { struct unaligned_load_ : ext::elementwise_<unaligned_load_> { typedef ext::elementwise_<unaligned_load_> parent; }; }

  //////////////////////////////////////////////////////////////////////////////
  // Unaligned_Load a data of type T from the memory zone given by (a0,a1)
  //////////////////////////////////////////////////////////////////////////////
  template<class T,class A0,class A1> inline
  typename boost::dispatch::meta::call<tag::unaligned_load_ ( A0 const&, A1 const&
                                                , boost::dispatch::meta::as_<T>
                                                )
                            >::type
  unaligned_load(A0 const& a0,A1 const& a1 )
  {
    typename boost::dispatch::make_functor<tag::unaligned_load_, A0>::type callee;
    return callee(a0,a1,boost::dispatch::meta::as_<T>());
  }

  //////////////////////////////////////////////////////////////////////////////
  // Unaligned_Load a data of type T from the memory zone given by (a0)
  //////////////////////////////////////////////////////////////////////////////
  template<class T,class A0> inline
  typename boost::dispatch::meta::call<tag::unaligned_load_ ( A0 const&, int
                                                , boost::dispatch::meta::as_<T>
                                                )
                            >::type
  unaligned_load(A0 const& a0)
  {
    typename boost::dispatch::make_functor<tag::unaligned_load_, A0>::type callee;
    return callee(a0,0,boost::dispatch::meta::as_<T>());
  }

  //////////////////////////////////////////////////////////////////////////////
  // Unaligned_Load a data of type T from the memory zone given by (a0,a1) and a sub-type
  // level offset
  //////////////////////////////////////////////////////////////////////////////
  template<class T,int Offset,class A0,class A1> inline
  typename boost::dispatch::meta::call<tag::unaligned_load_ ( A0 const&, A1 const&
                                                , boost::dispatch::meta::as_<T>
                                                , boost::mpl::int_<Offset>
                                                )
                            >::type
  unaligned_load(A0 const& a0,A1 const& a1 )
  {
    typename boost::dispatch::make_functor<tag::unaligned_load_, A0>::type callee;
    return callee(a0,a1,boost::dispatch::meta::as_<T>(),boost::mpl::int_<Offset>());
  }

  //////////////////////////////////////////////////////////////////////////////
  // Unaligned_Load a data of type T from the memory zone given by (a0) and a sub-type
  // level offset
  //////////////////////////////////////////////////////////////////////////////
  template<class T,int Offset,class A0> inline
  typename boost::dispatch::meta::call<tag::unaligned_load_ ( A0 const&, int
                                                , boost::dispatch::meta::as_<T>
                                                , boost::mpl::int_<Offset>
                                                )
                            >::type
  unaligned_load(A0 const& a0)
  {
    typename boost::dispatch::make_functor<tag::unaligned_load_, A0>::type callee;
    return callee(a0,0,boost::dispatch::meta::as_<T>(),boost::mpl::int_<Offset>());
  }

} }

#endif
