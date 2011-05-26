/*******************************************************************************
 *         Copyright 2003-2011 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_TOOLBOX_DUAL_SPECIFIC_SIMD_DUAL_TYPES_HPP_INCLUDED
#define NT2_TOOLBOX_DUAL_SPECIFIC_SIMD_DUAL_TYPES_HPP_INCLUDED



namespace nt2
{
  namespace simd
  {
    template<class T,  class X>
    struct native< nt2::dual<T>, X > 
    {
    public:
      typedef typename simd::native<T,X>                                       vtype;
      typedef T                                                                 type;
      typedef type                                                              part; 
      typedef simd::native<dual<T>,X>                                           self;
      typedef typename boost::fusion::tuple<vtype, vtype>                       pair;
      typedef meta::dual_<typename meta::hierarchy_of<type>::type> nt2_hierarchy_tag;
      
      
    ////////////////////////////////////////////////////////////////////////////
    /// @brief  Normal form constructor.
    ///
    /// This constructor produces an uninitialized dual
    ////////////////////////////////////////////////////////////////////////////
    native() {}

    ////////////////////////////////////////////////////////////////////////////
    /// @brief Destructor - nothing special
    ////////////////////////////////////////////////////////////////////////////
    ~native() {}

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  constructor from an other dual.
    ///
    /// constructor from an other dual.
    ///
    /// @param z the dual to be copied
    ////////////////////////////////////////////////////////////////////////////
    native(const self& z)
      : mhilo(z.mhilo) {}

    native(const pair& z)
      : mhilo(z) {}

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  constructor from two IEEE
    ///
    /// constructor from a  two real
    /// 
    /// @param a the hi part
    /// @param b the lo part  (default 0)
    ////////////////////////////////////////////////////////////////////////////
    native(const vtype& a,  const vtype& b) : mhilo(boost::fusion::make_tuple(a, b)) {}
    native(const vtype& a) : mhilo(boost::fusion::make_tuple(a, Zero<vtype>())) {}

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
	  mhilo = src.mhilo;
	}
      return *this;
    }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  hi const hi part accessor
    ///
    /// hi hi part accessor.
    ////////////////////////////////////////////////////////////////////////////
    const vtype& hi() const { return boost::fusion::get<0>(mhilo); }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  lo const lo part accessor
    ///
    /// lo lo part accessor.
    ////////////////////////////////////////////////////////////////////////////
    const vtype& lo() const { return boost::fusion::get<1>(mhilo); }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  hi hi part accessor
    ///
    /// hi hi part accessor.
    ////////////////////////////////////////////////////////////////////////////
    vtype& hi()       { return boost::fusion::get<0>(mhilo); }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  lo lo part accessor
    ///
    /// lo lo part accessor.
    ////////////////////////////////////////////////////////////////////////////
    vtype& lo()       { return boost::fusion::get<1>(mhilo); }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  hilo const pair accessor
    ///
    /// hilo accessor.
    ////////////////////////////////////////////////////////////////////////////
    const pair& hilo() const { return mhilo; }

    ////////////////////////////////////////////////////////////////////////////
    /// @brief  hilo part accessor
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
    self& operator+=(const vtype& a)
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
    self& operator-=(const vtype&a)
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
    self& operator*=(const vtype& a)
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
    self div(const vtype& b)const; 
      
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
  
    }; 
  }
}

#endif

// /////////////////////////////////////////////////////////////////////////////
// End of simd_dual_types.hpp
// /////////////////////////////////////////////////////////////////////////////
