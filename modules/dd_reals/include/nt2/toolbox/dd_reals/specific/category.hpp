/*******************************************************************************
 *         Copyright 2003-2011 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_TOOLBOX_DD_REALS_SPECIFIC_CATEGORY_HPP_INCLUDED
#define NT2_TOOLBOX_DD_REALS_SPECIFIC_CATEGORY_HPP_INCLUDED
////////////////////////////////////////////////////////////////////////////////
// Basic category registration
////////////////////////////////////////////////////////////////////////////////
#include <nt2/sdk/config/types.hpp>
#include <nt2/sdk/meta/hierarchy_of.hpp>

////////////////////////////////////////////////////////////////////////////////
// SIMD types tag
////////////////////////////////////////////////////////////////////////////////
namespace nt2
{
  namespace tag { template<class T> struct dd_reals_ {}; }

  //////////////////////////////////////////////////////////////////////////////
  // dd_reals types hierarchy
  //////////////////////////////////////////////////////////////////////////////
  namespace meta
  {
    template<class T> struct dd_reals_ : dd_reals_<typename T::parent>
    {
      typedef dd_reals_<typename T::parent>     parent;
      typedef tag::dd_reals_<typename T::type>  type;
    };

    template<class T> struct dd_reals_< unknown_<T> > : unknown_<T> {};
  }
}


#endif

// /////////////////////////////////////////////////////////////////////////////
// End of category.hpp
// /////////////////////////////////////////////////////////////////////////////
