/*******************************************************************************
 *         Copyright 2003-2011 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_TYPES_DUAL_OP_HPP_INCLUDED
#define NT2_SDK_TYPES_DUAL_OP_HPP_INCLUDED



namespace nt2
{
  template<class T, class A, class I>  inline dual<T,A,I> operator+(const dual<T,A,I> & a, const T & b)
  {
    T s1, s2;
    s1 = details::two_sum(a.hi(), b, s2);
    s2 += a.lo();
    s1 = details::quick_two_sum(s1, s2, s2);
    return dual<T,A,I>(s1, s2);
  }
  
  template<class T, class A, class I> static inline dual<T,A,I> operator+(const T & a, const dual<T,A,I> &b){return (b + a);}
  template<class A, class I>  static inline dual<float, A,I> operator+(const double& a,  const dual<float, A,I> &b){return (b + dual<float, A,I>(a));}                   
  template<class A, class I>  static inline dual<float, A,I> operator+(const dual<float, A,I> &b, const double& a){return (b + dual<float, A,I>(a));}
  
  template<class T, class A, class I>  inline dual<T,A,I> operator-(const dual<T,A,I> & a, const T & b)
  {
    T s1, s2;
    s1 = details::two_diff(a.hi(), b, s2);
    s2 += a.lo();
    s1 = details::quick_two_sum(s1, s2, s2);
    return dual<T,A,I>(s1, s2);
  }

  template<class T, class A, class I> static inline dual<T,A,I> operator-(const T & a, const dual<T,A,I> &b)
  {
    T s1, s2;
    s1 = details::two_diff(a, b.hi(), s2);
    s2 -= b.lo();
    s1 = details::quick_two_sum(s1, s2, s2);
    return dual<T,A,I>(s1, s2);
  }
  template<class A, class I>  static inline dual<float,A,I> operator-(const double& a,  const dual<float,A,I> &b){return (dual<float,A,I>(a)-b);}                   
  template<class A, class I>  static inline dual<float,A,I> operator-(const dual<float,A,I> &b, const double& a){return (b-dual<float,A,I>(a));}
  

  template<class T, class A, class I> inline dual<T,A,I> operator-(const dual<T,A,I> &a, const dual<T,A,I> &b)  
  {
    T s1, s2, t1, t2;
    s1 = details::two_diff(a.hi(), b.hi(), s2);
    t1 = details::two_diff(a.lo(), b.lo(), t2);
    s2 += t1;
    s1 = details::quick_two_sum(s1, s2, s2);
    s2 += t2;
    s1 = details::quick_two_sum(s1, s2, s2);
    return dual<T,A,I>(s1, s2);
  }

  template<class T, class A, class I>  inline dual<T,A,I> operator*(const dual<T,A,I> &a, const T & b)
  {
    T p1, p2;
    
    p1 = details::two_prod(a.hi(), b, p2);
    p2 += (a.lo() * b);
    p1 = details::quick_two_sum(p1, p2, p2);
    return dual<T,A,I>(p1, p2);
  }

  template<class T, class A, class I> static inline dual<T,A,I> operator*(const T & a, const dual<T,A,I> &b){  return (b * a);}
  template<class A, class I>  static inline dual<float,A,I> operator*(const double& a,  const dual<float,A,I> &b){return (b *dual<float,A,I>(a));}                   
  template<class A, class I>  static inline dual<float,A,I> operator*(const dual<float,A,I> &b, const double& a){return (b + dual<float,A,I>(a));}
  

  template<class T, class A, class I> inline dual<T,A,I> operator*(const dual<T,A,I> &a, const dual<T,A,I> &b)
  {
    T p2;
    T p1 = details::two_prod(a.hi(), b.hi(), p2);
    p2 += (a.hi() * b.lo() + a.lo() * b.hi());
    p1 = details::quick_two_sum(p1, p2, p2);
    p2 = a.lo()*b.lo();
    p1 = details::quick_two_sum(p1, p2, p2);
    return dual<T,A,I>(p1, p2);
  }
  
 template<class T, class A, class I> inline dual<T,A,I> operator/(const dual<T,A,I>& a, const T & b)
 {
   T q1, q2;
   T p1, p2;
   T s, e;
   dual<T,A,I> r;
   
   q1 = a.hi() / b;   /* approximate quotient. */
   
   /* Compute  this - q1 * d */
   p1 = details::two_prod(q1, b, p2);
   s = details::two_diff(a.hi(), p1, e);
   e += a.lo();
   e -= p2;
   
   /* get next approximation. */
   q2 = (s + e) / b;
   
   /* renormalize */
   r.hi() = details::quick_two_sum(q1, q2, r.lo());
   
   return r;   
 }

  template<class T, class A, class I> static inline dual<T,A,I> operator/(const T & a, const dual<T,A,I> &b){return dual<T,A,I>(a) / b;};
  template<class A, class I>  static inline dual<float,A,I> operator/(const double& a,  const dual<float,A,I> &b){return (dual<float,A,I>(a)/b);}                   
  template<class A, class I>  static inline dual<float,A,I> operator/(const dual<float,A,I> &b, const double& a){return (b /dual<float,A,I>(a));}

  namespace details
  {
    template<class T, class A, class I> struct accuracy_choice;
    template<class T, class I>          struct accuracy_choice < T, boost::mpl::true_, I>
    {
      typedef boost::mpl::true_ A; 
      typedef dual<T,A,I>     self; 
      
      static inline self inner_div(const self &a, const self &b)
      {
	typedef T                   type; 
	type q1, q2, q3;
	self r;
	q1 = a.hi() / b.hi();  /* approximate quotient */
	r = a-b*q1;
	q2 = r.hi() / b.hi();
	r -= q2*b;
	q3 = r.hi() / b.hi();
	q1 = details::quick_two_sum(q1, q2, q2);
	r = self(q1, q2)+ q3;
	return r; 
      }
    };
    
    template<class T, class I> struct accuracy_choice < T, boost::mpl::false_, I>
    {
      typedef boost::mpl::false_ A; 
      typedef dual<T,A,I>     self; 
      static inline self inner_div(const self &a, const self &b)
      {
	typedef T                   type; 
	typedef dual<type, A>       self; 
	type s1, s2;
	type q1, q2;
	self r;
	q1 = a.hi() / b.hi();  /* approximate quotient */
	/* compute  this - q1 * dd */
	r = b * q1;
	s1 = details::two_diff(a.hi(), r.hi(), s2);
	s2 -= r.lo();
	s2 += a.lo();
	/* get next approximation */
	q2 = (s1 + s2) / b.hi();
	/* renormalize */
	r.hi() = details::quick_two_sum(q1, q2, r.lo());
	return r;
      }
    }; 
  }    
  template<class T, class A, class I> inline dual<T,A,I> operator/(const dual<T,A,I> &a, const dual<T,A,I> &b)
  {
    return details::accuracy_choice<T, A, I>::inner_div(a, b);
  }
  
  
  

  //  template<class T, class A, class I> inline dual<T,A,I> operator/(const dual<T,A,I> &b){ return dual<T,A,I>::accurate_div(a, b); }

//   /*********** Equality Comparisons ************/

  
  /* T == T-T */
  template<class T, class A, class I> static inline bool operator==(const T& a, const dual<T,A,I> &b) {
    return (a == b.hi() && b.lo() == 0.0);
  }
  template<class A, class I>  static inline bool operator == (const double& a,  const dual<float,A,I> &b){return (dual<float,A,I>(a) == b);}                   
  template<class A, class I>  static inline bool operator == (const dual<float,A,I> &b, const double& a){return (b ==  dual<float,A,I>(a));}
  
  
  /*********** Greater-Than Comparisons ************/

  /* T > T-T */
  template<class T, class A, class I> static inline bool operator>(const T& a, const dual<T,A,I> &b) {
    return (a > b.hi() || (a == b.hi() && b.lo() < 0.0));
  }
  template<class A, class I>  static inline bool operator >  (const double& a,  const dual<float,A,I> &b){return (dual<float,A,I>(a) >  b);}                   
  template<class A, class I>  static inline bool operator >  (const dual<float,A,I> &b, const double& a){return (b >   dual<float,A,I>(a));}
  
  /*********** Less-Than Comparisons ************/

  
  /* T < T-T */
  template<class T, class A, class I> static inline bool operator<(const T& a, const dual<T,A,I> &b) {
    return (a < b.hi() || (a == b.hi() && b.lo() > 0.0));
  }
  template<class A, class I>  static inline bool operator <   (const double& a,  const dual<float,A,I> &b){return (dual<float,A,I>(a) <   b);}                   
  template<class A, class I>  static inline bool operator <   (const dual<float,A,I> &b, const double& a){return (b <    dual<float,A,I>(a));}
  
  /*********** Greater-Than-Or-Equal-To Comparisons ************/

  /* T >= T-T */
  template<class T, class A, class I> static inline bool operator>=(const T& a, const dual<T,A,I> &b) {
    return (b <= a);
  }
  template<class A, class I>  static inline bool operator >=  (const double& a,  const dual<float,A,I> &b){return (dual<float,A,I>(a) >=  b);}
  template<class A, class I>  static inline bool operator >=  (const dual<float,A,I> &b, const double& a){return (b >=   dual<float,A,I>(a));}
 
  /*********** Less-Than-Or-Equal-To Comparisons ************/
 
  
  /* T <= T-T */
  template<class T, class A, class I> static inline bool operator<=(const T& a, const dual<T,A,I> &b) {
    return (b >= a);
  }
  template<class A, class I>  static inline bool operator <=   (const double& a,  const dual<float,A,I> &b){return (dual<float,A,I>(a) <=   b);}                   
  template<class A, class I>  static inline bool operator <=   (const dual<float,A,I> &b, const double& a){return (b <=    dual<float,A,I>(a));}
  
  /*********** Not-Equal-To Comparisons ************/
  
  /* T != T-T */
  template<class T, class A, class I> static inline bool operator!=(const T& a, const dual<T,A,I> &b) {
    return (a != b.hi() || b.lo() != 0.0);
  }
  template<class A, class I>  static inline bool operator !=  (const double& a,  const dual<float,A,I> &b){return (dual<float,A,I>(a) !=  b);}                   
  template<class A, class I>  static inline bool operator !=  (const dual<float,A,I> &b, const double& a){return (b !=   dual<float,A,I>(a));}
  
}


#endif

// /////////////////////////////////////////////////////////////////////////////
// End of dual_op.hpp
// /////////////////////////////////////////////////////////////////////////////
