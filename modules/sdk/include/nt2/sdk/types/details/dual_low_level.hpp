/*******************************************************************************
 *         Copyright 2003-2011 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_TYPES_DETAILS_DUAL_LOW_LEVEL_HPP_INCLUDED
#define NT2_SDK_TYPES_DETAILS_DUAL_LOW_LEVEL_HPP_INCLUDED
#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/ldexp.hpp>


namespace nt2
{  // /////////////////////////////////////////////////////////////////////////////
  //   This file contains the basic functions used by dual arithmetic
  // /////////////////////////////////////////////////////////////////////////////
  
  
  namespace details
  {
    
  
    // Computes fl(a+b) and err(a+b).  Assumes |a| >= |b|. 
    template<class T> static inline T quick_two_sum(const T & a,
                                                    const T & b,
                                                    T &err)
    {
      volatile T s = a + b;
      err = b - (s - a);
      return s;
    }
    
    // Computes fl(a-b) and err(a-b).  Assumes |a| >= |b| 
    template<class T> static inline T quick_two_diff(const T & a,
                                                     const T & b,
                                                     T &err) {
      volatile T s = a - b;
      err = (a - s) - b;
      return s;
    }
    
    // Computes fl(a+b) and err(a+b).  
    template<class T> static inline T two_sum(const T & a,
                                              const T & b,
                                              T &err) {
      volatile T s = a + b;
      const T bb = s - a;
      err = (a - (s - bb)) + (b - bb);
      return s;
    }
    
    // Computes fl(a-b) and err(a-b).  
    template<class T> static inline T two_diff(const T & a,
                                               const T & b,
                                               T &err)
    {
      volatile T s = a - b;
      const T bb = s - a;
      err = (a - (s - bb)) - (b + bb);
      return s;
    }
    
    template<class T> static inline void split(T a, T &hi, T &lo); 
    
    // Computes high word and lo word of a 
    template<>  inline void split(double a, double &hi, double &lo)
    {
      static const double  splitter = 134217729.0;               // = 2^27 + 1
      static const double  thresh   = 6.69692879491417e+299;     // = 2^(1023-27)
      
      double temp;
      if (nt2::abs(a) > thresh)
        {
          a = nt2::ldexp(a, -28); //*= 3.7252902984619140625e-09;  // 2^-28
          temp = splitter * a;
          hi = temp - (temp - a);
          lo = a - hi;
          //          hi *= 268435456.0;          // 2^28
          //          lo *= 268435456.0;          // 2^28
          hi =  nt2::ldexp(hi, 28);
          lo =  nt2::ldexp(lo, 28);
        }
      else
        {
          temp = splitter * a;
          hi = temp - (temp - a);
          lo = a - hi;
        }
    }
    
    template<>  inline void split(float a, float &hi, float &lo)
    {
      
      static const float  splitter = 8193.0f;          // = 2^13 + 1
      static const float  thresh   = 2.076918743413931e+34f;   // = 2^(127-13)

      float temp;
      if (nt2::abs(a) > thresh )
        {
          //          a *= 6.1035156250e-05;  // 2^-14
          a = nt2::ldexp(a,-14); 
          temp = splitter * a;
          hi = temp - (temp - a);
          lo = a - hi;
          //          hi *= 16384.0f;          // 2^14
          //          lo *= 16384.0f;          // 2^14
          hi =  nt2::ldexp(hi, 14);
          lo =  nt2::ldexp(lo, 14);
        }
      else
        {
          temp = splitter * a;
          hi = temp - (temp - a);
          lo = a - hi;
        }      
    }
    
    // Computes fl(a*b) and err(a*b). 
    template<class T> static inline T two_prod(const T & a, const T & b, T &err)
    {
      T a_hi, a_lo; 
      split(a, a_hi, a_lo);
      T b_hi, b_lo;
      split(b, b_hi, b_lo);
      const T p = a * b;
      err = ((a_hi * b_hi - p) + a_hi * b_lo + a_lo * b_hi) + a_lo * b_lo;
      return p;
    }
    
    // Computes fl(a*a) and err(a*a).  Faster than the above method. 
    template<class T> static inline T two_sqr(const T & a, T &err)
    {
      T hi, lo;
      split(a, hi, lo);
      const T q = a * a;
      err = ((hi * hi - q) + 2.0 * hi * lo) + lo * lo;
      return q;
    }
    
//     // Computes the nearest integer to d. 
//     template<class T> static inline T nint(const T & d) {return sRound(d); }
    
//     // Computes the truncated integer. 
//     template<class T> static inline T aint(const T & d) {return sFix(d); }
    
//     // These are provided to give consistent 
//     // interface for T with T-T and quad-T. 
//     template<class T> static inline void sincosh(const T & t, T &sinh_t, T &cosh_t)
//     {
//       sinh_t = sSinh(t);
//       cosh_t = sCosh(t);
//     }

    
  }
}

#endif

// /////////////////////////////////////////////////////////////////////////////
// End of dual_low_level.hpp
// /////////////////////////////////////////////////////////////////////////////

