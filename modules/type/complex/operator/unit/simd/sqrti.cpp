//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 complex.arithmetic toolbox - sqrti/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.arithmetic components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 28/11/2010
///
#include <nt2/include/functions/bitwise_cast.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/simd/sdk/simd/io.hpp>
#include <nt2/include/functions/extract.hpp>
#include <nt2/include/functions/imag.hpp>
#include <nt2/include/functions/real.hpp>
#include <nt2/include/constants/sqrti.hpp>
#include <nt2/include/functions/splat.hpp>
#include <nt2/include/functions/real.hpp>
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/as_floating.hpp>
#include <nt2/sdk/meta/as_signed.hpp>
#include <nt2/sdk/meta/upgrade.hpp>
#include <nt2/sdk/meta/downgrade.hpp>
#include <nt2/sdk/meta/scalar_of.hpp>
#include <boost/dispatch/meta/as_floating.hpp>
#include <boost/type_traits/common_type.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>

#include <nt2/toolbox/constant/constant.hpp>
#include <nt2/sdk/meta/cardinal_of.hpp>
#include <nt2/include/functions/splat.hpp>

#include <nt2/sdk/complex/complex.hpp>
#include <nt2/sdk/complex/dry.hpp>
#include <nt2/sdk/complex/imaginary.hpp>
#include <nt2/sdk/complex/meta/as_complex.hpp>
#include <nt2/sdk/complex/meta/as_imaginary.hpp>
#include <nt2/sdk/complex/meta/as_dry.hpp>
#include <nt2/include/constants/sqrt_2o_2.hpp>

NT2_TEST_CASE_TPL ( abs_cplx__1_0,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::native;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef std::complex<T>                              cT;
  typedef native<T ,ext_t>                             vT;
  typedef native<cT ,ext_t>                           vcT;
  typedef typename nt2::meta::as_imaginary<T>::type   ciT;
  typedef native<ciT ,ext_t>                         vciT;
  typedef typename nt2::meta::as_dry<T>::type          dT;
  typedef native<dT ,ext_t>                           vdT;

  // specific values tests
  {
    std::cout << nt2::Sqrti<vcT >() << std::endl;
    NT2_TEST_EQUAL(nt2::Sqrti<vcT>(),  vcT(nt2::Sqrt_2o_2<vT>(),nt2::Sqrt_2o_2<vT>()));

  }

} // end of test for floating_
