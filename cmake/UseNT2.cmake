################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

list(APPEND CMAKE_MODULE_PATH ${NT2_MODULE_PATH})

#include_directories(BEFORE ${NT2_INCLUDE_DIR})
get_directory_property(INCLUDE_DIRECTORIES INCLUDE_DIRECTORIES)
set(INCLUDE_DIRECTORIES ${NT2_INCLUDE_DIR} ${INCLUDE_DIRECTORIES})
list(REMOVE_DUPLICATES INCLUDE_DIRECTORIES)
set_property(DIRECTORY PROPERTY INCLUDE_DIRECTORIES ${INCLUDE_DIRECTORIES})

#link_directories(${NT2_LIBRARY_DIR})
get_directory_property(LINK_DIRECTORIES LINK_DIRECTORIES)
set(LINK_DIRECTORIES ${NT2_LIBRARY_DIR} ${LINK_DIRECTORIES})
list(REMOVE_DUPLICATES LINK_DIRECTORIES)
set_property(DIRECTORY PROPERTY LINK_DIRECTORIES ${LINK_DIRECTORIES})

link_libraries(${NT2_LIBRARIES})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${NT2_COMPILE_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${NT2_COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${NT2_LINK_FLAGS}")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${NT2_LINK_FLAGS}")
set(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} ${NT2_LINK_FLAGS}")
nt2_str_remove_duplicates(CMAKE_C_FLAGS CMAKE_CXX_FLAGS CMAKE_EXE_LINKER_FLAGS CMAKE_SHARED_LINKER_FLAGS CMAKE_MODULE_LINKER_FLAGS)
