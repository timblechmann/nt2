/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define NT2_UNIT_MODULE "boost::dispatch::functor"

#include <boost/dispatch/functor/functor.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/basic.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>

namespace test
{
  template<class Sig, class Site>
  struct implement;

  using boost::dispatch::meta::unspecified_;
  using boost::dispatch::meta::scalar_;

  namespace tag
  {
    struct test1_ : unspecified_<test1_>
    {
      typedef unspecified_<test1_> parent;
    };

    struct test2_ : unspecified_<test2_>
    {
      typedef unspecified_<test2_> parent;
    };
  }
  
  BOOST_DISPATCH_IMPLEMENT((test), test::tag::test1_, boost::dispatch::tag::cpu_, (A0), (unspecified_<A0>))
  {
    typedef int result_type;
    result_type operator()(A0 const&) const
    {
      return 0;
    }
  };

  BOOST_DISPATCH_IMPLEMENT((test), test::tag::test2_, boost::dispatch::tag::cpu_, (A0), (unspecified_<A0>))
  {
    typedef int result_type;
    result_type operator()(A0 const& a0) const
    {
      return boost::dispatch::functor<tag::test1_>()(a0);
    }
  };

  BOOST_DISPATCH_IMPLEMENT((test), test::tag::test1_, boost::dispatch::tag::cpu_, (A0), (scalar_< unspecified_<A0> >))
  {
    typedef int result_type;
    result_type operator()(A0 const&) const
    {
      return 1;
    }
  };
}

NT2_TEST_CASE(global_test)
{
  NT2_TEST_EQUAL( boost::dispatch::functor<test::tag::test2_>()(0), 1 );
}

#define TEST_FUNCTION_DECLARE(Tag)                                             \
} }                                                                            \
namespace boost { namespace dispatch { namespace meta                          \
{                                                                              \
  BOOST_DISPATCH_WITH(test::tag::Tag, BOOST_PP_CAT(dispatching_, Tag))         \
} } }                                                                          \
namespace test { namespace tag {
/**/

#define TEST_FUNCTOR_IMPLEMENTATION(Tag, Site, Types, Seq)                                         \
BOOST_DISPATCH_REGISTER_TO_WITH( (test), test::tag::Tag, Site                                      \
                               , (boost)(dispatch)(meta)(BOOST_PP_CAT(dispatching_, Tag))          \
                               , Types, Seq                                                        \
                               , ( test::                                                          \
                                   BOOST_DISPATCH_IMPLEMENT_(test::tag::Tag, Site, Seq)            \
                                 )                                                                 \
                               )                                                                   \
BOOST_DISPATCH_IMPLEMENT_BODY(test::tag::Tag, Site, Types, Seq, BOOST_DISPATCH_TYPE)               \
/**/

namespace test
{
  namespace tag
  {
    struct test3_ : unspecified_<test3_>
    {
      typedef unspecified_<test3_> parent;
    };
    TEST_FUNCTION_DECLARE(test3_)

    struct test4_ : unspecified_<test4_>
    {
      typedef unspecified_<test4_> parent;
    };
    TEST_FUNCTION_DECLARE(test4_)
  }
  
  TEST_FUNCTOR_IMPLEMENTATION(test3_, boost::dispatch::tag::cpu_, (A0), (unspecified_<A0>))
  {
    typedef int result_type;
    result_type operator()(A0 const&) const
    {
      return 0;
    }
  };

  TEST_FUNCTOR_IMPLEMENTATION(test4_, boost::dispatch::tag::cpu_, (A0), (unspecified_<A0>))
  {
    typedef int result_type;
    result_type operator()(A0 const& a0) const
    {
      return boost::dispatch::functor<tag::test1_>()(a0);
    }
  };

  TEST_FUNCTOR_IMPLEMENTATION(test3_, boost::dispatch::tag::cpu_, (A0), (scalar_< unspecified_<A0> >))
  {
    typedef int result_type;
    result_type operator()(A0 const&) const
    {
      return 1;
    }
  };
}

NT2_TEST_CASE(local_test)
{
  NT2_TEST_EQUAL( boost::dispatch::functor<test::tag::test4_>()(0), 1 );
}
