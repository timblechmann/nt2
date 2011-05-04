##############################################################################
###   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
###   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
###
###          Distributed under the Boost Software License, Version 1.0
###                 See accompanying file LICENSE.txt or copy at
###                     http://www.boost.org/LICENSE_1_0.txt
##############################################################################

SET( SOURCES
  plus.cpp
  two_sqr.cpp
  two_split.cpp
  two_prod.cpp
  two_sum.cpp
  two_diff.cpp
  quick_two_sum.cpp
  quick_two_diff.cpp
# List of simd test files for toolbox dual
   )

##****************************************************************************
# For each filename
##****************************************************************************
FOREACH( EXAMPLE ${SOURCES})
  STRING(REGEX REPLACE ".cpp" "" EXAMPLE ${EXAMPLE})
  nt2_module_add_unit(dual.simd.${EXAMPLE}.unit ${EXAMPLE}.cpp)
ENDFOREACH()
