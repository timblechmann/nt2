//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_BENCH_MODULE "nt2 swar toolbox - comparator/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of swar components in scalar mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/swar/include/functions/comparator.hpp>
#include <nt2/sdk/bench/benchmark.hpp>
#include <nt2/sdk/bench/timing.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
// scalar runtime benchmark for functor<comparator_> from swar
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::comparator_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) ,T(V2))

namespace n1 {
  typedef float T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(comparator_,(RS(T,T(-100),T(100)))(RS(T,T(-100),T(100)))(RS(iT,iT(0),iT(1))))
}
namespace n2 {
  typedef double T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(comparator_,(RS(T,T(-100),T(100)))(RS(T,T(-100),T(100)))(RS(iT,iT(0),iT(1))))
}

#undef RS
