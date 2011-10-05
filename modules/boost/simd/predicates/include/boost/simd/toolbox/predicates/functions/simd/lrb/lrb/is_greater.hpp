//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTIONS_SIMD_LRB_LRB_IS_GREATER_TO_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_PREDICATES_FUNCTIONS_SIMD_LRB_LRB_IS_GREATER_TO_HPP_INCLUDED

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::is_greater_, boost::simd::tag::lrb_
                            , (A0)
                            , ((simd_<double_<A0>,boost::simd::tag::lrb_>))
                              ((simd_<double_<A0>,boost::simd::tag::lrb_>))
                            )
  {
    typedef typename meta::boolean<A0>::type result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return _mm512_cmplt_pd(a1,a0);
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::is_greater_, boost::simd::tag::lrb_
                            , (A0)
                            , ((simd_<single_<A0>,boost::simd::tag::lrb_>))
                              ((simd_<single_<A0>,boost::simd::tag::lrb_>))
                            )
  {
    typedef typename meta::boolean<A0>::type result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return _mm512_cmplt_ps(a1,a0);

    }
  };



  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::is_greater_, boost::simd::tag::lrb_
                            , (A0)
                            , ((simd_<int32_<A0>,boost::simd::tag::lrb_>))
                              ((simd_<int32_<A0>,boost::simd::tag::lrb_>))
                            )
  {
    typedef typename meta::boolean<A0>::type result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return _mm512_cmplt_pi(a1,a0);
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::is_greater_, boost::simd::tag::lrb_
                            , (A0)
                            , ((simd_<uint32_<A0>,boost::simd::tag::lrb_>))
                              ((simd_<uint32_<A0>,boost::simd::tag::lrb_>))
                            )
  {
    typedef typename meta::boolean<A0>::type result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return _mm512_cmplt_pu(a1,a0);
    }
  };
} } }

#endif
