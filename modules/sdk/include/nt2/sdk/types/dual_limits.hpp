/*******************************************************************************
 *         Copyright 2003-2011 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_TYPES_DUAL_LIMITS_HPP_INCLUDED
#define NT2_SDK_TYPES_DUAL_LIMITS_HPP_INCLUDED

// /////////////////////////////////////////////////////////////////////////////
//  Standard limits conditions for dual<float> and dual<double>    
// /////////////////////////////////////////////////////////////////////////////
namespace std {
  template<class A>
  struct numeric_limits<nt2::dual<double, A> > 
  {
    typedef double                     base;
    typedef std::numeric_limits<base>  lims; 
    typedef nt2::dual<base, A>           dd; 
    static const bool is_specialized = true;
    
    static dd min() throw() { return dd(lims::min(), base(0)); }
    static dd max() throw() { return dd(lims::max(), base(0)); }
    static const int digits = 104;
    static const int digits10 = 31;
    static const bool is_signed = true;
    static const bool is_integer = false;
    static const bool is_exact = false;
    static const int radix = __FLT_RADIX__;
    static dd epsilon() throw()  { return dd(4.93038065763132e-32, base(0)); }// 2^-104
    static dd round_error() throw() { return dd(base(0.5), base(0)); }
    
    static const int min_exponent = lims::min_exponent;
    static const int min_exponent10 = lims::min_exponent10; 
    static const int max_exponent = lims::max_exponent;
    static const int max_exponent10 = lims::max_exponent10;
    
    static const bool has_infinity = lims::has_infinity;
    static const bool has_quiet_NaN = lims::has_quiet_NaN;
    static const bool has_signaling_NaN = has_quiet_NaN;
    static const float_denorm_style has_denorm  = lims::has_denorm; 
    static const bool has_denorm_loss = lims::has_denorm_loss; 
    
    static dd infinity() throw()      { return dd(lims::infinity(), lims::infinity()); }
    static dd quiet_NaN() throw()     { return dd(lims::quiet_NaN(), lims::quiet_NaN()); }
    static dd signaling_NaN() throw() { return dd(__builtin_nans (""), base(0)); }
    static dd denorm_min() throw()    { return dd(2.0041683600089728e-292, base(0)); }// = 2^(-1022 + 53)
    
    static const bool is_iec559  = has_infinity && has_quiet_NaN && has_denorm == denorm_present;
    static const bool is_bounded = true;
    static const bool is_modulo = false;
    
    static const bool traps = lims::traps; 
    static const bool tinyness_before = lims::tinyness_before; 
    static const float_round_style round_style = lims::round_style; 
  };
  
  template<class A>
  struct numeric_limits<nt2::dual<float, A> > 
  {
    typedef float                      base; 
    typedef std::numeric_limits<base>  lims; 
    typedef nt2::dual<base, A>           df; 
    static const bool is_specialized = true;
    
    static df min() throw() { return df(lims::min(), base(0)); }
    static df max() throw() { return df(lims::max(), base(0)); }
    
    static const int digits = 44;
    static const int digits10 = 14;
    static const bool is_signed = true;
    static const bool is_integer = false;
    static const bool is_exact = false;
    static const int radix = __FLT_RADIX__;
    static df epsilon() throw()
    { return df(1.136868377216160e-13f, 0.0f); }//2^-43
    static df round_error() throw() { return df(0.5f, 0.0f); }
    
    static const int min_exponent = lims::min_exponent;
    static const int min_exponent10 = lims::min_exponent10; 
    static const int max_exponent = lims::max_exponent;
    static const int max_exponent10 = lims::max_exponent10;
    
    static const bool has_infinity = lims::has_infinity;
    static const bool has_quiet_NaN = lims::has_quiet_NaN;
    static const bool has_signaling_NaN = has_quiet_NaN;
    static const float_denorm_style has_denorm  = lims::has_denorm; 
    static const bool has_denorm_loss = lims::has_denorm_loss; 
    
    static df infinity() throw()      { return df(lims::infinity(), lims::infinity()); }
    static df quiet_NaN() throw()     { return df(lims::quiet_NaN(), lims::quiet_NaN()); }
    static df signaling_NaN() throw() { return df(__builtin_nans (""), base(0)); }
    static df denorm_min() throw()    { return df(4.135903062765138e-25f, 0.0f); }// = 2^(-126 + 45)
    
    static const bool is_iec559  = has_infinity && has_quiet_NaN && has_denorm == denorm_present;
    static const bool is_bounded = true;
    static const bool is_modulo = false;
    
    static const bool traps = lims::traps; 
    static const bool tinyness_before = lims::tinyness_before; 
    static const float_round_style round_style = lims::round_style; 
  };
  
  
  
#endif
  
  // /////////////////////////////////////////////////////////////////////////////
  // End of dual_limits.hpp
  // /////////////////////////////////////////////////////////////////////////////
  
