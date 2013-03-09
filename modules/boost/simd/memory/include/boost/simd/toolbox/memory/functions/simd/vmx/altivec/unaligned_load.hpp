//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SIMD_VMX_ALTIVEC_UNALIGNED_LOAD_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SIMD_VMX_ALTIVEC_UNALIGNED_LOAD_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_VMX_SUPPORT

#include <boost/simd/toolbox/memory/functions/unaligned_load.hpp>
#include <boost/simd/toolbox/memory/functions/details/char_helper.hpp>
#include <boost/simd/sdk/meta/cardinal_of.hpp>
#include <boost/simd/sdk/meta/make_dependent.hpp>
#include <iterator>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::unaligned_load_, boost::simd::tag::altivec_
                            , (A0)(A1)(A2)
                            , (iterator_< scalar_< arithmetic_<A0> > >)
                              (scalar_< fundamental_<A1> >)
                              ((target_<simd_<arithmetic_<A2>,boost::simd::tag::altivec_> >))
                            )
  {
    typedef typename A2::type result_type;
    typedef native<typename meta::make_dependent<boost::simd::uint8_t, A0>::type, boost::simd::tag::altivec_> n_t;
    inline result_type operator()(const A0& a0, const A1& a1, const A2&)const
    {
      static std::size_t sz   = sizeof(typename std::iterator_traits<A0>::value_type);
      static std::size_t card = meta::cardinal_of<result_type>::value;
      result_type MSQ  = vec_ld(a1*sz, char_helper(a0));
      result_type LSQ  = vec_ld((a1*sz)+card*sz-1, char_helper(a0));
      n_t         mask = vec_lvsl(a1*sz, char_helper(a0));
      return vec_perm(MSQ(), LSQ(), mask());
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::unaligned_load_, boost::simd::tag::altivec_
                            , (A0)(A1)
                            , (iterator_< scalar_< arithmetic_<A0> > >)
                              ((target_<simd_<arithmetic_<A1>,boost::simd::tag::altivec_> >))
                            )
  {
    typedef typename A1::type result_type;
    typedef native<typename meta::make_dependent<boost::simd::uint8_t, A0>::type, boost::simd::tag::altivec_> n_t;
    inline result_type operator()(const A0& a0, const A1&)const
    {
      static std::size_t sz   = sizeof(typename std::iterator_traits<A0>::value_type);
      static std::size_t card = meta::cardinal_of<result_type>::value;
      result_type MSQ  = vec_ld(0, char_helper(a0));
      result_type LSQ  = vec_ld(card*sz-1, char_helper(a0));
      n_t         mask = vec_lvsl(0, char_helper(a0));
      return vec_perm(MSQ(), LSQ(), mask());
    }
  };
} } }

#endif
#endif /* BOOST_SIMD_TOOLBOX_MEMORY_FUNCTIONS_SIMD_VMX_ALTIVEC_UNALIGNED_LOAD_HPP_INCLUDED */
