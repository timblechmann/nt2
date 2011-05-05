/*******************************************************************************
 *         Copyright 2003-2011 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_TOOLBOX_DUAL_SPECIFIC_META_HPP_INCLUDED
#define NT2_TOOLBOX_DUAL_SPECIFIC_META_HPP_INCLUDED
#include <nt2/sdk/meta/factory_of.hpp>
#include <nt2/sdk/meta/primitive_of.hpp>


namespace nt2 {namespace meta
{
  template<class Type>
  struct factory_of< dual<Type> >
  {
    typedef dual<boost::mpl::_> type;
  };
  template<class Type>
  struct primitive_of< dual<Type> >
  {
    typedef Type type;
  };  

} }


#endif

// /////////////////////////////////////////////////////////////////////////////
// End of meta.hpp
// /////////////////////////////////////////////////////////////////////////////
