##############################################################################
###   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
###   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
###
###          Distributed under the Boost Software License, Version 1.0
###                 See accompanying file LICENSE.txt or copy at
###                     http://www.boost.org/LICENSE_1_0.txt
##############################################################################

##****************************************************************************
##*     Toolbox boost_math unit tests
##****************************************************************************

nt2_module_use_modules( test.unit        core.ieee         core.arithmetic
                        core.euler  core.exponential  core.hyperbolic
                        core.elliptic
                      )
ADD_SUBDIRECTORY(scalar)
