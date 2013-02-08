//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2011 - 2012   MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_FUNCTIONS_COMMON_BAND_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_COMMON_BAND_HPP_INCLUDED

#include <nt2/core/functions/band.hpp>
#include <nt2/include/functions/ge.hpp>
#include <nt2/include/functions/le.hpp>
#include <nt2/include/functions/eq.hpp>
#include <nt2/include/functions/run.hpp>
#include <nt2/include/functions/if_else.hpp>
#include <nt2/include/functions/enumerate.hpp>
#include <nt2/include/functions/logical_and.hpp>
#include <nt2/include/constants/zero.hpp>
#include <nt2/sdk/meta/as_index.hpp>
#include <nt2/core/utility/as_index.hpp>
#include <nt2/core/utility/as_subscript.hpp>

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::run_, tag::cpu_
                            , (A0)(State)(Data)(N)
                            , ((node_<A0, nt2::tag::band_, N, nt2::container::domain>))
                              (generic_< integer_<State> >)
                              (target_< unspecified_<Data> >)
                            )
  {
    typedef typename Data::type                                     result_type;
    typedef typename meta::as_index<result_type>::type                      i_t;
    typedef typename meta::
                     call<nt2::tag::enumerate_(State,meta::as_<i_t>)>::type p_t;
    typedef typename result_of::as_subscript<_2D,p_t>::type                 s_t;

    BOOST_FORCEINLINE result_type
    operator()(A0 const& a0, State const& p, Data const& t) const
    {
      // Retrieve 2D position from the linear index
      s_t const pos = as_subscript(_2D(a0.extent()),enumerate<i_t>(p));

      // Return the upper triangular section with 1 on the diagonal
      return nt2::if_else ( nt2::eq(pos[0],pos[1])
                          , nt2::run(boost::proto::child_c<0>(a0),p,t)
                          , Zero<result_type>()
                          );
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::run_, tag::cpu_
                            , (A0)(State)(Data)(N)
                            , ((node_<A0, nt2::tag::offset_band1_, N, nt2::container::domain>))
                              (generic_< integer_<State> >)
                              (target_< unspecified_<Data> >)
                            )
  {
    typedef typename Data::type                                     result_type;
    typedef typename meta::as_index<result_type>::type                    i_t;
    typedef typename meta::
                     call<nt2::tag::enumerate_(State,meta::as_<i_t>)>::type p_t;
    typedef typename result_of::as_subscript<_2D,p_t>::type                 s_t;
    typedef typename s_t::value_type                                       sp_t;

    BOOST_FORCEINLINE result_type
    operator()(A0 const& a0, State const& p, Data const& t) const
    {
      // Retrieve 2D position from the linear index
      s_t  const pos = as_subscript(_2D(a0.extent()), nt2::enumerate<i_t>(p) );
      sp_t const is  = pos[0];
      sp_t const ju  = pos[1] + boost::proto::value(boost::proto::child_c<1>(a0));
      sp_t const jd  = pos[1] - boost::proto::value(boost::proto::child_c<1>(a0));

      // Return the band between +/-offset around the main diagonal
      return nt2::if_else ( nt2::logical_and( nt2::le(is,ju), nt2::ge(is,jd) )
                          , nt2::run(boost::proto::child_c<0>(a0),p,t)
                          , Zero<result_type>()
                          );
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::run_, tag::cpu_
                            , (A0)(State)(Data)(N)
                            , ((node_<A0, nt2::tag::offset_band2_, N, nt2::container::domain>))
                              (generic_< integer_<State> >)
                              (target_< unspecified_<Data> >)
                            )
  {
    typedef typename Data::type                                     result_type;
    typedef typename meta::as_index<result_type>::type              i_t;
    typedef typename meta::
                     call<nt2::tag::enumerate_(State,meta::as_<i_t>)>::type p_t;
    typedef typename result_of::as_subscript<_2D,p_t>::type                 s_t;
    typedef typename s_t::value_type                                       sp_t;

    BOOST_FORCEINLINE result_type
    operator()(A0 const& a0, State const& p, Data const& t) const
    {
      // Retrieve 2D position from the linear index
      s_t  const pos = as_subscript(_2D(a0.extent()),nt2::enumerate<i_t>(p) );
      sp_t const is  = pos[0];
      sp_t const ju  = pos[1] + boost::proto::value(boost::proto::child_c<2>(a0));
      sp_t const jd  = pos[1] - boost::proto::value(boost::proto::child_c<1>(a0));

      // Return the band between +/-offset around the main diagonal
      return nt2::if_else ( nt2::logical_and( nt2::le(is,ju), nt2::ge(is,jd) )
                          , nt2::run(boost::proto::child_c<0>(a0),p,t)
                          , Zero<result_type>()
                          );
    }
  };
} }

#endif
