//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 dual toolbox - load/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of dual components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 05/03/2011
/// modified by jt the 10/05/2011
#include <nt2/sdk/memory/is_aligned.hpp>
#include <nt2/sdk/memory/aligned_type.hpp>
//#include <nt2/sdk/memory/load.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
// #include <nt2/sdk/constant/real.hpp>
// #include <nt2/sdk/constant/infinites.hpp>
#include <nt2/include/functions/max.hpp>
#include <nt2/include/functions/load.hpp>
#include <nt2/toolbox/dual/include/load.hpp>


NT2_TEST_CASE_TPL(load, (nt2::dual<float>)(nt2::dual<double>))
{
  using nt2::load;
  using nt2::simd::native;
  using nt2::meta::cardinal_of;

  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef native<T,ext_t>             n_t;

  NT2_ALIGNED_TYPE(T) data[3*cardinal_of<n_t>::value];
  for(std::size_t i=0;i<3*cardinal_of<n_t>::value;++i)
    data[i] = 1+i;

  for(std::size_t i=0;i<3;++i)
  {
    n_t v = load<n_t>(&data[0],i);
    for(std::size_t j=0;j<cardinal_of<n_t>::value;++j)
    {
      NT2_TEST_EQUAL( v[j], 1+i*cardinal_of<n_t>::value+j );
    }
  }
}
