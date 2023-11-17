# Install script for directory: D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/src/cd25ece3b9-089ebeb171.clean

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/pkgs/poco_x86-windows/debug")
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

if(CMAKE_INSTALL_COMPONENT STREQUAL "Devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES
    "D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/Poco/PocoConfig.cmake"
    "D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/Poco/PocoConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/src/cd25ece3b9-089ebeb171.clean/cmake/FindPCRE2.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/Foundation/cmake_install.cmake")
  include("D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/Encodings/cmake_install.cmake")
  include("D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/XML/cmake_install.cmake")
  include("D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/JSON/cmake_install.cmake")
  include("D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/Util/cmake_install.cmake")
  include("D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/Net/cmake_install.cmake")
  include("D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/MongoDB/cmake_install.cmake")
  include("D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/Redis/cmake_install.cmake")
  include("D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/Prometheus/cmake_install.cmake")
  include("D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/JWT/cmake_install.cmake")
  include("D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/NetSSL_OpenSSL/cmake_install.cmake")
  include("D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/Crypto/cmake_install.cmake")
  include("D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/Data/cmake_install.cmake")
  include("D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/ActiveRecord/cmake_install.cmake")
  include("D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/ActiveRecord/Compiler/cmake_install.cmake")
  include("D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/SevenZip/cmake_install.cmake")
  include("D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/Zip/cmake_install.cmake")
  include("D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/CppParser/cmake_install.cmake")
  include("D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/PocoDoc/cmake_install.cmake")
  include("D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/PageCompiler/cmake_install.cmake")
  include("D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/PageCompiler/File2Page/cmake_install.cmake")
  include("D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/Encodings/Compiler/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "D:/ArkAscendedApi/ServerAPI/AsaApi/vcpkg_installed/vcpkg/blds/poco/x86-windows-dbg/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
