##############################################################################
###   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
###   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
###
###          Distributed under the Boost Software License, Version 1.0
###                 See accompanying file LICENSE.txt or copy at
###                     http://www.boost.org/LICENSE_1_0.txt
##############################################################################

SET( SOURCES
#  along.cpp
#  blkdiag.cpp
#  cat.cpp
  colvect.cpp
  diag_of.cpp
#  expand.cpp
#  expand_to.cpp
#  flipdim.cpp
#  fliplr.cpp
#  flipud.cpp
  from_diag.cpp
#  horzcat.cpp
#  ifvectvert.cpp
#  putalong.cpp
#  reshape.cpp
#  resize.cpp
  rowvect.cpp
#  squeeze.cpp
#  transpose.cpp
#  ctranspose.cpp
#  vertcat.cpp
# List of simd test files for toolbox generative
   )

nt2_module_add_tests(type.complex.restructuring.table.unit ${SOURCES})
