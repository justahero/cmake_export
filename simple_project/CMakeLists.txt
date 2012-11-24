project ("simple_project" C CXX)
cmake_minimum_required (VERSION 2.8)

set (Sample_DIR "../cmake_export_install")
find_package (Sample REQUIRED)

message (STATUS "SAMPLE_DIR: ${Sample_DIR}")
message (STATUS "SAMPLE_INCLUDE_DIR: ${SAMPLE_INCLUDE_DIR}")
message (STATUS "SAMPLE_INCLUDE_DIRS: ${SAMPLE_INCLUDE_DIRS}")
message (STATUS "SAMPLE_LIBRARIES: ${SAMPLE_LIBRARIES}")
message (STATUS "SAMPLE_EXECUTABLE: ${SAMPLE_EXECUTABLE}")

include_directories (SAMPLE_INCLUDE_DIRS)

message (STATUS "projects")
add_subdirectory (bar)
message (STATUS "     bar")

