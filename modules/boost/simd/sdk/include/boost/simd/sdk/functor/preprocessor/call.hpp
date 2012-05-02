//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_SDK_FUNCTOR_PREPROCESSOR_CALL_HPP_INCLUDED
#define BOOST_SIMD_SDK_FUNCTOR_PREPROCESSOR_CALL_HPP_INCLUDED

#include <boost/dispatch/functor/preprocessor/call.hpp>
#include <boost/simd/sdk/functor/hierarchy.hpp>

#define BOOST_SIMD_FUNCTOR_CALL(N) BOOST_DISPATCH_CALL(N)
#define BOOST_SIMD_FUNCTOR_CALL_REPEAT(N) BOOST_DISPATCH_CALL_REPEAT(N)

#define BOOST_SIMD_FUNCTOR_IMPLEMENTATION(Tag, Site, Types, Seq)                                   \
BOOST_DISPATCH_REGISTER_TO_WITH( (boost)(simd)(ext), boost::simd::tag::Tag, Site                   \
                               , (boost)(dispatch)(meta)(BOOST_PP_CAT(dispatching_, Tag))          \
                               , Types, Seq                                                        \
                               , ( boost::simd::ext::                                              \
                                   BOOST_DISPATCH_IMPLEMENT_(boost::simd::tag::Tag, Site, Seq)     \
                                 )                                                                 \
                               )                                                                   \
BOOST_DISPATCH_IMPLEMENT_BODY(boost::simd::tag::Tag, Site, Types, Seq, BOOST_DISPATCH_TYPE)        \
/**/

#define BOOST_SIMD_FUNCTOR_IMPLEMENTATION_TPL(Tag, Site, Types, Seq)                               \
BOOST_DISPATCH_REGISTER_TPL_TO_WITH( (boost)(simd)(ext), boost::simd::tag::Tag, Site               \
                               , (boost)(dispatch)(meta)(BOOST_PP_CAT(dispatching_, Tag))          \
                               , Types, Seq                                                        \
                               , ( boost::simd::ext::                                              \
                                   BOOST_DISPATCH_IMPLEMENT_(boost::simd::tag::Tag, Site, Seq)     \
                                 )                                                                 \
                               )                                                                   \
BOOST_DISPATCH_IMPLEMENT_BODY(boost::simd::tag::Tag, Site, Types, Seq, BOOST_DISPATCH_TYPE_TPL)    \
/**/

#define BOOST_SIMD_FUNCTOR_IMPLEMENTATION_IF(Tag, Site, Types, Cond, Seq)                          \
BOOST_DISPATCH_REGISTER_TO_IF_WITH( (boost)(simd)(ext), boost::simd::tag::Tag, Site                \
                               , (boost)(dispatch)(meta)(BOOST_PP_CAT(dispatching_, Tag))          \
                               , Types, Cond, Seq                                                  \
                               , ( boost::simd::ext::                                              \
                                   BOOST_DISPATCH_IMPLEMENT_(boost::simd::tag::Tag, Site, Seq)     \
                                 )                                                                 \
                               )                                                                   \
BOOST_DISPATCH_IMPLEMENT_BODY(boost::simd::tag::Tag, Site, Types, Seq, BOOST_DISPATCH_TYPE)        \
/**/

#define BOOST_SIMD_FUNCTOR_IMPLEMENTATION_GEN(Tag,Site,Types,Seq)             \
BOOST_DISPATCH_IMPLEMENT((boost)(simd)(ext),Tag,Site,Types,Seq)

#define BOOST_SIMD_FUNCTOR_IMPLEMENTATION_IF_GEN(Tag,Site,Types,Cond,Seq)     \
BOOST_DISPATCH_IMPLEMENT_IF((boost)(simd)(ext),Tag,Site,Types,Cond,Seq)

#endif
