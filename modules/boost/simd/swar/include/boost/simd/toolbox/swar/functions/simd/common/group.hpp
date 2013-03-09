//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_SWAR_FUNCTIONS_SIMD_COMMON_GROUP_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_SWAR_FUNCTIONS_SIMD_COMMON_GROUP_HPP_INCLUDED

#include <boost/simd/toolbox/swar/functions/group.hpp>
#include <boost/simd/include/functions/simd/load.hpp>
#include <boost/simd/include/functions/simd/saturate.hpp>
#include <boost/simd/memory/aligned_type.hpp>
#include <boost/simd/sdk/meta/cardinal_of.hpp>
#include <boost/simd/sdk/meta/scalar_of.hpp>
#include <boost/simd/sdk/simd/details/native/meta/downgrade.hpp>
#include <boost/mpl/not.hpp>
#include <boost/type_traits/is_same.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is downgradable
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION_IF( boost::simd::tag::group_, tag::cpu_,
                          (A0)(X),
                          (boost::mpl::not_< boost::is_same<A0, typename dispatch::meta::downgrade<A0>::type> >),
                          ((simd_<arithmetic_<A0>,X>))((simd_<arithmetic_<A0>,X>))
                        )
  {

    typedef typename dispatch::meta::downgrade<A0>::type result_type;

    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      A0 aa0 =  boost::simd::saturate<result_type>(a0);
      A0 aa1 =  boost::simd::saturate<result_type>(a1);
      static const size_t size = boost::simd::meta::cardinal_of<A0>::value;
      typedef typename meta::scalar_of<result_type>::type sR;
      BOOST_SIMD_ALIGNED_TYPE(sR) tmp[size*2];
      for(size_t i = 0; i != size; ++i)  tmp[i]      = static_cast<sR>(aa0[i]);
      for(size_t i = 0; i != size; ++i)  tmp[i+size] = static_cast<sR>(aa1[i]);
      return load<result_type>(&tmp[0], 0);
    }
  };
} } }
#endif
