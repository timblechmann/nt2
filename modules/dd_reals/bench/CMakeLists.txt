
################################################################################
###   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
###   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
###
###          Distributed under the Boost Software License, Version 1.0
###                 See accompanying file LICENSE.txt or copy at
###                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

################################################################################
# Add global bench driver rules
################################################################################
ADD_CUSTOM_TARGET(dd_reals.scalar.bench)
ADD_CUSTOM_TARGET(dd_reals.simd.bench)
ADD_DEPENDENCIES(dd_reals.bench dd_reals.scalar.bench dd_reals.simd.bench)

##############################################################################
# Toolbox dd_reals bench tests
##############################################################################
nt2_module_use_modules(bench predicates)
ADD_SUBDIRECTORY(scalar)
ADD_SUBDIRECTORY(simd)

