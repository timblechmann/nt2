/*******************************************************************************
 *         Copyright 2003-2011 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_TYPES_DUAL_FUNCS_HPP_INCLUDED
#define NT2_SDK_TYPES_DUAL_FUNCS_HPP_INCLUDED

#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/floor.hpp>
#include <nt2/include/functions/ceil.hpp>
//#include <nt2/include/functions/atan2.hpp>
#include <nt2/include/functions/log.hpp>
#include <nt2/include/functions/exp.hpp>
#include <nt2/include/functions/round.hpp>
#include <nt2/include/functions/rsqrt.hpp>



namespace nt2
{
  

 /* Round to Nearest integer */
  template<class T, class A, class I>  inline  dual<T,A,I>  nint(const dual<T,A,I> &a) {
    T hi = nt2::round(a.hi());
    T lo;
    
    if (hi == a.hi()) {
      /* High word is an integer already.  Round the low word.*/
      lo = nt2::round(a.lo());
       
      /* Renormalize. This is needed if hi() = some integer, lo() = 1/2.*/
      hi = details::quick_two_sum(hi, lo, lo);
    } else {
      /* High word is not an integer. */
      lo = 0.0;
      if (nt2::abs(hi-a.hi()) == 0.5 && a.lo() < 0.0) {
        /* There is a tie in the high word, consult the low word 
           to break the tie. */
        hi -= 1.0;      /* NOTE: This does not cause INEXACT. */
      }
    }
    
    return dual<T,A,I>(hi, lo);
  }
  
  template<class T, class A, class I>  inline  dual<T,A,I>  floor(const dual<T,A,I> &a) {
    T hi = nt2::floor(a.hi());
    T lo = 0.0;
    
    if (hi == a.hi()) {
      /* High word is integer already.  Round the low word. */
      lo = nt2::floor(a.lo());
      hi = details::quick_two_sum(hi, lo, lo);
    }
    
    return dual<T,A,I>(hi, lo);
  }
  
  template<class T, class A, class I>  inline  dual<T,A,I> ceil(const dual<T,A,I> &a) {
    T hi = nt2::ceil(a.hi());
    T lo = 0.0;
    
    if (hi == a.hi()) {
      /* High word is integer already.  Round the low word. */
      lo = nt2::ceil(a.lo());
      hi = details::quick_two_sum(hi, lo, lo);
    }
    
    return dual<T,A,I>(hi, lo);
  }
  

//   /* Random number generator */
//   template<class T, class A, class I> static inline  dual<T,A,I> rand() {
//     return dual<T,A,I>rand();
//   }
  
//   template<class T, class A, class I>  inline  dual<T,A,I>  rec(const dual<T,A,I> &a) {
//     typedef typename dual<T,A,I>::part part; 
//     return One<part>() / a;
// }


//  template<class T, class A, class I>    
//   void dual<T,A,I>::print_double_info(std::ostream &os, double x);
  
  /* This routine is called whenever a fatal error occurs. */
  static inline void error(const char *msg) { 
    if (msg) { std::cerr << "ERROR " << msg << std::endl; }
  }
  
  /* Computes the square root of the T-T number dual<T,A,I>.
     NOTE: dual<T,A,I> must be a non-negative number.                   */
  template<class T, class A, class I>  inline dual<T,A,I> sqrt(const dual<T, A> &a) {
    typedef dual<T, A> self;
    typedef typename self::type type; 
    /* Strategy:  Use Karp's trick:  if x is an approximation
       to sqrt(a), then
       
       sqrt(a) = a*x + [a - (a*x)^2] * x / 2   (approx)
       
       The approximation is accurate to twice the accuracy of x.
       Also, the multiplication (a*x) and [-]*x can be done with
       only half the precision.
    */
    
    if (a.iseqz())
      return a.zero();
    
    if (a.isltz()) {
      return a.nan();
    }
    
    type x = nt2::rsqrt(a.hi());
    self ax(a.hi() * x);
    self z = (a - sqr(ax)); 
    return ax + (z.hi() * (x * Half<type>()));
}
  
  
  /* Computes the n-th power of a T-T number. 
     NOTE:  0^0 causes an error.                         */
  template<class T, class A, class I>
  inline dual<T,A,I> npwr(const dual<T,A,I> &a, const int& n) {
    
    if (n == 0) {
      if (a.iseqz()) {
        return a.nan();
      }
      return a.one();
    }
    
    dual<T,A,I> r = a;
    dual<T,A,I> s = a.one();
    int N = nt2::abs(n); 
    
    if (N > 1) {
      /* Use binary exponentiation */
      while (N > 0) {
        if (N % 2 == 1) {
          s *= r;
        }
        N >>= 1;
        if (N > 0)
          r = dual<T,A,I>::sqr(r);
      }
    } else {
      s = r;
    }
    
    /* Compute the reciprocal if n is negative. */
    if (n < 0)
      return dual<T,A,I>::rec(s);
    
    return s;
  }
  
  /* Computes the n-th root of the T-T number a.
     NOTE: n must be a positive integer.  
     NOTE: If n is even, then a must not be negative.       */
  template < class T, class A, class I > 
  dual<T,A,I> nthroot(const dual<T,A,I> &a, int n) {
    /* Strategy:  Use Newton iteration for the function
       
    f(x) = x^(-n) - a
    
    to find its root a^{-1/n}.  The iteration is thus
    
    x' = x + x * (1 - a * x^n) / n
    
    which converges quadratically.  We can then find 
    a^{1/n} by taking the reciprocal.
    */
    
    if (n <= 0) {
      return a.nan();
    }
    
    if (n%2 == 0 && a.isltz()) {
      return a.nan();
    }
    
    if (n == 1) {
      return a;
    } 
    if (n == 2) {
      return sqrt(a);
    }
    
    if (a.iseqz())
      return 0.0;
    
    /* Note  a^{-1/n} = exp(-log(a)/n) */
    dual<T,A,I> r = abs(a);
    dual<T,A,I> x = nt2::exp(-nt2::log(r.hi()) / n);
    
    /* Perform Newton's iteration. */
    x += x * (1.0 - r * npwr(x, n)) / static_cast<T>(n);
    if (a.hi() < 0.0)
      x = -x;
    return rec(x);
  }
  
  template<class T, class A, class I> inline dual<T,A,I> log10(const dual<T,A,I> &a)
  {
    typedef dual<T,A,I> self;
    static const self Log_10_("2.3025850929940456840179914546843642"); 
    return log(a) / Log_10_;
  }
  
  /* Exponential.  Computes exp(x) in T-T precision. */
  template<class T, class A, class I>
  inline dual<T,A,I> exp(const dual<T,A,I> &a) {
    typedef dual<T,A,I> self; 
    typedef details::dual_values<T> dv; 
    /* Strategy:  We first reduce the size of x by noting that
       
    exp(kr + m * log(2)) = 2^m * exp(r)^k
    
    where m and k are integers.  By choosing m appropriately
    we can make |kr| <= log(2) / 2 = 0.347.  Then exp(r) is 
    evaluated using the familiar Taylor series.  Reducing the 
    argument substantially speeds up the convergence.       */  
    
    const T k = 512.0;
    const T inv_k = 1.0 / k;
    
    if (a.hi() <= -709.0)
      return a.zero();
    
    if (a.hi() >=  709.0)
      return a.inf() ;
    
    if (a.is_zero())
      return a.one();
    
//     if (a.is_one())
//       return details::Exp_1< dual<T,A,I> >() ;
    static const self log_2_("0.69314718055994530941723212145817657");
    self ll = log_2_; 
    T tmp =  ll.hi(); 
    T m = nt2::floor(a.hi() / tmp + 0.5);
    dual<T,A,I> r = mul_pwr2(a - ll * m, inv_k);
    dual<T,A,I> s, t;
    
    dual<T,A,I> p = sqr(r);
    s = mul_pwr2(p, 0.5)+r;
    p *= r;
    t = p * dv::inv_fact()[0];
    int i = 0;
    do {
      s += t;
      p *= r;
      t = p * dv::inv_fact()[++i];
    } while (nt2::abs(to_type(t)) > Eps<self>()*inv_k && i < 5);
    
    s += t;
    
    s = mul_pwr2(s, 2.0) + self::sqr(s);
    s = mul_pwr2(s, 2.0) + self::sqr(s);
    s = mul_pwr2(s, 2.0) + self::sqr(s);
    s = mul_pwr2(s, 2.0) + self::sqr(s);
    s = mul_pwr2(s, 2.0) + self::sqr(s);
    s = mul_pwr2(s, 2.0) + self::sqr(s);
    s = mul_pwr2(s, 2.0) + self::sqr(s);
    s = mul_pwr2(s, 2.0) + self::sqr(s);
    s = mul_pwr2(s, 2.0) + self::sqr(s);
    s += 1.0;
    
    return self::ldexp(s, static_cast<int>(m));
  }
  
  /* Logarithm.  Computes log(x) in T-T precision.
     This is a natural logarithm (i.e., base e).            */
  template<class T, class A, class I> inline dual<T,A,I> log(const dual<T,A,I> &a) {
    /* Strategy.  The Taylor series for log converges much more
       slowly than that of exp, due to the lack of the factorial
       term in the denominator.  Hence this routine instead tries
       to determine the root of the function
       
       f(x) = exp(x) - a
       
       using Newton iteration.  The iteration is given by
       
       x' = x - f(x)/f'(x) 
       = x - (1 - a * exp(-x))
       = x + a * exp(-x) - 1.
       
       Only one iteration is needed, since Newton's iteration
       approximately Ts the number of digits per iteration. */
    
    if (a.is_one()) {
      return dual<T,A,I>(T(0));
    }
    
    if (a.hi() <= 0.0) {
      error("(dual<T,A,I>::log): Non-positive argument.");
      return a.nan(); 
    }
    
    dual<T,A,I> x(nt2::log(a.hi()));   /* Initial approximation */
    
    x = x + a * exp(-x) - 1.0;
    return x;
  }

 
  
//   /* Computes sin(a) using Taylor series.
//      Assumes |a| <= pi/32.                           */
//   template < class T, class A, class I > dual<T,A,I> dual<T,A,I>::sin_taylor(const dual<T,A,I> &a) {
    
//     const T thresh = 0.5 * nt2::abs(to_type(a)) * Eps<type>();
//     dual<T,A,I> r, s, t, x;
    
//     if (a.iseqz()) {
//       return Zero<self>();
//     }
    
//     int i = 0;
//     x = -sqr(a);
//     s = a;
//     r = a;
//     do {
//       r *= x;
//       t = r * dv::inv_fact()[i];
//       s += t;
//       i += 2;
//     } while (i < dv::n_inv_fact() && nt2::abs(to_type(t)) > thresh);
//     return s;
//   }
  
//   template<class T, class A, class I> inline dual<T,A,I> dual<T,A,I>::cos_taylor(const dual<T,A,I> &a) {
//     const T thresh = 0.5 * details::Eps<type>();
//     dual<T,A,I> r, s, t, x;
    
//     if (a.is_zero()) {
//       return details::One<self>();
//     }
    
//     x = -sqr(a);
//     r = x;
//     s = details::One<dual<T,A,I> >()+ mul_pwr2(r, 0.5);
//     int i = 1;
//     do {
//       r *= x;
//       t = r * dv::inv_fact()[i];
//       s += t;
//       i += 2;
//     } while (i < dv::n_inv_fact() && nt2::abs(to_type(t)) > thresh);
    
//     return s;
//   }
  
//   template<class T, class A, class I> inline void dual<T,A,I>::sincos_taylor(const dual<T,A,I> &a, 
//                             dual<T,A,I> &sin_a, dual<T,A,I> &cos_a) {
//     if (a.is_zero()) {
//       sin_a = details::Zero<self>();
//       cos_a = details::One<self>();   
//       return;
//     }
    
//     sin_a = sin_taylor(a);
//     cos_a = sqrt(details::One<self>() - sqr(sin_a));
//   }
  
  
//   template<class T, class A, class I> inline dual<T,A,I> dual<T,A,I>::sin(const dual<T,A,I> &a) {  
    
//     /* Strategy.  To compute sin(x), we choose integers a, b so that
       
//     x = s + a * (pi/2) + b * (pi/16)
    
//     and |s| <= pi/32.  Using the fact that 
    
//     sin(pi/16) = 0.5 * sqrt(2 - sqrt(2 + sqrt(2)))
    
//     we can compute sin(x) from sin(s), cos(s).  This greatly 
//     increases the convergence of the sine Taylor series. */
    
//     if (a.is_zero()) {
//       return details::Zero < self > ();
//     }
    
//     // approximately reduce modulo 2*pi
//     dual<T,A,I> z = nint(a / details::Two_pi<self>());
//     dual<T,A,I> r = a - details::Two_pi<self>() * z;
    
//     // approximately reduce modulo pi/2 and then modulo pi/16.
//     dual<T,A,I> t;
//     T q = nt2::floor(r.hi() / details::Half_pi<self>().hi() + 0.5);
//     t = r - details::Half_pi<self>() * q;
//     int j = static_cast<int>(q);
//     q = sFloor(t.hi() / dv::_pi16().hi() + 0.5);
//     t -= dv::_pi16() * q;
//     int k = static_cast<int>(q);
//     int abs_k = nt2::abs(k);
    
//     if (j < -2 || j > 2) {
//       error("(dual<T,A,I>::sin): Cannot reduce modulo pi/2.");
//       return details::Nan < self >() ;
//     }
    
//     if (abs_k > 4) {
//       error("(dual<T,A,I>::sin): Cannot reduce modulo pi/16.");
//       return details::Nan<self>();
//     }
    
//     if (k == 0) {
//       switch (j) {
//       case 0:
//         return sin_taylor(t);
//       case 1:
//         return cos_taylor(t);
//       case -1:
//         return -cos_taylor(t);
//       default:
//         return -sin_taylor(t);
//       }
//     }
    
//     dual<T,A,I> u = dv::cos_table()[abs_k-1];
//     dual<T,A,I> v = dv::sin_table()[abs_k-1];
//     dual<T,A,I> sin_t, cos_t;
//     sincos_taylor(t, sin_t, cos_t);
//     if (j == 0) {
//       if (k > 0) {
//         r = u * sin_t + v * cos_t;
//       } else {
//         r = u * sin_t - v * cos_t;
//       }
//     } else if (j == 1) {
//       if (k > 0) {
//         r = u * cos_t - v * sin_t;
//       } else {
//         r = u * cos_t + v * sin_t;
//       }
//     } else if (j == -1) {
//       if (k > 0) {
//         r = v * sin_t - u * cos_t;
//       } else if (k < 0) {
//         r = -u * cos_t - v * sin_t;
//       }
//     } else {
//       if (k > 0) {
//         r = -u * sin_t - v * cos_t;
//       } else {
//         r = v * cos_t - u * sin_t;
//       }
//     }
    
//     return r;
//   }
  
//   template<class T, class A, class I> inline dual<T,A,I> dual<T,A,I>::cos(const dual<T,A,I> &a) {
    
//     if (a.is_zero()) {
//       return details::One<self>();
//     }
    
//     // approximately reduce modulo 2*pi
//     dual<T,A,I> z = nint(a / details::Two_pi<self>());
//     dual<T,A,I> r = a - z * details::Two_pi<self>();
    
//     // approximately reduce modulo pi/2 and then modulo pi/16
//     dual<T,A,I> t;
//     T q = nt2::floor(r.hi() / details::Half_pi<self>().hi() + 0.5);
//     t = r - details::Half_pi<self>() * q;
//     int j = static_cast<int>(q);
//     q = sFloor(t.hi() / dv::_pi16().hi() + 0.5);
//     t -= dv::_pi16() * q;
//     int k = static_cast<int>(q);
//     int abs_k = nt2::abs(k);
    
//     if (j < -2 || j > 2) {
//       error("(dual<T,A,I>::cos): Cannot reduce modulo pi/2.");
//       return details::Nan<self>();
//     }
    
//     if (abs_k > 4) {
//       error("(dual<T,A,I>::cos): Cannot reduce modulo pi/16.");
//       return details::Nan<self>();
//     }
    
//     if (k == 0) {
//       switch (j) {
//       case 0:
//         return cos_taylor(t);
//       case 1:
//         return -sin_taylor(t);
//       case -1:
//         return sin_taylor(t);
//       default:
//         return -cos_taylor(t);
//       }
//     }
    
//     dual<T,A,I> sin_t, cos_t;
//     sincos_taylor(t, sin_t, cos_t);
//     dual<T,A,I> u = dv::cos_table()[abs_k-1];
//     dual<T,A,I> v = dv::sin_table()[abs_k-1];
    
//     if (j == 0) {
//       if (k > 0) {
//         r = u * cos_t - v * sin_t;
//       } else {
//         r = u * cos_t + v * sin_t;
//       }
//     } else if (j == 1) {
//       if (k > 0) {
//         r = - u * sin_t - v * cos_t;
//       } else {
//         r = v * cos_t - u * sin_t;
//       }
//     } else if (j == -1) {
//       if (k > 0) {
//         r = u * sin_t + v * cos_t;
//       } else {
//         r = u * sin_t - v * cos_t;
//       }
//     } else {
//       if (k > 0) {
//         r = v * sin_t - u * cos_t;
//       } else {
//         r = - u * cos_t - v * sin_t;
//       }
//     }
    
//     return r;
//   }
  
//   template<class T, class A, class I>  inline void dual<T,A,I>::sincos(const dual<T,A,I> &a, dual<T,A,I> &sin_a, dual<T,A,I> &cos_a) {
    
//     if (a.is_zero()) {
//       sin_a = 0.0;
//       cos_a = 1.0;
//       return;
//     }
    
//     // approximately reduce modulo 2*pi
//     dual<T,A,I> z = nint(a / details::Two_pi<self>());
//     dual<T,A,I> r = a - details::Two_pi<self>() * z;
    
//     // approximately reduce module pi/2 and pi/16
//     dual<T,A,I> t;
//     T q = nt2::floor(r.hi() / details::Half_pi<self>().hi() + 0.5);
//     t = r - details::Half_pi<self>() * q;
//     int j = static_cast<int>(q);
//     int abs_j = nt2::abs(j);
//     q = nt2::floor(t.hi() / dv::_pi16().hi() + 0.5);
//     t -= dv::dv::_pi16()() * q;
//     int k = static_cast<int>(q);
//     int abs_k = nt2::abs(k);
    
//     if (abs_j > 2) {
//       error("(dual<T,A,I>::sincos): Cannot reduce modulo pi/2.");
//       cos_a = sin_a = details::Nan<self>();
//       return;
//     }
    
//     if (abs_k > 4) {
//       error("(dual<T,A,I>::sincos): Cannot reduce modulo pi/16.");
//       cos_a = sin_a = details::Nan<self>();
//       return;
//     }
    
//     dual<T,A,I> sin_t, cos_t;
//     dual<T,A,I> s, c;
    
//     sincos_taylor(t, sin_t, cos_t);
    
//     if (abs_k == 0) {
//       s = sin_t;
//       c = cos_t;
//     } else {
//       dual<T,A,I> u = dv::cos_table()[abs_k-1];
//       dual<T,A,I> v = dv::sin_table()[abs_k-1];
      
//       if (k > 0) {
//         s = u * sin_t + v * cos_t;
//         c = u * cos_t - v * sin_t;
//       } else {
//         s = u * sin_t - v * cos_t;
//         c = u * cos_t + v * sin_t;
//       }
//     }
    
//     if (abs_j == 0) {
//       sin_a = s;
//       cos_a = c;
//     } else if (j == 1) {
//       sin_a = c;
//       cos_a = -s;
//     } else if (j == -1) {
//       sin_a = -c;
//       cos_a = s;
//     } else {
//       sin_a = -s;
//       cos_a = -c;
//     }
    
//   }
  
  
//   template<class T, class A, class I>  inline dual<T,A,I> dual<T,A,I>::atan2(const dual<T,A,I> &y, const dual<T,A,I> &x) {
//     /* Strategy: Instead of using Taylor series to compute 
//        arctan, we instead use Newton's iteration to solve
//        the equation
       
//        sin(z) = y/r    or    cos(z) = x/r
       
//        where r = sqrt(x^2 + y^2).
//        The iteration is given by
       
//        z' = z + (y - sin(z)) / cos(z)          (for equation 1)
//        z' = z - (x - cos(z)) / sin(z)          (for equation 2)
       
//        Here, x and y are normalized so that x^2 + y^2 = 1.
//        If |x| > |y|, then first iteration is used since the 
//        denominator is larger.  Otherwise, the second is used.
//     */
    
//     if (x.is_zero()) {
      
//       if (y.is_zero()) {
//         /* Both x and y is zero. */
//         error("(dual<T,A,I>::atan2): Both arguments zero.");
//         return details::Nan<self>();
//       }
      
//       return (y.is_positive()) ? details::Half_pi<self>() : -details::Half_pi<self>();
//     } else if (y.is_zero()) {
//       return (x.is_positive()) ? dual<T,A,I>(0.0) : dual<T,A,I>::_pi;
//     }
    
//     if (x == y) {
//       return (y.is_positive()) ? dual<T,A,I>::_pi4 : -dual<T,A,I>::_3pi4;
//     }
    
//     if (x == -y) {
//       return (y.is_positive()) ? dual<T,A,I>::_3pi4 : -dual<T,A,I>::_pi4;
//     }
    
//     dual<T,A,I> r = sqrt(sqr(x) + sqr(y));
//     dual<T,A,I> xx = x / r;
//     dual<T,A,I> yy = y / r;
    
//     /* Compute T precision approximation to atan. */
//     dual<T,A,I> z = nt2::atan2(to_type(y), to_type(x));
//     dual<T,A,I> sin_z, cos_z;
    
//     if (nt2::abs(xx.hi()) > nt2::abs(yy.hi())) {
//       /* Use Newton iteration 1.  z' = z + (y - sin(z)) / cos(z)  */
//       sincos(z, sin_z, cos_z);
//       z += (yy - sin_z) / cos_z;
//     } else {
//       /* Use Newton iteration 2.  z' = z - (x - cos(z)) / sin(z)  */
//       sincos(z, sin_z, cos_z);
//       z -= (xx - cos_z) / sin_z;
//     }
    
//     return z;
//   }
  
  
//   template<class T, class A, class I>  inline dual<T,A,I> dual<T,A,I>::asin(const dual<T,A,I> &a) {
//     dual<T,A,I> abs_a = abs(a);
    
//     if (abs_a > 1.0) {
//       error("(dual<T,A,I>::asin): Argument out of domain.");
//       return details::Nan<self>();
//     }
    
//     if (abs_a.is_one()) {
//       return (a.is_positive()) ? details::Half_pi<self>() : -details::Half_pi<self>();
//     }
    
//     return atan2(a, sqrt(1.0 - sqr(a)));
//   }
  
//   template<class T, class A, class I>  inline dual<T,A,I> dual<T,A,I>::acos(const dual<T,A,I> &a) {
//     dual<T,A,I> abs_a = abs(a);
    
//     if (abs_a > 1.0) {
//       error("(dual<T,A,I>::acos): Argument out of domain.");
//       return details::Nan<self>();
//     }
    
//     if (abs_a.is_one()) {
//       return (a.is_positive()) ? dual<T,A,I>(0.0) : dual<T,A,I>::_pi;
//     }
    
//     return atan2(sqrt(1.0 - sqr(a)), a);
//   }
  
//   template<class T, class A, class I>  inline dual<T,A,I> dual<T,A,I>::sinh(const dual<T,A,I> &a) {
//     if (a.is_zero()) {
//       return 0.0;
//     }
    
//     if (abs(a) > 0.05) {
//       dual<T,A,I> ea = exp(a);
//       return mul_pwr2(ea - inv(ea), 0.5);
//     }
    
//     /* since a is small, using the above formula gives
//        a lot of cancellation.  So use Taylor series.   */
//     dual<T,A,I> s = a;
//     dual<T,A,I> t = a;
//     dual<T,A,I> r = sqr(t);
//     T m = 1.0;
//     T thresh = nt2::abs((to_type(a)) * details::Eps<self>());
    
//     do {
//       m += 2.0;
//       t *= r;
//       t /= (m-1) * m;
      
//       s += t;
//     } while (abs(t) > thresh);
    
//     return s;
    
//   }
  
//   template<class T, class A, class I>  inline dual<T,A,I> dual<T,A,I>::cosh(const dual<T,A,I> &a) {
//     if (a.is_zero()) {
//       return 1.0;
//     }
    
//     dual<T,A,I> ea = exp(a);
//     return mul_pwr2(ea + inv(ea), 0.5);
//   }
  
//   template<class T, class A, class I>  inline dual<T,A,I> dual<T,A,I>::tanh(const dual<T,A,I> &a) {
//     if (a.is_zero()) {
//       return 0.0;
//     }
    
//     dual<T,A,I> ea = exp(a);
//     dual<T,A,I> inv_ea = inv(ea);
//     return (ea - inv_ea) / (ea + inv_ea);
//   }
  
//   template<class T, class A, class I>  inline void dual<T,A,I>::sincosh(const dual<T,A,I> &a, dual<T,A,I> &sinh_a, dual<T,A,I> &cosh_a) {
//     sinh_a = sinh(a);
//     cosh_a = cosh(a);
//   }
  
//   template<class T, class A, class I>  inline dual<T,A,I> dual<T,A,I>::asinh(const dual<T,A,I> &a) {
//     return log(a + sqrt(sqr(a) + 1.0));
//   }
  
//   template<class T, class A, class I>  inline dual<T,A,I> dual<T,A,I>::acosh(const dual<T,A,I> &a) {
//     if (a < 1.0) {
//       error("(dual<T,A,I>::acosh): Argument out of domain.");
//       return details::Nan<self>();
//     }
    
//     return log(a + sqrt(sqr(a) - 1.0));
//   }
  
//   template<class T, class A, class I>  inline dual<T,A,I> dual<T,A,I>::atanh(const dual<T,A,I> &a) {
//     if (abs(a) >= 1.0) {
//       error("(dual<T,A,I>::atanh): Argument out of domain.");
//       return details::Nan<self>();
//     }
    
//     return mul_pwr2(log((1.0 + a) / (1.0 - a)), 0.5);
//   }
  
//   template<class T, class A, class I>  inline  dual<T,A,I>rand() {
//     static const T m_const = 4.6566128730773926e-10;  /* = 2^{-31} */
//     T m = m_const;
//     dual<T,A,I> r = 0.0;
//     T d;
    
//     /* Strategy:  Generate 31 bits at a time, using lrand48 
//        random number generator.  Shift the bits, and reapeat
//        4 times. */
    
//     for (int i = 0; i < 4; i++, m *= m_const) {
//       //    d = lrand48() * m;
//       d = nt2::rand() * m;
//       r += d;
//     }
    
//     return r;
//   }
  
//   /* polyeval(c, n, x)
//      Evaluates the given n-th degree polynomial at x.
//      The polynomial is given by the array of (n+1) coefficients. */
//   template<class T, class A, class I>  inline dual<T,A,I> polyeval(const dual<T,A,I> *c, int n, const dual<T,A,I> &x) {
//     /* Just use Horner's method of polynomial evaluation. */
//     dual<T,A,I> r = c[n];
    
//     for (int i = n-1; i >= 0; i--) {
//       r *= x;
//       r += c[i];
//     }
    
//     return r;
//   }
  
//   /* polyroot(c, n, x0)
//      Given an n-th degree polynomial, finds a root close to 
//      the given guess x0.  Note that this uses simple Newton
//      iteration scheme, and does not work for multiple roots.  */
//   template<class T, class A, class I>  inline dual<T,A,I> dual<T,A,I>::polyroot(const dual<T,A,I> *c, int n, 
//               const dual<T,A,I> &x0, int max_iter, T thresh) {
//     dual<T,A,I> x = x0;
//     dual<T,A,I> f;
//     dual<T,A,I> *d = new dual<T,A,I>[n];
//     bool conv = false;
//     int i;
//     T max_c = nt2::abs(to_type(c[0]));
//     T v;
    
//     if (thresh == 0.0) thresh = details::Eps<self>();
    
//     /* Compute the coefficients of the derivatives. */
//     for (i = 1; i <= n; i++) {
//       v = nt2::abs(to_type(c[i]));
//       if (v > max_c) max_c = v;
//       d[i-1] = c[i] * static_cast<T>(i);
//     }
//     thresh *= max_c;
    
//     /* Newton iteration. */
//     for (i = 0; i < max_iter; i++) {
//       f = polyeval(c, n, x);
      
//       if (abs(f) < thresh) {
//         conv = true;
//         break;
//       }
//       x -= (f / polyeval(d, n-1, x));
//     }
//     delete [] d;
    
//     if (!conv) {
//       error("(dual<T,A,I>::polyroot): Failed to converge.");
//       return details::Nan<self>();
//     }
    
//     return x;
//   }

 

  // ///////////////////////////////////////////////////////////////////////////
  //  externalization of static functions
  // ///////////////////////////////////////////////////////////////////////////
//   template < class T, class A, class I > static inline dual<T,A,I> abs     (const dual<T,A,I>  &a){return dual<T,A,I>::abs(a);} 
//   template < class T, class A, class I > static inline dual<T,A,I> sqr     (const dual<T,A,I> &a){return dual<T,A,I>::sqr(a);}  
//   template < class T, class A, class I > static inline dual<T,A,I> round   (const dual<T,A,I> &a){return dual<T,A,I>::round(a);}  
//   template < class T, class A, class I > static inline T to_type    (const dual<T,A,I> &a){return dual<T,A,I>::to_type(a);}   
//   template < class T, class A, class I > static inline int  to_int     (const dual<T,A,I> &a){return dual<T,A,I>::to_int(a);}
//   template < class T, class A, class I > static inline dual<T,A,I> sqrt    (const dual<T,A,I> &a){return dual<T,A,I>::sqrt(a);}  
//   template < class T, class A, class I > static inline dual<T,A,I> nroot   (const dual<T,A,I> &a, int n){return dual<T,A,I>::pow(a, n);}          
//   template < class T, class A, class I > static inline dual<T,A,I> pow     (const dual<T,A,I> &a, int n){return dual<T,A,I>::pow(a, n);} 
//   template < class T, class A, class I > static inline dual<T,A,I> pow     (const dual<T,A,I> &a, const dual<T,A,I> &b){return dual<T,A,I>::pow(a, b);} 
//   template < class T, class A, class I > static inline dual<T,A,I> sin     (const dual<T,A,I> &a) {return dual<T,A,I>::sin(a);}                   
//   template < class T, class A, class I > static inline dual<T,A,I> cos     (const dual<T,A,I> &a) {return dual<T,A,I>::cos(a);}                   
//   template < class T, class A, class I > static inline void sincos     (const dual<T,A,I> &a, dual<T,A,I> &sin_a, dual<T,A,I> &cos_a){dual<T,A,I>::sincos(a, sin_a, cos_a);} 
//   template < class T, class A, class I > static inline dual<T,A,I> atan    (const dual<T,A,I> &a){return dual<T,A,I>::atan(a);} 
//   template < class T, class A, class I > static inline dual<T,A,I> tan     (const dual<T,A,I> &a){return dual<T,A,I>::tan(a);} 
//   template < class T, class A, class I > static inline dual<T,A,I> asin    (const dual<T,A,I> &a) {return dual<T,A,I>::asin(a);}                   
//   template < class T, class A, class I > static inline dual<T,A,I> acos    (const dual<T,A,I> &a) {return dual<T,A,I>::acos(a);}                   
//   template < class T, class A, class I > static inline dual<T,A,I> sinh    (const dual<T,A,I> &a) {return dual<T,A,I>::sinh(a);}                   
//   template < class T, class A, class I > static inline dual<T,A,I> cosh    (const dual<T,A,I> &a) {return dual<T,A,I>::cosh(a);}                   
//   template < class T, class A, class I > static inline dual<T,A,I> tanh    (const dual<T,A,I> &a) {return dual<T,A,I>::tanh(a);}                   
//   template < class T, class A, class I > static inline void sincosh    (const dual<T,A,I> &a, dual<T,A,I> &sinh_a, dual<T,A,I> &cosh_a){dual<T,A,I>::sincos(a, sinh_a, cosh_a);} 
//   template < class T, class A, class I > static inline dual<T,A,I> asinh   (const dual<T,A,I> &a) {return dual<T,A,I>::asinh(a);}                   
//   template < class T, class A, class I > static inline dual<T,A,I> acosh   (const dual<T,A,I> &a) {return dual<T,A,I>::acosh(a);}                   
//   template < class T, class A, class I > static inline dual<T,A,I> atanh   (const dual<T,A,I> &a) {return dual<T,A,I>::atanh(a);}                   
//   template < class T, class A, class I > static inline dual<T,A,I> atan2   (const dual<T,A,I> &y, const dual<T,A,I> &x){return dual<T,A,I>::atan2(y,x);} 
  
  
}


#endif

// /////////////////////////////////////////////////////////////////////////////
// End of dual_funcs.hpp
// /////////////////////////////////////////////////////////////////////////////
