#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Poco::NetSSL" for configuration "Debug"
set_property(TARGET Poco::NetSSL APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Poco::NetSSL PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/PocoNetSSLd.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/PocoNetSSLd.dll"
  )

list(APPEND _cmake_import_check_targets Poco::NetSSL )
list(APPEND _cmake_import_check_files_for_Poco::NetSSL "${_IMPORT_PREFIX}/debug/lib/PocoNetSSLd.lib" "${_IMPORT_PREFIX}/debug/bin/PocoNetSSLd.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
