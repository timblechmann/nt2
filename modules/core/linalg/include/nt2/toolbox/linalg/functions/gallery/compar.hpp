/*******************************************************************************
 *         Copyright 2003-2012 LASME UMR 6602 CNRS/U.B.P
 *         Copyright 2011-2012 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_TOOLBOX_LINALG_FUNCTIONS_GALLERY_COMPAR_HPP_INCLUDED
#define NT2_TOOLBOX_LINALG_FUNCTIONS_GALLERY_COMPAR_HPP_INCLUDED
#include <nt2/include/functions/colon.hpp>
#include <nt2/include/functions/height.hpp>
#include <nt2/include/functions/width.hpp>
#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/from_diag.hpp>
#include <nt2/include/functions/diag_of.hpp>
#include <nt2/include/functions/maximum.hpp>
#include <nt2/include/functions/istril.hpp>
#include <nt2/include/functions/istriu.hpp>
#include <nt2/include/functions/tril.hpp>
#include <nt2/include/functions/triu.hpp>
#include <nt2/include/functions/expand.hpp>
#include <nt2/include/functions/oneplus.hpp>
#include <nt2/include/functions/ones.hpp>
#include <nt2/core/container/table/table.hpp>

namespace nt2{ namespace ext
{

  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::compar_, tag::cpu_,
                              (A0),
                              ((ast_<A0, nt2::container::domain >))
                            )
  {
    typedef typename  boost::proto::result_of::make_expr< nt2::tag::compar_
      , container::domain
      , A0 const &, size_t, box<_2D>
      >::type                        result_type;
    BOOST_FORCEINLINE result_type operator()(A0 const& a0) const
    {
      _2D sizee; sizee[0] = nt2::height(a0); sizee[1] = nt2::width(a0);
      return  boost::proto::make_expr<nt2::tag::compar_, nt2::container::domain>
        ( boost::cref(a0), size_t(0), boxify(sizee));
    }
  };
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::compar_, tag::cpu_,
                              (A0)(A1),
                              ((ast_<A0, nt2::container::domain >))
                              (scalar_<integer_<A1> > )
                            )
  {
    typedef typename  boost::proto::result_of::make_expr< nt2::tag::compar_
      , container::domain
      , A0 const &, size_t, box<_2D>
      >::type                        result_type;
    BOOST_FORCEINLINE result_type operator()(A0 const& a0, A1 const& a1) const
    {
      _2D sizee; sizee[0] = nt2::height(a0); sizee[1] = nt2::width(a0);
      return  boost::proto::make_expr<nt2::tag::compar_, nt2::container::domain>
        ( boost::cref(a0), size_t(a1), boxify(sizee));
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::run_assign_, tag::cpu_
                              , (A0)(A1)(N)
                              , ((ast_<A0, nt2::container::domain>))
                              ((node_<A1,nt2::tag::compar_,N,nt2::container::domain>))
    )
  {
    typedef A0&                                                     result_type;
    result_type operator()(A0& out, const A1& in) const
    {
      typedef typename A0::value_type value_type;
      size_t k = boost::proto::child_c<1>(in);
      out.resize(extent(in));
      BOOST_AUTO_TPL(idx, nt2::_(size_t(1), nt2::oneplus(height(out)), nt2::numel(out)));
      BOOST_AUTO_TPL(absa,nt2::abs(boost::proto::child_c<0>(in)));
      if (k == 0)
      {
        out = -absa;
        out(idx) = nt2::diag_of(absa);
      }
      else
      {
        BOOST_AUTO_TPL(mx, nt2::maximum(absa - nt2::expand(nt2::from_diag(nt2::diag_of(absa)), extent(in)),2));
        out = -mx(nt2::_,nt2::ones(size_t(1),width(absa), nt2::meta::as_<value_type>()));
        out(idx) = nt2::diag_of(absa);
        if (istril(absa)) out = tril(out);
        if (istriu(absa)) out = triu(out);
      }
      return out;
    }
  };
} }


#endif
