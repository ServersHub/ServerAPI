#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Poco::CppParser" for configuration "Release"
set_property(TARGET Poco::CppParser APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Poco::CppParser PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/PocoCppParser.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/PocoCppParser.dll"
  )

list(APPEND _cmake_import_check_targets Poco::CppParser )
list(APPEND _cmake_import_check_files_for_Poco::CppParser "${_IMPORT_PREFIX}/lib/PocoCppParser.lib" "${_IMPORT_PREFIX}/bin/PocoCppParser.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
