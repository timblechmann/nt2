//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2013   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TOOLBOX_LINALG_FUNCTIONS_LAPACK_PLINSOLVE_HPP_INCLUDED
#define NT2_TOOLBOX_LINALG_FUNCTIONS_LAPACK_PLINSOLVE_HPP_INCLUDED

#include <nt2/linalg/functions/plinsolve.hpp>
#include <nt2/include/functions/svx.hpp>
#include <nt2/include/functions/ysvx.hpp>
#include <nt2/include/functions/posvx.hpp>
#include <nt2/include/functions/of_size.hpp>
#include <nt2/include/functions/resize.hpp>
#include <nt2/linalg/options.hpp>
#include <nt2/sdk/meta/concrete.hpp>
#include <nt2/linalg/functions/details/eval_linsolve.hpp>
#include <nt2/sdk/meta/settings_of.hpp>
#include <nt2/sdk/meta/as_real.hpp>

#include <nt2/core/container/table/table.hpp>

#include <boost/dispatch/meta/ignore_unused.hpp>

namespace nt2 { namespace ext
{
  //============================================================================
  // LINSOLVE
  //============================================================================
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::plinsolve_, tag::cpu_
                            , (A0)(A1)(A2)
                            , ((ast_<A0, nt2::container::domain>))  // A
                              ((ast_<A1, nt2::container::domain>))  // B
                              ((ast_<A2, nt2::container::domain>))  // X
                            )
  {
    typedef void  result_type;
    typedef typename A0::value_type ctype_t;
    typedef typename nt2::meta::as_real<ctype_t>::type   type_t;
    typedef typename meta::option<typename A0::settings_type,nt2::tag::shape_>::type shape;
    typedef nt2::container::table<ctype_t>  entry_type;
    typedef nt2::container::table<ctype_t,shape>  matrix_type;

    BOOST_FORCEINLINE result_type operator()( A0 const& a0, A1 const& a1, A2&  a2 ) const
    {
      shape_analysis(a0,a1,a2,shape());
    }

    //==========================================================================
    /// INTERNAL ONLY - Shape analysis

    BOOST_FORCEINLINE
    void shape_analysis ( A0 const& a0, A1 const& a1 , A2& a2
                        , nt2::rectangular_ const&
                        ) const
    {
      eval(a0, a1, a2);
    }

    /// INTERNAL ONLY - Positive definite shape
    BOOST_FORCEINLINE
    void shape_analysis ( A0 const& a0, A1 const& a1 , A2& a2
                        , nt2::positive_definite_ const&
                        ) const
    {
      type_t rcond;
      a2.resize(nt2::of_size(a0.leading_size(),1));
      nt2_la_int iter = nt2::posvx( boost::proto::value(a0), boost::proto::value(a1)
                                  , boost::proto::value(a2), rcond);
      boost::dispatch::ignore_unused(iter);
    }
    /// INTERNAL ONLY - Symmetric shape
    BOOST_FORCEINLINE
    void shape_analysis ( A0 const& a0, A1 const& a1 , A2& a2
                        , nt2::symmetric_ const&
                        ) const
    {
      type_t rcond;
      nt2::container::table<nt2_la_int> piv(nt2::of_size(a0.leading_size(),1));
      a2.resize(nt2::of_size(a0.leading_size(),1));
      nt2_la_int iter = nt2::ysvx( boost::proto::value(a0),boost::proto::value(piv)
                                 , boost::proto::value(a1),boost::proto::value(a2)
                                 , rcond);
      boost::dispatch::ignore_unused(iter);
    }

    /// INTERNAL ONLY - No info on this shape
    template<typename sh>
    BOOST_FORCEINLINE
    void shape_analysis ( A0 const& a0, A1 const& a1, A2& a2, sh const&) const
    {
      eval(a0,a1,a2);
    }

    //==========================================================================
    /// INTERNAL ONLY - Solve with no shape info - Todo : Analyse shape
    BOOST_FORCEINLINE
    void eval ( A0 const& a0, A1 const& a1 , A2& a2) const
    {
      type_t rcond;
      a2.resize(nt2::of_size(a0.leading_size(),1));
      nt2::svx( boost::proto::value(concrete(a0)), boost::proto::value(concrete(a1))
              , boost::proto::value(a2), rcond );
    }

  };


} }


#endif
