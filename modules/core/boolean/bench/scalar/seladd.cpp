//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_BENCH_MODULE "nt2 bitwise toolbox - seladd/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// timing Test behavior of bitwise components in scalar mode
//////////////////////////////////////////////////////////////////////////////
#include <nt2/toolbox/bitwise/include/functions/seladd.hpp>
#include <nt2/sdk/bench/benchmark.hpp>
#include <nt2/sdk/bench/timing.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <cmath>


//////////////////////////////////////////////////////////////////////////////
// scalar runtime benchmark for functor<seladd_> from bitwise
//////////////////////////////////////////////////////////////////////////////
using nt2::tag::seladd_;

//////////////////////////////////////////////////////////////////////////////
// range macro
//////////////////////////////////////////////////////////////////////////////
#define RS(T,V1,V2) (T, T(V1) ,T(V2))

namespace n1 {
  typedef float T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(seladd_,(RS(T,T(0),T(0)))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
  NT2_TIMING(seladd_,(RS(T,nt2::Nan<T>(),nt2::Nan<T>()))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
}
namespace n2 {
  typedef double T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(seladd_,(RS(T,T(0),T(0)))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
  NT2_TIMING(seladd_,(RS(T,nt2::Nan<T>(),nt2::Nan<T>()))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
}
namespace n3 {
  typedef nt2::int8_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(seladd_,(RS(T,T(0),T(0)))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
  NT2_TIMING(seladd_,(RS(T,T(-1),T(-1)))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
}
namespace n4 {
  typedef nt2::int16_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(seladd_,(RS(T,T(0),T(0)))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
  NT2_TIMING(seladd_,(RS(T,T(-1),T(-1)))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
}
namespace n5 {
  typedef nt2::int32_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(seladd_,(RS(T,T(0),T(0)))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
  NT2_TIMING(seladd_,(RS(T,T(-1),T(-1)))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
}
namespace n6 {
  typedef nt2::int64_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(seladd_,(RS(T,T(0),T(0)))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
  NT2_TIMING(seladd_,(RS(T,T(-1),T(-1)))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
}
namespace n7 {
  typedef nt2::uint8_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(seladd_,(RS(T,T(0),T(0)))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
  NT2_TIMING(seladd_,(RS(T,T(-1),T(-1)))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
}
namespace n8 {
  typedef nt2::uint16_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(seladd_,(RS(T,T(0),T(0)))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
  NT2_TIMING(seladd_,(RS(T,T(-1),T(-1)))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
}
namespace n9 {
  typedef nt2::uint32_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(seladd_,(RS(T,T(0),T(0)))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
  NT2_TIMING(seladd_,(RS(T,T(-1),T(-1)))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
}
namespace n10 {
  typedef nt2::uint64_t T;
  typedef boost::dispatch::meta::as_integer<T>::type iT;
  NT2_TIMING(seladd_,(RS(T,T(0),T(0)))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
  NT2_TIMING(seladd_,(RS(T,T(-1),T(-1)))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2))(RS(T,nt2::Valmin<T>()/2,nt2::Valmax<T>()/2)))
}

#undef RS
