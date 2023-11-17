# Install script for directory: D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/expat/src/R_2_5_0-56671c0753.clean/expat

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/pkgs/expat_x86-windows/debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "OFF")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/expat/x86-windows-dbg/expat_config.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/expat/x86-windows-dbg/libexpatd.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/expat/x86-windows-dbg/libexpatd.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/expat/src/R_2_5_0-56671c0753.clean/expat/lib/expat.h"
    "D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/expat/src/R_2_5_0-56671c0753.clean/expat/lib/expat_external.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/expat/x86-windows-dbg/Debug/expat.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/expat" TYPE FILE FILES
    "D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/expat/src/R_2_5_0-56671c0753.clean/expat/AUTHORS"
    "D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/expat/x86-windows-dbg/changelog"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/expat-2.5.0" TYPE FILE FILES
    "D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/expat/x86-windows-dbg/cmake/expat-config.cmake"
    "D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/expat/x86-windows-dbg/cmake/expat-config-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/expat-2.5.0/expat.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/expat-2.5.0/expat.cmake"
         "D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/expat/x86-windows-dbg/CMakeFiles/Export/3008fbcc3e30b4dfd7b1299dbea941c7/expat.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/expat-2.5.0/expat-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/expat-2.5.0/expat.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/expat-2.5.0" TYPE FILE FILES "D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/expat/x86-windows-dbg/CMakeFiles/Export/3008fbcc3e30b4dfd7b1299dbea941c7/expat.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/expat-2.5.0" TYPE FILE FILES "D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/expat/x86-windows-dbg/CMakeFiles/Export/3008fbcc3e30b4dfd7b1299dbea941c7/expat-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/expat/x86-windows-dbg/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
