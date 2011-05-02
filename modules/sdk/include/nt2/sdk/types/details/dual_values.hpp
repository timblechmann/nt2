/*******************************************************************************
 *         Copyright 2003-2011 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_TYPES_DETAILS_DUAL_VALUES_HPP_INCLUDED
#define NT2_SDK_TYPES_DETAILS_DUAL_VALUES_HPP_INCLUDED



namespace nt2
{
  namespace details
  {
    
    template < class T >  struct dual_values;
    
    template <>  struct dual_values < double > 
    {
      typedef dual < double >   dtype; 
      static const int n_inv_fact = 15;
      static dtype _pi16()
      {
        static dtype tmp(1.963495408493620697e-01, 7.654042494670957545e-18);
        return tmp;
      }
      
      static const dtype* inv_fact(){
        static dtype s_inv_fact[n_inv_fact] = {
          dtype( 1.66666666666666657e-01,  9.25185853854297066e-18),
          dtype( 4.16666666666666644e-02,  2.31296463463574266e-18),
          dtype( 8.33333333333333322e-03,  1.15648231731787138e-19),
          dtype( 1.38888888888888894e-03, -5.30054395437357706e-20),
          dtype( 1.98412698412698413e-04,  1.72095582934207053e-22),
          dtype( 2.48015873015873016e-05,  2.15119478667758816e-23),
          dtype( 2.75573192239858925e-06, -1.85839327404647208e-22),
          dtype( 2.75573192239858883e-07,  2.37677146222502973e-23),
          dtype( 2.50521083854417202e-08, -1.44881407093591197e-24),
          dtype( 2.08767569878681002e-09, -1.20734505911325997e-25),
        }; 
        return &s_inv_fact[0]; 
      }
      /* Table of sin(k * pi/16) and cos(k * pi/16). */
      static const dtype* sin_table(){
        static dtype s_sin_table [] = {
          dual<double>(1.950903220161282758e-01, -7.991079068461731263e-18), 
          dual<double>(3.826834323650897818e-01, -1.005077269646158761e-17), 
          dual<double>(5.555702330196021776e-01,  4.709410940561676821e-17),
          dual<double>(7.071067811865475727e-01, -4.833646656726456726e-17)
        };
        return &s_sin_table[0]; 
      };
      
      static const dtype* cos_table(){
        static dtype s_cos_table [] = {
          dual<double>(9.807852804032304306e-01, 1.854693999782500573e-17),
          dual<double>(9.238795325112867385e-01, 1.764504708433667706e-17),
          dual<double>(8.314696123025452357e-01, 1.407385698472802389e-18),
          dual<double>(7.071067811865475727e-01, -4.833646656726456726e-17)
        };
      }
      
    }; 

    template <>  struct dual_values < float > 
    {
      typedef dual<float> dtype; 
      static const int n_inv_fact =  15; 
      static dtype _pi16()
      {
        static dtype tmp(1.963495408493620697e-01, 7.654042494670957545e-18);
        return tmp;
      }
      static const dtype* inv_fact(){
        static dtype s_inv_fact[n_inv_fact] = {
          dtype( 1.66666666666666657e-01,  9.25185853854297066e-18),
          dtype( 4.16666666666666644e-02,  2.31296463463574266e-18),
          dtype( 8.33333333333333322e-03,  1.15648231731787138e-19),
          dtype( 1.38888888888888894e-03, -5.30054395437357706e-20),
          dtype( 1.98412698412698413e-04,  1.72095582934207053e-22),
          dtype( 2.48015873015873016e-05,  2.15119478667758816e-23),
          dtype( 2.75573192239858925e-06, -1.85839327404647208e-22),
          dtype( 2.75573192239858883e-07,  2.37677146222502973e-23),
          dtype( 2.50521083854417202e-08, -1.44881407093591197e-24),
          dtype( 2.08767569878681002e-09, -1.20734505911325997e-25),
        }; 
        return &s_inv_fact[0]; 
      }
    };
    
    
  }
  
}


#endif

// /////////////////////////////////////////////////////////////////////////////
// End of dual_values.hpp
// /////////////////////////////////////////////////////////////////////////////
