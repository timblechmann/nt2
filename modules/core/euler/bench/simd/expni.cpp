//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_BENCH_MODULE "nt2 euler toolbox - expni/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of euler components in simd mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/euler/include/functions/expni.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <nt2/sdk/bench/benchmark.hpp>
#include <nt2/sdk/bench/timing.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <cmath>
typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;

//////////////////////////////////////////////////////////////////////////////
// simd runtime benchmark for functor<expni_> from euler
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::expni_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, (V1) ,(V2))

namespace n1 {
  typedef float T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<iT,ext_t> viT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(expni_,(RS(iT,iT(0),iT(10)))(RS(vT,T(0),T(10))))
}
namespace n2 {
  typedef double T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<iT,ext_t> viT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(expni_,(RS(iT,iT(0),iT(10)))(RS(vT,T(0),T(10))))
}

#undef RS
