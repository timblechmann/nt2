//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_BENCH_MODULE "nt2 dual toolbox - load/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of dual components in scalar mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/dual/include/load.hpp>
#include <nt2/sdk/unit/benchmark.hpp>
#include <nt2/sdk/unit/bench_includes.hpp>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
// scalar runtime benchmark for functor<load_> from dual
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::load_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) ,T(V2))

namespace n1 {
  typedef nt2::dual<float> T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(load_,(RS(T,T(-10),T(10))))
}
namespace n2 {
  typedef nt2::dual<double> T;
  typedef nt2::meta::as_integer<T>::type iT;
  NT2_TIMING(load_,(RS(T,T(-10),T(10))))
}

#undef RS
