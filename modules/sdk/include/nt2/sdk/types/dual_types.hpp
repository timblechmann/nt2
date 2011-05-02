/*******************************************************************************
 *         Copyright 2003-2011 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_TYPES_DUAL_TYPES_HPP_INCLUDED
#define NT2_SDK_TYPES_DUAL_TYPES_HPP_INCLUDED
#include <string>
#include <nt2/sdk/meta/is_scalar.hpp>
#include <nt2/include/functions/is_inf.hpp>
#include <nt2/include/functions/is_finite.hpp>
#include <nt2/include/functions/is_nan.hpp>
#include <nt2/include/functions/is_eqz.hpp>
#include <nt2/include/functions/is_ltz.hpp>
#include <nt2/include/functions/ldexp.hpp>
#include <nt2/include/functions/floor.hpp>
#include <nt2/include/functions/log10.hpp>

#include <nt2/sdk/types/details/dual_low_level.hpp>

namespace nt2
{
     template <class TAI>  void digits(const TAI &dd,
                                    char *s,
                                    int &expn,
                                    int precision); 

  //////////////////////////////////////////////////////////////////////////////
  /// @class dual
  ///
  ///  A dual number is an unevaluated sum of two numbers of type T
  ///  T being IEEE float or double precision numbers, able to handle 
  ///  at least 43 bits (for floats) and 106 bits of significand (for double)
  ///  but with the same exponent precision.
  ///
  ///  the package is based on Yozo Hida work on double double
  ///
  ///  dual<float> can look ugly but on architectures as cell for which float
  ///  computation are more than 10 times faster than double 43 bits, can be
  ///  worthy
  //////////////////////////////////////////////////////////////////////////////
  ///  Double-double precision (>= 106-bit significand) floating point
  ///  arithmetic package based on Yozo Hida package
  //////////////////////////////////////////////////////////////////////////////
  template<class T,
	   class ACCURACY = boost::mpl::true_, 
	   class IS_SCALAR  = typename meta::is_scalar<T>::type>
  class dual;
  template<class T,
	   class ACCURACY>
  class dual < T, ACCURACY, boost::mpl::false_> 
  {
    void to_digits(char *s,
		   int &expn,
		   int precision) const;

  };

  //  template < class T, class ACCURACY = boost::mpl::false_>  struct dual_values;

  /// scalar version
  template<class T,
	   class ACCURACY>
  class dual < T, ACCURACY, boost::mpl::true_> 
  {
  public:
    typedef T                                  type;
    typedef typename meta::scalar_of<T>::type  part; 
    typedef ACCURACY                       accuracy;  
    typedef dual<type,accuracy>                self;
    //    typedef dual_values<type>                    dv; 
    typedef self                           floating;
    
  ////////////////////////////////////////////////////////////////////////////
  /// @brief  Normal form constructor.
  ///
  /// This constructor produces an uninitialized dual
  ////////////////////////////////////////////////////////////////////////////
    dual() {}

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destructor - nothing special,  it's a pod
    ////////////////////////////////////////////////////////////////////////////
    ~dual() {}

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  constructor from an other dual.
    ///
    /// constructor from an other dual.
    ///
    /// @param z the dual to be copied
    ////////////////////////////////////////////////////////////////////////////
//      template<class U, class V> dual(const dual<U, V>& z)
//                     : mhi(cast<U,T>::Value(z.hi())),
//                       mlo(cast<U,T>::Value(z.lo()))  {}

    dual(const self& z)
      : mhi(z.hi()),
        mlo(z.lo())  {}

 
    ////////////////////////////////////////////////////////////////////////////
    /// @brief  constructor from two IEEE
    ///
    /// constructor from a  two real
    /// 
    /// @param a the hi part
    /// @param b the lo part  (default 0)
    ////////////////////////////////////////////////////////////////////////////
    explicit dual(const type& a,  const type& b) : mhi(a), mlo(b) {}

    dual(const double& a){
      mhi = static_cast < type > (a); 
      mlo = static_cast < type > (a-static_cast < double > (mhi)); 
      //        std::cout <<  std::setprecision(15) << a << std::endl;
      //        std::cout <<  std::setprecision(7)  << mhi <<  " -- " << mlo <<  std::endl;
    }

    dual(const float& a): mhi(type(a)), mlo(type(0)){}

    explicit dual(const int&a): mhi(a), mlo(0) {}

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  constructor from char*
    ///
    /// constructor from a  two real
    ///
    /// @param s is the string
    ////////////////////////////////////////////////////////////////////////////
		 //    explicit dual(const char * s){ read(s); }; 

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  constructor from std::string
    ///
    /// constructor from a  two real
    ///
    /// @param s is the string
    ////////////////////////////////////////////////////////////////////////////
		 //    explicit dual(const std::string& s){ read(s.c_str()); }
    
    ////////////////////////////////////////////////////////////////////////////
    /// @brief  affectation from an other dual.
    ///
    /// affectation from an other dual.
    ///
    /// @param src the dual to be assigned
    ////////////////////////////////////////////////////////////////////////////
    self& operator=( const self& src)
    {
      if (&src !=  this)
	{
	  mhi = src.hi();
	  mlo = src.lo();
	}
      return *this;
    }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  hi const hi part accessor
    ///
    /// hi hi part accessor.
    ////////////////////////////////////////////////////////////////////////////
     const type& hi() const { return mhi; }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  lo const lo part accessor
    ///
    /// lo lo part accessor.
    ////////////////////////////////////////////////////////////////////////////
    const type& lo() const { return mlo; }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  hi hi part accessor
    ///
    /// hi hi part accessor.
    ////////////////////////////////////////////////////////////////////////////
    type& hi()       { return mhi; }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  lo lo part accessor
    ///
    /// lo lo part accessor.
    ////////////////////////////////////////////////////////////////////////////
    type& lo()       { return mlo; }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  ! true if non 0
    ////////////////////////////////////////////////////////////////////////////
    bool operator!()           const { return (!mhi() && !mlo());       }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  ! logical complement
    ////////////////////////////////////////////////////////////////////////////
    self operator~()           const { return self(~mhi, ~mlo);         }
    
    ////////////////////////////////////////////////////////////////////////////
    /// @brief  - unary minus
    ////////////////////////////////////////////////////////////////////////////
    self operator-()           const { return self(-mhi,-mlo);          }

    bool isnan()    const { return nt2::is_nan(mhi) || nt2::is_nan(mlo); }
    bool isfin()    const { return nt2::is_finite(mhi); }
    bool isinf()    const { return nt2::is_inf(mhi); }
    bool iseqz()    const { return nt2::is_eqz(hi());}
//     bool isone()    const{return (hi() == One<part>() && lo() == Zero<part>()); }
//     bool isgtz()    const{return (hi() > Zero<part>());}
    bool isltz()    const{return nt2::is_ltz(hi());}

    self operator&  (const self& b) const  { return self(mhi & b.mhi, mlo & b.mlo); }
    self operator|  (const self& b) const  { return self(mhi | b.mhi, mlo | b.mlo); }
    self operator^  (const self& b) const  { return self(mhi ^ b.mhi, mlo ^ b.mlo); }
    self operator<< (const int & i) const  { return self(mhi << i, mlo << i);       }
    self operator>> (const int & i) const  { return self(mhi >> i, mlo >> i);       }    
//     self operator+  (const self& b) const  { return add(*this, b);                  }   
//     self operator-  (const self& b) const; 
//     self operator*  (const self& b) const; 
//     self operator/  (const self& b) const  { return div(*this, b);                } 
    bool operator== (const self& b) const  { return (hi() == b.hi() && lo() == b.lo());       }
    bool operator!= (const self& b) const  { return (hi() != b.hi() || lo() != b.lo());}
    bool operator<  (const self& b) const  { return (hi() <  b.hi() || (hi() == b.hi() && lo() <  b.lo()));}
    bool operator>  (const self& b) const  { return (hi() >  b.hi() || (hi() == b.hi() && lo() >  b.lo()));}
    bool operator<= (const self& b) const  { return (hi() <  b.hi() || (hi() == b.hi() && lo() <= b.lo()));}
    bool operator>= (const self& b) const  { return (hi() >  b.hi() || (hi() == b.hi() && lo() >= b.lo()));} 
    bool operator&& (const self& b) const  { return (mhi || mlo) && b; }
    bool operator|| (const self& b) const  { return (mhi || mlo || b); }

//     self operator*  (const type& b) const; 
//     self operator/  (const type& b) const;
    bool operator== (const type& b) const { return (hi() == b && lo() == Zero<part>()); };
    bool operator!= (const type& b) const { return (hi() != b || lo() != Zero<part>());}
    bool operator<  (const type& b) const { return (hi() < b || (hi() == b && lo() < Zero<part>()));       }
    bool operator>  (const type& b) const { return (hi() > b.hi() || (hi() == b.hi() && lo() < b.lo()));   }
    bool operator<= (const type& b) const { return (hi() < b || (hi() == b && lo() <= Zero<part>()));}
    bool operator>= (const type& b) const { return (hi() > b || (hi() == b && lo() >= Zero<part>()));          }
    bool operator&& (const type& b) const { return (mhi || mlo)  && (b.mhi || b.mlo); };
    bool operator|| (const type& b) const { return (mhi || mlo || b.mhi || b.mlo); };

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  - abs
    ////////////////////////////////////////////////////////////////////////////
    self abs()
    {
      if(mhi < 0) {mhi = -mhi;  mlo = -mlo; };
      return *this; 
    }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  self type += 
    ///
    /// @param a value to be added
    ////////////////////////////////////////////////////////////////////////////
    self& operator+=(const type& a)
    {
      type s2;
      type s1 = details::two_sum(hi(), a, s2);
      s2 += lo();
      hi() = details::quick_two_sum(s1, s2, lo());
      return *this;
    }
    
    ////////////////////////////////////////////////////////////////////////////
    /// @brief  self type += 
    ///
    /// @param a value to be added
    ////////////////////////////////////////////////////////////////////////////
    self& operator+=(const self& a)
    {
      type s2, t2;
      type s1 = details::two_sum(hi(), a.hi(), s2);
      s2 += details::two_sum(lo(), a.lo(), t2);
      s1 = details::quick_two_sum(s1, s2, s2);
      s2 += t2;
      hi() = details::quick_two_sum(s1, s2, lo());
      return *this;
    }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  self type -= 
    ///
    /// @param a value to be substracted
    ////////////////////////////////////////////////////////////////////////////
    self& operator-=(const type&a)
    {
      type s2;
      const type s1 = details::two_diff(hi(), a, s2);
      s2 += lo();
      hi() = details::quick_two_sum(s1, s2, lo());
      return *this; 
    }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  self type -= 
    ///
    /// @param a value to be substracted
    ////////////////////////////////////////////////////////////////////////////
    self& operator-=(const self& a)
    {
      type s2, t2;
      type s1 = details::two_diff(hi(), a.hi(), s2);
      s2 += details::two_diff(lo(), a.lo(), t2);
      s1 = details::quick_two_sum(s1, s2, s2);
      s2 += t2;
      hi() = details::quick_two_sum(s1, s2, lo());
      return *this;
    }


    ////////////////////////////////////////////////////////////////////////////
    /// @brief  self type *= 
    ///
    /// @param a value to be multiplicated by
    ////////////////////////////////////////////////////////////////////////////
    self& operator*=(const type& a)
    {
      type p2;
      const type p1 = details::two_prod(hi(), a, p2);
      p2 += lo() * a;
      hi() = details::quick_two_sum(p1, p2, lo());
      return *this;
     }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  self type *= 
    ///
    /// @param a value to be multiplicated by
    ////////////////////////////////////////////////////////////////////////////
    self& operator*=(const self& a)
    {
      type p2;
      const type p1 = details::two_prod(hi(), a.hi(), p2);
      p2 += a.lo() * hi();
      p2 += a.hi() * lo();
      hi() = details::quick_two_sum(p1, p2, lo());
      return *this;
     }
      
    ////////////////////////////////////////////////////////////////////////////
    /// @brief  self type /= 
    ///
    /// @param s value to be divided by
    ////////////////////////////////////////////////////////////////////////////
    self& operator/=(const T& a)
    {
      return *this = *this / self(a);
    }
    
    ////////////////////////////////////////////////////////////////////////////
    /// @brief  self type /= 
    ///
    /// @param s value to be divided by
    ////////////////////////////////////////////////////////////////////////////
    self& operator/=(const self& a)
    {
      return *this = (*this)/ a;
    }
    
    ////////////////////////////////////////////////////////////////////////////
    /// @brief  normalization 
    ///
    /// @param s value to be divided by
    ////////////////////////////////////////////////////////////////////////////
    self& normalize()
    {
      std::cout << " normalize " << hi() <<  "  " << lo() <<  std::endl; 
      if ( nt2::abs(hi())*Eps<type>() <  nt2::abs(lo()) ) mlo = Zero<type>();
      std::cout << " normalize2 " << hi() <<  "  " << lo() <<  std::endl; 
      return *this; 
    }


//     // /////////////////////////////////////////////////////////////////////////
//     // static members
//     ////////////////////////////////////////////////////////////////////////////
    
     static self abs     (const self &a){return (a.hi() < 0) ? -a : a; }
     static self sqr     (const self &a) { return a*a;                        }
//     static self round   (const self &a) { return nint(a); }
//     static self nint    (const self &a); 
//     static self floor   (const self &a);
//     static self ceil    (const self &a);
//     static self aint    (const self &a) { return (a.hi() >= Zero<part>()) ? floor(a) : ceil(a);}
    static type to_type (const self &a) { return a.hi();}
     static int  to_int  (const self &a) { return static_cast<int>(a.hi());}
    static self rec     (const self &a){return One<part>() / a;}
//     static self sqrt    (const self &a); 
//     static self npwr    (const self &a, const int& n); 
//     static self nroot   (const self &a, int n); 
//     static self pow     (const self &a, int n) { return npwr(a, n); }
//     static self pow     (const self &a, const self &b) { return exp(b * log(a)); }
//     static self exp     (const self &a);
//     static self log     (const self &a);
//     static self log10   (const self &a);
//     static self sin     (const self &a) ;  
//     static self cos     (const self &a) ;
//     static void sincos  (const self &a, self &sin_a, self &cos_a) ;
//     static self atan    (const self &a) { return atan2(a, One<type>() ); } //pb de quadrant
//     static self tan     (const self &a) { self s, c;  sincos(a, s, c); return s/c; }
//     static self asin    (const self &a) ;
//     static self acos    (const self &a) ;
//     static self sinh    (const self &a) ;
//     static self cosh    (const self &a) ;
//     static self tanh    (const self &a) ;
//     static void sincosh (const self &a, self &sinh_a, self &cosh_a) ;
//     static self asinh   (const self &a) ;
//     static self acosh   (const self &a) ;
//     static self atanh   (const self &a) ;
//     static self atan2   (const self &y, const self &x); 
    
//     static self rand();
//     static self polyeval(const self *c, int n, const self &x) ;
//     static self polyroot(const self *c, int n, const self &x0, int max_iter, type thresh) ;
//     static self mul_pwr2(const self  &a, double b) { return self (a.hi() * b, a.lo() * b); }
    /* double-double * (2.0 ^ exp) */
    static self ldexp   (const self  &a, const int& exp) { return self (nt2::ldexp(a.hi(), exp), nt2::ldexp(a.lo(), exp)); }
    /* Cast to double. */
    static double to_double(const self &a) { return a.hi();}
    static void error   (const char *msg) { if (msg) { std::cerr << "ERROR " << msg << std::endl; } }
    
    //     private:
    mutable type mhi, mlo;
    static const self& one(){static self z(1, 0);  return z; }
    static const self& zero(){static self z(0, 0);  return z; }
    static const self& nan (){static self z(Nan<type>(),Nan<type>());  return z; }
    static const self& inf (){static self z(Inf<type>(),Zero<type>());  return z; }
//     static self sin_taylor(const self &a) ;
//     static self cos_taylor(const self &a) ;
//     static void sincos_taylor(const self &a, self &sin_a, self &cos_a) ;
    
    int read(const char *s);
    
//     static self div(const self &a, const self &b); 
//     static self mul(const self &a, const self &b); 
//     //     static self div(const self &a, const self &b);
//     static self sub(const self &a, const self &b); 
//     static self add(const self &a, const self &b); 
    static inline void append_expn(std::string &str, int expn)
    {
      int k;
      
      str += (expn < 0 ? '-' : '+');
      expn = nt2::abs(expn);
      
      if (expn >= 100) {
	k = (expn / 100);
	str += '0' + k;
	expn -= 100*k;
      }
      
      k = (expn / 10);
      str += '0' + k;
      expn -= 10*k;
      
      str += '0' + expn;
    }

    std::string to_string(int precision, int width, std::ios_base::fmtflags fmt, 
			    bool showpos, bool uppercase, char fill) const
    {
      std::string s;
      bool fixed = (fmt & std::ios_base::fixed) != 0;
      bool sgn = true;
      int i, e = 0;
      
      if (isnan())
	{
	  s = uppercase ? "NAN" : "nan";
	  sgn = false;
	}
      else
	{
	  if (isltz())
	    s += '-';
	  else if (showpos)
	    s += '+';
	  else
	    sgn = false;
	  
	  if (isinf()) {
	    s += uppercase ? "INF" : "inf";
	  } else if (iseqz()) {
	    /* Zero case */
	    s += '0';
	    if (precision > 0) {
	      s += '.';
	      s.append(precision, '0');
	    }
	  } else {
	    /* Non-zero case */
	    int off = (fixed ? (One<T>() + to_int(nt2::floor(nt2::log10(nt2::abs(hi()))))) : One<T>());
	    int d = precision + off;
	    
	    if (fixed && d <= 0) {
	      s += '0';
	      if (precision > 0) {
		s += '.';
		s.append(precision, '0');
	      }
	    } else {
	      char *t = new char[d+1];
	      int j;
	      
	      //	      to_digits(t, e, d);
	      
	      if (fixed) {
		if (off > 0) {
		  for (i = 0; i < off; i++) s += t[i];
		  if (precision > 0) {
		    s += '.';
		    for (j = 0; j < precision; j++, i++) s += t[i];
		  }
		} else {
		  s += "0.";
		  if (off < 0) s.append(-off, '0');
		  for (i = 0; i < d; i++) s += t[i];
		}
	      } else {
		s += t[0];
		if (precision > 0) s += '.';
		
		for (i = 1; i <= precision; i++)
		  s += t[i];
		
		delete [] t;
	      }
	    }
	  }
	  
	  if (!fixed && !isinf()) {
	    /* Fill in exponent part */
	    s += uppercase ? 'E' : 'e';
	    append_expn(s, e);
	  }
	}
      
      /* Fill in the blanks */
      int len = s.length();
      if (len < width) {
	int delta = width - len;
	if (fmt & std::ios_base::internal) {
	  if (sgn)
	    s.insert(static_cast<std::string::size_type>(1), delta, fill);
	  else
	    s.insert(static_cast<std::string::size_type>(0), delta, fill);
	} else if (fmt & std::ios_base::left) {
	  s.append(delta, fill);
	} else {
	  s.insert(static_cast<std::string::size_type>(0), delta, fill);
	}
      }
      
      return s;
    }

    void to_digits(char *s,
		   int &expn,
		   int precision) const
    {
      digits(*this, s, expn, precision);
    } 
  };
  
}
#include <nt2/sdk/types/details/dual_values.hpp>
//#include <nt2/sdk/types/dual_constants.hpp>
#include <nt2/sdk/types/dual_op.hpp>
#include <nt2/sdk/types/dual_funcs.hpp>
#include <nt2/sdk/types/details/dual_low_level_io.hpp>
#include <nt2/sdk/types/dual_impl.hpp>
#include <nt2/sdk/types/dual_io.hpp>

#endif

// /////////////////////////////////////////////////////////////////////////////
// End of dual_types.hpp
// /////////////////////////////////////////////////////////////////////////////

