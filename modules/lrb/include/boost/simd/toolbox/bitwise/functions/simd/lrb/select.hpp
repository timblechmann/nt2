//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_BITWISE_FUNCTIONS_SIMD_LRB_LRB_SELECT_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_BITWISE_FUNCTIONS_SIMD_LRB_LRB_SELECT_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_LRB_SUPPORT
#include <iostream>

#include <boost/simd/toolbox/predicates/functions/is_nez.hpp>
#include <boost/simd/toolbox/bitwise/functions/select.hpp>
#include <boost/simd/sdk/simd/native_cast.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::select_, boost::simd::tag::lrb_
                            , (A0)(A1)
                            , ((simd_<type32_<A0>, boost::simd::tag::lrb_>))
                              ((simd_<type32_<A1>, boost::simd::tag::lrb_>))
                              ((simd_<type32_<A1>, boost::simd::tag::lrb_>))
                            )
  {
    typedef A1 result_type;
    inline result_type operator()(A0 const& a0,A1 const& a1,A1 const& a2) const
    {
      typedef native < float, boost::simd::tag::lrb_> vf;
      vf tmp1 = native_cast<vf>(a1);
      vf tmp2 =native_cast<vf>(a2);
      __mmask m = is_nez(a0); 
      A1 that = { native_cast<A1>(_mm512_mask_movd(tmp2, m, tmp1))};
      return that; 
    }
  }; 
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::select_, boost::simd::tag::lrb_
                            , (A0)(A1)
                            , ((simd_<type64_<A0>, boost::simd::tag::lrb_>))
                              ((simd_<type64_<A1>, boost::simd::tag::lrb_>))
                              ((simd_<type64_<A1>, boost::simd::tag::lrb_>))
                            )
  {
    typedef A1 result_type;
    inline result_type operator()(A0 const& a0,A1 const& a1,A1 const& a2) const
    {
      typedef native < float, boost::simd::tag::lrb_> vf;
      vf tmp1 = native_cast<vf>(a1);
      vf tmp2 =native_cast<vf>(a2);
      __mmask m = is_nez(a0); 
      A1 that = { native_cast<A1>(_mm512_mask_movq(tmp2, m, tmp1))};
      return that; 
    }
  };
  
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::select_, boost::simd::tag::lrb_
                            , (A0)(A1)
                            , ((scalar_<arithmetic_<A0> >))
                              ((simd_<type32_<A1>, boost::simd::tag::lrb_>))
                              ((simd_<type32_<A1>, boost::simd::tag::lrb_>))
                            )
  {
    typedef A1 result_type;
    inline result_type operator()(A0 const& a0,A1 const& a1,A1 const& a2) const
    {
      typedef native < float, boost::simd::tag::lrb_> vf;
      vf tmp1 = native_cast<vf>(a1);
      vf tmp2 =native_cast<vf>(a2);
      __mmask m = a0; 
      A1 that = { native_cast<A1>(_mm512_mask_movd(tmp2, m, tmp1))};
      return that; 
    }
  };
  
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::select_, boost::simd::tag::lrb_
                            , (A0)(A1)
                            , ((scalar_<arithmetic_<A0> >))
                              ((simd_<type64_<A1>, boost::simd::tag::lrb_>))
                              ((simd_<type64_<A1>, boost::simd::tag::lrb_>))
                            )
  {
    typedef A1 result_type;
    inline result_type operator()(A0 const& a0,A1 const& a1,A1 const& a2) const
    {
      typedef native < float, boost::simd::tag::lrb_> vf;
      vf tmp1 = native_cast<vf>(a1);
      vf tmp2 =native_cast<vf>(a2);
      __mmask m = a0; 
      A1 that = { native_cast<A1>(_mm512_mask_movq(tmp2, m, tmp1))};
      return that; 
    }
  };

} } }



#endif
#endif
