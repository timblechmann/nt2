//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_BENCH_MODULE "nt2 boost.simd.operator toolbox - comma/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of boost.simd.operator components in simd mode
//////////////////////////////////////////////////////////////////////////////
#include <boost/simd/toolbox/operator/include/functions/comma.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <nt2/sdk/bench/benchmark.hpp>
#include <nt2/sdk/bench/timing.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <cmath>
typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;

//////////////////////////////////////////////////////////////////////////////
// simd runtime benchmark for functor<comma_> from boost.simd.operator
//////////////////////////////////////////////////////////////////////////////
using boost::simd::tag::comma_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, (V1) ,(V2))

namespace n1 {
  typedef float T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(comma_,(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2))(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2)))
}
namespace n2 {
  typedef double T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(comma_,(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2))(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2)))
}
namespace n3 {
  typedef boost::simd::int8_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(comma_,(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2))(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2)))
}
namespace n4 {
  typedef boost::simd::int16_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(comma_,(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2))(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2)))
}
namespace n5 {
  typedef boost::simd::int32_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(comma_,(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2))(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2)))
}
namespace n6 {
  typedef boost::simd::int64_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(comma_,(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2))(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2)))
}
namespace n7 {
  typedef boost::simd::uint8_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(comma_,(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2))(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2)))
}
namespace n8 {
  typedef boost::simd::uint16_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(comma_,(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2))(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2)))
}
namespace n9 {
  typedef boost::simd::uint32_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(comma_,(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2))(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2)))
}
namespace n10 {
  typedef boost::simd::uint64_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  typedef boost::simd::native<T,ext_t> vT;
  NT2_TIMING(comma_,(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2))(RS(vT,boost::simd::Valmin<T>()/2,boost::simd::Valmax<T>()/2)))
}

#undef RS
