
################################################################################
###   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
###   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
###
###          Distributed under the Boost Software License, Version 1.0
###                 See accompanying file LICENSE.txt or copy at
###                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

SET( SOURCES
  splat.cpp
  unary_minus.cpp
# List of simd test files for toolbox dd_reals
   )

##############################################################################
# For each filename
##############################################################################
FOREACH( EXAMPLE ${SOURCES})
  STRING(REGEX REPLACE ".cpp" "" EXAMPLE ${EXAMPLE})
  nt2_module_add_unit(dd_reals.simd.${EXAMPLE}.unit ${EXAMPLE}.cpp)
ENDFOREACH()

