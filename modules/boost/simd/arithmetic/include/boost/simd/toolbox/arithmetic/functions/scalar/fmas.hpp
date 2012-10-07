//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_SCALAR_FMAS_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_SCALAR_FMAS_HPP_INCLUDED
#include <boost/simd/toolbox/arithmetic/functions/fmas.hpp>
#include <boost/simd/include/functions/scalar/saturate.hpp>
#include <boost/simd/include/functions/scalar/is_gtz.hpp>
#include <boost/simd/include/functions/scalar/is_greater.hpp>
#include <boost/simd/include/functions/scalar/is_less.hpp>
#include <boost/simd/include/functions/scalar/min.hpp>
#include <boost/simd/include/functions/scalar/max.hpp>
#include <boost/simd/include/constants/valmin.hpp>
#include <boost/simd/include/constants/valmax.hpp>
#include <boost/dispatch/meta/upgrade.hpp>
#include <boost/dispatch/meta/as_unsigned.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::fmas_, tag::cpu_
                                     , (A0)
                                     , (scalar_< integer_<A0> >)
                                     (scalar_< integer_<A0> >)
                                     (scalar_< integer_<A0> >)
                                     )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(3)
    {
      typedef typename dispatch::meta::upgrade<A0>::type utype; 
      return static_cast<A0>(boost::simd::saturate<A0>(utype(a0)*utype(a1)+utype(a2)));
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::fmas_, tag::cpu_
                                     , (A0)
                                     , (scalar_< unsigned_<A0> >)
                                     (scalar_< unsigned_<A0> >)
                                     (scalar_< unsigned_<A0> >)
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(3)
    {
      typedef typename dispatch::meta::upgrade<A0>::type utype; 
      return static_cast<A0>(boost::simd::min(utype(boost::simd::Valmax<A0>()),
                                              utype(a0)*utype(a1)+utype(a2)));
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::fmas_, tag::cpu_
                                     , (A0)
                                     , (scalar_< int64_<A0> >)
                                     (scalar_< int64_<A0> >)
                                     (scalar_< int64_<A0> >)
                                     )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      typedef typename dispatch::meta::as_unsigned<A0>::type utype;
      result_type_t tmp = muls(a0, a1);
      if (tmp > Valmin<result_type>() && tmp < Valmax<result_type>())
        {
          return adds(tmp, a1);
        }
      else if (tmp == Valmax<A0>())
        { //This part is incorrect
          if (a2 >= 0) return Valmax<A0>();
          else
            {
              result_type ma =  max(a1, a0);
              result_type mi =  min(a1, a0);
              if (a0 > 0)       return adds(muls(ma-1, mi), mi+a2);
              else /*(a0 < 0)*/ return adds(muls(mi+1, ma), (a2-(mi+1))+1); 
            }
        }
      else /*if (tmp == Valmin) */
        {
          if (a2 <= 0) return Valmin<A0>();
          else
            {
              result_type ma =  max(nt2::abs(a1), nt2::abs(a0));
              result_type mi =  min(nt2::abs(a1), nt2::abs(a0));
              return adds(mi, subss(a2, muls(ma-1, mi))); 
            }
        }
    };
    
    BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::fmas_, tag::cpu_
                                     , (A0)
                                     , (scalar_< uint64_<A0> >)
                                     (scalar_< uint64_<A0> >)
                                     (scalar_< uint64_<A0> >)
                                     )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(3)
    {
      return adds(muls(a0, a1), a2); 
    };

} } }


#endif
