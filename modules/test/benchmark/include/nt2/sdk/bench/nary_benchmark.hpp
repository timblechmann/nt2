#if !BOOST_PP_IS_ITERATING

//==============================================================================
//         Copyright 2003 - 2012 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2012        MetaScale SAS
//         Copyright 2012        Domagoj Saric, Little Endian Ltd.
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_BENCH_NARY_BENCHMARK_HPP_INCLUDED
#define NT2_SDK_BENCH_NARY_BENCHMARK_HPP_INCLUDED

#include <nt2/sdk/bench/benchmark.hpp>
#include <nt2/sdk/meta/type_id.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>
#include <boost/simd/memory/allocator.hpp>
#include <boost/simd/include/functions/load.hpp>
#include <boost/simd/include/functions/store.hpp>
#include <vector>

#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/iteration/iterate.hpp>

namespace nt2 { namespace unit
{
  template<typename Call> class nary_benchmark;
} }

#define BOOST_PP_FILENAME_1 "nt2/sdk/bench/nary_benchmark.hpp"
#define BOOST_PP_ITERATION_LIMITS (1, 5)
#include BOOST_PP_ITERATE()

#endif

#else

#define N BOOST_PP_ITERATION()

#define M0(z,n,t)                                                   \
typedef typename boost::dispatch                                    \
                      ::meta::scalar_of<BOOST_PP_CAT(T,n)>::type    \
                                              BOOST_PP_CAT(type,n); \
/**/

#define M1(z,n,t)                                                     \
typedef boost::simd::memory                                           \
             ::allocator<BOOST_PP_CAT(type,n)> BOOST_PP_CAT(alloc,n); \
/**/

#define M2(z,n,t)                         \
  BOOST_PP_CAT(type,n) BOOST_PP_CAT(mn,n) \
, BOOST_PP_CAT(type,n) BOOST_PP_CAT(mx,n) \

#define M3(z,n,t)                           \
  BOOST_PP_CAT(rmin,n)(BOOST_PP_CAT(mn,n))  \
, BOOST_PP_CAT(rmax,n)(BOOST_PP_CAT(mx,n))  \
/**/

#define M4(z,n,t)                                               \
boost::simd::load<BOOST_PP_CAT(T,n)>(&BOOST_PP_CAT(in,n)[0],i)  \
/**/

#define M5(z,n,t)                                               \
mutable std::vector<BOOST_PP_CAT(type,n),BOOST_PP_CAT(alloc,n)> \
                                            BOOST_PP_CAT(in,n); \
/**/

#define M6(z,n,t)                                                 \
BOOST_PP_CAT(type,n) BOOST_PP_CAT(rmin,n), BOOST_PP_CAT(rmax,n);  \
/**/

#define M7(z,n,t)                                                         \
BOOST_PP_CAT(in,n).resize(size);                                          \
nt2::roll(BOOST_PP_CAT(in,n),BOOST_PP_CAT(rmin,n), BOOST_PP_CAT(rmax,n)); \
/**/

#define M8(z,n,t)                           \
os << "("; print(BOOST_PP_CAT(rmin,n),os);  \
os << ","; print(BOOST_PP_CAT(rmax,n),os);  \
os << ") ";                                 \
/**/

namespace nt2 { namespace unit
{
  template< typename Function
          , BOOST_PP_ENUM_PARAMS(N,class T)
          >
  NT2_EXPERIMENT(nary_benchmark<Function(BOOST_PP_ENUM_PARAMS(N,T))>)
  {
    public:

    BOOST_PP_REPEAT(N, M0, ~)
    BOOST_PP_REPEAT(N, M1, ~)

    typedef typename boost::dispatch::meta
            ::result_of<Function(BOOST_PP_ENUM_PARAMS(N,T))>::type      v_t;

    typedef typename boost::dispatch::meta
            ::result_of<Function(BOOST_PP_ENUM_PARAMS(N,type))>::type   out_t;

    typedef typename Function::tag_type     tag_type;
    typedef typename Function::context_type context_type;

    nary_benchmark( BOOST_PP_ENUM(N,M2,~) )
        : details::base_experiment
          ( 3. , type_id<tag_type(BOOST_PP_ENUM_PARAMS(N,T),context_type)>()
          ,"cycles/value", &nt2::details::main_bench_suite
          )
        , size(1024), BOOST_PP_ENUM(N,M3,~)
    {
      out.resize(size);
      BOOST_PP_REPEAT(N, M7, ~)
    }

    virtual void run() const
    {
      static const std::size_t s = boost::simd::meta::cardinal_of<v_t>::value;
      for ( std::size_t i=0; i < size; i += s)
      {
        boost::simd::store( func(BOOST_PP_ENUM(N,M4,~))
                          , &out[0], i
                          );
      }
    }

    virtual void info(std::ostream& os) const { BOOST_PP_REPEAT(N, M8, ~) }

    virtual double compute(nt2::benchmark_result_t const& r) const
    {
      return r.first/double(size);
    }

    private:
    template<class X> void print(X const& x, std::ostream& os) const
    {
      os << (sizeof(X)==1 ? int(x) : x);
    }

    std::size_t                                                         size;
    Function                                                            func;
    mutable std::vector<out_t, boost::simd::memory::allocator<out_t> >  out;
    BOOST_PP_REPEAT(N, M5, ~)
    BOOST_PP_REPEAT(N, M6, ~)
  };
} }

#undef M8
#undef M7
#undef M6
#undef M5
#undef M4
#undef M3
#undef M2
#undef M1
#undef M0
#undef N

#endif
