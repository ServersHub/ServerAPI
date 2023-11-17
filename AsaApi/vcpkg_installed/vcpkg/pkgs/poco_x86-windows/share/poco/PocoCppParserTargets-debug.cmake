#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Poco::CppParser" for configuration "Debug"
set_property(TARGET Poco::CppParser APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Poco::CppParser PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/PocoCppParserd.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/PocoCppParserd.dll"
  )

list(APPEND _cmake_import_check_targets Poco::CppParser )
list(APPEND _cmake_import_check_files_for_Poco::CppParser "${_IMPORT_PREFIX}/debug/lib/PocoCppParserd.lib" "${_IMPORT_PREFIX}/debug/bin/PocoCppParserd.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
