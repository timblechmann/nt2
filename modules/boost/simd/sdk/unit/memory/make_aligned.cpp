/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 0x01.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#define NT2_UNIT_MODULE "boost::simd::memory::make_aligned"

#include <boost/simd/sdk/config/types.hpp>
#include <boost/simd/sdk/memory/allocate.hpp>
#include <boost/simd/sdk/memory/deallocate.hpp>
#include <boost/simd/sdk/memory/is_aligned.hpp>
#include <boost/simd/sdk/memory/aligned_type.hpp>
#include <boost/simd/sdk/memory/meta/make_aligned.hpp>
#include <boost/simd/sdk/memory/make_aligned.hpp>

#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/basic.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>

////////////////////////////////////////////////////////////////////////////////
// Test make_aligned on simple type
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE(make_aligned)
{
  using boost::simd::is_aligned;

  BOOST_SIMD_ALIGNED_TYPE(double       ) ad;
  BOOST_SIMD_ALIGNED_TYPE(float        ) af;
  BOOST_SIMD_ALIGNED_TYPE(boost::simd::uint64_t) aui64;
  BOOST_SIMD_ALIGNED_TYPE(boost::simd::uint32_t) aui32;
  BOOST_SIMD_ALIGNED_TYPE(boost::simd::uint16_t) aui16;
  BOOST_SIMD_ALIGNED_TYPE(boost::simd::uint8_t ) aui8;
  BOOST_SIMD_ALIGNED_TYPE(boost::simd::int64_t ) ai64;
  BOOST_SIMD_ALIGNED_TYPE(boost::simd::int32_t ) ai32;
  BOOST_SIMD_ALIGNED_TYPE(boost::simd::int16_t ) ai16;
  BOOST_SIMD_ALIGNED_TYPE(boost::simd::int8_t  ) ai8;
  BOOST_SIMD_ALIGNED_TYPE(bool         ) ab;

  NT2_TEST( is_aligned(&ad) );
  NT2_TEST( is_aligned(&af) );
  NT2_TEST( is_aligned(&aui64) );
  NT2_TEST( is_aligned(&aui32) );
  NT2_TEST( is_aligned(&aui16) );
  NT2_TEST( is_aligned(&aui8) );
  NT2_TEST( is_aligned(&ai64) );
  NT2_TEST( is_aligned(&ai32) );
  NT2_TEST( is_aligned(&ai16) );
  NT2_TEST( is_aligned(&ai8) );
  NT2_TEST( is_aligned(&ab) );
}

////////////////////////////////////////////////////////////////////////////////
// Test make_aligned on array type
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE(make_aligned_array)
{
  using boost::simd::is_aligned;

  BOOST_SIMD_ALIGNED_TYPE(double       ) ad[3];
  BOOST_SIMD_ALIGNED_TYPE(float        ) af[3];
  BOOST_SIMD_ALIGNED_TYPE(boost::simd::uint64_t) aui64[3];
  BOOST_SIMD_ALIGNED_TYPE(boost::simd::uint32_t) aui32[3];
  BOOST_SIMD_ALIGNED_TYPE(boost::simd::uint16_t) aui16[3];
  BOOST_SIMD_ALIGNED_TYPE(boost::simd::uint8_t ) aui8[3];
  BOOST_SIMD_ALIGNED_TYPE(boost::simd::int64_t ) ai64[3];
  BOOST_SIMD_ALIGNED_TYPE(boost::simd::int32_t ) ai32[3];
  BOOST_SIMD_ALIGNED_TYPE(boost::simd::int16_t ) ai16[3];
  BOOST_SIMD_ALIGNED_TYPE(boost::simd::int8_t  ) ai8[3];
  BOOST_SIMD_ALIGNED_TYPE(bool         ) ab[3];

  NT2_TEST( is_aligned(&ad[0])    );
  NT2_TEST( is_aligned(&af[0])    );
  NT2_TEST( is_aligned(&aui64[0]) );
  NT2_TEST( is_aligned(&aui32[0]) );
  NT2_TEST( is_aligned(&aui16[0]) );
  NT2_TEST( is_aligned(&aui8[0])  );
  NT2_TEST( is_aligned(&ai64[0])  );
  NT2_TEST( is_aligned(&ai32[0])  );
  NT2_TEST( is_aligned(&ai16[0])  );
  NT2_TEST( is_aligned(&ai8[0])   );
  NT2_TEST( is_aligned(&ab[0])    );
}

////////////////////////////////////////////////////////////////////////////////
// Test make_aligned metafunction
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE_TPL(make_aligned_meta, BOOST_SIMD_TYPES)
{
  using boost::simd::is_aligned;
  using boost::simd::memory::allocate;
  using boost::simd::memory::deallocate;

  typename boost::simd::meta::make_aligned<T, 32>::type test__;
  NT2_TEST( is_aligned(&test__, 32) );
}

////////////////////////////////////////////////////////////////////////////////
// Test make_aligned metafunction
////////////////////////////////////////////////////////////////////////////////
NT2_TEST_CASE(make_aligned_ptr)
{
  using boost::simd::memory::byte;
  using boost::simd::memory::make_aligned;
  using boost::simd::is_aligned;
  using boost::simd::memory::allocate;
  using boost::simd::memory::deallocate;

  byte* ptr = allocate(15, 32);
  boost::simd::meta::make_aligned<byte, 32>::type* p = make_aligned<32>(ptr);
  NT2_TEST( is_aligned(p, 32) );
  NT2_TEST_EQUAL(p, ptr);

  deallocate(ptr);
}
