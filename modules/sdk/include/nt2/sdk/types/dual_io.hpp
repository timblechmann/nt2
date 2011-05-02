/*******************************************************************************
 *         Copyright 2003-2011 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_TYPES_DUAL_IO_HPP_INCLUDED
#define NT2_SDK_TYPES_DUAL_IO_HPP_INCLUDED



namespace nt2
{
  /* Outputs the double-double number dd. */
  template < class T, class A> static inline
  std::ostream &operator<<(std::ostream &os, const dual<T,A>&dd) {
    bool showpos = (os.flags() & std::ios_base::showpos) != 0;
    bool uppercase =  (os.flags() & std::ios_base::uppercase) != 0;
    // os << std::setprecision(os.precision()) << "(" << dd.hi() << ", " << dd.lo() << ")" << std::endl; ; 
    return os << dd.to_string(os.precision(), os.width(), os.flags(), 
                              showpos, uppercase, os.fill());
  }
  
  /* Reads in the double-double number a. */
  template < class T, class A> static inline
  std::istream &operator>>(std::istream &s, dual<T, A> &a) {
    char str[255];
    s >> str;
    a = dual<T, A>(str);
    return s;
  }
}


#endif

// /////////////////////////////////////////////////////////////////////////////
// End of dual_io.hpp
// /////////////////////////////////////////////////////////////////////////////
