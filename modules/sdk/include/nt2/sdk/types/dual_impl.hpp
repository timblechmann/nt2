/*******************************************************************************
 *         Copyright 2003-2011 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_TYPES_DUAL_IMPL_HPP_INCLUDED
#define NT2_SDK_TYPES_DUAL_IMPL_HPP_INCLUDED



namespace nt2
{
  
     template <class A, class I>  void digits(const dual<double, A, I> &dd,
                                    char *s,
                                    int &expn,
                                    int precision)
      
    {
      typedef dual < double, A, I> self;
      typedef double           type; 
      int D = precision + 1;  /* number of digits to compute */
      
      self r = (dd.hi() > 0) ? dd : -dd;
      int e;  /* exponent */
      int i, d;
      
      if (dd.hi() == 0.0) {
        /* this == 0.0 */
        expn = 0;
        for (i = 0; i < precision; i++) s[i] = '0';
        return;
      }
      
      /* First determine the (approximate) exponent. */
      e = static_cast < int > (nt2::floor(nt2::log10(nt2::abs(dd.hi()))));
      static const self ten(type(10)); 
      if (e < -300) {
        r *= npwr(ten, 300);
        r /= npwr(ten, (e + 300));
      } else if (e > 300) {
        r = self::ldexp(r, -53);
        r /= npwr(ten, e);
        r = self::ldexp(r, 53);
      } else {
        r /= npwr(ten, e);
      }
      
      /* Fix exponent if we are off by one */
      if (r >= ten) {
        r /= type(10);
        e++;
      } else if (r < r.one()) {
        r *= type(10);
        e--;
      }
      
      if (r >= ten || r <r.one()) {
        error("(self::to_digits): can't compute exponent.");
        return;
      }
      
      /* Extract the digits */
      for (i = 0; i < D; i++) {
        d = static_cast<int>(r.hi());
        r -= d;
        r *= ten;
        
        s[i] = static_cast<char>(d + '0');
      }
      
      /* Fix negative digits. */
      for (i = D-1; i > 0; i--) {
        if (s[i] < '0') {
          s[i-1]--;
          s[i] += 10;
        }
      }
      
      if (s[0] <= '0') {
        error("(self::to_digits): non-positive leading digit.");
        return;
      }
      
      /* Round, handle carry */
      if (s[D-1] >= '5') {
        s[D-2]++;
        
        i = D-2;
        while (i > 0 && s[i] > '9') {
          s[i] -= 10;
          s[--i]++;
        }
      }
      
      /* If first digit is 10, shift everything. */
      if (s[0] > '9') { 
        e++; 
        for (i = precision; i >= 2; i--) s[i] = s[i-1]; 
        s[0] = '1';
        s[1] = '0';
      }
      
      s[precision] = 0;
      expn = e;
    }
    
    template <class A, class I>  void digits(const dual<float, A, I> &dd,
                                    char *s,
                                    int &expn,
                                    int precision)
      
    {
      typedef dual<float, A, I>    self;
      typedef float          type; 
      int D = precision + 1;  /* number of digits to compute */
      
      self r = abs(dd); //(dd.hi() > 0) ? dd : -dd;
      int e;  /* exponent */
      int i, d;
      
      if (dd.hi() == 0.0f) {
        /* this == 0.0 */
        expn = 0;
        for (i = 0; i < precision; i++) s[i] = '0';
        return;
      }
      
      /* First determine the (approximate) exponent. */
      e = static_cast < int > (nt2::floor(nt2::log10(nt2::abs(dd.hi()))));
      static const self ten(type(10), type(0));
      if(e)
        {
          if (e < -30) {
            r *= npwr(ten, 30);
            r *= npwr(ten, (30-e));
          } else if (e > 30) {
            r = self::ldexp(r, -24);
            r *= npwr(ten, -e);
            r = self::ldexp(r, 24);
          } else {
            r *= npwr(ten, -e); 
          }
        }
      /* Fix exponent if we are off by one */
      if (r >= ten) {
        r /= ten;
        e++;
      } else if (r < r.one()) {
        r *= ten;
        e--;
      }
      if (r >= ten || r <r.one()) {
        error("(self::to_digits): can't compute exponent.");
        return;
      }
      
      /* Extract the digits */
      for (i = 0; i < D; i++) {
        d = static_cast<int>(r.hi());
        r -= d;
        r = r*self(ten);
        s[i] = static_cast<char>(d + '0');
      }
      
      /* Fix negative digits. */
      for (i = D-1; i > 0; i--) {
        if (s[i] < '0') {
          s[i-1]--;
          s[i] += 10;
        }
      }
      
      if (s[0] <= '0') {
        error("(self::to_digits): non-positive leading digit.");
        return;
      }
      
      /* Round, handle carry */
      if (s[D-1] >= '5') {
        s[D-2]++;
        
        i = D-2;
        while (i > 0 && s[i] > '9') {
          s[i] -= 10;
          s[--i]++;
        }
      }
      
      /* If first digit is 10, shift everything. */
      if (s[0] > '9') { 
        e++; 
        for (i = precision; i >= 2; i--) s[i] = s[i-1]; 
        s[0] = '1';
        s[1] = '0';
      }
      
      s[precision] = 0;
      expn = e;
    }
    
  }
  
  
//   template <class A, class I>  void digits(const dual<float, A, I> &dd,
// 				  char *s,
// 				  int &expn,
// 				  int precision)
    
//   {
//     typedef dual<float, A, I>    self;
//     typedef float          type; 
//     int D = precision + 1;  /* number of digits to compute */
    
//     self r = self::abs(dd); //(dd.hi() > 0) ? dd : -dd;
//     int e;  /* exponent */
//     int i, d;
    
//     if (dd.hi() == 0.0f) {
//       /* this == 0.0 */
//       expn = 0;
//       for (i = 0; i < precision; i++) s[i] = '0';
//       return;
//     }
    
//     /* First determine the (approximate) exponent. */
//     e = static_cast < int > (nt2::floor(nt2::log10(nt2::abs(dd.hi()))));
//     static const self ten(type(10), type(0));
//     if(e)
//       {
// 	if (e < -30) {
// 	  r *= npwr(ten, 30);
// 	  r *= npwr(ten, (30-e));
// 	} else if (e > 30) {
// 	  r = self::ldexp(r, -24);
// 	  r *= npwr(ten, -e);
// 	  r = self::ldexp(r, 24);
// 	} else {
// 	  r *= npwr(ten, -e); 
// 	}
//       }
//     /* Fix exponent if we are off by one */
//     if (r >= ten) {
//       r /= ten;
//       e++;
//     } else if (r < r.one()) {
//       r *= ten;
//       e--;
//     }
//     if (r >= ten || r < r.one()) {
//       std::cout << ("(self::to_digits): can't compute exponent.") << std::endl;
//       return;
//     }
    
//     /* Extract the digits */
//     for (i = 0; i < D; i++) {
//       d = static_cast<int>(r.hi());
//       r -= d;
//       r = r*self(ten);
//       s[i] = static_cast<char>(d + '0');
//     }
    
//     /* Fix negative digits. */
//     for (i = D-1; i > 0; i--) {
//       if (s[i] < '0') {
// 	s[i-1]--;
// 	s[i] += 10;
//       }
//     }
    
//     if (s[0] <= '0') {
//       std::cout <<("(self::to_digits): non-positive leading digit.") << std::endl;
//       return;
//     }
    
//     /* Round, handle carry */
//     if (s[D-1] >= '5') {
//       s[D-2]++;
      
//       i = D-2;
//       while (i > 0 && s[i] > '9') {
// 	s[i] -= 10;
// 	s[--i]++;
//       }
//     }
    
//     /* If first digit is 10, shift everything. */
//     if (s[0] > '9') { 
//       e++; 
//       for (i = precision; i >= 2; i--) s[i] = s[i-1]; 
//       s[0] = '1';
//       s[1] = '0';
//     }
    
//     s[precision] = 0;
//     expn = e;
//   }
  
//}



#endif

// /////////////////////////////////////////////////////////////////////////////
// End of dual_impl.hpp
// /////////////////////////////////////////////////////////////////////////////
