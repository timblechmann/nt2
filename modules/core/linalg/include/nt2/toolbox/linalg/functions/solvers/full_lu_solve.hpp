//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TOOLBOX_LINALG_FUNCTIONS_SOLVERS_FULL_LU_SOLVE_HPP_INCLUDED
#define NT2_TOOLBOX_LINALG_FUNCTIONS_SOLVERS_FULL_LU_SOLVE_HPP_INCLUDED

#include <nt2/toolbox/linalg/functions/full_lu_solve.hpp>
#include <nt2/options.hpp>
#include <nt2/core/container/table/table.hpp>
#include <nt2/include/functions/issquare.hpp>
#include <nt2/include/functions/ofsameheight.hpp>
#include <nt2/toolbox/linalg/functions/details/full_lu_solve.hpp>

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::solvers::full_lu_solve_, tag::cpu_
                            , (A0)(A1)(A2)
                            , ((ast_<A0, nt2::container::domain>))
                              ((ast_<A1, nt2::container::domain>))
                              (scalar_<type8_< A2> >)
                            )
  {
    typedef typename meta::strip<A0>::type                              base_t;
    typedef typename base_t::value_type                                value_t;
    typedef typename base_t::settings_type                          settings_t;
    typedef details::full_lu_solve_result< container::table<value_t,settings_t> > result_type;

    BOOST_FORCEINLINE result_type operator()(A0 const& a,
                                             A1 const& b,
                                             char const & trans) const
    {
      BOOST_ASSERT_MSG( nt2::issquare(a)
                      , "??? Error using 'full_lu_solve' : Matrix must be square."
                      );
      BOOST_ASSERT_MSG(ofsameheight(a, b),
                       "a and b have different heights");
      result_type that(a, b, trans);
      return that;
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::solvers::full_lu_solve_, tag::cpu_
                              , (A0)(A1)(A2)(IP)
                              , ((ast_<A0, nt2::container::domain>))
                                ((ast_<A1, nt2::container::domain>))
                                (scalar_<type8_< A2> >)
                                (unspecified_< IP >)
                              )
  {
    typedef details::full_lu_solve_result<A0&, A1&> result_type;

    BOOST_FORCEINLINE result_type
      operator()(A0& a, A1& b, A2 const& trans, IP const&) const
    {
      BOOST_ASSERT_MSG( nt2::issquare(a)
                        , "??? Error using 'full_lu_solve' : Matrix must be square."
                        );
      BOOST_ASSERT_MSG(ofsameheight(a, b),
                       "a and b have different heights");
      result_type that(a, b, trans);
      return that;
    }
  };
} }

#endif
