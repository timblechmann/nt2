/*******************************************************************************
 *         Copyright 2003-2011 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_TOOLBOX_DD_REALS_SPECIFIC_DD_REALS_TYPES_HPP_INCLUDED
#define NT2_TOOLBOX_DD_REALS_SPECIFIC_DD_REALS_TYPES_HPP_INCLUDED
#include <nt2/toolbox/dd_reals/function/two_sum.hpp>
#include <nt2/toolbox/dd_reals/function/quick_two_sum.hpp>
#include <nt2/toolbox/dd_reals/function/two_diff.hpp>
#include <nt2/toolbox/dd_reals/function/two_prod.hpp>

// #include <string>
// #include <nt2/sdk/meta/is_scalar.hpp>
// #include <nt2/include/functions/is_inf.hpp>
// #include <nt2/include/functions/is_finite.hpp>
// #include <nt2/include/functions/is_nan.hpp>
// #include <nt2/include/functions/is_eqz.hpp>
// #include <nt2/include/functions/is_ltz.hpp>
// #include <nt2/include/functions/ldexp.hpp>
// #include <nt2/include/functions/floor.hpp>
// #include <nt2/include/functions/log10.hpp>

// #include <nt2/sdk/types/details/dd_reals_low_level.hpp>
namespace bf = boost::fusion;

namespace nt2
{
  //////////////////////////////////////////////////////////////////////////////
  /// @class dd_reals
  ///
  ///  A dd_reals number is an unevaluated sum of two numbers of type T
  ///  T being IEEE float or double precision numbers, able to handle 
  ///  at least 43 bits (for floats) and 106 bits of significand (for double)
  ///  but with the same exponent precision.
  ///
  ///  the package is based on Yozo Hida work on double double
  ///
  ///  dd_reals<float> can look ugly but on architectures as cell for which float
  ///  computation are more than 10 times faster than double 43 bits, can be
  ///  worthy
  //////////////////////////////////////////////////////////////////////////////
  ///  Double-double precision (>= 106-bit significand) floating point
  ///  arithmetic package based on Yozo Hida package
  //////////////////////////////////////////////////////////////////////////////

  /// scalar version
  template<class T >
  class dd_reals
  {
  public:
    typedef T                                  type;
    typedef typename meta::scalar_of<T>::type  part; 
    typedef dd_reals<type>                         self;
    typedef self                           floating;
    typedef boost::fusion::tuple<T,T>    pair;
    typedef meta::dd_reals_<typename meta::hierarchy_of<T>::type> nt2_hierarchy_tag;

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  Normal form constructor.
    ///
    /// This constructor produces an uninitialized dd_reals
    ////////////////////////////////////////////////////////////////////////////
    dd_reals() {}

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destructor - nothing special
    ////////////////////////////////////////////////////////////////////////////
    ~dd_reals() {}

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  constructor from an other dd_reals.
    ///
    /// constructor from an other dd_reals.
    ///
    /// @param z the dd_reals to be copied
    ////////////////////////////////////////////////////////////////////////////
    dd_reals(const self& z)
      : mhilo(z.mhilo) {}

    dd_reals(const pair& z)
      : mhilo(z) {}

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  constructor from two IEEE
    ///
    /// constructor from a  two real
    /// 
    /// @param a the hi part
    /// @param b the lo part  (default 0)
    ////////////////////////////////////////////////////////////////////////////
    explicit dd_reals(const type& a,  const type& b) : mhilo(boost::fusion::make_tuple(a, b)) {}
    explicit dd_reals(const type& a) : mhilo(boost::fusion::make_tuple(a, Zero<type>())) {}

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  affectation from an other dd_reals.
    ///
    /// affectation from an other dd_reals.
    ///
    /// @param src the dd_reals to be assigned
    ////////////////////////////////////////////////////////////////////////////
    self& operator=( const self& src)
    {
      if (&src !=  this)
	{
	  mhilo = src.mhilo;
	}
      return *this;
    }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  hi const hi part accessor
    ///
    /// hi hi part accessor.
    ////////////////////////////////////////////////////////////////////////////
    const type& hi() const { return boost::fusion::get<0>(mhilo); }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  lo const lo part accessor
    ///
    /// lo lo part accessor.
    ////////////////////////////////////////////////////////////////////////////
    const type& lo() const { return boost::fusion::get<1>(mhilo); }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  hi hi part accessor
    ///
    /// hi hi part accessor.
    ////////////////////////////////////////////////////////////////////////////
    type& hi()       { return boost::fusion::get<0>(mhilo); }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  lo lo part accessor
    ///
    /// lo lo part accessor.
    ////////////////////////////////////////////////////////////////////////////
    type& lo()       { return boost::fusion::get<1>(mhilo); }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  hilo const pair accessor
    ///
    /// hilo accessor.
    ////////////////////////////////////////////////////////////////////////////
    const pair& hilo() const { return mhilo; }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  hi hi part accessor
    ///
    /// hilo accessor.
    ////////////////////////////////////////////////////////////////////////////
    pair& hilo()       { return mhilo; }

    void print() const
    {
      std::cout << "(" << hi() << ", " << lo() << ")" << std::endl;
    }
    void print(const char* m) const
    {
      std::cout << m << " = (" << hi() << ", " << lo() << ")" << std::endl;
    }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  self type += 
    ///
    /// @param a value to be added
    ////////////////////////////////////////////////////////////////////////////
    self& operator+=(const type& a)
    {
      pair s = two_sum(hi(), a);
      bf::get<1>(s) += lo();
      hilo() = quick_two_sum(bf::get<0>(s), bf::get<1>(s));
      return *this;
    }
    
    ////////////////////////////////////////////////////////////////////////////
    /// @brief  self type += 
    ///
    /// @param a value to be added
    ////////////////////////////////////////////////////////////////////////////
    self& operator+=(const self& a)
    {
      pair s = two_sum(hi(), a.hi());
      pair t = two_sum(lo(), a.lo());
      bf::get<1>(s) += bf::get<0>(t); 
      s = quick_two_sum(bf::get<0>(s), bf::get<1>(s));
      bf::get<1>(s) += bf::get<1>(t);
      hilo() = quick_two_sum(bf::get<0>(s), bf::get<1>(s));
      return *this;
    }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  self type -= 
    ///
    /// @param a value to be substracted
    ////////////////////////////////////////////////////////////////////////////
    self& operator-=(const type&a)
    {
      pair s = two_diff(hi(), a);
      bf::get<1>(s) += lo();
      hilo() = quick_two_sum(bf::get<0>(s), bf::get<1>(s));
      return *this; 
    }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  self type -= 
    ///
    /// @param a value to be substracted
    ////////////////////////////////////////////////////////////////////////////
    self& operator-=(const self& a)
    {
      pair s = two_diff(hi(), a.hi());
      pair t = two_diff(lo(), a.lo());
      bf::get<1>(s) += bf::get<0>(t); 
      s = quick_two_sum(bf::get<0>(s), bf::get<1>(s));
      bf::get<1>(s) += bf::get<1>(t);
      hilo() = quick_two_sum(bf::get<0>(s), bf::get<1>(s));
      return *this;
    }


    ////////////////////////////////////////////////////////////////////////////
    /// @brief  self type *= 
    ///
    /// @param a value to be multiplicated by
    ////////////////////////////////////////////////////////////////////////////
    self& operator*=(const type& a)
    {
      pair p = two_prod(hi(), a);
       bf::get<1>(p) += lo()*a;
      hilo() = quick_two_sum(bf::get<0>(p), bf::get<1>(p));
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
      pair p = two_prod(hi(), a.hi());
      bf::get<1>(p) += a.lo() * hi();
      bf::get<1>(p) += a.hi() * lo();
      bf::get<1>(p) += a.lo() * lo();
      hilo() = quick_two_sum(bf::get<0>(p), bf::get<1>(p));
      return *this;
     }
    
    ////////////////////////////////////////////////////////////////////////////
    /// @brief  self type / 
    ///
    /// @param b value to be divided by
    ////////////////////////////////////////////////////////////////////////////
    self div(const self& b)const; 
    self div(const type& b)const; 
      
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
    
  private:
    mutable pair mhilo; //perhaps normalization capability is not useful
    //    int read(const char *s);
    

  };
  template <int I, class T> const T& get(const dd_reals<T> & d){return bf::get<I>(d.hilo()); }
  template <int I, class T>       T& get(      dd_reals<T> & d){return bf::get<I>(d.hilo()); }
  
}

#include <nt2/toolbox/dd_reals/specific/simd_dd_reals_types.hpp>
#include <nt2/toolbox/dd_reals/include/plus.hpp>
#include <nt2/toolbox/dd_reals/include/minus.hpp>
#include <nt2/toolbox/dd_reals/include/multiplies.hpp>

namespace nt2
{
  template < class T> 
  dd_reals<T> inline dd_reals<T>::div(const dd_reals<T>& b) const
  {
    type q1, q2, q3;
    self r = *this;
    q1 = hi() / b.hi();  /* approximate quotient */
    r -= b*q1;
    q2 = r.hi() / b.hi();
    r -= q2*b;
    q3 = r.hi() / b.hi();
    r = self(quick_two_sum(q1, q2))+ q3;
    return r; 
  } 
  template < class T> 
  dd_reals<T> inline dd_reals<T>::div(const typename dd_reals<T>::type & b) const
  {
    type q1 = hi() / b;  /* approximate quotient */
    pair p =  two_prod(q1, b);
    pair s =  two_diff(hi(), bf::get<0>(p));
    bf::get<1>(s) += lo();
    bf::get<1>(s) -= bf::get<1>(p);
    type q2 = (bf::get<0>(s)+bf::get<1>(s))/b; 
    return self(quick_two_sum(q1, q2)); 
  }

}

// #include <nt2/sdk/types/details/dd_reals_values.hpp>
// //#include <nt2/sdk/types/dd_reals_constants.hpp>
// #include <nt2/sdk/types/dd_reals_op.hpp>
// #include <nt2/sdk/types/dd_reals_funcs.hpp>
// #include <nt2/sdk/types/details/dd_reals_low_level_io.hpp>
// #include <nt2/sdk/types/dd_reals_impl.hpp>
// #include <nt2/sdk/types/dd_reals_io.hpp>



#endif

// /////////////////////////////////////////////////////////////////////////////
// End of dd_reals_types.hpp
// /////////////////////////////////////////////////////////////////////////////
