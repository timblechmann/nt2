/*******************************************************************************
 *         Copyright 2003-2011 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_TYPES_DUAL_CONSTANTS_HPP_INCLUDED
#define NT2_SDK_TYPES_DUAL_CONSTANTS_HPP_INCLUDED

#include <nt2/sdk/types/dual_limits.hpp>


namespace nt2
{
    template < class T > struct  constant_defs; 
    // /////////////////////////////////////////////////////////////////////////
    // Common mathematical constant. for dual types for float and double
    // /////////////////////////////////////////////////////////////////////////
    template < class T, class A> struct constant_defs<dual<T, A> > 
    {
      typedef dual<T, A> type; 
      // /////////////////////////////////////////////////////////////////////////
      // eps : Floating-point relative accuracy - see also sEps and eps
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Eps()
      {
        typedef typename  result<type>::real_type                             base;
        static const base tmp_ = std::numeric_limits<base>::epsilon();
        return tmp_;
      }

      // /////////////////////////////////////////////////////////////////////////
      // sqrteps : square root of eps
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Sqrteps()
      {
        typedef typename  result<type>::real_type                             base;
        static const base tmp_ = std::sqrt(Eps());
        return tmp_;
      }

      // /////////////////////////////////////////////////////////////////////////
      // Inf : Best infinity approximation for current type
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Inf()
      {
        typedef typename result<type>::real_type                        base;
        static const base tmp_ =std::numeric_limits<base>::infinity();
        return tmp_;
      }

      // /////////////////////////////////////////////////////////////////////////
      // NaN : Not-a-Number representation
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Nan()
      {
        typedef typename result<type>::real_type                        base;
        static const base tmp_ = std::numeric_limits<base>::quiet_NaN();
        return tmp_;
      }

      // /////////////////////////////////////////////////////////////////////////
      // Zero One typewo typehree Four
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Zero()
      {
        typedef typename result<type>::real_type                        base;
        static const base zero_ = static_cast<base>(0);
        return zero_;
      }
      static inline const typename result<type>::real_type& One()
      {
        typedef typename result<type>::real_type                        base;
        static const base one_ = static_cast<base>(1);
        return one_;
      }
      static inline const typename result<type>::real_type& Two()
      {
        typedef typename result<type>::real_type                        base;
        static const base two_ = static_cast<base>(2);
        return two_;
      }
      static inline const typename result<type>::real_type& Three()
      {
        typedef typename result<type>::real_type                        base;
        static const base three_ = static_cast<base>(3);
        return three_;
      }
      static inline const typename result<type>::real_type& Four()
      {
        typedef typename result<type>::real_type                        base;
        static const base four_ = static_cast<base>(4);
        return four_;
      }
      // /////////////////////////////////////////////////////////////////////////
      // Half
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Half()
      {
        typedef typename result<type>::real_type                        base;
        static const base half__ = static_cast<base>(0.5);
        return half__;
      }

      // /////////////////////////////////////////////////////////////////////////
      // pi: Ratio of a circle's circumference to its diameter
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Pi()
      {
        typedef typename result<type>::real_type                        base;
        static const base pi_("3.141592653589793238462643383279502884197"); 
        return pi_;
      }

      // /////////////////////////////////////////////////////////////////////////
      // Two_pi: Ratio of a circle's circumference to its diameter
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Two_pi()
      {
        typedef typename result<type>::real_type                        base;
        static const base tmp_("6.283185307179586476925286766559005768394"); 
        return tmp_;
      }

      // /////////////////////////////////////////////////////////////////////////
      // p/2: Ratio of a circle's circumference to its diameter:2
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Half_pi()
      {
        typedef typename result<type>::real_type                        base;
        static const base half_pi_("1.570796326794896619231321691639751442098"); 
        return half_pi_;
      }

      // /////////////////////////////////////////////////////////////////////////
      // pi/4: Ratio of a circle's circumference to its diameter/4
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Quarter_pi()
      {
        typedef typename result<type>::real_type                        base;
        static const base quarter_pi_(".7853981633974483096156608458198757210492"); 
        return quarter_pi_;
      }

      // /////////////////////////////////////////////////////////////////////////
      // e: base of natural log
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Exp_1()
      {
        typedef typename result<type>::real_type                        base;
        static const base tmp_("2.718281828459045235360287471352662497757"); 
        return tmp_;
      }
      
      // /////////////////////////////////////////////////////////////////////////
      // smallestposval : Smallest non-zero, positive value that can be coded in
      // a given type.
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Smallestposval()
      {
        typedef typename result<type>::real_type                        base;
        typedef std::numeric_limits<base> lim;
        static const base tmp_ = lim::is_integer ? 1 :lim::min();
        return tmp_;
      }

      // /////////////////////////////////////////////////////////////////////////
      // degInrad : pi/180, used in degree to radian conversion
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Deginrad()
      {
        typedef typename result<type>::real_type                        base;
        static const base degInRad_(".17453292519943295769236907684886127e-1");
        return degInRad_;
      }

      // /////////////////////////////////////////////////////////////////////////
      // radInDeg : 180/pi, used in radian to degree conversion
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Radindeg()
      {
        typedef typename result<type>::real_type                        base;
        static const base radInDeg_("57.295779513082320876798154814105170");

        return radInDeg_;
      }

      // /////////////////////////////////////////////////////////////////////////
      // gold : 'Divina Proportione' defined as
      //               ___
      //         1 + \/ 5
      // gold = -----------
      //             2
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Gold()
      {
        typedef typename result<type>::real_type                        base;
        static const base gold_("1.6180339887498948482045868343656381");
        return gold_;
      }

      // /////////////////////////////////////////////////////////////////////////
      // cgold : 'Divina Proportione' complement to 1
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Cgold()
      {
        typedef typename result<type>::real_type                        base;
        static const base cgold_("0.381966011250105151795413165635");
        return cgold_;
      }

      // /////////////////////////////////////////////////////////////////////////
      // sqrt2  : Square root of 2
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Sqrt2()
      {
        typedef typename result<type>::real_type                        base;
        static const base sqrt2_ ("1.4142135623730950488016887242097");
        return sqrt2_;
      }

      // /////////////////////////////////////////////////////////////////////////
      // sqrt2_2  : inverse of sqrt(2)
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Sqrt2_2()
      {
        typedef typename result<type>::real_type                        base;
        static const base sqrt2_2_("0.70710678118654752440084436210484");
        return sqrt2_2_;
      }

      // /////////////////////////////////////////////////////////////////////////
      // ln_2 : Logarithm of 2
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Log_2()
      {
        typedef typename result<type>::real_type                        base;
        static const base log_2_("0.69314718055994530941723212145817657");

        return log_2_;
      }

      // /////////////////////////////////////////////////////////////////////////
      // ln_10 : Logarithm of 10
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Log_10()
      {
        typedef typename result<type>::real_type                        base;
        static const base Log_10_("2.3025850929940456840179914546843642");
        return Log_10_;
      }

      // /////////////////////////////////////////////////////////////////////////
      // ln_2_10 : Logarithm of 2/ Logarithm of 10
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Log_2_10()
      {
        typedef typename result<type>::real_type                        base;
        static const base Log_2_10_(".30102999566398119521373889472449303");
        return Log_2_10_;
      }
      // /////////////////////////////////////////////////////////////////////////
      // valmax : Largest possible value of specified integer type
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Valmax()
      {
        typedef typename result<type>::real_type                        base;
        static const base tmp_ =  std::numeric_limits<type>::max();
        return tmp_;
      }

      // /////////////////////////////////////////////////////////////////////////
      // realmax : Largest positive floating-point number as in Matlab
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Realmax()
      {
        typedef typename result<type>::real_type                        base;
        static const base tmp_ =  std::numeric_limits<base>::max();
        return tmp_;
      }

      // /////////////////////////////////////////////////////////////////////////
      // valmin : Smallest possible value of specified integer type, which can be
      //          negative.
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Valmin()
      {
        typedef typename result<type>::real_type                        base;
        static const base valmin_ = is_unsigned<base>::type::value ? Zero():-Valmax() ;
        return valmin_;
      }


      // /////////////////////////////////////////////////////////////////////////
      // realmin : Smallest positive floating-point number as in Matlab
      // /////////////////////////////////////////////////////////////////////////
      static inline const typename result<type>::real_type& Realmin()
      {
        typedef typename result<type>::real_type                        base;
        typedef std::numeric_limits<type> lim;
        static const base tmp_ = lim::is_integer ? 1 : lim::min();
        return tmp_;
      }

      static inline const typename result<type>::real_type Safemax(const type& t)
      {
        typedef typename result<type>::real_type                        base;
        static const base Num = std::sqrt(Realmax());
        return Num/t;
      }
      static inline const typename result<type>::real_type Safemin(const type& t)
      {
        typedef typename result<type>::real_type                        base;
        static const base Fact = std::sqrt(Realmin());
        return Fact*t;
      }

      static inline const int& Nbexponentbits(){
        static const int tmp = float_internals<type>::NbExponentBits();
        return tmp ;
      }
      static inline const int& Nbmantissabits(){
        static const int tmp = float_internals<type>::NbMantissaBits() ;
        return tmp;
      }
      static inline const int& Maxexponent(){
        static const int tmp = float_internals<type>::MaxExponent();
        return tmp;
      }

    };

}


#endif

// /////////////////////////////////////////////////////////////////////////////
// End of dual_constants.hpp
// /////////////////////////////////////////////////////////////////////////////
