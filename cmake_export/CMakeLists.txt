# see http://www.cmake.org/Wiki/CMake/Tutorials/How_to_create_a_ProjectConfig.cmake_file
# for further details

cmake_minimum_required (VERSION 2.8)
project ("export_example" C CXX)

set (SAMPLE_MAJOR_VERSION 0)
set (SAMPLE_MINOR_VERSION 1)
set (SAMPLE_PATCH_VERSION 0)
set (SAMPLE_VERSION ${SAMPLE_MAJOR_VERSION}.${SAMPLE_MINOR_VERSION}.${SAMPLE_PATCH_VERSION})

# Set module path for using custom cmake commands
#set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAE_SOURCE_DIR}/cmake/Modules")

# Offer the user the choice of overriding the installation directories
set(INSTALL_LIB_DIR lib CACHE PATH "Installation directory for libraries")
set(INSTALL_BIN_DIR bin CACHE PATH "Installation directory for executables")
set(INSTALL_ARCHIVE_DIR CACHE PATH "Installation directory for arcbives")
set(INSTALL_INCLUDE_DIR include CACHE PATH "Installation directory for header files")
#
if (WIN32 AND NOT CYGWIN)
  set (DEF_INSTALL_CMAKE_DIR CMake)
else ()
  set (DEF_INSTALL_CMAKE_DIR lib/CMake/Sample)
endif ()
set (INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH "Installation directory for CMake files")

# Make relative paths absolute (needed later on)
foreach (p LIB BIN INCLUDE CMAKE)
  set (var INSTALL_${p}_DIR)
  if (NOT IS_ABSOLUTE "${${var}}")
    set (${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
  endif ()
endforeach ()

# used to find project specific include files
include_directories (
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_BINARY_DIR}"
)


# The interesting part goes here!

# add projects
message (STATUS "Libraries")
include_directories (libs/libfoo)
add_subdirectory (libs/libfoo)
message (STATUS "    libfoo")
message (STATUS "Applications")
add_subdirectory (project_a)
message (STATUS "    project_a")


# add and set export targets
export (TARGETS
    project_a foo
    FILE "${PROJECT_BINARY_DIR}/SampleLibraryDepends.cmake"
)

# export the Package!
export (PACKAGE Sample)

# create build tree setinngs cmake file
configure_file (SampleBuildTreeSettings.cmake.in
    "${PROJECT_BINARY_DIR}/SampleBuildTreeSettings.cmake" @ONLY)

file (RELATIVE_PATH CONF_REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}"
    "${INSTALL_INCLUDE_DIR}/include")

configure_file (SampleConfig.cmake.in
    "${PROJECT_BINARY_DIR}/SampleConfig.cmake" @ONLY)
configure_file (SampleConfigVersion.cmake.in
    "${PROJECT_BINARY_DIR}/SampleConfigVersion.cmake" @ONLY)

# Install SampleConfig.cmake and SampleConfigVersion.cmake files
install (FILES
    "${PROJECT_BINARY_DIR}/SampleConfig.cmake"
    "${PROJECT_BINARY_DIR}/SampleConfigVersion.cmake"
    DESTINATION "{INSTALL_CMAKE_DIR}" COMPONENT dev
)

install (
    EXPORT SampleLibraryDepends
    DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev
)


