//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_CONTAINER_DSL_ITERATOR_HPP_INCLUDED
#define NT2_CORE_CONTAINER_DSL_ITERATOR_HPP_INCLUDED

#include <nt2/core/functions/extent.hpp>
#include <boost/iterator/iterator_facade.hpp>

namespace nt2 { namespace details
{
  template<class Sz>
  std::size_t last_dim(Sz const& dims)
  {
    for(int i=Sz::static_size-1; i>=0; i--)
      if(dims[i] != 1)
        return i;

    return 0;
  }

  template<class Expr, int N>
  struct iterator_dereference;

#define M0(z,n,t)                                                                                  \
  template<class Expr>                                                                             \
  struct iterator_dereference<Expr, n>                                                             \
  {                                                                                                \
    typedef typename meta::                                                                        \
    call< tag::function_ ( Expr&                                                                   \
                         , BOOST_PP_ENUM_PARAMS( BOOST_PP_DEC(n)                                   \
                                               , nt2::colon_placeholder BOOST_PP_INTERCEPT         \
                                               )                                                   \
                           BOOST_PP_COMMA_IF( BOOST_PP_DEC(n) )                                    \
                           std::size_t                                                             \
                         )                                                                         \
        >::type                                                            type;                   \
                                                                                                   \
    static type call(Expr& expr, std::size_t i)                                                    \
    {                                                                                              \
      return expr( BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(n), nt2::_ BOOST_PP_INTERCEPT)                \
                   BOOST_PP_COMMA_IF( BOOST_PP_DEC(n) )                                            \
                   i                                                                               \
                 );                                                                                \
    }                                                                                              \
  }                                                                                                \
/**/
#undef M0

} }

namespace nt2 { namespace container
{
  template<class Expr>
  struct iterator
   : boost::iterator_facade< iterator<Expr>
                           , typename boost::remove_const<typename meta::scalar_of<Expr>::type>::type
                           , std::random_access_iterator_tag
                           , typename meta::scalar_of<Expr&>::type
                           >
  {
    iterator()
    {
    }

    iterator(Expr& _expr, std::size_t _i) : expr(&_expr), i(_i)
    {
    }

  private:
    friend class boost::iterator_core_access;

    void increment()
    {
      ++i;
    }

    void decrement()
    {
      --i;
    }

    void advance(std::ptrdiff_t n)
    {
      i += n;
    }

    std::ptrdiff_t distance_to(iterator const& other)
    {
      return other.i - i;
    }

    bool equal(iterator const& other) const
    {
      return i == other.i;
    }

    typename iterator::reference dereference() const
    {
      return (*expr)(i);
    }

    Expr* expr;
    std::size_t i;
  };

  template<class Expr>
  iterator<Expr> begin_(Expr& expr)
  {
    typename meta::call<tag::extent_(Expr&)>::type sz = nt2::extent(expr);
    std::size_t last_dim = details::last_dim(sz);
    typename Expr::index_type bs;
    return iterator<Expr>(expr, bs[last_dim]);
  }

  template<class Expr>
  iterator<Expr> end_(Expr& expr)
  {
    typename meta::call<tag::extent_(Expr&)>::type sz = nt2::extent(expr);
    std::size_t last_dim = details::last_dim(sz);
    typename Expr::index_type bs;
    return iterator<Expr>(expr, bs[last_dim]+sz[last_dim]);
  }

  template<class Expr> iterator<Expr>       begin(Expr&       expr) { return begin_(expr); }
  template<class Expr> iterator<Expr const> begin(Expr const& expr) { return begin_(expr); }
  template<class Expr> iterator<Expr>       end  (Expr&       expr) { return end_(expr);   }
  template<class Expr> iterator<Expr const> end  (Expr const& expr) { return end_(expr);   }
} }

#endif
