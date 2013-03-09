//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SIMD_VMX_ALTIVEC_UNALIGNED_STORE_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SIMD_VMX_ALTIVEC_UNALIGNED_STORE_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_VMX_SUPPORT

#include <boost/simd/toolbox/memory/functions/unaligned_store.hpp>
#include <boost/simd/toolbox/memory/functions/details/char_helper.hpp>
#include <boost/simd/sdk/meta/cardinal_of.hpp>
#include <boost/simd/sdk/meta/make_dependent.hpp>
#include <iterator>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::unaligned_store_ , boost::simd::tag::altivec_
                            , (A0)(A1)(A2)
                            , ((simd_< arithmetic_<A0>, boost::simd::tag::altivec_ >))
                              (iterator_< scalar_< arithmetic_<A1> > >)
                              (scalar_< integer_<A2> >)
                            )
  {
    typedef A0 result_type;
    typedef native<typename meta::make_dependent<boost::simd::uint8_t, A0>::type, boost::simd::tag::altivec_> n_t;

    BOOST_SIMD_FUNCTOR_CALL(3)
    {
      static std::size_t sz   = sizeof(typename std::iterator_traits<A1>::value_type);
      static std::size_t card = meta::cardinal_of<A0>::value;
      result_type   MSQ = vec_ld(a2*sz, char_helper(a1));
      result_type   LSQ = vec_ld((a2*sz)+card*sz-1, char_helper(a1));
      n_t     edgeAlign = vec_lvsl(a2*sz, char_helper(a1));
      result_type edges = vec_perm(LSQ(), MSQ(), edgeAlign());
      n_t         align = vec_lvsr(a2*sz, char_helper(a1));
      MSQ = vec_perm(edges(), a0(), align());
      LSQ = vec_perm(a0(), edges(), align());
      vec_st(LSQ(), (a2*sz)+card*sz-1, char_helper(a1));
      vec_st(MSQ(), (a2*sz)          , char_helper(a1));
      return a0;
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::unaligned_store_ , boost::simd::tag::altivec_
                            , (A0)(A1)
                            , ((simd_< arithmetic_<A0>, boost::simd::tag::altivec_ >))
                              (iterator_< scalar_< arithmetic_<A1> > >)
                            )
  {
    typedef A0 result_type;
    typedef native<typename meta::make_dependent<boost::simd::uint8_t, A0>::type, boost::simd::tag::altivec_> n_t;

    BOOST_SIMD_FUNCTOR_CALL(2)
    {
      static std::size_t sz   = sizeof(typename std::iterator_traits<A1>::value_type);
      static std::size_t card = meta::cardinal_of<A0>::value;
      result_type   MSQ = vec_ld(0        , char_helper(a1));
      result_type   LSQ = vec_ld(card*sz-1, char_helper(a1));
      n_t     edgeAlign = vec_lvsl(0      , char_helper(a1));
      result_type edges = vec_perm(LSQ(), MSQ(), edgeAlign());
      n_t         align = vec_lvsr(0, char_helper(a1));
      MSQ = vec_perm(edges(), a0(), align());
      LSQ = vec_perm(a0(), edges(), align());
      vec_st(LSQ(), card*sz-1, char_helper(a1));
      vec_st(MSQ(),         0, char_helper(a1));
      return a0;
    }
  };
} } }

#endif
#endif /* BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SIMD_VMX_ALTIVEC_UNALIGNED_STORE_HPP_INCLUDED */
