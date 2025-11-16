# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION ${CMAKE_VERSION}) # this file comes with cmake

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/home/runner/work/re-plants-vs-zombies/re-plants-vs-zombies/cmake-build/libpng")
  file(MAKE_DIRECTORY "/home/runner/work/re-plants-vs-zombies/re-plants-vs-zombies/cmake-build/libpng")
endif()
file(MAKE_DIRECTORY
  "/home/runner/work/re-plants-vs-zombies/re-plants-vs-zombies/cmake-build/libpng"
  "/home/runner/work/re-plants-vs-zombies/re-plants-vs-zombies/cmake-build/SexyAppFramework/imagelib/libpng-src-prefix"
  "/home/runner/work/re-plants-vs-zombies/re-plants-vs-zombies/cmake-build/SexyAppFramework/imagelib/libpng-src-prefix/tmp"
  "/home/runner/work/re-plants-vs-zombies/re-plants-vs-zombies/cmake-build/SexyAppFramework/imagelib/libpng-src-prefix/src/libpng-src-stamp"
  "/home/runner/work/re-plants-vs-zombies/re-plants-vs-zombies/cmake-build/SexyAppFramework/imagelib/libpng-src-prefix/src"
  "/home/runner/work/re-plants-vs-zombies/re-plants-vs-zombies/cmake-build/SexyAppFramework/imagelib/libpng-src-prefix/src/libpng-src-stamp"
)

set(configSubDirs Debug;Release)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/runner/work/re-plants-vs-zombies/re-plants-vs-zombies/cmake-build/SexyAppFramework/imagelib/libpng-src-prefix/src/libpng-src-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/runner/work/re-plants-vs-zombies/re-plants-vs-zombies/cmake-build/SexyAppFramework/imagelib/libpng-src-prefix/src/libpng-src-stamp${cfgdir}") # cfgdir has leading slash
endif()
